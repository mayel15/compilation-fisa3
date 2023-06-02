%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*struct {
  int val; // valeur 
  Liste* suiv; // pointeur 
} liste;

typedef struct maillon
{
  int data;
  struct maillon* next;
}maillon;*/

// Définition de la structure de la liste chaînée
typedef struct mot_categorie {
    char mot[50];
    char categorie[50];
    struct mot_categorie *suivant;
} MotCategorie;


%}
. | 
\n ; 
%%

/*liste * insertion(liste* L, int a){
    Liste * nouv = (liste *)malloc(sizeof(liste));
    nouv->val = a;
    nouv->suiv = L;
    return nouv;
}

maillon* creeMaillon(int n)
{
  maillon* l;
  l = (maillon*)malloc(sizeof(maillon));
  if(l == NULL) exit(0);
  l->data = n;
  l->next = NULL;
  return l;

}*/



// Fonction d'insertion d'un mot et de sa catégorie dans la liste chaînée
void inserer_mot_categorie(MotCategorie **debut, char mot[], char categorie[]) {
    MotCategorie *nouveau_mot = malloc(sizeof(MotCategorie));
    strcpy(nouveau_mot->mot, mot);
    strcpy(nouveau_mot->categorie, categorie);
    nouveau_mot->suivant = NULL;

    if (*debut == NULL) {
        // La liste est vide
        *debut = nouveau_mot;
    } else {
        // On parcourt la liste jusqu'à la fin
        MotCategorie *actuel = *debut;
        while (actuel->suivant != NULL) {
            actuel = actuel->suivant;
        }
        // On ajoute le nouveau mot à la fin de la liste
        actuel->suivant = nouveau_mot;
    }
}

// Fonction de recherche de la catégorie d'un mot dans la liste chaînée
char* rechercher_categorie_mot(MotCategorie *debut, char mot[]) {
    MotCategorie *actuel = debut;
    while (actuel != NULL) {
        if (strcmp(actuel->mot, mot) == 0) {
            // On a trouvé le mot dans la liste
            return actuel->categorie;
        }
        actuel = actuel->suivant;
    }
    // Le mot n'a pas été trouvé dans la liste
    return "inconnu";
}

// Fonction main
int main() {
    MotCategorie *debut = NULL;

    // Apprentissage des mots et de leurs catégories
    inserer_mot_categorie(&debut, "je", "sujet");
    inserer_mot_categorie(&debut, "tu", "sujet");
    inserer_mot_categorie(&debut, "il", "sujet");
    inserer_mot_categorie(&debut, "cours", "verbe");
    inserer_mot_categorie(&debut, "suis", "verbe");
    inserer_mot_categorie(&debut, "marche", "verbe");
    inserer_mot_categorie(&debut, "rapide", "adjectif");
    inserer_mot_categorie(&debut, "grand", "adjectif");
    inserer_mot_categorie(&debut, "petit", "adjectif");

    // Test d'analyse de la phrase "je cours vite"
    char phrase[] = "je cours vite";
    char *mot;
    char categorie[50];
    mot = strtok(phrase, " ");
    while (mot != NULL) {
        strcpy(categorie, rechercher_categorie_mot(debut, mot));
        printf("%s : %s\n", mot, categorie);
        mot = strtok(NULL, " ");
    }

    return 0;
}


