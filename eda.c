#include "eda.h"

tLista *criarLista (char *id){
    tLista *elem = (tLista*)malloc(sizeof(tLista));
    if (elem != NULL){
        memcpy(elem->id, id, MAXID);
        elem->proximo = NULL;
    }
    return elem;
}

void insereTipo(tLista *head, TIPO tipo){
    if (head != NULL){
        head->tipo = tipo;
    }
}

void insereLista(tLista *head, char *id){
    if(head->proximo == NULL){
        head->proximo = (tLista *)malloc(sizeof(tLista));
        if(head->proximo != NULL){
            memcpy(head->proximo->id,id,MAXID);
            head->proximo->proximo = NULL;
        }
    }
    else{
        insereLista(head->proximo,id);
    }
}

void printLista(tLista *cabeca){
    if (cabeca == NULL){
        printf(";\n");
        return;
    }
    else {
        if (cabeca->tipo == T_INT)
        printf("int");

        if (cabeca->tipo == T_FLOAT)
        printf("float");

        if (cabeca->tipo == T_STRING)
        printf("String");

        if(cabeca->proximo == NULL)
        printf(" %s",(char*)cabeca->id );
        else
        printf(" %s,",(char*)cabeca->id );

        printLista(cabeca->proximo);
    }
}


tArvore * criarArvore(){
    tArvore * elem = (tArvore*)malloc(sizeof(tArvore));
    elem->raiz = NULL;
    elem->qtd = 0;
    return elem;
}

void insereArvore(tArvore *arv, tLista *lista){
    if(arv->raiz == NULL){
        arv->raiz = criaNo(lista, arv->qtd);
        arv->qtd++;
        return;
    }
    else{
        insereArvoreInterna(arv->raiz, lista, arv->qtd);
        arv->qtd++;
        return;
    }
}

void insereArvoreInterna(tNo *no, tLista *lista, int posicao){
    int elem = strcmp(no->valor, lista->id);
    if(elem == 0){
        printf("Símbolo %s já existe\n", lista->id);
        exit(-1);
    }
    if(elem > 0 && no->direita == NULL){
        no->direita = criaNo(lista,posicao);
        return;
    }
    if(elem<0 && no->esquerda == NULL){
        no->esquerda = criaNo(lista,posicao);
        return;
    }
    if(elem<0){
        insereArvoreInterna(no->esquerda, lista,posicao);
    }
    else {
        insereArvoreInterna(no->direita, lista,posicao);
    }
}

tNo * criaNo(tLista *lista, int num){
    tNo *elem = (tNo*)malloc(sizeof(tNo));

    elem->tipo = lista->tipo;
    elem->valor = malloc(sizeof(char)*100);
    strcpy(elem->valor,lista->id);

    elem->valor[99] = '\0';
    elem->num = num;
    elem->direita = NULL;
    elem->esquerda = NULL;
    return elem;
}

void printArvoreInicio(tArvore *arv){
    tNo *elem = (tNo*)malloc(sizeof(tNo));
    elem = arv->raiz;
    printArvore(elem, 0);
}

void printArvore(tNo *elem, int nivel){

    if(elem == NULL){
        printf("*");
        return;
    }
    printArvore(elem->esquerda, nivel+1);
    printNos(elem, nivel);
    printArvore(elem->direita, nivel+1);
}

void printNos(tNo *no, int nivel){
    int j;

    if(no == NULL) return;
    if(no->tipo == T_INT) printf("int ");
    if(no->tipo == T_FLOAT) printf("float ");
    if(no->tipo == T_STRING) printf("String ");

    for(j=0;j<nivel;j++){ printf("   ");}
    printf("%s\n", no->valor);
}

void insereListaNaArvore(tLista *lista, tArvore *arv){
    if(lista == NULL) return;

    insereArvore(arv, lista);
    insereListaNaArvore(lista->proximo, arv);
}

char *percorreArvore(tNo *no, int i){
    if(no->esquerda != NULL){
        if(i < no->num) return no->esquerda->valor;
    }
    if(no->direita != NULL){
        if(i > no->num) return no->direita->valor;
    }
    return no->valor;
}

tAST *criar_ast_id(tArvore *tabSimb, char *id){
    int i;
    char *aux;

    tAST *ast = (tAST*)malloc(sizeof(tAST));
    tNo *no = (tNo*)malloc(sizeof(tNo));
    no = tabSimb->raiz;

    for (i = 0; i < tabSimb->qtd; i++) {
        if(no != NULL){
            aux = percorreArvore(no, i);
            // se o id informado for um id válido (dentro da tabelaSimbolos)
            if(aux == id){
                ast->id = id;
                ast->pt1 = NULL;
                ast->pt2 = NULL;
                return ast;
            }
        }
    }
    // o ID nao está na tabelaSimbolos, ou seja é um ID invalido
    printf("A variavel %s nao eh valida\n", id);
    //exit(-1);
}

tAST *criar_ast_int(int valor_int){
    tAST *elem = (tAST*)malloc(sizeof(tAST));
    elem->ConstInt = valor_int;
    elem->id = NULL;
    elem->pt1 = NULL;
    elem->pt2 = NULL;
    return elem;
}

tAST *criar_ast_float(float valor_float){
    tAST *elem = (tAST*)malloc(sizeof(tAST));
    elem->ConstFloat = valor_float;
    elem->id = NULL;
    elem->pt1 = NULL;
    elem->pt2 = NULL;
    return elem;
}

tAST *cria_ast_op(tAST *exp_esq, tAST *exp_dir, int cod){
    int  dir=0, esq=0;
    float dirf=0.0, esqf=0.0, resultado;
    tAST *elem = (tAST*)malloc(sizeof(tAST));
    elem->pt1 = exp_esq;
    elem->pt2 = exp_dir;
    elem-> cod = cod;
    elem->id = NULL;
}

void printa_arv_exp(tAST *cabeca){

    if(cabeca->pt1 != NULL) printa_arv_exp(cabeca->pt1);
    if(cabeca->pt2 != NULL) printa_arv_exp(cabeca->pt1);

    if(cabeca->id != NULL) printf("%s ", cabeca->id);
    else{
        if(cabeca->ConstInt != 0) printf("%d ", cabeca->ConstInt);
        if(cabeca->ConstFloat != 0.0) printf("%.1f ", cabeca->ConstFloat);
    }

}

/*
if (elem->pt1->id != NULL){
if(elem->id->tipo == T_INT) esq = elem->id->num;
else{
if(elem->id->tipo == T_FLOAT) esqf = elem->id->num;
}
}
else{
if(elem->pt1->ConstInt != 0) esq = elem->pt1->ConstInt;
else{
if(elem->pt1->ConstFloat != 0.0) esqf = elem->pt1->ConstFloat;
}
}
if (elem->pt2->id != NULL){
if(elem->id->tipo == T_INT) dir = elem->id->num;
else{
if(elem->id->tipo == T_FLOAT) dirf = elem->id->num;
}
}
else{
if(elem->pt2->ConstInt != 0) dir = elem->id->ConstInt;
else{
if(elem->pt2->ConstFloat != 0.0) dirf = elem->id->ConstFloat;
}
}

if(cod == ADD){
if(esq != 0 && dir != 0) resultado = esq + dir;
}
*/
