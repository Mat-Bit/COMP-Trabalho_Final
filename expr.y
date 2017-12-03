%{
#include <stdio.h>
#include <stdlib.h>
#include "eda.h"

tArvore *tabelaSimbolos;
FILE *arq_saida;
tAST *raiz;


typedef struct Atributo{
  tLista *listaId;
  tArvore *tabelaSimbolos;
  char id[MAXID];
  char mensagem[100];
  TIPO tipo;
  int ConstInt;
  float ConstFloat;
  tAST *ast;
//
}tAtributo;

#define YYSTYPE tAtributo
int __linha__ = 1;
%}

%token TADD TSUB TMUL TDIV TMENOR TMAIOR TATB TMENORIG TMAIORIG TCOM TDIF TCEE TCOU TNEG TIF TWHILE TELSE TAPAR TFPAR TACHA TFCHA TASP TINT TFLOAT TSTRING TID TPV TV TRET TPRINT TREAD TVOID TLITERAL TRUE FALSE TEND T_FIM

%%
Programa: ListaFuncoes BlocoPrincipal
    | BlocoPrincipal  {$$.ast = $1.ast; raiz = $$.ast;};

ListaFuncoes: ListaFuncoes Funcao
    | Funcao;

Funcao: TipoRetorno TID TAPAR DeclParametros BlocoPrincipal TFPAR BlocoPrincipal
    | TipoRetorno TID TAPAR TFPAR BlocoPrincipal;

TipoRetorno: Tipo
    | TVOID;

DeclParametros: DeclParametros TV Parametro
    | Parametro;

Parametro: Tipo TID;

BlocoPrincipal: TACHA Declaracoes ListaCmd TFCHA {$$.ast = $3.ast;}
    | TACHA ListaCmd TFCHA {$$.ast = $2.ast;};

Declaracoes: Declaracoes Declaracao
    | Declaracao;

Declaracao: Tipo ListaId TPV {insereTipo($2.listaId, $1.tipo); insereListaNaArvore($2.listaId, tabelaSimbolos);};

Tipo: TINT {$$.tipo = T_INT;}
    | TSTRING {$$.tipo = T_STRING;}
    | TFLOAT {$$.tipo = T_FLOAT;};

ListaId: ListaId TV TID {insereLista($1.listaId, $3.id); $$.listaId = $1.listaId;}
    | TID {$$.listaId = criarLista($1.id);};

Bloco: TACHA ListaCmd TFCHA {$$.ast = $2.ast;};


ListaCmd: ListaCmd Comando {$$.ast = insereListaComando($1.ast, $2.ast, CMD);}
    | Comando {$$.ast = $1.ast;} ;

Comando: CmdSe {$$.ast = $1.ast;}
    | CmdEnquanto {$$.ast = $1.ast;}
    | CmdAtrib {$$.ast = $1.ast;}
    | CmdEscrita {$$.ast = $1.ast;}
    | CmdLeitura {$$.ast = $1.ast;}
    | ChamadaProc {$$.ast = $1.ast;}
    | Retorno {$$.ast = $1.ast;};

Retorno: TRET ExpressaoAritimetica TPV
    | TRET TLITERAL TPV;

CmdSe: TIF TAPAR ExpressaoLogica TFPAR Bloco {$$.ast = criaCmdIf($3.ast, $5.ast, IFF);}
    | TIF TAPAR ExpressaoLogica TFPAR Bloco TELSE Bloco {$$.ast = criaCmdIfElse($3.ast, $5.ast, $7.ast, IFEL);};

CmdEnquanto: TWHILE TAPAR ExpressaoLogica TFPAR Bloco {$$.ast = criaCmdWhile($3.ast, $5.ast, WLE);};

CmdAtrib: TID TATB ExpressaoAritimetica TPV {$$.ast = criaCmdAtrib(tabelaSimbolos, $3.ast, $1.id);}
    | TID TATB TLITERAL;

CmdEscrita: TPRINT TAPAR ExpressaoAritimetica TFPAR TPV {$$.ast = cmdPrint($3.ast, PRT)}
    | TPRINT TAPAR TLITERAL TFPAR TPV {$3.ast = criaLiteral($3.mensagem, MSG); $$.ast = cmdPrint($3.ast, PRT);};

CmdLeitura: TREAD TAPAR TID TFPAR TPV
    | TREAD TAPAR TEND TID TFPAR TPV;

ChamadaProc: ChamadaFuncao TPV;

ChamadaFuncao: TID TAPAR ListaParametros TFPAR
    | TID TAPAR TFPAR;

ListaParametros: ListaParametros TV ExpressaoAritimetica
    | ListaParametros TV TLITERAL
    | ExpressaoAritimetica
    | TLITERAL;

//Expressões
ExpressaoAritimetica: ExpressaoAritimetica TADD TExpressaoAritimetica { $$.ast = criaAst_ExpArit($1.ast, $3.ast, ADD);}
    | ExpressaoAritimetica TSUB TExpressaoAritimetica { $$.ast = criaAst_ExpArit($1.ast, $3.ast, SUB); }
    | TExpressaoAritimetica { $$.ast = $1.ast; } ;

TExpressaoAritimetica: TExpressaoAritimetica TMUL FExpressaoAritmetica { $$.ast = criaAst_ExpArit($1.ast, $3.ast, MUL); }
    | TExpressaoAritimetica TDIV FExpressaoAritmetica { $$.ast = criaAst_ExpArit($1.ast, $3.ast, DIV); }
    | FExpressaoAritmetica  { $$.ast = $1.ast; } ;

FExpressaoAritmetica: TAPAR ExpressaoAritimetica TFPAR { $$.ast = $2.ast; }
    | TFLOAT {$$.ast = criar_ast_float($1.ConstFloat);}
    | TINT {$$.ast = criar_ast_int($1.ConstInt);}
    | TID {$$.ast = criar_ast_id(tabelaSimbolos, $1.id);};

ExpressaoLogica: ExpressaoLogica TCEE FExpressaoLogica {$$.ast = criaAst_ExpLog($1.ast, $3.ast, EEE);}
    | ExpressaoLogica TCOU FExpressaoLogica {$$.ast = criaAst_ExpLog($1.ast, $3.ast, OOU);}
    | FExpressaoLogica;

FExpressaoLogica: TNEG FExpressaoLogica {$$.ast = criaAst_ExpLog($2.ast, NULL, NEG);}
    | TAPAR FExpressaoLogica TFPAR {$$.ast = $2.ast;}
    | TRUE
    | FALSE
    | ExpressaoRelacional;

ExpressaoRelacional: ExpressaoAritimetica TMAIOR ExpressaoAritimetica {$$.ast = criaAst_ExpRelac($1.ast, $3.ast, MAIOR);}
    | ExpressaoAritimetica TMAIORIG ExpressaoAritimetica {$$.ast = criaAst_ExpRelac($1.ast, $3.ast, MAIIG);}
    | ExpressaoAritimetica TMENOR ExpressaoAritimetica  {$$.ast = criaAst_ExpRelac($1.ast, $3.ast, MENOR);}
    | ExpressaoAritimetica TMENORIG ExpressaoAritimetica {$$.ast = criaAst_ExpRelac($1.ast, $3.ast, MENIG);}
    | ExpressaoAritimetica TCOM ExpressaoAritimetica {$$.ast = criaAst_ExpRelac($1.ast, $3.ast, IGUAL);}
    | ExpressaoAritimetica TDIF ExpressaoAritimetica {$$.ast = criaAst_ExpRelac($1.ast, $3.ast, DIF);};

%%
#include "lex.yy.c"

int yyerror (char *str)
{
	printf("[Linha%d]\tTipo de erro: %s\t antes do caracter: %s\n", __linha__,str, yytext);
}

int yywrap()
{
	return 1;
}
