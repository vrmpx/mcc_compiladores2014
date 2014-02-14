/*
 * file:  dpp.l
 * ------------
 * Lex inupt file to generate the scanner for the preprocessor.
 * If you decide to use lex for the preprocesor, put your rules
 * here, otherwise the file can remain empty.
 */

%{
#include <string.h>
#include "scanner.h"
#include "utility.h" // for PrintDebug()
#include "errors.h"

/* Global variable: yylval
 * -----------------------
 * This global variable is how we get attribute information about the token
 * just scanned to the client. The scanner sets the global variable
 * appropriately and since it's global the client can just read it.  In the
 * future, this variable will be declared for us in the y.tab.c file
 * produced by Yacc, but for now, we declare it manually.
 */
YYSTYPE yylval;  // manually declared for pp1, later Yacc provides

/* Global variable: yylloc
 * -----------------------
 * This global variable is how we get position information about the token
 * just scanned to the client. (Operates similarly to yylval above)
 */
struct yyltype yylloc; // manually dclared for pp1, later Yacc provides

int n_def = 0; //numero de define
char defined[50][50]; //arreglo de definiciones
char subs[50][50]; //arreglo de substituciones
int linea = 1;
int first_col = 1;
int last_col = 1;

static void DoBeforeEachAction(); 
#define YY_USER_ACTION DoBeforeEachAction();

%}

%x DEFINE 
%x SUB

%%
 /* DEFINE MACROS */
"#define "    {
	BEGIN(DEFINE);
}
<DEFINE>[A-Z]+    {
	strcpy(defined[n_def], yytext);
	BEGIN(SUB);
}
<DEFINE>[^A-Z]+"\n"    {
	ReportError::InvalidDirective(linea);
}
<SUB>[^"\n"]*    {
	strcpy(subs[n_def], ++yytext);
	// printf("(%s) --> (%s)", defined[n_def], subs[n_def]);
	n_def++;
	linea++;
	BEGIN(0);
}
"#"[A-Z]+    {
	yytext++; //eliminamos el #
	//printf("2SUB::(%s)\n", yytext);
	int i = n_def - 1;
	bool found = false;
	while(i >= 0 && !found){
		if(strcmp(yytext, defined[i]) == 0){
			found = true;			
		}else{
			i--;	
		}
	}

	if(found){
		char* s = (char *)malloc(50);
		strcpy(s,subs[i]);
		for(int z = strlen(s) - 1; z >= 0; z--){
			unput(s[z]);
		}	
	}else{
		ReportError::InvalidDirective(linea);
	}
}
 /* Cada nueva linea incrementa el contador y resetea las columnas */
<*>[\n]    {
	linea++;
	printf("\n");
}

%%
/* Function: DoBeforeEachAction()
 * ------------------------------
 * This function is installed as the YY_USER_ACTION. This is a place
 * to group code common to all actions.
 */
static void DoBeforeEachAction(){
	first_col = last_col;
	last_col += strlen(yytext);

	yylloc.first_line = linea;
	yylloc.first_column = first_col;
	yylloc.last_column = last_col - 1;
}