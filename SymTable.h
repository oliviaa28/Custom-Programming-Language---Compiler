#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Value.h"

using namespace std;

class ASTNode;
class SymTable;

enum IdKind {KIND_VAR, KIND_FUNC, KIND_CLASS, KIND_PARAM, KIND_FIELD};

class SymbolInfo {
public:
    string name;
    string type;
    IdKind kind;

    string returnType;
    vector<string> paramTypes;
    vector<string> paramNames;
    vector<ASTNode*>* body;
    SymTable* defScope;
    SymbolInfo* refObject;

    string value;
    map<string, Value> fieldValues;

    SymbolInfo(string n, string t, IdKind k) : name(n), type(t), kind(k) {
        body = nullptr;
        defScope = nullptr;
        refObject = nullptr;
    }
    SymbolInfo() {
        body = nullptr;
        defScope = nullptr;
        refObject = nullptr;
    }
};

class SymTable {
public:
    string scopeName;
    SymTable* parent;
    map<string, SymbolInfo*> symbols;

    SymTable(string name, SymTable* p = nullptr) : scopeName(name), parent(p) {}

    bool addSymbol(SymbolInfo* symbol);
    SymbolInfo* lookup(string name);
    bool existsSym(string name);
    void print(ofstream& out);

    ~SymTable();
};

class SymTableManager {
public:
    SymTable* currentScope;
    vector<SymTable*> allTables;

    SymTableManager();

    void enterScope(string name);
    void exitScope();
    SymTable* findClassScope(string className);
    bool classExists(string className);
    void ensureObjectFields(SymbolInfo* obj);
    void printAll(string filename);
};
