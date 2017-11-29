#include <stdio.h>
#include "eda.h"
extern FILE *yyin;
extern tArvore *tabelaSimbolos;
extern FILE *arq_saida;

int main(int c, char *argv[])
{
	FILE *file;
	file = fopen (argv[1], "r");
	arq_saida = fopen("opcodes", "w");
	if ( file == NULL){
		printf("Arquivo \"%s\" não econtrado.\n", argv[1] );
		return 1;
	}
	tabelaSimbolos = criarArvore();
	yyin = file;
	yyparse();
	printf("\n");
	printArvoreInicio(tabelaSimbolos);
	fclose(arq_saida);
	return 0;
}
