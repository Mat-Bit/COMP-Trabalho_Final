#include "eda.h"
extern FILE *yyin;
extern tArvore *tabelaSimbolos;
extern FILE *arq_saida;
extern tAST *raiz;

int main(int c, char *argv[])
{
	FILE *file;
	file = fopen (argv[1], "r");
	char arq_sem_ext[100];
	arq_saida = fopen("opcodes", "w");
	if ( file == NULL){
		printf("Arquivo \"%s\" não econtrado.\n", argv[1] );
		return 1;
	}
	retiraExtensao(argv[1], &arq_sem_ext);

	fprintf(arq_saida, ".class public %s\n", arq_sem_ext);
	fprintf(arq_saida, ".super java/lang/Object\n\n");
	fprintf(arq_saida, ".method public <init>()V\n");
	fprintf(arq_saida, "\taload_0\n\n");
	fprintf(arq_saida, "\tinvokenonvirtual java/lang/Object/<init>()V\n");
	fprintf(arq_saida, "\treturn\n");
	fprintf(arq_saida, ".end method\n\n");
	fprintf(arq_saida, ".method public static main([Ljava/lang/String;)V\n");

	tabelaSimbolos = criarArvore();
	yyin = file;
	yyparse();

	fprintf(arq_saida, "\t.limit stack 10\n");
	fprintf(arq_saida, "\t.limit locals %d\n", (tabelaSimbolos->qtd + 1));

	printa_op_code(raiz, tabelaSimbolos, arq_saida);
	fprintf(arq_saida, "\treturn\n");
	fprintf(arq_saida, ".end method\n");

	printf("\n");
	printArvoreInicio(tabelaSimbolos);
	fclose(arq_saida);
	return 0;
}
