#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _EDA_N_DEFINIDO_
#define _EDA_N_DEFINIDO_

#define ADD 100
#define SUB 200
#define MUL 300
#define DIV 400

#define MAXID 10
#define TIPO int
#define NDEFINIDO 0
#define T_INT 1
#define T_FLOAT 2
#define T_STRING 3
#define T_VOID 4

typedef struct Lista{
    char id[MAXID];
    TIPO tipo;
    struct Lista *proximo;
} tLista;

typedef struct no{
    char *valor;
    TIPO tipo;
    int num;
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
    struct AST *pt1,*pt2;
    int ConstInt;
    float ConstFloat;
    //
}tAST;

void printLista(tLista *cabeca);
tLista *criarLista (char *id);
void insereLista (tLista *head, char *id);
tArvore * criarArvore();
void insereArvore(tArvore *arv, tLista *lista);
void insereArvoreInterna(tNo *no, tLista *lista, int posicao);
tNo * criaNo(tLista *lista, int num);
void printArvoreInicio(tArvore *arv);
void printArvore(tNo *elem, int nivel);
void printNos(tNo *no, int nivel);
void insereListaNaArvore(tLista * lista, tArvore * arv);
tNo *busca(tNo *arvore, char *id);

tAST *criar_ast_id(tArvore *tabSimb, char *id);
tAST *criar_ast_int(int valor_int);
tAST *criar_ast_float(float valor_float);
tAST *cria_ast_op(tAST *exp_esq, tAST *exp_dir, int cod);
void printa_arv_exp(tAST *cabeca);

#endif
