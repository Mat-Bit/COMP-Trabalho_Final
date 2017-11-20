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

    int elem = strcmp(lista->id, no->valor);
    if(elem == 0){
        printf("Símbolo %s já existe\n", lista->id);
        exit(-1);
    }

    //printf("lista[id]: %s , no[valor]: %s\n", lista->id, no->valor);
    //printf("elem = %d\n\n", elem);

    if(elem > 0 && no->direita == NULL){
        no->direita = criaNo(lista, posicao);
        return;
    }
    if(elem < 0 && no->esquerda == NULL){
        no->esquerda = criaNo(lista, posicao);
        return;
    }
    if(elem < 0){
        insereArvoreInterna(no->esquerda, lista, posicao);
    }
    else {
        insereArvoreInterna(no->direita, lista, posicao);
    }
}

tNo * criaNo(tLista *lista, int num){
    tNo *elem = (tNo*)malloc(sizeof(tNo));

    elem->tipo = lista->tipo;
    elem->valor = malloc(sizeof(char)*100);
    strcpy(elem->valor,lista->id);

    elem->valor[99] = '\0';
    elem->num = num;
    elem->atrib = NATRIBUIDO;
    elem->direita = NULL;
    elem->esquerda = NULL;
    return elem;
}

void printArvoreInicio(tArvore *arv){
    tNo *elem = (tNo*)malloc(sizeof(tNo));
    elem = arv->raiz;
    printArvore(elem, 0);
    printf("\n");
}

void printArvore(tNo *elem, int nivel){

    if(elem == NULL) return;
    printNos(elem, nivel);
    printf("\n");
    printArvore(elem->esquerda, nivel+1);
    printArvore(elem->direita, nivel+1);
}

void printNos(tNo *no, int nivel){
    int j;

    if(no == NULL) return;
    //if(no->tipo == T_INT) printf("int ");
    //if(no->tipo == T_FLOAT) printf("float ");
    //if(no->tipo == T_STRING) printf("String ");

    for(j=0;j<nivel;j++){ printf("\t");}
    printf("%s(%d,%d)", no->valor, no->num, nivel);
}

void insereListaNaArvore(tLista *lista, tArvore *arv){
    if(lista == NULL) return;

    insereArvore(arv, lista);
    insereListaNaArvore(lista->proximo, arv);
}

tNo *busca(tNo *arvore, char *id){
    int comp;
    //printf("Valor no: %s, id pra conferir: %s\n", arvore->valor, id);
    if (arvore == NULL)
        return NULL;

        comp = strcmp(arvore->valor, id);

    if (comp == 0){
        //printf("Achooou\n");
        return arvore;
    }
    if (comp > 0)
        return busca(arvore->esquerda, id);
    else
        return busca(arvore->direita, id);
}


tAST *criar_ast_id(tArvore *tabSimb, char *id){
    tAST *ast = (tAST*)malloc(sizeof(tAST));
    tNo *aux = (tNo*)malloc(sizeof(tNo));
    tNo *no = (tNo*)malloc(sizeof(tNo));

    no = tabSimb->raiz;

    aux = busca(no, id);

    if(aux == NULL){
        // o ID nao está na tabelaSimbolos, ou seja é um ID invalido
        printf("A variavel %s nao eh valida\n", id);
        exit(-1);
    }else{
        // se o id informado for um id válido (dentro da tabelaSimbolos)

        // Se o id for uma String:
        if(aux->tipo == T_STRING){
          printf("%s nao pode estar numa Op. Aritimetica pois eh uma String\n", aux->valor);
          exit(-1);
        }

        ast->id = aux->valor;
        ast->ConstInt = 0;
        ast->ConstFloat = 0.0;
        ast->pt1 = NULL;
        ast->pt2 = NULL;
        ast->cod = IDD;
        return ast;
    }
}

tAST *criar_ast_int(int valor_int){
    tAST *elem = (tAST*)malloc(sizeof(tAST));
    elem->ConstInt = valor_int;
    elem->ConstFloat = 0.0;
    elem->id = "NULL";
    elem->pt1 = NULL;
    elem->pt2 = NULL;
    elem->cod = CONSTI;
    return elem;
}

tAST *criar_ast_float(float valor_float){
    tAST *elem = (tAST*)malloc(sizeof(tAST));
    elem->ConstFloat = valor_float;
    elem->ConstInt = 0;
    elem->id = "NULL";
    elem->pt1 = NULL;
    elem->pt2 = NULL;
    elem->cod = CONSTF;
    return elem;
}

tAST *criaAst_ExpArit(tAST *exp_esq, tAST *exp_dir, int cod){
    int comp;
    tAST *elem = (tAST*)malloc(sizeof(tAST));

    elem->pt1 = exp_esq;
    elem->pt2 = exp_dir;

    elem->id = "NULL";
    elem->cod = cod;

    comp = strcmp(exp_esq->id, "NULL");
    if (comp != 0) elem->pt1->id = exp_esq->id;
    else{
        if(exp_esq->ConstInt != 0) elem->pt1->ConstInt = exp_esq->ConstInt;
        if(exp_esq->ConstFloat != 0.0) elem->pt1->ConstFloat = exp_esq->ConstFloat;
    }
    comp = strcmp(exp_dir->id, "NULL");
    if (comp != 0) elem->pt2->id = exp_dir->id;
    else{
        if(exp_dir->ConstInt != 0) elem->pt2->ConstInt = exp_dir->ConstInt;
        if(exp_dir->ConstFloat != 0.0) elem->pt2->ConstFloat = exp_dir->ConstFloat;
    }

    return elem;
}

void printa_arv_exp(tAST *cabeca){

    if(cabeca->cod != 0){
        switch (cabeca->cod) {
            case IDD:
                printf("%s", cabeca->id);
                break;
            case CONSTI:
                printf("%d", cabeca->ConstInt);
                break;
            case CONSTF:
                printf("%.1f", cabeca->ConstFloat);
                break;
            case ADD:
                //printf("Simbolo raiz: +\n");
                printf("(");
                printa_arv_exp(cabeca->pt1);
                printa_arv_exp(cabeca->pt2);
                printf("+) ");
                break;
            case SUB:
                //printf("Simbolo raiz: -\n");
                printf("(");
                printa_arv_exp(cabeca->pt1);
                printa_arv_exp(cabeca->pt2);
                printf("-) ");
                break;
            case MUL:
                //printf("Simbolo raiz: *\n");
                printf("(");
                printa_arv_exp(cabeca->pt1);
                printa_arv_exp(cabeca->pt2);
                printf("*) ");
                break;
            case DIV:
                //printf("Simbolo raiz: /\n");
                printf("(");
                printa_arv_exp(cabeca->pt1);
                printa_arv_exp(cabeca->pt2);
                printf("/) ");
                break;
        }
    }
}

tAST *criaCmdAtrib(tArvore *tabSimb, tAST *cabeca, char *id){
    tAST *ast = (tAST*)malloc(sizeof(tAST));
    tNo *aux = (tNo*)malloc(sizeof(tNo));
    tNo *no = (tNo*)malloc(sizeof(tNo));

    no = tabSimb->raiz;

    aux = busca(no, id);

    if(aux == NULL){
        // o ID nao está na tabelaSimbolos, ou seja é um ID invalido
        printf("A variavel %s nao eh valida\n", id);
        exit(-1);
    }else{
        // se o id informado for um id válido (dentro da tabelaSimbolos)
        ast->id = aux->valor; // que eh = ao id passado como parametro
        ast->ConstInt = 0;
        ast->ConstFloat = 0.0;
        ast->pt1 = cabeca;
        ast->pt2 = NULL;
        ast->cod = ATR;
        printf("%s = ", ast->id);
        printa_arv_exp(cabeca);

        return ast;
    }
}

tAST *criaAst_ExpRelac(tAST *exp_esq, tAST *exp_dir, int cod){
    tAST *elem = (tAST*)malloc(sizeof(tAST));

    elem->pt1 = exp_esq;
    elem->pt2 = exp_dir;
    elem->cod = cod;

    switch (cod) {
        case DIF:
            //TODO DIF
            break;
        case IGUAL:
            //TODO IGUAL
            break;
        /*
        ...
        */
    }
}

tAST *insereListaComando(tAST *listaCmd, tAST *comando){
    tAST *ast = (tAST*)malloc(sizeof(tAST));

    if (listaCmd->cod == ATR && comando->cod == ATR){
        ast->pt1 = listaCmd;
        ast->pt2 = comando;
        ast->cod = ATR;
    }
    return ast;
}

void printa_op_code(tAST *cabeca, tArvore *tabelaSimbolos){
  tNo *aux = (tNo*)malloc(sizeof(tNo));
  tNo *no = (tNo*)malloc(sizeof(tNo));


  if(cabeca->cod != 0){
      switch (cabeca->cod) {
          case ATR:
              no = tabelaSimbolos->raiz;
              aux = busca(no, cabeca->id);
              if(aux == NULL){
                  // o ID nao está na tabelaSimbolos, ou seja é um ID invalido
                  printf("A variavel %s nao eh valida\n", cabeca->id);
                  exit(-1);
              }else{
                  // se o id informado for um id válido (dentro da tabelaSimbolos)
                  printf("istore %d\n", aux->num);
                  break;
              }
          case CONSTI:
              if(cabeca->ConstInt <= 5){
                printf("iconst_%d\n", cabeca->ConstInt);
              }
              else{
                printf("bipush %d\n", cabeca->ConstInt);
              }
              break;
          case CONSTF:
              if(cabeca->ConstFloat <= 5.00){
                printf("fconst_%f\n", cabeca->ConstFloat);
              }
              else{
                  printf("bipush %f\n", cabeca->ConstFloat);
              }
              break;
          case ADD:
              //printf("Simbolo raiz: +\n");
              printf("(");
              printa_arv_exp(cabeca->pt1);
              printa_arv_exp(cabeca->pt2);
              printf("+) ");
              break;
          case SUB:
              //printf("Simbolo raiz: -\n");
              printf("(");
              printa_arv_exp(cabeca->pt1);
              printa_arv_exp(cabeca->pt2);
              printf("-) ");
              break;
          case MUL:
              //printf("Simbolo raiz: *\n");
              printf("(");
              printa_arv_exp(cabeca->pt1);
              printa_arv_exp(cabeca->pt2);
              printf("*) ");
              break;
          case DIV:
              //printf("Simbolo raiz: /\n");
              printf("(");
              printa_arv_exp(cabeca->pt1);
              printa_arv_exp(cabeca->pt2);
              printf("/) ");
              break;
      }
  }
}
