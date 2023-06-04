// THIAM - ALMAJJO - DOULKOM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int posSource=0; 

char source[100] ;
// A -> B+C | B
// B -> 4 
// C -> 3


// E -> T+E | T
// T -> F*T | F
// F -> (E) | CHIFFRE | V 
// V -> VAR=CHIFFRE  

// expression ::= term | expression '+' term | expression '-' term
// term ::= factor | term '*' factor | term '/' factor
// factor ::= number | '(' expression ')'
// number ::= [0-9]+
// variable ::= [a-z.A-Z]++ 
// eprvar ::= variable = CHIFFRE

// CHIFFRE -> 1 | 2 | 3 | 4 | 6 | 8 | 9
// VAR -> [a-z.A-Z]++ 

// A tester : ((2+4*5)+4)

// on incremente pas quand c'est un non terminal 
// des qu'on compare la posSource on incremente

// structure 
typedef struct valeur {
    int estVrai;
    int valeur;
} res;

int calcul = 0;

res E();
res T();
res F();
res CHIFFRE();
res VAR();
res V();

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
}

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

    res v = V();
    if(v.estVrai)
    {
        c.estVrai = 1;
        c.valeur = C.valeur;
        return c;
    }
    c.estVrai = 0;
    return c; 
}

res VAR()
{
    res c; 
    if(source[posSource]=='a')
    {
        c.estVrai = 1;
        //c.valeur = a;
        posSource += 1;
        return c;
    }
    c.estVrai = 0;
    return c;

}

/// pour l'affectation 
res V(){
    int posLocal = posSource;
    res c, v, C; 
    v = VAR();
    // cas de l'addition 
    if(v.estVrai)
    {
        if(source[posSource]=='=')
        {
            posSource += 1;
            C = CHIFFRE();
            if(C.estVrai)
            {
                c.estVrai = 1;
                c.valeur = C.valeur;
                return c;   
            }
        }       
    }
    c.estVrai = 0;
    return c;
}

/*
// ancienne version de chiffre
res CHIFFRE()
{
    res c; 
    if(source[posSource]=='0')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        posSource += 1;
        return c;
    }
    if(source[posSource]=='1')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        posSource += 1;
        return c;
    }
    if(source[posSource]=='2')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        posSource += 1;
        return c;
    }
    if(source[posSource]=='3')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        posSource += 1;
        return c;
    }
    if(source[posSource]=='4')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        posSource += 1;
        return c;
    }
    if(source[posSource]=='5')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        posSource += 1;
        return c;
    }
    if(source[posSource]=='6')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        posSource += 1;
        return c;
    }
    if(source[posSource]=='7')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        posSource += 1;
        return c;
    }
    if(source[posSource]=='8')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        posSource += 1;
        return c;
    }
    if(source[posSource]=='9')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        posSource += 1;
        return c;
    }
    c.estVrai = 0;
    c.valeur = atoi(&source[posSource]);
    return c;
}*/

// nouvelle versin de chiffre 
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
    source[0] = 'a';
    source[1] = '=';
    source[2] = '4';

    /*source[1] = '(';
    source[2] = '2';
    source[3] = '+';
    source[4] = '4';
    source[5] = '*';
    source[6] = '5';
    source[7] = ')';
    source[8] = '+';
    source[9] = '2';
    source[10] = '1';
    source[11] = ')';*/

    //res e = E();
    res v = V();
    if(v.estVrai)
    {
        printf("expression correcte\n");
        printf("resultat = %d \n", v.valeur);
    }
    else
    {
        printf("expression incorrecte\n");
    } 

}