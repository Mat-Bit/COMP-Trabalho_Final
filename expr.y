%{
#include <stdio.h>
#include <stdlib.h>
#include "eda.h"

tArvore *tabelaSimbolos;

typedef struct Atributo{
  tLista *listaId;
  tArvore *tabelaSimbolos;
  char id[MAXID];
  int tipo;
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
    | BlocoPrincipal;

ListaFuncoes: ListaFuncoes Funcao
    | Funcao;

Funcao: TipoRetorno TID TAPAR DeclParametros TFPAR BlocoPrincipal
    | TipoRetorno TID TAPAR TFPAR BlocoPrincipal;

TipoRetorno: Tipo
    | TVOID;

DeclParametros: DeclParametros TV Parametro
    | Parametro;

Parametro: Tipo TID;

BlocoPrincipal: TACHA Declaracoes ListaCmd TFCHA
    | TACHA ListaCmd TFCHA;

Declaracoes: Declaracoes Declaracao
    | Declaracao;

Declaracao: Tipo ListaId TPV {insereTipo($2.listaId, $1.tipo); printLista($2.listaId); insereListaNaArvore($2.listaId, tabelaSimbolos); printf("\n");};

Tipo: TINT {$$.tipo = T_INT;}
    | TSTRING {$$.tipo = T_STRING;}
    | TFLOAT {$$.tipo = T_FLOAT;};

ListaId: ListaId TV TID {insereLista($1.listaId, $3.id); $$.listaId = $1.listaId;}
    | TID {$$.listaId = criarLista($1.id);};

Bloco: TACHA ListaCmd TFCHA;

ListaCmd: ListaCmd Comando {$$.ast = insereListaComando($1.ast, $2.ast);}
    | Comando

Comando: CmdSe
    | CmdEnquanto
    | CmdAtrib  {$$.ast = $1.ast}
    | CmdEscrita
    | CmdLeitura
    | ChamadaProc
    | Retorno;

Retorno: TRET ExpressaoAritimetica TPV
    | TRET TLITERAL TPV;

CmdSe: TIF TAPAR ExpressaoLogica TFPAR Bloco
    | TIF TAPAR ExpressaoLogica TFPAR Bloco TELSE Bloco

CmdEnquanto: TWHILE TAPAR ExpressaoLogica TFPAR Bloco;

CmdAtrib: TID TATB ExpressaoAritimetica TPV {$$.ast = criaCmdAtrib(tabelaSimbolos, $3.ast, $1.id); printf("\n");printa_op_code($$.ast, tabelaSimbolos); printf("\n\n");}
    | TID TATB TLITERAL;

CmdEscrita: TPRINT TAPAR TASP ExpressaoAritimetica TASP TFPAR TPV
    | TPRINT TAPAR ExpressaoAritimetica TFPAR TPV
    | TPRINT TAPAR TLITERAL TFPAR TPV;

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
ExpressaoAritimetica: ExpressaoAritimetica TADD TExpressaoAritimetica { $$.ast = criaAst_ExpArit($1.ast, $3.ast, ADD); }
    | ExpressaoAritimetica TSUB TExpressaoAritimetica { $$.ast = criaAst_ExpArit($1.ast, $3.ast, SUB); }
    | TExpressaoAritimetica { $$.ast = $1.ast; } ;

TExpressaoAritimetica: TExpressaoAritimetica TMUL FExpressaoAritmetica { $$.ast = criaAst_ExpArit($1.ast, $3.ast, MUL); }
    | TExpressaoAritimetica TDIV FExpressaoAritmetica { $$.ast = criaAst_ExpArit($1.ast, $3.ast, DIV); }
    | FExpressaoAritmetica  { $$.ast = $1.ast; } ;

FExpressaoAritmetica: TAPAR ExpressaoAritimetica TFPAR { $$.ast = $2.ast; }
    | TFLOAT {$$.ast = criar_ast_float($1.ConstFloat);printa_op_code($$.ast, tabelaSimbolos);}
    | TINT {$$.ast = criar_ast_int($1.ConstInt); printa_op_code($$.ast, tabelaSimbolos);}
    | TID {$$.ast = criar_ast_id(tabelaSimbolos, $1.id); printa_op_code($$.ast, tabelaSimbolos);};

ExpressaoLogica: ExpressaoLogica TCEE FExpressaoLogica
    | ExpressaoLogica TCOU FExpressaoLogica
    | FExpressaoLogica;

FExpressaoLogica: TNEG FExpressaoLogica
    | TAPAR FExpressaoLogica TFPAR
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
