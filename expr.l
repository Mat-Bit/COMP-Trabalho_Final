delim	[ \t]
ws	{delim}+
digito	[0-9]
letras [a-zA-Z]
metacharacter [a-zA-Z0-9_]

int {digito}+{digito}*
float {int}+\.{int}
string {metacharacter}*
literal \".*\"

id ([_]|{letras})+{metacharacter}*

%%
{ws}	{}
"+"	{return TADD;}
"-"	{return TSUB;}
"*"	{return TMUL;}
"/"	{return TDIV;}

"<" {return TMENOR;}
">" {return TMAIOR;}
"=" {return TATB;}
"<=" {return TMENORIG;}
">=" {return TMAIORIG;}

"==" {return TCOM;}
"!=" {return TDIF;}
"&&" {return TCEE;}
"||" {return TCOU;}
"!" {return TNEG;}

"if"	{return TIF;}
"while"	{return TWHILE;}
"else"	{return TELSE;}
"do"    {return TDO;}

"("	{return TAPAR;}
")"	{return TFPAR;}
"{"	{return TACHA;}
"}"	{return TFCHA;}
"\"" {return TASP;}

";" {return TPV;}
"," {return TV;}
"return" {return TRET;}
"print" {return TPRINT;}
"read" {return TREAD;}
"void" {return TVOID;}
"TRUE" {return TRUE;}
"FALSE" {return FALSE;}

"int" {return TINT;}
"float" {return TFLOAT;}
"String" {return TSTRING;}
{id} { strncpy(yylval.id, yytext, 9); return TID;}
{int}	{yylval.ConstInt=atoi(yytext); return TINT;}
{float}	{yylval.ConstFloat=atof(yytext); return TFLOAT;}
{literal} {strncpy(yylval.mensagem, yytext, 99); return TLITERAL;}
"&" {return TEND;}
\0	{return T_FIM;}
\n  {__linha__ ++;}
