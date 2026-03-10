#include "SymTable.h"
#include "AST.h"
#include <iostream>
using namespace std;

namespace {
struct ReturnSignal {
    Value value;
};

SymTable* runtimeScopeFromDef(SymbolInfo* func, SymTableManager& x, const vector<Value>& argVals){
    SymTable* defScope = nullptr;
    if(func != nullptr)
        defScope = func->defScope;

    SymTable* parent = x.allTables[0];
    if(defScope != nullptr && defScope->parent != nullptr)
        parent = defScope->parent;
    SymTable* runtime = new SymTable("Call_" + func->name, parent);

    if(defScope != nullptr)
        for(const auto& [name, sym] : defScope->symbols){
            if(sym->kind != KIND_VAR && sym->kind != KIND_PARAM)
                continue;
            SymbolInfo* copy = new SymbolInfo(*sym);
            copy->paramTypes.clear();
            copy->paramNames.clear();
            copy->body= nullptr;
            copy->defScope= nullptr;
            copy->refObject= nullptr;
            runtime->addSymbol(copy);
        }

    for(size_t i=0; i < func->paramNames.size() && i < argVals.size(); i++){
        const string& pname = func->paramNames[i];
        auto it= runtime->symbols.find(pname);
        
        if(it != runtime->symbols.end())
            it->second->value = argVals[i].to_str();
        else {
            SymbolInfo* p = new SymbolInfo(pname, func->paramTypes[i], KIND_PARAM);
            p->value = argVals[i].to_str();
            runtime->addSymbol(p);
        }
    }

    for(auto& [name, sym] : runtime->symbols)
        if(x.classExists(sym->type))
            x.ensureObjectFields(sym);

    return runtime;
}

Value evalStatementList(vector<ASTNode*>* list, SymTableManager& x){
    if(list == nullptr)
        return Value();
    for(ASTNode* n : *list){
        if(n == nullptr)
            continue;
        n->eval(x);
    }
    return Value();
}
} // 

static Value transf(const string& t, const string& v){
    if( t == "int"){
     if (v =="" || v== "<uninitialized>")
        return Value::def("int");
     return Value::makeInt(stoi(v));
    }

    if( t == "float"){
     if (v =="" || v== "<uninitialized>")
        return Value::def("float");
     return Value::makeFloat(stof(v));
    }

    if( t == "bool"){
     if (v =="" || v== "<uninitialized>")
        return Value::def("bool");
     return Value::makeBool( v == "true");
    }

    if( t == "string"){
     if (v =="" || v== "<uninitialized>")
        return Value::def("string");
     return Value::makeString( v);
    }
 return Value();
}

void runConstructor(SymbolInfo* objectVar, vector<ASTNode*>* args, SymTableManager& x) {
    SymTable* classScope = x.findClassScope(objectVar->type);
    if(!classScope) return;

    SymbolInfo* ctor = classScope->lookup(objectVar->type);
    if(ctor == nullptr || ctor->kind != KIND_FUNC || ctor->body == nullptr)
        return;

    vector<Value> argVals;
    if(args)
        for(ASTNode* a: *args)
            if(a != nullptr)
                argVals.push_back(a->eval(x));
            else
                argVals.push_back(Value());

    if (ctor->paramTypes.size() != argVals.size())
        return;

    SymTable* defScope = ctor->defScope;
    SymTable* parent = x.allTables[0];
    if(defScope != nullptr && defScope->parent != nullptr)
        parent = defScope->parent;
    SymTable* runtime = new SymTable("Constructor_" + ctor->name, parent);

    for(size_t i = 0; i < ctor->paramNames.size(); i++){
        SymbolInfo* p = new SymbolInfo(ctor->paramNames[i], ctor->paramTypes[i], KIND_PARAM);
        p->value = argVals[i].to_str();
        runtime->addSymbol(p);
    }

    for(const auto& [name, sym] : classScope->symbols){
        if(sym->kind == KIND_FIELD || sym->kind == KIND_VAR){
             SymbolInfo* copy = new SymbolInfo(*sym);
             // Daca obiectul are deja o valoare salvata, o folosim
             if(objectVar->fieldValues.count(name)) 
                 copy->value = objectVar->fieldValues[name].to_str();
             runtime->addSymbol(copy);
        }
    }

    SymTable* saved = x.currentScope;
    x.currentScope = runtime;
    try {
        if(ctor->body)
            for(ASTNode* n : *(ctor->body)) if(n) n->eval(x);
    } catch (...) {
        // Ignoram return in constructor
    }

    for(const auto& [name, sym] : runtime->symbols){
        if(sym->kind == KIND_FIELD || sym->kind == KIND_VAR){
             // Salvam valoarea inapoi in map-ul obiectului
             objectVar->fieldValues[name] = transf(sym->type, sym->value);
        }
    }

    x.currentScope = saved;
    delete runtime;
}

 Value ASTNode::eval(SymTableManager& x){ //fucntie recursiva care calculeaza valoarea expresiei
 
    if(this == nullptr) return Value();

    if(tip == NK_LITERAL) return lit;

    if(tip == NK_OTHER) return Value::def(exprType);  //default pt tipul lui

    if(tip == NK_CALL){
        vector<Value> valoriArgumente;

        if(args != nullptr){
            valoriArgumente.reserve(args->size());

            for(ASTNode* nodArg : *args){
                if(nodArg != nullptr)
                    valoriArgumente.push_back(nodArg->eval(x));
                else
                    valoriArgumente.push_back(Value());
               }
          }

        if(objName.empty()){//functie simpla
            SymbolInfo* functie= x.currentScope->lookup(idName);

            if(functie==nullptr|| functie->kind != KIND_FUNC || functie->body==nullptr)
                return Value();

            SymTable* scopApel=runtimeScopeFromDef(functie, x, valoriArgumente);
            SymTable* scopSalvat=x.currentScope;
            x.currentScope= scopApel;

            try {
                evalStatementList(functie->body, x);//executam codul
            } catch (const ReturnSignal& r) {
                x.currentScope= scopSalvat;
                delete scopApel;
                return r.value;
            }

            x.currentScope=scopSalvat;
            delete scopApel;
            return Value::def(functie->returnType);
        } 
        else // apel metoda **
         {
            SymbolInfo* obiect = x.currentScope->lookup(objName);
            if(obiect == nullptr || !x.classExists(obiect->type) )
                return Value();

            SymTable* scopClasa = x.findClassScope(obiect->type); 
            if(scopClasa == nullptr)
                return Value();

            SymbolInfo* metoda = scopClasa->lookup(fieldName); //cautam in tabelul clasei , nu in ala glibal
            if(metoda == nullptr || metoda->kind != KIND_FUNC || metoda->body == nullptr)
                return Value();

            x.ensureObjectFields(obiect); 
            SymTable* scopApel= runtimeScopeFromDef(metoda, x, valoriArgumente);
            SymbolInfo* simbolObiectCurent = nullptr;

            auto itSimbol = scopApel->symbols.find("this");
            if(itSimbol != scopApel->symbols.end())
                 simbolObiectCurent= itSimbol->second;

            if(simbolObiectCurent != nullptr){
                simbolObiectCurent->refObject = obiect;
                simbolObiectCurent->type= obiect->type;
            }
             else {
                SymbolInfo* variabilathis= new SymbolInfo("this", obiect->type, KIND_VAR);
                variabilathis->refObject= obiect; //pointer catre ob real
                scopApel->addSymbol(variabilathis);
            }

            //executie
            SymTable* scopSalvat= x.currentScope;
            x.currentScope= scopApel;

            try {
                evalStatementList(metoda->body, x);
            } 
            catch (const ReturnSignal& r){
                x.currentScope=scopSalvat;
                delete scopApel;
                return r.value;
            }
            x.currentScope = scopSalvat;
            delete scopApel;
            return Value::def(metoda->returnType);
          }
     }

    if(tip == NK_IF){
        if(left == nullptr) return Value();
        Value cond = left->eval(x);

        if(cond.type != "bool") return Value();
        if(cond.b)
            evalStatementList(thenBlock, x);
        else
            evalStatementList(elseBlock, x);
        return Value();
    }

    if(tip == NK_WHILE){
        if(left == nullptr) return Value();
        Value cond = left->eval(x);
        if(cond.type != "bool") return Value();
        while(cond.b){
            evalStatementList(thenBlock, x);
            cond = left->eval(x);
            if(cond.type != "bool") return Value();
        }
        return Value();
    }

    if(tip == NK_RETURN){
        if(left == nullptr) throw ReturnSignal{Value()};
        Value v = left->eval(x);
        throw ReturnSignal{v};
    }

    if(tip == NK_FIELD){
        SymbolInfo* obj = x.currentScope->lookup(objName);
        if(obj == nullptr)
            return Value();

        if(obj->refObject != nullptr)
            obj = obj->refObject;

        x.ensureObjectFields(obj);
        auto it = obj->fieldValues.find(fieldName);

        if(it != obj->fieldValues.end())
            return it->second;
        return Value::def(exprType);
    }

    if(tip == NK_ID){//returnam valoarea din symta
        SymbolInfo* s= x.currentScope->lookup(idName);
        if(s == nullptr)
          return Value();

        if (s->value == "") return Value::def(s->type) ; //daca nu are valoare returnam ce este default pt tip
       
        return transf( s->type, s->value);
    }

    if(tip == NK_ASSIGN){
        if(left ==nullptr) return Value();

        Value a= left->eval(x);

        if(!objName.empty()){
            SymbolInfo* obj = x.currentScope->lookup(objName);

            if(obj==nullptr) return Value();

            if(obj->refObject != nullptr)
                obj = obj->refObject;

            x.ensureObjectFields(obj);
            obj->fieldValues[fieldName] = a;
            return a;
        }

       SymbolInfo* s = x.currentScope->lookup( idName );
         if(s == nullptr) return Value(); // eroare

        // update in tabel
        s->value = a.to_str();

        if(left->tip == NK_NEW && x.classExists(s->type)){
            x.ensureObjectFields(s);
            runConstructor(s, left->args, x);
        }

        return a;
    }
  
    if( tip == NK_PRINT){
        if(left ==nullptr) return Value();

        Value v = left->eval(x);
        cout<< v.to_str() <<endl;
        return v;
    }

    if( tip == NK_NEW){
        Value v;
        v.type=idName;
        return v;
    }

    if(tip == NK_OP){
         
        if(op =="NOT"){
            Value a;
            if(left != nullptr)
                 a=left->eval(x);
            else a= Value();

            if(a.type !="bool") return Value();

          return Value::makeBool(!a.b); // b e variabila bool din clasa
        }

        if ( op =="UMINUS" ){
             Value a;
            if(left != nullptr)
                 a=left->eval(x);
            else a= Value();

            if(a.type =="int") return Value::makeInt(-a.i);
             if(a.type =="float") return Value::makeFloat(-a.f);
            return Value();
    
        }
//________________________binar________________________
     
       Value a, b;
        if(left != nullptr) a=left->eval(x);
         else a= Value();

        if(right != nullptr) b=right->eval(x);
         else b= Value();

         if(op == "+"){
           if(a.type == "int") return Value::makeInt (a.i +b.i);
           if(a.type =="float") return Value::makeFloat(a.f +b.f);
           if(a.type == "string") return Value::makeString(a.s+b.s);
         return Value();
         }

        if(op =="-"){
           if(a.type == "int") return Value::makeInt (a.i-b.i);
           if(a.type =="float") return Value::makeFloat(a.f-b.f);
         return Value();
         }

        if(op =="*"){
           if(a.type == "int") return Value::makeInt (a.i * b.i);
           if(a.type =="float") return Value::makeFloat(a.f * b.f);
         return Value();
         }

        
        if(op =="/"){
           if(a.type == "int"){ 
             if(b.i ==0 ) return Value();
           return Value::makeInt (a.i / b.i);
          }

           if(a.type =="float"){
             if(b.f ==0 ) return Value();
            return Value::makeFloat(a.f /b.f);
           }
         return Value();
         }

        if(op =="%"){
           if(a.type == "int"){ 
             if(b.i ==0 ) return Value();
           return Value::makeInt (a.i % b.i);
          }
          return Value();
        }
//_____________________________ comparatii ________________________________
   
   if(op == "<"){
     if(a.type == "int") return Value::makeBool(a.i < b.i);
     if(a.type =="float") return Value::makeBool(a.f <b.f);
    return Value();
   }

    if(op == "<="){
     if(a.type == "int") return Value::makeBool(a.i <= b.i);
     if(a.type =="float") return Value::makeBool(a.f <= b.f);
    return Value();
   }

    if(op == ">"){
       if(a.type == "int") return Value::makeBool(a.i > b.i);
       if(a.type =="float") return Value::makeBool(a.f >b.f);
    return Value();
   }

    if(op == ">="){
     if(a.type == "int") return Value::makeBool(a.i >= b.i);
      if(a.type =="float") return Value::makeBool(a.f >=b.f);
    return Value();
   }

   if(op == "=="){
        if(a.type == "int") return Value::makeBool(a.i == b.i);
        if(a.type =="float") return Value::makeBool(a.f == b.f);
        if(a.type == "bool") return Value::makeBool(a.b == b.b);
        if(a.type =="string") return Value::makeBool(a.s ==b.s);
    return Value();
   }

   if(op == "!="){
        if(a.type == "int") return Value::makeBool(a.i != b.i);
        if(a.type =="float") return Value::makeBool(a.f != b.f);
        if(a.type == "bool") return Value::makeBool(a.b != b.b);
        if(a.type =="string") return Value::makeBool(a.s !=b.s);
    return Value();
   }

   if (op =="AND"){
    if(a.type!="bool"|| b.type!="bool") return Value();
    return Value::makeBool(a.b && b.b);
   }

    if (op =="OR"){
    if(a.type!="bool"|| b.type!="bool") return Value();
    return Value::makeBool(a.b || b.b);
   }
  return Value();
  }
 return Value();
}
