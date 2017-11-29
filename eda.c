#include "eda.h"

int conta_label = 0;

tLista *criarLista (char *id){
    tLista *elem = (tLista*)malloc(sizeof(tLista));
    if (elem != NULL){
        memcpy(elem->id, id, MAXID);
        elem->proximo = NULL;
    }
    return elem;
}

void insereTipo(tLista *head, TIPO tipo){
    while (head != NULL){
        head->tipo = tipo;
        head = head->proximo;
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
    int tipo;
    tipo = lista->tipo;
    if(arv->raiz == NULL){
        arv->qtd++;
        arv->raiz = criaNo(lista, arv->qtd, tipo);
        return;
    }
    else{
        arv->qtd++;
        insereArvoreInterna(arv->raiz, lista, arv->qtd, tipo);
        return;
    }
}

void insereArvoreInterna(tNo *no, tLista *lista, int posicao, TIPO tipo){

    int elem = strcmp(lista->id, no->valor);
    if(elem == 0){
        printf("Símbolo %s já existe\n", lista->id);
        exit(-1);
    }

    //printf("lista[id]: %s , no[valor]: %s\n", lista->id, no->valor);
    //printf("elem = %d\n\n", elem);

    if(elem > 0 && no->direita == NULL){
        no->direita = criaNo(lista, posicao, tipo);
        return;
    }
    if(elem < 0 && no->esquerda == NULL){
        no->esquerda = criaNo(lista, posicao, tipo);
        return;
    }
    if(elem < 0){
        insereArvoreInterna(no->esquerda, lista, posicao, tipo);
    }
    else {
        insereArvoreInterna(no->direita, lista, posicao, tipo);
    }
}

tNo * criaNo(tLista *lista, int posicao, TIPO tipo){
    tNo *elem = (tNo*)malloc(sizeof(tNo));

    elem->valor = malloc(sizeof(char)*100);
    strcpy(elem->valor,lista->id);
    elem->valor[99] = '\0';

    elem->tipo = tipo;
    elem->pos = posicao;
    elem->atrib = NATRIBUIDO;
    elem->direita = NULL;
    elem->esquerda = NULL;
    return elem;
}

void printArvoreInicio(tArvore *arv){
    tNo *elem = (tNo*)malloc(sizeof(tNo));
    elem = arv->raiz;
    printArvore(elem, 1);
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

    for(j=1;j<nivel;j++){ printf("\t");}
    printf("%s(%d,%.1f)", no->valor, no->pos, no->atrib);
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
        printf("A variavel %s nao foi declarada\n", id);
        exit(-1);
    }
    else{
        // se o id informado for um id válido (dentro da tabelaSimbolos)

        ast->id = aux->valor;
        ast->ConstInt = 0;
        ast->ConstFloat = 0.0;
        ast->pt1 = NULL;
        ast->pt2 = NULL;
        ast->cod = IDD;
        ast->tipo = aux->tipo;
        ast->atrib = aux->atrib;

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
    elem->tipo = T_INT;
    elem->atrib = valor_int;
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
    elem->tipo = T_FLOAT;
    elem->atrib = valor_float;
    return elem;
}

tAST *criaAst_ExpArit(tAST *exp_esq, tAST *exp_dir, int cod){
    float resultado1, resultado2, aux;
    int comp;
    tAST *elem = (tAST*)malloc(sizeof(tAST));
    tAST *conv = (tAST*)malloc(sizeof(tAST));

    elem->id = "NULL";
    elem->cod = cod;

    elem->pt1 = exp_esq;

    //Definindo o tipo:
    if(exp_esq->tipo == T_STRING || exp_dir->tipo == T_STRING){
        printf("Um dos valores eh do tipo string, logo nao eh possivel a Op. Arit.\n");
        exit(-1);
    }
    else {
        if (exp_esq->tipo != exp_dir->tipo){
            if(exp_esq->tipo == T_FLOAT){
                conv = i2f(exp_dir);
                elem->pt2 = conv;
                elem->tipo = T_FLOAT;
            }
            else{
                conv = f2i(exp_dir);
                elem->pt2 = conv;
                elem->tipo = T_INT;
            }
        }
        else{
            elem->tipo = exp_esq->tipo;
            elem->pt2 = exp_dir;
        }
    }

    switch (cod) {
        case ADD:
            aux = elem->pt1->atrib + elem->pt2->atrib;
            break;
        case SUB:
            aux = elem->pt1->atrib - elem->pt2->atrib;
            break;
        case MUL:
            aux = elem->pt1->atrib * elem->pt2->atrib;
            break;
        case DIV:
            aux = elem->pt1->atrib / elem->pt2->atrib;
            break;
    }
    elem->atrib = aux;

    return elem;
}

void printa_arv_exp(tAST *cabeca){

    if(cabeca->cod != 0 && cabeca != NULL){
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
                printa_arv_exp(cabeca->pt1);
                printa_arv_exp(cabeca->pt2);
                printf("+");
                break;
            case SUB:
                printa_arv_exp(cabeca->pt1);
                printa_arv_exp(cabeca->pt2);
                printf("-");
                break;
            case MUL:
                printa_arv_exp(cabeca->pt1);
                printa_arv_exp(cabeca->pt2);
                printf("*");
                break;
            case DIV:
                printa_arv_exp(cabeca->pt1);
                printa_arv_exp(cabeca->pt2);
                printf("/");
                break;
            case I2F:
                printa_arv_exp(cabeca->pt1);
                break;
            case F2I:
                printa_arv_exp(cabeca->pt1);
                break;
        }
    }
}

tAST *criaCmdAtrib(tArvore *tabSimb, tAST *cabeca, char *id){
    tAST *ast = (tAST*)malloc(sizeof(tAST));
    tAST *conv = (tAST*)malloc(sizeof(tAST));
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
        ast->pt2 = NULL;
        ast->cod = ATR;
        ast->atrib = cabeca->atrib;
        ast->tipo = aux->tipo;

        if(ast->tipo != cabeca->tipo){
            if(ast->tipo == T_FLOAT){
                conv = i2f(cabeca);
                ast->pt1 = conv;
            }
            else{
                conv = f2i(cabeca);
                ast->pt1 = conv;
            }
        }
        else ast->pt1 = cabeca;

        aux->atrib = ast->atrib;

        return ast;
    }
}

tAST *criaAst_ExpRelac(tAST *exp_esq, tAST *exp_dir, int cod){
    tAST *elem = (tAST*)malloc(sizeof(tAST));
    tAST *conv = (tAST*)malloc(sizeof(tAST));

    elem->pt1 = exp_esq;
    elem->cod = cod;

    if (exp_esq->tipo != exp_dir->tipo){
        if(exp_esq->tipo == T_FLOAT){
            conv = i2f(exp_dir);
            elem->pt2 = conv;
            elem->tipo = T_FLOAT;
        }
        else{
            conv = f2i(exp_dir);
            elem->pt2 = conv;
            elem->tipo = T_INT;
        }
    }
    else{
        elem->tipo = exp_esq->tipo;
        elem->pt2 = exp_dir;
    }

    switch (cod) {
        case DIF:
            if (exp_esq->atrib != exp_dir->atrib) {elem->id = "TRUE";}
            else {elem->id = "FALSE";}
            break;
        case IGUAL:
            if (exp_esq->atrib == exp_dir->atrib) {elem->id = "TRUE";}
            else {elem->id = "FALSE";}
            break;
        case MENIG:
            if (exp_esq->atrib <= exp_dir->atrib) {elem->id = "TRUE";}
            else {elem->id = "FALSE";}
            break;
        case MENOR:
            if (exp_esq->atrib < exp_dir->atrib) {elem->id = "TRUE";}
            else {elem->id = "FALSE";}
            break;
        case MAIIG:
            if (exp_esq->atrib >= exp_dir->atrib) {elem->id = "TRUE";}
            else {elem->id = "FALSE";}
            break;
        case MAIOR:
            if (exp_esq->atrib > exp_dir->atrib) {elem->id = "TRUE";}
            else {elem->id = "FALSE";}
            break;
    }

    return elem;
}

tAST *criaAst_ExpLog(tAST *exp_esq, tAST *exp_dir, int cod){
    tAST *ast = (tAST*)malloc(sizeof(tAST));
    int laux;

    ast->cod = cod;

    switch (cod) {
        case EEE:
            if(exp_esq->id == "TRUE" && exp_dir->id == "TRUE"){
                ast->id = "TRUE";
            }
            else {ast->id = "FALSE";}
            ast->pt1 = exp_esq;
            ast->pt2 = exp_dir;
            break;
        case OOU:
            if(exp_esq->id == "TRUE" || exp_dir->id == "TRUE"){
                ast->id = "TRUE";
            }
            else {ast->id = "FALSE";}
            ast->pt1 = exp_esq;
            ast->pt2 = exp_dir;
            break;
        case NEG:
            if(exp_esq->id == "TRUE") {ast->id = "FALSE";}
            else {ast->id = "TRUE";}
            ast->pt1 = exp_esq;
            ast->pt2 = exp_dir;
            break;
    }

    return ast;
}

tAST *criaCmdIf(tAST *exp_esq, tAST *exp_dir, int cod){
    tAST *ast = (tAST*)malloc(sizeof(tAST));
    tAST *bloco = (tAST*)malloc(sizeof(tAST));

    ast->cod = cod;
    ast->pt1 = exp_esq;

    bloco->cod = BLC;
    bloco->pt1 = exp_dir;
    bloco->pt2 = NULL;
    ast->pt2 = bloco;

    if (exp_esq->id == "TRUE") {ast->id = "TRUE";}
    else {ast->id = "FALSE";}

    return ast;
}

tAST *criaCmdIfElse(tAST *expr, tAST *p_if, tAST *p_else, int cod){
    tAST *ast = (tAST*)malloc(sizeof(tAST));
    tAST *bloco = (tAST*)malloc(sizeof(tAST));

    ast->cod = cod;
    ast->pt1 = expr;

    bloco->cod = BLC;
    bloco->pt1 = p_if;
    bloco->pt2 = p_else;
    ast->pt2 = bloco;

    if (expr->id == "TRUE") {ast->id = "TRUE";}
    else {ast->id = "FALSE";}

    return ast;
}

tAST *criaCmdWhile(tAST *exp_esq, tAST *exp_dir, int cod){
    tAST *ast = (tAST*)malloc(sizeof(tAST));
    tAST *bloco = (tAST*)malloc(sizeof(tAST));

    ast->cod = cod;
    ast->pt1 = exp_esq;

    bloco->cod = BLC;
    bloco->pt1 = exp_dir;
    bloco->pt2 = NULL;
    ast->pt2 = bloco;

    if (exp_esq->id == "TRUE") {ast->id = "TRUE";}
    else {ast->id = "FALSE";}

    return ast;
}

tAST *criaListaComando(tAST *comando, int cod){
    tAST *ast = (tAST*)malloc(sizeof(tAST));

    ast->cod = cod;
    ast->pt1 = comando;
    return ast;
}

tAST *insereListaComando(tAST *listaCmd, tAST *comando, int cod){
    tAST *ast = (tAST*)malloc(sizeof(tAST));

    ast->cod = cod;
    ast->pt1 = listaCmd;
    ast->pt2 = comando;
    return ast;
}

tAST *i2f(tAST *ptr){
    tAST *ast = (tAST*)malloc(sizeof(tAST));

    ast->cod = I2F;
    ast->pt1 = ptr;
    ast->atrib = ptr->atrib;

    return ast;
}

tAST *f2i(tAST *ptr){
    tAST *ast = (tAST*)malloc(sizeof(tAST));

    ast->cod = F2I;
    ast->pt1 = ptr;
    ast->atrib = ptr->atrib;

    return ast;
}

int geraLabel(){
    return ++conta_label;
}

void printa_op_code(tAST *cabeca, tArvore *tabelaSimbolos, FILE *arq_saida){
    tNo *aux = (tNo*)malloc(sizeof(tNo));
    tNo *no = (tNo*)malloc(sizeof(tNo));
    int cont, laux;

    if(cabeca->cod != 0){
        switch (cabeca->cod) {
            case CMD:
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                break;
            case ATR:
                no = tabelaSimbolos->raiz;
                aux = busca(no, cabeca->id);
                if(aux == NULL){
                    // o ID nao está na tabelaSimbolos, ou seja é um ID invalido
                    printf("A variavel %s nao eh valida\n", cabeca->id);
                    exit(-1);
                }else{
                    // se o id informado for um id válido (dentro da tabelaSimbolos)
                    printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                    fprintf(arq_saida, "istore %d\n", aux->pos);
                    printf("Salva (%s)\n", aux->valor);
                    break;
                }
            case IDD:
                no = tabelaSimbolos->raiz;
                aux = busca(no, cabeca->id);
                if(aux == NULL){
                    // o ID nao está na tabelaSimbolos, ou seja é um ID invalido
                    printf("A variavel %s nao eh valida\n", cabeca->id);
                    exit(-1);
                }else{
                    // se o id informado for um id válido (dentro da tabelaSimbolos)
                    fprintf(arq_saida, "iload %d\n", aux->pos);
                    printf("Carrega (%s)\n", cabeca->id);
                    break;
                }
            case CONSTI:
                if(cabeca->ConstInt <= 5) {fprintf(arq_saida, "iconst_%d\n", cabeca->ConstInt);}
                else {fprintf(arq_saida, "bipush %d\n", cabeca->ConstInt);}
                printf("Le (%d)\n", cabeca->ConstInt);
                break;
            case CONSTF:
                if(cabeca->ConstFloat <= 5.00) {fprintf(arq_saida, "fconst_%.2f\n", cabeca->ConstFloat);}
                else {fprintf(arq_saida, "bipush %.2f\n", cabeca->ConstFloat);}
                printf("Le (%.2f)\n", cabeca->ConstFloat);
                break;
            case ADD:
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                if (cabeca->tipo == T_INT) {fprintf(arq_saida, "iadd\n");}
                if (cabeca->tipo == T_FLOAT) {fprintf(arq_saida, "fadd\n");}
                printf("Op (add)\n");
                break;
            case SUB:
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                if (cabeca->tipo == T_INT) {fprintf(arq_saida, "isub\n");}
                if (cabeca->tipo == T_FLOAT) {fprintf(arq_saida, "fsub\n");}
                printf("Op (sub)\n");
                break;
            case MUL:
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                if (cabeca->tipo == T_INT) {fprintf(arq_saida, "imul\n");}
                if (cabeca->tipo == T_FLOAT) {fprintf(arq_saida, "fmul\n");}
                printf("Op (mul)\n");
                break;
            case DIV:
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                if (cabeca->tipo == T_INT) {fprintf(arq_saida, "idiv\n");}
                if (cabeca->tipo == T_FLOAT) {fprintf(arq_saida, "fdiv\n");}
                printf("Op (div)\n");
                break;
            case I2F:
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                fprintf(arq_saida, "i2f\n");
                printf("Conv (i2f)\n");
                break;
            case F2I:
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                fprintf(arq_saida, "f2i\n");
                printf("Conv (f2i)\n");
                break;
            case DIF:
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                if(cabeca->tipo == T_FLOAT) {fprintf(arq_saida, "if_fcmpne ");}
                if(cabeca->tipo == T_INT) {fprintf(arq_saida, "if_icmpne ");}
                fprintf(arq_saida, "L%d\n", cabeca->lv);
                fprintf(arq_saida, "goto L%d\n", cabeca->lf);
                printf("Rel (!=) \n");
                break;
            case IGUAL:
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                if(cabeca->tipo == T_FLOAT) {fprintf(arq_saida, "if_fcmpeq ");}
                if(cabeca->tipo == T_INT) {fprintf(arq_saida, "if_icmpeq ");}
                fprintf(arq_saida, "L%d\n", cabeca->lv);
                fprintf(arq_saida, "goto L%d\n", cabeca->lf);
                printf("Rel (==) \n");
                break;
            case MENIG:
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                if(cabeca->tipo == T_FLOAT) {fprintf(arq_saida, "if_fcmple ");}
                if(cabeca->tipo == T_INT) {fprintf(arq_saida, "if_icmple ");}
                fprintf(arq_saida, "L%d\n", cabeca->lv);
                fprintf(arq_saida, "goto L%d\n", cabeca->lf);
                printf("Rel (<=) \n");
                break;
            case MENOR:
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                if(cabeca->tipo == T_FLOAT) {fprintf(arq_saida, "if_fcmplt ");}
                if(cabeca->tipo == T_INT) {fprintf(arq_saida, "if_icmplt ");}
                fprintf(arq_saida, "L%d\n", cabeca->lv);
                fprintf(arq_saida, "goto L%d\n", cabeca->lf);
                printf("Rel (<) \n");
                break;
            case MAIIG:
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                if(cabeca->tipo == T_FLOAT) {fprintf(arq_saida, "if_fcmpge ");}
                if(cabeca->tipo == T_INT) {fprintf(arq_saida, "if_icmpge ");}
                fprintf(arq_saida, "L%d\n", cabeca->lv);
                fprintf(arq_saida, "goto L%d\n", cabeca->lf);
                printf("Rel (>=)\n");
                break;
            case MAIOR:
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                if(cabeca->tipo == T_FLOAT) {fprintf(arq_saida, "if_fcmpgt ");}
                if(cabeca->tipo == T_INT) {fprintf(arq_saida, "if_icmpgt ");}
                fprintf(arq_saida, "L%d\n", cabeca->lv);
                fprintf(arq_saida, "goto L%d\n", cabeca->lf);
                printf("Rel (>)\n");
                break;
            case EEE:
                laux = geraLabel();

                cabeca->pt1->lv = laux;
                cabeca->pt1->lf = cabeca->lf;
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);

                fprintf(arq_saida, "L%d:\n", laux);

                cabeca->pt2->lv = cabeca->lv;
                cabeca->pt2->lf = cabeca->lf;
                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                break;
            case OOU:
                laux = geraLabel();

                cabeca->pt1->lv = cabeca->lv;
                cabeca->pt1->lf = laux;
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);

                fprintf(arq_saida, "L%d:\n", laux);

                cabeca->pt2->lv = cabeca->lv;
                cabeca->pt2->lf = cabeca->lf;
                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                break;
            case NEG:
                cabeca->pt1->lv = cabeca->lf;
                cabeca->pt1->lf = cabeca->lv;
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                break;
            case IFF:
                cabeca->lv = geraLabel();
                cabeca->lf = geraLabel();
                cabeca->pt1->lv = cabeca->lv;
                cabeca->pt1->lf = cabeca->lf;

                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                fprintf(arq_saida, "L%d:\n", cabeca->lv);

                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                fprintf(arq_saida, "L%d:\n", cabeca->lf);
                break;
            case IFEL:
                cabeca->lv = geraLabel();
                cabeca->lf = geraLabel();
                cabeca->pt1->lv = cabeca->lv;
                cabeca->pt1->lf = cabeca->lf;

                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                // Bloco if:
                fprintf(arq_saida, "L%d:\n", cabeca->lv);
                printa_op_code(cabeca->pt2->pt1, tabelaSimbolos, arq_saida);

                laux = geraLabel();
                fprintf(arq_saida, "goto L%d\n", laux);
                // Bloco else:
                fprintf(arq_saida, "L%d:\n", cabeca->lf);
                printa_op_code(cabeca->pt2->pt2, tabelaSimbolos, arq_saida);

                fprintf(arq_saida, "L%d:\n", laux);
                break;
            case WLE:
                laux = geraLabel();
                cabeca->lv = geraLabel();
                cabeca->lf = geraLabel();
                fprintf(arq_saida, "L%d:\n", laux);

                cabeca->pt1->lv = cabeca->lv;
                cabeca->pt1->lf = cabeca->lf;

                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                fprintf(arq_saida, "L%d:\n", cabeca->lv);

                printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                fprintf(arq_saida, "goto L%d\n", laux);
                fprintf(arq_saida, "L%d:\", cabeca->lf);

                break;
            case BLC:
                printa_op_code(cabeca->pt1, tabelaSimbolos, arq_saida);
                if (cabeca->pt2 != NULL)
                    printa_op_code(cabeca->pt2, tabelaSimbolos, arq_saida);
                break;
        }
    }
}
