#pragma once 
#include<string>
#include "Value.h"
#include "SymTable.h"
using namespace std;

enum nodeKind{
    NK_LITERAL, // 6, "ceva", true 
    NK_ID,  //a , b
    NK_FIELD, // obj ** field
    NK_OTHER,
    NK_OP, // + - / etc..
    NK_CALL,

    NK_IF,
    NK_WHILE,
    NK_RETURN,
    NK_ASSIGN,
    NK_PRINT,
    NK_NEW
};

class ASTNode{
   public:
         nodeKind tip;

         string exprType;
         string op;
         string idName;
         string objName;
         string fieldName;
         vector<ASTNode*>* args;
         vector<ASTNode*>* thenBlock;
         vector<ASTNode*>* elseBlock;
         Value lit;

         ASTNode* left;
         ASTNode* right;

   ASTNode (nodeKind k){
    tip =k;
    exprType ="error";
    op="";
    idName="";
    objName="";
    fieldName="";
    args =nullptr;
    thenBlock =nullptr;
    elseBlock =nullptr;
    left =nullptr;
    right =nullptr;
   }

   ~ASTNode(){
    delete right;
    delete left;
    left=right=nullptr;
    if(args){
        for(ASTNode* n : *args) delete n;
        delete args;
    }
    if(thenBlock){
        for(ASTNode* n : *thenBlock) delete n;
        delete thenBlock;
    }
    if(elseBlock){
        for(ASTNode* n : *elseBlock) delete n;
        delete elseBlock;
    }
   }

   static ASTNode* makeLiteral(const Value& v){
    ASTNode* n= new ASTNode(NK_LITERAL);
    n->lit = v;
    n->exprType = v.type;
    return n;
   }

   static ASTNode* makeNew(const string& className, vector<ASTNode*>* args){
      ASTNode* n = new ASTNode(NK_NEW);
       n->idName=className;
       n->args =args;
       n->exprType =className;
     return n;
   }

  static ASTNode* makeId(const string& name, const string& t){
       ASTNode* n= new ASTNode(NK_ID);
       n->idName= name;
       n->exprType=t;
    return n;
   }

    static ASTNode* makeFieldAccess(const string& obj, const string& field, const string& t){
         ASTNode* n = new ASTNode(NK_FIELD);
         n->objName = obj;
         n->fieldName = field;
         n->exprType = t;
    return n;
   }

    static ASTNode* makeOther(const string& t){
         ASTNode* n= new ASTNode(NK_OTHER);
        n->exprType =t;
    return n;
   }

    static ASTNode* makeOp(const string& oper, ASTNode* a, ASTNode* b, const string& t){
        ASTNode* n= new ASTNode(NK_OP);
        n->exprType =t;
        n->op= oper;
        n->left=a;
        n->right=b;
    return n;
   }

  static ASTNode* makeAssign(const string& name,ASTNode* expr){
       ASTNode* n= new ASTNode(NK_ASSIGN);
       n->idName = name;
       n->left= expr; 

    if(expr != nullptr)
        n->exprType = expr->exprType;
    else
        n->exprType = "error";
    return n;
   }

   static ASTNode* makeAssignField(const string& obj, const string& field, ASTNode* expr){
   
    ASTNode* n= new ASTNode(NK_ASSIGN);
    n->objName =obj;
    n->fieldName = field;
    n->left = expr;
    if(expr != nullptr)
        n->exprType = expr->exprType;
    else
        n->exprType = "error";
    return n;
   }

   static ASTNode* makeCall(const string& name, vector<ASTNode*>* a, const string& t){
    ASTNode* n = new ASTNode(NK_CALL);
    n->idName = name;
    n->args = a;
    n->exprType = t;
    return n;
   }

   static ASTNode* makeMethodCall(const string& obj, const string& method, vector<ASTNode*>* a, const string& t){
    ASTNode* n = new ASTNode(NK_CALL);
    n->objName = obj;
    n->fieldName = method;
    n->args = a;
    n->exprType = t;
    return n;
   }

   static ASTNode* makeIf(ASTNode* cond, vector<ASTNode*>* thenB, vector<ASTNode*>* elseB){
    ASTNode* n = new ASTNode(NK_IF);
    n->left = cond;
    n->thenBlock = thenB;
    n->elseBlock = elseB;
    n->exprType = "void";
    return n;
   }

   static ASTNode* makeWhile(ASTNode* cond, vector<ASTNode*>* body){
    ASTNode* n = new ASTNode(NK_WHILE);
    n->left = cond;
    n->thenBlock = body;
    n->exprType = "void";
    return n;
   }

   static ASTNode* makeReturn(ASTNode* expr){
    ASTNode* n = new ASTNode(NK_RETURN);
    n->left = expr;
    if(expr != nullptr)
        n->exprType = expr->exprType;
    else
        n->exprType = "error";
    return n;
   }

   static ASTNode* makePrint(ASTNode* expr){
    ASTNode* n= new ASTNode(NK_PRINT);
    n->left= expr; 
    if(expr != nullptr)
        n->exprType = expr->exprType;
    else
        n->exprType = "error";
    return n;
   }

   Value eval(SymTableManager& x);
};
