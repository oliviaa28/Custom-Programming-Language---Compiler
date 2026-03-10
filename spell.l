%{
    #include "spell.tab.h"
    #include <string>
    #include <iostream>

     using namespace std;
    extern int yylineno;
 
%}

%option noyywrap

letter [a-zA-Z]
digit  [0-9]
id     {letter}({letter}|{digit}|_)*

integer {digit}+

float ({digit}+\.{digit}+)|(\.{digit}+) 

string \"[^\"]*\" 
whitespace [ \t\r]+
comment \/\/.*

%%

{whitespace}    {/*ignore*/}
"\n"            { yylineno++;}
{comment}       {/*ignore*/}

"DUEL"          { yylval.str_val = new string(yytext); return DUEL_KW;}
"HOUSE"         { yylval.str_val = new string(yytext); return HOUSE_KW; }
"FIELD"         { yylval.str_val = new string(yytext); return FIELD_KW; }
"CHARM"         { yylval.str_val = new string(yytext); return CHARM_KW; }
"SPELL"         { yylval.str_val = new string(yytext); return SPELL_KW; }
"PARCHMENT"     { yylval.str_val = new string(yytext); return PARCHMENT_KW; }
"SUMMON"        { yylval.str_val = new string(yytext); return SUMMON_KW; }
"PROPHECY"      { yylval.str_val = new string(yytext); return IF_KW; }
"CHANT"         { yylval.str_val = new string(yytext); return WHILE_KW; }
"ACCIO"         { yylval.str_val = new string(yytext); return RETURN_KW; }
"Print"         { yylval.str_val = new string(yytext); return PRINT_KW; }
"else"          { yylval.str_val = new string(yytext); return ELSE_KW; }

"int"           { yylval.str_val = new string(yytext); return TYPE_INT; }
"float"         { yylval.str_val = new string(yytext); return TYPE_FLOAT; }
"string"        { yylval.str_val = new string(yytext); return TYPE_STRING; }
"bool"          { yylval.str_val = new string(yytext); return TYPE_BOOL; }
"true"          { yylval.bool_val = true; return TRUE_LITERAL; }
"false"         { yylval.bool_val = false; return FALSE_LITERAL;}


{integer}       { yylval.int_val = stoi(yytext); return INT_LITERAL;}
{float}         { yylval.float_val = stod(yytext); return FLOAT_LITERAL;}
{string}        {
                    string tmp(yytext);
                    if(tmp.size() >= 2) tmp= tmp.substr(1, tmp.size()-2);   
                    yylval.str_val = new string(tmp);
                    return STRING_LITERAL;
                }

"<~"     { return ASSIGN_OP;}
"**"      { return ACCESS_OP;}
"&&"     {return AND;}
"||"    {return OR;}
"=="    {return EQUAL;}
"!="    {return NOT_EQUAL;}
"!"     {return NOT;}

"+"   { return '+'; }
"-"   { return '-'; }
"*"  { return '*'; }
"/"  { return '/'; }
"%"   { return '%'; }
"<"   { return '<'; }
">"   { return '>'; }
"<="    {return LESS_EQUAL;}
">="    {return GREATER_EQUAL;}

"("   { return '('; }
")"   { return ')'; }
"{"   { return '{'; }
"}"   { return '}'; }
","   { return ','; }
";"   { return ';'; }
":"   { return ':'; }

{id}            { yylval.str_val = new string(yytext); return ID; }

.               { cerr <<"lexical error on line "<< yylineno; }

%%
