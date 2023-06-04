// THIAM - ALMAJJO - DOULKOM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int posSource=0; 

char source[100] ;

// Grammaire 
// E -> T+E | T-E | T | V 
// T -> F*T | F/T | F
// F -> (E) | CHIFFRE | VAR
// V -> VAR=E  
// CHIFFRE -> [0-9]++
// VAR -> [a-z.A-Z]++ 

// A tester : ((2+4*5)+4)

// on incremente pas quand c'est un non terminal 
// des qu'on compare la posSource on incremente

// structure 
typedef struct valeur {
    int estVrai;
    int valeur;
} res;


res E();
res T();
res F();
res CHIFFRE();
res VAR();
res V();

// regle : E -> T+E | T-E | T
res E()
{
    int posLocal = posSource;
    res c, t, e; 
    t = T();

    // cas de l'addition 
    if(t.estVrai)
    {
        if(source[posSource]=='+')
        {
            posSource += 1;
            e = E();
            if(e.estVrai)
            {
                c.estVrai = 1;
                c.valeur = t.valeur + e.valeur;
                return c;   
            }
        }       
    }

    posSource = posLocal;
    t = T();
    
    // cas de la soustraction 
    if(t.estVrai)
    {  
        posSource += 1 ;
        if(source[posSource]=='-')
        {
            posSource += 1;
            e = E();
            if(e.estVrai)
            {
                c.estVrai = 1;
                c.valeur = t.valeur - e.valeur;
                return c;   
            }
        }       
    }

    posSource = posLocal;
    t = T();
    if(t.estVrai)
    {
        c.estVrai = 1;
        c.valeur = t.valeur;
        return c;
    }
    c.estVrai = 0;
    return c; 

    posSource = posLocal;
    res v = V();
    printf("ok");
    if(v.estVrai)
    {
        c.estVrai = 1;
        c.valeur = v.valeur;
        return c;
    }
    printf("ok");
    c.estVrai = 0;
    return c; 
}


// regle: T -> F*T | F/T | F
res T()
{
    int posLocal = posSource;
    res c, f, t;
    f = F();
    
    // cas de la multiplication
    if(f.estVrai)
    {
        
        if(source[posSource]=='*')
        {
            posSource += 1;
            t = T();
            if(t.estVrai)
            {
                c.estVrai = 1;
                c.valeur = f.valeur * t.valeur;
                return c;   
            }
        }       
    }

    posSource = posLocal; 
    f =  F();

    // cas de la division, c'est une divion entiere car ça prend car la valuer est un int
    if(f.estVrai)
    {
        
        if(source[posSource]=='/')
        {
            posSource += 1;
            t = T();
            if(t.estVrai)
            {
                c.estVrai = 1;
                c.valeur = f.valeur / t.valeur;
                return c;   
            }
        }       
    }

    posSource = posLocal; 
    f =  F();

    if(f.estVrai)
    {
        c.estVrai = 1;
        c.valeur = f.valeur;
        return c;
    }
    c.estVrai = 0;
    return c;
}

// regle: F -> (E) | CHIFFRE | VAR
res F()
{
    int posLocal = posSource;
    res c, e; 
    if(source[posSource]=='(')
    {
        posSource += 1;
        e = E();
        if(e.estVrai)
        {
            if(source[posSource]==')')
            {
                posSource += 1;
                c.estVrai = 1;
                c.valeur = e.valeur;
                return c;   
            }
        }       
    }

    posSource = posLocal;

    res C = CHIFFRE();
    if(C.estVrai)
    {
        c.estVrai = 1;
        c.valeur = C.valeur;
        return c;
    }
    c.estVrai = 0;
    return c; 

    posSource = posLocal;
    res v = VAR();
    if(v.estVrai)
    {
        c.estVrai = 1;
        c.valeur = v.valeur;
        return c;
    }
    c.estVrai = 0;
    return c; 
}


// regle: VAR -> [a-z.A-Z]++
res VAR() {
    res c;
    c.estVrai = 0;
    c.valeur = 0;
    
    int posLoc = posSource; 
    
    // recupere un lettre ou une suite de lettres
    while (isalpha(source[posSource])) {
        posSource++;
        c.estVrai = 1;
    }
    
    
    if (!c.estVrai) {
        posSource = posLoc; 
    }
    
    return c;
}

// regle: V -> VAR=CHIFFRE; pour l'affectation 
res V(){
    int posLocal = posSource;
    res c, v, e; 
    v = VAR();
    // cas de l'addition 
    if(v.estVrai)
    {
        if(source[posSource]=='=')
        {
            posSource += 1;
            e = E();
            if(e.estVrai)
            {
                c.estVrai = 1;
                c.valeur = e.valeur;
                return c;   
            }
        }       
    }
    c.estVrai = 0;
    return c;
}

// nouvelle version de chiffre 
// regle: CHIFFRE -> [0-9]++
res CHIFFRE() {
    res c;
    c.estVrai = 0;
    c.valeur = 0;
    
    int posLoc = posSource; 
    
    // recupere un chiffre ou une suite de chiffre
    while (isdigit(source[posSource])) {
        c.valeur = c.valeur * 10 + (source[posSource] - '0');
        posSource++;
        c.estVrai = 1;
    }
    
    
    if (!c.estVrai) {
        posSource = posLoc; 
    }
    
    return c;
}

int main()
{
    // pour faire le test d'une version, il faut commenter l'un et decommenter l'autre
    
    // version 1&2: test pour analyse syntaxique et evaluation
    source[0] = '(';
    source[1] = '(';
    source[2] = '2';
    source[3] = '+';
    source[4] = '4';
    source[5] = '*';
    source[6] = '5';
    source[7] = ')';
    source[8] = '+';
    source[9] = '2';
    source[10] = '1';
    source[11] = ')';

    // pour tester les expression arithmetiques, on appelle l'axiome E
    res e = E();
    if(e.estVrai)
    {
        printf("expression correcte\n");
        printf("resultat = %d \n", e.valeur);
    }
    else
    {
        printf("expression incorrecte\n");
    }

    
    
    // version 3: test de l'affectation avec des variables
    /*source[0] = 'x';
    source[1] = '=';
    source[2] = '5';
    source[3] = '+';
    source[4] = '(';
    source[5] = '3';
    source[6] = '*';
    source[7] = '5';
    source[8] = ')';
    
    // pour tester l'affectation, on utilise V
    res v = V();
    if(v.estVrai)
    {
        printf("expression correcte\n");
        printf("variable = %d \n", v.valeur);
    }
    else
    {
        printf("expression incorrecte\n");
    }*/

}