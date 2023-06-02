%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.yy.c"

%}

%token SUJET VERBE ADJECTIF ADVERBE
%start phrase
%%
phrase: SUJET VERBE COMPLEMENT  {printf("La phrase est correcte\n"); return;}
; 
COMPLEMENT: ADJECTIF
| ADVERBE
; 
%%


int main(void){
    char sujets[100];
    char verbes[100];
    char adjectifs[100];
    char adverbes[100];

    // Saisie des sujets. Le dernier sujet doit etre suivi d'un espace.
    printf("Saisissez les sujets séparés par des espaces :\n");
    fgets(sujets, sizeof(sujets), stdin);
    char* sujet = strtok(sujets, " ");
    while (sujet != NULL) {
        insert_mot_categorie(sujet, "sujet");
        sujet = strtok(NULL, " ");
    }


    // Saisie des verbes. Le dernier verbe doit etre suivi d'un espace.
    printf("Saisissez les verbes séparés par des espaces :\n");
    fgets(verbes, sizeof(verbes), stdin);
    char* verbe = strtok(verbes, " ");
    while (verbe != NULL) {
        insert_mot_categorie(verbe, "verbe");
        verbe = strtok(NULL, " ");
    }

    // Saisie des adjectifs. Le dernier adjectif doit etre suivi d'un espace.
    printf("Saisissez les adjectifs séparés par des espaces :\n");
    fgets(adjectifs, sizeof(adjectifs), stdin);
    char* adjectif = strtok(adjectifs, " ");
    while (adjectif != NULL) {
        insert_mot_categorie(adjectif, "adjectif");
        adjectif = strtok(NULL, " ");
    }

    // Saisie des adverbes. Le dernier adverbe doit etre suivi d'un espace.
    printf("Saisissez les adverbes séparés par des espaces :\n");
    fgets(adverbes, sizeof(adverbes), stdin);
    char* adverbe = strtok(adverbes, " ");
    while (adverbe != NULL) {
        insert_mot_categorie(adverbe, "adverbe");
        adverbe = strtok(NULL, " ");
    }


    printf("phrase :");
    yyparse();
}
int yyerror(char *s){     
    printf("expression invalide\n");   
}
