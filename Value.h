#pragma once
#include<string>
using namespace std;

class Value{
    public:
        string type; // int, float, strinf, bool sau error
        int i;
        float f;
        bool b;
        string s;

Value(){
    type = "error";
    i=0; f=0.0; b=false; s="";
}
//constructori
   static Value makeInt(int x){
    Value v;
    v.type= "int";
    v.i=x;
    return v;
   }

   static Value makeFloat(float x){
    Value v;
    v.type="float";
    v.f=x;
    return v;
   }

   static Value makeBool(bool x){
    Value v;
    v.type="bool";
    v.b=x;
    return v;
   }

    static Value makeString(const string& x){
    Value v;
    v.type="string";
    v.s=x;
    return v;
   }

   static Value def( const string &a){
    if( a == "int") return makeInt(0);
    if ( a== "float") return makeFloat(0);
    if( a == "bool") return makeBool(false);
    if(a == "string") return makeString("");
    return Value(); //err
   }

   string to_str() const{

     if( type== "int") return to_string(i);
    if ( type == "float") return to_string(f);
    if( type== "bool") return b ? "true":"false";
    if( type == "string") return s;
    return "error";
   }

};