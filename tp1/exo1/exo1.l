%{
// THIAM - ALMAJJO - DOULKOM
#define MAX 30
int T[MAX]; // on déclare un tableau de MAX
%}
%% 
[a-zA-Z]+ T[yyleng]++; //yyleng : longueur du mot courant
. | 
\n ;
%%
int yywrap()
{ 
    printf("Longueur des mots\n");
    for(int i=0; i <MAX ;i++){ 
        if(T[i]>=1){
            printf(" %d mots de longueur %d\n",T[i],i);
        } 
    } 
    fclose(yyin);
    return 0;
}

int main(){
    // pour le fichier contenant l'entrée
    FILE * f = fopen("fichier.txt", "r") ;
    yyin = f ;
    yylex();
    return 0;
}

