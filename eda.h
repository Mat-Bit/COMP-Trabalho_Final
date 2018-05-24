#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _EDA_N_DEFINIDO_
#define _EDA_N_DEFINIDO_

#define ADD 100
#define SUB 200
#define MUL 300
#define DIV 400
#define I2F 1000
#define F2I 1010
#define NEGAT 1020

#define ATR 500
#define IDD 600
#define CONSTI 700
#define CONSTF 800
#define MSG 850

#define IGUAL 900
#define DIF 910
#define MENIG 920
#define MAIIG 930
#define MAIOR 940
#define MENOR 950

#define NEG 1100
#define EEE 1110
#define OOU 1111

#define IFF  1200
#define IFEL 1250
#define WLE  1300
#define PRT 1400
#define DOWLE 1500
#define CMD 2000
#define BLC 3000

#define MAXID 10
#define TIPO int
#define NDEFINIDO 0
#define T_INT 1
#define T_FLOAT 2
#define T_STRING 3
#define T_VOID 4
#define NATRIBUIDO 0.0

typedef struct Lista{
    char id[MAXID];
    TIPO tipo;
    struct Lista *proximo;
} tLista;

typedef struct Msg{
    char mensagem[100];
} tMsg;

typedef struct no{
    char *valor;
    TIPO tipo;
    int pos;
    float atrib;
    char *atr_ch;
    struct no *direita;
    struct no *esquerda;
} tNo;

typedef struct arvore{
    tNo *raiz;
    int qtd;
}tArvore;

typedef struct AST{
    int cod;
    char *id;
    float atrib;
    tMsg *atr_ch;
    TIPO tipo;
    int ConstInt;
    float ConstFloat;
    int lv, lf;
    struct AST *pt1,*pt2;
}tAST;


void printLista(tLista *cabeca);
tLista *criarLista (char *id);
void insereLista (tLista *head, char *id);
void insereTipo(tLista *head, TIPO tipo);

tArvore * criarArvore();
void insereArvore(tArvore *arv, tLista *lista);
void insereArvoreInterna(tNo *no, tLista *lista, int posicao, TIPO tipo);
tNo * criaNo(tLista *lista, int posicao, TIPO tipo);
void printArvoreInicio(tArvore *arv);
void printArvore(tNo *elem, int nivel);
void printNos(tNo *no, int nivel);
void insereListaNaArvore(tLista * lista, tArvore * arv);
tNo *busca(tNo *arvore, char *id);

tAST *criar_ast_id(tArvore *tabSimb, char *id);
tAST *criar_ast_int(int valor_int);
tAST *criar_ast_float(float valor_float);
tAST *criaAst_ExpArit(tAST *exp_esq, tAST *exp_dir, int cod);
void printa_arv_exp(tAST *cabeca);
tAST *criaCmdAtrib(tArvore *tabSimb, tAST *cabeca, char *id);
tAST *criaListaComando(tAST *comando, int cod);
tAST *insereListaComando(tAST *listaCmd, tAST *comando, int cod);
tAST *criaAst_ExpRelac(tAST *exp_esq, tAST *exp_dir, int cod);
tAST *criaAst_ExpLog(tAST *exp_esq, tAST *exp_dir, int cod);
tAST *criaCmdIf(tAST *exp_esq, tAST *exp_dir, int cod);
tAST *criaCmdIfElse(tAST *expr, tAST *p_if, tAST *p_else, int cod);
tAST *criaCmdWhile(tAST *exp_esq, tAST *exp_dir, int cod);
tAST *criaCmdDoWhile(tAST *exp_esq, tAST *exp_dir, int cod);
tAST *criaLiteral(tMsg *msg, int cod);
tMsg *criaMensagem (char *escrita);
tAST *cmdPrint(tAST *param, int cod);

void retiraExtensao(char *nome_arquivo, char arq_sem_ext[]);
int geraLabel();
void printa_op_code(tAST *cabeca, tArvore *tabelaSimbolos, FILE *arq_saida);
tAST *i2f(tAST *ptr);
tAST *f2i(tAST *ptr);
tAST *neg(tAST *ptr);

#endif
