%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.yy.c"
%}
%token NOMBRE
%%
calcul: expression {printf("%d\n",$1);}
;
expression: expression '+' terme {$$ = $1 + $3;}
| expression '-' terme {$$ = $1 - $3;}
| terme {$$ = $1;}
;
terme: terme '*' facteur {$$ = $1 * $3;}
| terme '/' facteur {$$ = $1 / $3;}
| facteur {$$ = $1;}
;
facteur: '(' expression ')' {$$ = $2;}
| '-' facteur {$$ = -$2;}
| NOMBRE {$$ = $1;}
;
%%
int main(void){
    printf("phrase :");
    yyparse();
}
int yyerror(char *s){     
    printf("expression invalide");   
}

