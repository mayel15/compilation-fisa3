%{
// THIAM - ALMAJJO - DOULKOM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

const char* recherche_categorie(const char* mot) {
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
[A-Z.a-z]++ { printf("%s : %s\n", yytext, recherche_categorie(yytext));}
. |
\n ; 
%%

int main() {
    char sujets[100];
    char verbes[100];
    char complements[100];

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

    // Saisie des complements. Le dernier complement doit etre suivi d'un espace.
    printf("Saisissez les compléments séparés par des espaces :\n");
    fgets(complements, sizeof(complements), stdin);
    char* complement = strtok(complements, " ");
    while (complement != NULL) {
        insert_mot_categorie(complement, "complement");
        complement = strtok(NULL, " ");
    }

    yylex();
    return 0;
}