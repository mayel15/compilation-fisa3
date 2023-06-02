%{
// THIAM - ALMAJJO - DOULKOM
%}
%% 
cours | 
parle | 
marche | 
pete | 
gagne |
cree | 
detecte | 
joue | 
tire | 
lance printf("%s : verbe \n", yytext);
[a-z.A-Z]++ printf("%s : non verbe \n", yytext);
. | 
\n ; 
%%

int main(){
    // pour le fichier contenant l'entrée
    FILE * f = fopen("fichier.txt", "r") ;
    yyin = f ;
    yylex();
    fclose(f);
    return 0;
}
