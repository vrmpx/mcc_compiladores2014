/*
 * file:  dpp.l
 * ------------
 * Lex inupt file to generate the scanner for the preprocessor.
 * If you decide to use lex for the preprocesor, put your rules
 * here, otherwise the file can remain empty.
 */

%{
 	
int n_def = 0; //numero de define
char defined[50][50]; //arreglo de definiciones
char subs[50][50]; //arreglo de substituciones

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
<SUB>[^\n]*    {
	strcpy(subs[n_def], ++yytext);
	// printf("(%s) --> (%s)", defined[n_def], subs[n_def]);
	n_def++;
	BEGIN(0);
}
"#"[A-Z]+    {
	yytext++; //eliminamos el #
	// printf("2SUB::(%s)\n", yytext);
	int i = 0;
	bool found = false;
	while(i < n_def && !found){
		if(strcmp(yytext, defined[i]) == 0){
			found = true;
			
			char* s = (char *)malloc(20);
			strcpy(s,subs[i]);
			for(int z = strlen(s) - 1; z >= 0; z--){
				unput(s[z]);
			}
		}
		i++;
	}
	if(!found){
		printf("%s", yytext);
	}
}
%%