%code requires {
    #include <string>
    #include <vector>
    using namespace std;
    class ASTNode; 
}

%{
#include <iostream>
#include <string>
#include <vector>
#include "SymTable.h"
#include "AST.h"
#include "Value.h"
using namespace std;

extern int yylex();
extern int yylineno;
SymTableManager tableManager;
string currentType;
string currentClass;
SymbolInfo* currentFunction = nullptr;
void yyerror(const char *s);
int errorCount = 0;

%}

%union {
    string* str_val;
    bool bool_val;
    int int_val;
    float float_val;
  //  vector<string>* vec_val;

    ASTNode* node_val;
    vector<ASTNode*>* node_list;
}

%token <str_val> DUEL_KW  HOUSE_KW  FIELD_KW  CHARM_KW  SPELL_KW
%token <str_val> PARCHMENT_KW  SUMMON_KW
%token <str_val> IF_KW   WHILE_KW   ELSE_KW
%token <str_val> RETURN_KW   PRINT_KW

%token <str_val> TYPE_INT  TYPE_FLOAT  TYPE_STRING  TYPE_BOOL

%token <str_val> ID
%token <int_val> INT_LITERAL
%token <float_val> FLOAT_LITERAL
%token <str_val> STRING_LITERAL
%token <bool_val>TRUE_LITERAL   FALSE_LITERAL

%token ASSIGN_OP   ACCESS_OP
%type <str_val> type ret_type
%type <node_val> expr literal lvalue call_expr new_obj expr_bool
%type <node_list> args args_opt func_body
%type <node_val> st_fara_decl assign_st print_st call_st if_st while_st return_st
%type <node_list> lista_st_fara_decl bloc_fara_decl

%left OR
%left AND
%left EQUAL NOT_EQUAL
%left '<' LESS_EQUAL '>' GREATER_EQUAL

%left '+' '-'
%left '*' '/' '%'

%right NOT
%right UMINUS
%%

program : def_globale duel 
     /*   if (errorCount == 0) cout<< "The program is correct!" << endl;*/
        ;

def_globale : def_globale def_globala 
            | 
            ;

def_globala : class_def 
            | func_def
            | global_decl
            ;

global_decl : ID ':' type ';'
            {   SymbolInfo* s = new SymbolInfo(*$1, *$3, KIND_VAR); /*creeaza o variabila cu numele dolar 1 si tipul.. 3*/
             
               if(!tableManager.currentScope->addSymbol(s)){ /*incercam sa o adaugam in tabel */
                    yyerror(("Error: Variable " + *$1 + " is already defined.").c_str()); 
                }
                 else if( tableManager.classExists(*$3) ) 
                    tableManager.ensureObjectFields(s);
                
              delete $1; delete $3;
            }   
            | ID ':' type ASSIGN_OP expr ';'
            {      
                if(*$3 != $5->exprType && $5->exprType != "error")
                      yyerror(("Type mismatch in initialization of " + *$1 +". Declared: " + *$3 + " but got: " +  $5->exprType).c_str());

                  SymbolInfo* s = new SymbolInfo(*$1, *$3, KIND_VAR);
                  if($5->tip == NK_LITERAL) 
                       s->value= $5->lit.to_str();
                  else s->value = "<uninitialized>";

                 if(!tableManager.currentScope->addSymbol(s)){
                   yyerror(("Error: Variable " + *$1 + " is already defined.").c_str());
                 } 
                  else if(tableManager.classExists(*$3)) 
                          tableManager.ensureObjectFields(s);
                 
             delete $1; delete $3; delete $5;
            }
            ;


duel : DUEL_KW 
    { 
        tableManager.enterScope("Global_Duel"); 
    }
    bloc_fara_decl
    { 
        for(ASTNode* n : *$3 ) 
           if(n)
            n->eval(tableManager);

        for(ASTNode* n : *$3 ) delete n;
        delete $3;

        tableManager.exitScope();
    } 
     ;


bloc_fara_decl : '{' lista_st_fara_decl '}' { $$ = $2 ;}
              ;

lista_st_fara_decl : lista_st_fara_decl st_fara_decl 
                    {
                        $$=$1;
                        if( $2 != nullptr)
                           $$->push_back($2);
                    }
                   | 
                   {
                    $$= new vector<ASTNode*>();
                   }
                  ;

st_fara_decl : print_st
             | assign_st
             | call_st
             | if_st
             | while_st
             | return_st
             ;

func_def : SPELL_KW ID
         {
            SymbolInfo* f = new SymbolInfo(*$2, "error", KIND_FUNC);
            f->returnType = "error";
            if(!tableManager.currentScope->addSymbol(f)){
                yyerror(("Error: Function " + *$2 + " is already defined.").c_str());
            }
            tableManager.enterScope("Func_" + *$2);
            currentFunction = f;
         }
         '(' params_opt ')' ret_type
         {
            if(currentFunction != nullptr && $7 != nullptr){
                currentFunction->returnType = *$7;
                currentFunction->type = *$7;
            }
            delete $7;
         }
         func_body
         { /*cand terminam functia, inchidem */
            currentFunction->body= $9;
            currentFunction->defScope= tableManager.currentScope;
            tableManager.exitScope();
            currentFunction= nullptr;
         }
         ;

func_body : '{' parchment_opt lista_st_fara_decl '}' { $$ = $3; }
          ;

/* lista de declaratii, de ex x: int <~ 10*/ /*_________________________________________________________________________________________________________*/
parchment_opt : PARCHMENT_KW '{' local_decl_list_opt '}' | 
              ;

local_decl_list_opt: local_decl_list
                    | 
                    ;

local_decl_list : local_decl_list local_decl
                | local_decl
                ;

local_decl : ID ':' type ';'
            {
               SymbolInfo* s = new SymbolInfo(*$1, *$3, KIND_VAR);
              if(!tableManager.currentScope->addSymbol(s)){
                  yyerror(("Error: Variable " + *$1 + " is already defined.").c_str());
               } else if(tableManager.classExists(*$3)) {
                  tableManager.ensureObjectFields(s);
               }
            delete $1; delete $3;
           }
            | ID ':' type ASSIGN_OP expr ';'
            {
              if(*$3 !=  $5->exprType &&  $5->exprType != "error")
                        yyerror(("Type mismatch in initialization of " + *$1 +". Declared: " + *$3 + " but got: " +  $5->exprType).c_str());

              SymbolInfo* s = new SymbolInfo(*$1, *$3, KIND_VAR);

               if( $5 && $5->tip == NK_LITERAL ) s->value = $5->lit.to_str();
                else s->value = "<uninitialized>";

              if(!tableManager.currentScope->addSymbol(s))
                  yyerror(("Error: Variable " + *$1 + " is already defined.").c_str());
              else if(tableManager.classExists(*$3)) {
                  tableManager.ensureObjectFields(s);
              }
                
             delete $1; delete $3; delete $5;
            }

            ;
/*_________________________________________________________________________________________________________*/

class_def : HOUSE_KW ID
            {   SymbolInfo* c = new SymbolInfo(*$2, "class", KIND_CLASS);
                if(!tableManager.currentScope->addSymbol(c)){
                    yyerror(("Error: Class " + *$2 + " is already defined.").c_str());
                }
                currentClass = *$2;
                tableManager.enterScope("Class_" + *$2); 
            }
         '{' class_members_opt '}'
            { tableManager.exitScope(); currentClass.clear(); }
          ;

class_members_opt : class_members_opt class_member
                  | 
                     ;

class_member: FIELD_KW ID ':' type ';'
            {   SymbolInfo* s = new SymbolInfo(*$2, *$4, KIND_FIELD);
                if(!tableManager.currentScope->addSymbol(s)){
                    yyerror(("Error: Variable " + *$2 + " is already defined.").c_str());
                }
            }   
             | CHARM_KW ID 
             {
                SymbolInfo* m = new SymbolInfo(*$2, "error", KIND_FUNC);
                m->returnType = "error";

                if(!tableManager.currentScope->addSymbol(m)){
                    yyerror(("Error: Method " + *$2 + " is already defined.").c_str());
                }

                tableManager.enterScope("Method_" + *$2);
                currentFunction = m;
                if(!currentClass.empty()){
                    SymbolInfo* selfSym = new SymbolInfo("this", currentClass, KIND_VAR);
                    if(!tableManager.currentScope->addSymbol(selfSym)){
                        delete selfSym;
                    }
                }
             }
             '(' params_opt ')' ret_type
             {
                if(currentFunction != nullptr && $7 != nullptr){
                    currentFunction->returnType = *$7;
                    currentFunction->type = *$7;
                }
                delete $7;
             }
             func_body
             {
                currentFunction->body = $9;
                currentFunction->defScope = tableManager.currentScope;
                tableManager.exitScope();
                currentFunction = nullptr;
             }
             ;

/*________________________________________ STATEMENTS ___________________________________________________________*/


if_st : IF_KW '(' expr_bool ')' bloc_fara_decl
        {
            if($3->exprType != "bool" && $3->exprType != "error")
                yyerror("Condition must be bool");
            
            $$ = nullptr;
        }
      | IF_KW '(' expr_bool ')' bloc_fara_decl ELSE_KW bloc_fara_decl
        {
            if($3->exprType != "bool" && $3->exprType != "error")
                 yyerror("Condition must be bool");  
            $$ = nullptr;
        }
    ;

while_st: WHILE_KW '(' expr_bool ')' bloc_fara_decl
         {
            if($3->exprType != "bool" && $3->exprType != "error")
                yyerror("Condition must be bool");
            
            $$ = nullptr;
         }
         ;

return_st: RETURN_KW expr_bool ';'
        {
            if ( currentFunction != nullptr ) {
                if( $2->exprType != currentFunction->returnType) {
                    yyerror(("Return type mismatch. Expected " + currentFunction->returnType + " but got " + $2->exprType).c_str());
                }
            } 
            else {
                yyerror("Return statement outside of function/method");
            }
            $$ = nullptr;
        }
         ;

print_st : PRINT_KW '(' expr_bool ')' ';'
        {
            if ($3->exprType== "void") {
                yyerror("Cannot print void expr.");
            }

            $$ = ASTNode::makePrint($3);
        }
         ;

assign_st : lvalue ASSIGN_OP expr_bool ';'
{
    if($1->exprType != "error" && $3->exprType != "error" && $1->exprType != $3->exprType){
        yyerror(("Cannot assign value of type " + $3->exprType + " to variable of type " + $1->exprType).c_str());
    }

    if($1->tip == NK_ID) 
       $$= ASTNode::makeAssign($1->idName, $3);
    else if($1->tip == NK_FIELD) 
            $$= ASTNode::makeAssignField($1->objName, $1->fieldName, $3);
    else {
      $$= nullptr;
      delete $3;
    }
   delete $1;
}
;

lvalue: ID
      {
        SymbolInfo* s = tableManager.currentScope->lookup(*$1);
        if( s == nullptr ) {
            yyerror(("Variable " + *$1 + " is not defined.").c_str());
           $$ = ASTNode::makeOther("error");
        }
        else 
             $$=ASTNode::makeId(*$1, s->type);
        
        delete $1;
      }
      | ID ACCESS_OP ID
      {
        SymbolInfo* obj = tableManager.currentScope->lookup(*$1);

        if(obj == nullptr){
            yyerror(("Object " + *$1 + " not defined.").c_str());
             $$ = ASTNode::makeOther("error");
        }
        else 
        if(!tableManager.classExists(obj->type)) {
            yyerror(("Type " + obj->type + " is not a class, cannot access members.").c_str());
          $$=ASTNode::makeOther("error");
        }
        else {
            SymTable* classScope = tableManager.findClassScope(obj->type);

            if(classScope == nullptr) {
                yyerror(("Class scope for " + obj->type + " not found.").c_str());
                 $$=ASTNode::makeOther("error");
            }
            else {
                SymbolInfo* field = classScope->lookup(*$3);
                if(field == nullptr) {
                    yyerror(("Field " + *$3 + " not found in class " + obj->type).c_str());
                     $$=ASTNode::makeOther("error");
                }
                else if(field->kind != KIND_FIELD) {
                    yyerror(("Member " + *$3 + " is not a field in class " + obj->type).c_str());
                     $$=ASTNode::makeOther("error");
                }
                else {
                   $$ = ASTNode::makeFieldAccess(*$1, *$3, field->type);
                }
            }
        } 
        delete $1; delete $3;
      }
      ;

call_expr : ID '(' args_opt ')'
        {
            SymbolInfo* f = tableManager.currentScope->lookup(*$1);

            if( f == nullptr || f->kind != KIND_FUNC ) {
                yyerror(("Function " + *$1 + " is not defined.").c_str());
                for(ASTNode* n: *$3) delete n;
                delete $3;
                $$ = ASTNode::makeOther("error");
            }
            else {
                if(f->paramTypes.size() != $3->size()) {
                    yyerror(("Function " + *$1 + " expects " + to_string(f->paramTypes.size()) + " arguments, but got " + to_string($3->size())).c_str());
                    for(ASTNode* n: *$3) delete n;
                    delete $3;
                    $$ = ASTNode::makeOther("error");
                }
                else {
                    bool ok =true;
                    for ( size_t i =0; i < f->paramTypes.size(); i++) {
                        if(f->paramTypes[i] != (*$3)[i]->exprType ) {
                          yyerror(( "Argument " + to_string(i+1) + " of function " + *$1 +" type mismatch. Expected " + f->paramTypes[i] +", got " + (*$3)[i]->exprType).c_str());

                            ok = false;
                        }
                    }
                  if (ok) $$ =ASTNode::makeCall(*$1, $3, f->returnType);
                    else {
                      for(ASTNode* n: *$3) delete n;
                      delete $3;
                      $$ = ASTNode::makeOther("error");
                    }
                }
            }
              delete $1;
        }
        | ID ACCESS_OP ID '(' args_opt ')'
        {
            SymbolInfo* obj = tableManager.currentScope->lookup(*$1);

            if(obj == nullptr) {
                yyerror(("Object " + *$1 + " is not defined.").c_str());
                for(ASTNode* n : *$5) delete n;
                delete $5;
                $$ = ASTNode::makeOther("error");
            }
            else if( !tableManager.classExists(obj->type) ) {
               yyerror(("Type " + obj->type + " is not a class, cannot access members.").c_str());
             for(ASTNode* n : *$5) delete n;
             delete $5;
             $$ = ASTNode::makeOther("error");
           }
            else {
                SymTable* classScope = tableManager.findClassScope(obj->type);

                if(classScope == nullptr) {
                    yyerror(("Class scope for object " + *$1 + " not found.").c_str());
                    for(ASTNode* n : *$5) delete n;
                    delete $5;
                    $$ = ASTNode::makeOther("error");
                }
                else {
                    SymbolInfo* method = classScope->lookup(*$3);

                    if(method == nullptr || method->kind != KIND_FUNC) {
                        yyerror(("Method " + *$3 + " is not defined in class " + obj->type).c_str());
                        for(ASTNode* n : *$5) delete n;
                        delete $5;
                        $$ = ASTNode::makeOther("error");
                    }
                    else {
                        
                        if(method->paramTypes.size() != $5->size()) {
                            yyerror(("Method " + *$3 + " expects " + to_string(method->paramTypes.size()) + " arguments, but got " + to_string($5->size())).c_str());
                            for(ASTNode* n : *$5) delete n;
                            delete $5;
                            $$ = ASTNode::makeOther("error");
                        }
                        else {
                            bool ok = true;
                            for (size_t i = 0; i < method->paramTypes.size(); i++) {
                                if(method->paramTypes[i] != (*$5)[i]->exprType ){
                                   yyerror(( "Argument " + to_string(i+1) + " of method " + *$3 +" type mismatch. Expected " + method->paramTypes[i] +", got " + (*$5)[i]->exprType).c_str());

                                    ok = false;
                                }
                            }
                            if (ok) $$ = ASTNode::makeMethodCall(*$1, *$3, $5, method->returnType);
                            else {
                              for(ASTNode* n : *$5) delete n;
                              delete $5;
                              $$ = ASTNode::makeOther("error");
                            }
                        }
                    }
                }
            }
          delete $1; delete $3;
        }
        ;

call_st : call_expr ';' { $$ = nullptr; }
         ;

new_obj: SUMMON_KW ID '(' args_opt ')'
     {
      if(!tableManager.classExists(*$2)){
           yyerror(("Class " + *$2 + " is not defined.").c_str());
          $$=ASTNode::makeOther("error");
          for(ASTNode* n : *$4) delete n;
          delete $4;
      } else 
        $$ = ASTNode::makeNew(*$2, $4);

    delete $2;
}
;

/*____________________________________________________________________________________________________*/
expr_bool : expr { $$ = $1; }

        | expr LESS_EQUAL expr
        { 
            if($1->exprType != $3->exprType && $1->exprType != "error" && $3->exprType != "error")
                yyerror(("<= requires same types, but got " + $1->exprType + " and " + $3->exprType).c_str());

            if(($1->exprType != "int" && $1->exprType != "float") && $1->exprType != "error")
                yyerror("<= requires numeric operands");

            $$ = ASTNode::makeOp("<=", $1, $3, "bool"); 
        }

       | expr GREATER_EQUAL expr
       {  
            if($1->exprType != $3->exprType && $1->exprType != "error" && $3->exprType != "error")
                yyerror((">= requires same types, but got " + $1->exprType + " and " + $3->exprType).c_str());

            if(($1->exprType != "int" && $1->exprType != "float") && $1->exprType != "error")
                yyerror(">= requires numeric operands");

            $$ =ASTNode::makeOp(">=", $1, $3, "bool"); 
       }

       | expr EQUAL expr
       {
            if($1->exprType != $3->exprType && $1->exprType != "error" && $3->exprType != "error")
                yyerror(("== requires same types, but got " + $1->exprType + " and " + $3->exprType).c_str());

            $$ =ASTNode::makeOp("==", $1, $3, "bool"); 
       }

       | expr NOT_EQUAL expr
       {
            if($1->exprType != $3->exprType && $1->exprType != "error" && $3->exprType != "error")
                yyerror(("!= requires same types, but got " + $1->exprType + " and " + $3->exprType).c_str());

            $$ =ASTNode::makeOp("!=", $1, $3, "bool"); 
       }

       | expr_bool AND expr_bool
       { 
            if ($1->exprType != "bool" || $3->exprType != "bool")
                yyerror("AND requires boolean operands");
            $$ =ASTNode::makeOp("AND", $1, $3, "bool"); 
       }

       | expr_bool OR expr_bool
       { 
            if ($1->exprType != "bool" || $3->exprType != "bool")
                yyerror("OR requires boolean operands");
            $$=ASTNode::makeOp("OR", $1, $3, "bool"); 
       }

       | expr '<' expr 
       {  
            if($1->exprType != $3->exprType && $1->exprType != "error" && $3->exprType != "error")
                yyerror(("< requires same types, but got " + $1->exprType + " and " + $3->exprType).c_str());

            if(($1->exprType != "int" && $1->exprType != "float") && $1->exprType != "error")
                yyerror("< requires numeric operands");

            $$ = ASTNode::makeOp("<", $1, $3, "bool"); 
       } 

       | expr '>' expr  
       { 
            if($1->exprType != $3->exprType && $1->exprType != "error" && $3->exprType != "error")
                yyerror(("> requires same types, but got " + $1->exprType + " and " + $3->exprType).c_str());

            if(($1->exprType != "int" && $1->exprType!= "float") && $1->exprType != "error")
                yyerror("> requires numeric operands");

            $$=ASTNode::makeOp(">", $1, $3, "bool"); 
       }

       | NOT expr_bool
       {
            if($2->exprType != "bool")
                yyerror("NOT requires boolean operand");
            $$=ASTNode::makeOp("NOT", $2, nullptr, "bool"); 
       }
       ;


expr: literal
    {
        $$ = $1;
    }
    | ID 
    {
        SymbolInfo* s = tableManager.currentScope->lookup(*$1);
        if (s == nullptr) {
            yyerror(("Variable " + *$1 + " is not declared.").c_str());
             $$ =ASTNode::makeOther("error");
        } else 
             $$ =ASTNode::makeId(*$1, s->type);
     delete $1; 
    }
    |call_expr
    {
        $$ = $1;
    }
    | ID ACCESS_OP ID 
    {
        SymbolInfo* obj = tableManager.currentScope->lookup(*$1);
        if(obj == nullptr){
            yyerror(("Object " + *$1 + " not defined.").c_str());
            $$=ASTNode::makeOther("error");

        }
        else if(!tableManager.classExists(obj->type)){
            yyerror(("Type " + obj->type + " is not a class, cannot access members.").c_str());
        $$ = ASTNode::makeOther("error");
        }
        else {
            SymTable* classScope = tableManager.findClassScope(obj->type);

            if(classScope == nullptr) {
                yyerror(("Class definition for object" + *$1 + " not found.").c_str());
               $$ = ASTNode::makeOther("error");
            }
            else {
                SymbolInfo* field = classScope->lookup(*$3);
                if(field == nullptr) {
                    yyerror(("Field " + *$3 + " not found in class " + obj->type).c_str());
                    $$ = ASTNode::makeOther("error");
                }
                else if(field->kind != KIND_FIELD) {
                    yyerror(("Member " + *$3 + " is not a field in class " + obj->type).c_str());
                    $$=ASTNode::makeOther("error");
                }
                else {
                   $$=ASTNode::makeFieldAccess(*$1, *$3, field->type);
                }
            }
        } 
     delete $1; delete $3;
      }
    | new_obj
    {
        $$ = $1;
    }
    | '(' expr_bool ')'
    {
        $$ = $2;
    }

   | '-' expr %prec UMINUS 
   {
     if($2->exprType != "int" && $2->exprType != "float"){
         yyerror("Unary minus requires numeric type");
         $$ = ASTNode::makeOther("error");
        delete $2;
      } else 
          $$ = ASTNode::makeOp("UMINUS", $2, nullptr, $2->exprType);
   }

   | expr '*' expr
   {
       if( $1->exprType != $3->exprType ){
           yyerror(("Type mismatch: cannot multiply " + $1->exprType + " and " + $3->exprType).c_str());
           $$ = ASTNode::makeOther("error");
        delete $1; delete $3;
     } else 
        $$ = ASTNode::makeOp("*", $1, $3, $1->exprType);

    }

   | expr '/' expr
   {
      if( $1->exprType != $3->exprType ) {
          yyerror("Type mismatch in division");
          $$ =ASTNode::makeOther("error");
        delete $1; delete $3;
      } else 
         $$ =ASTNode::makeOp("/", $1, $3, $1->exprType);
   }

   | expr '%' expr
   {
    if( $1->exprType  != "int" || $3->exprType != "int") {
        yyerror("Modulo requires int types");
         $$ =ASTNode::makeOther("error");
        delete $1; delete $3;
    } else 
        $$ =ASTNode::makeOp("%", $1, $3, $1->exprType);
   }

   | expr '+' expr
   {
       if( $1->exprType != $3->exprType ){
           yyerror(("Type mismatch: cannot add " + $1->exprType + " and " + $3->exprType).c_str());
           $$ =ASTNode::makeOther("error");
        delete $1; delete $3;
      } else 
         $$ = ASTNode::makeOp( "+", $1, $3, $1->exprType);
    }

  | expr '-' expr
  {
      if( $1->exprType != $3->exprType ){
           yyerror(("Type mismatch: " + $1->exprType + " and " + $3->exprType).c_str());
           $$ =ASTNode::makeOther("error");
        delete $1; delete $3;
      } else 
         $$ = ASTNode::makeOp( "-", $1, $3, $1->exprType);
  } 

    ;

/*doar literali ne boleeni */
literal : INT_LITERAL { $$ = ASTNode::makeLiteral(Value::makeInt($1));}
        | FLOAT_LITERAL { $$ =ASTNode::makeLiteral(Value::makeFloat($1));  }
        | STRING_LITERAL { $$=ASTNode::makeLiteral(Value::makeString(*$1)); delete $1; }
        | TRUE_LITERAL   { $$ = ASTNode::makeLiteral(Value::makeBool(true)); }
        | FALSE_LITERAL  { $$ = ASTNode::makeLiteral(Value::makeBool(false)); }
    ;
         ;

type: TYPE_INT
    | TYPE_FLOAT
    | TYPE_STRING
    | TYPE_BOOL
    | ID   
      {
        if(!tableManager.classExists(*$1)){
            yyerror("Type __ is not a defined class");
            $$ =new string("error");
          delete $1;
        }else
            $$ = $1; /*tipul e numele claseii */
      }         
    ;

params_opt: params
          | 
          ;

params : param
       | params ',' param
       ;

param: ID ':' type
        {   SymbolInfo* s = new SymbolInfo(*$1, *$3, KIND_PARAM);
            if(!tableManager.currentScope->addSymbol(s)){
                yyerror(("Error: Variable " + *$1 + " is already defined.").c_str());
                }

            if(currentFunction != nullptr ){
                currentFunction->paramTypes.push_back(*$3);
                currentFunction->paramNames.push_back(*$1);
            }
        }   
      ;

args_opt : args { $$ = $1; }
         | { $$ = new vector<ASTNode*>(); }
         ;

args: expr_bool
   {
     $$=new vector<ASTNode*>();
     $$->push_back($1);
  }
  | args ',' expr_bool
  {
    $$ =$1;
    $$->push_back($3);
  }
;

ret_type : ':' type { $$ = $2; }
        ;

%%

void yyerror(const char * s){
     cout << "error:" << s << " at line: "<< yylineno << endl;
     errorCount++;
}

int main(){
    yyparse();
    tableManager.printAll("tables.txt");
    return 0;
}
