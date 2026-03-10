#include "SymTable.h"

using namespace std;

bool SymTable::addSymbol(SymbolInfo* symbol){
    if(symbols.find(symbol->name)!= symbols.end()){
        return false;
    }
    symbols[symbol->name] = symbol;
    return true;
}

SymbolInfo* SymTable::lookup(string name){
    if(symbols.find(name) != symbols.end()){
        return symbols[name];
    }
    if(parent != nullptr){
        return parent->lookup(name);
    }
    return nullptr;
}

bool SymTable::existsSym(string name){
    return symbols.find(name) != symbols.end();
}

void SymTable::print(ofstream& out){
    out << "== Scope: "<<scopeName<<" ==="<<endl;
    if(parent){
        out << "Parent scope: "<<parent->scopeName<<endl;
    }
    out<<"Symbols:"<<endl;

    for(auto const& [key,val] : symbols){
        out<<" Name: "<< val->name <<" , Type: "<< val->type;

     if(val->kind == KIND_FUNC){
            out << ", Return: " << val->returnType << ", Parameters: (";
            for(auto p : val->paramTypes) out << p << " ";
            out << ")";
        }

    string kindStr;
         if(val->kind == KIND_VAR) kindStr = "Var";  
    else if(val->kind == KIND_FUNC) kindStr = "Func";
    else if(val->kind == KIND_CLASS) kindStr = "Class";
    else if(val->kind == KIND_PARAM) kindStr = "Param";
    else if(val->kind == KIND_FIELD) kindStr = "Field";
    else kindStr = "Unknown";

    out << ", Kind: " << kindStr;

    if(val->value != "") out << ", Value: " << val->value;
    out << endl;
  }
  out<<endl;
}

SymTable::~SymTable(){
    for ( auto p : symbols){
        delete p.second;
    }
}

SymTableManager::SymTableManager(){
    currentScope = new SymTable("Global");
    allTables.push_back(currentScope);
}

void SymTableManager::enterScope(string name){
    SymTable* newScope = new SymTable(name, currentScope);
    allTables.push_back(newScope);
    currentScope = newScope;
}

void SymTableManager::exitScope() {
    if(currentScope->parent != nullptr){
        currentScope = currentScope->parent;
    }
}

SymTable* SymTableManager::findClassScope(string className){
    for(auto t : allTables){
        if(t->scopeName == "Class_" + className) return t;
    }
    return nullptr;
}

bool SymTableManager::classExists(string className){
    SymbolInfo* s= allTables[0]->lookup(className);
    return ( s != nullptr && s->kind == KIND_CLASS);
}

void SymTableManager::ensureObjectFields(SymbolInfo* obj){
    if(obj == nullptr){
        return;
    }
    if(!classExists(obj->type)){
        return;
    }
    SymTable* classScope = findClassScope(obj->type);
    if(classScope == nullptr){
        return;
    }
    for(const auto& [name, sym] : classScope->symbols){
        if(sym->kind != KIND_FIELD){
            continue;
        }
        if(obj->fieldValues.find(name) == obj->fieldValues.end()){
            obj->fieldValues[name] = Value::def(sym->type);
        }
    }
}

void SymTableManager::printAll(string filename){
    ofstream out(filename);
    for(auto t: allTables){
        t->print(out);
    }
    out.close();
}
