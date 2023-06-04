%{
// THIAM - ALMAJJO - DOULKOM 
// version apprentissage avec liste chainée
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

typedef struct node {
    char mot[50];
    char categorie[50];
    struct node* suivant;
} ListNode;

ListNode* liste = NULL;

void insert_mot_categorie(const char* mot, const char* categorie) {
    ListNode* node = malloc(sizeof(ListNode));
    strcpy(node->mot, mot);
    strcpy(node->categorie, categorie);
    node->suivant = liste;
    liste = node;
}

const char *recherche_categorie(const char* mot) {
    ListNode* current = liste;
    while (current != NULL) {
        if (strcmp(current->mot, mot) == 0) {
            return current->categorie;
        }
        current = current->suivant;
    }
    return "Inconnu";
}

%}

%%
[A-Z.a-z]++ {  
    yylval = *recherche_categorie(yytext);  
    printf("%s : %s\n", yytext, recherche_categorie(yytext));
    if(strcmp(recherche_categorie(yytext), "sujet") == 0) return SUJET; 
    if(strcmp(recherche_categorie(yytext), "verbe") == 0) return VERBE; 
    else return ADJECTIF;
}
. |
\n ; 
%%
