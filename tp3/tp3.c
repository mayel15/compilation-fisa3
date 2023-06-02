#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int posSource=0; 

char source[100] ;
// A -> B+C | B
// B -> 4 
// C -> 3


// E -> T+E | T
// T -> F*T | E
// F -> (E) | CHIFFRE   
// CHIFFRE -> 1 | 2 | 3 | 4 | 6 | 8 | 9

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

res E()
{
    int poslLocal = posSource;
    res c;
    if(T().estVrai)
    {

        calcul += T().valeur;
        
        posSource += 1;
        
        if(source[posSource]=='+')
        {
            posSource += 1;
            if(E().estVrai)
            {
                c.estVrai = 1;
                c.valeur = E().valeur;
                calcul += E().valeur;
                return c;   
            }
        }       
    }

    posSource = poslLocal;

    if(T().estVrai)
    {
        c.estVrai = 1;
        c.valeur = T().valeur;
        calcul += T().valeur;
        return c;
    }
    c.estVrai = 0;
    return c; 
}

res T()
{
    int poslLocal = posSource;
    res c;
    if(F().estVrai)
    {

        calcul += F().valeur;
        
        posSource += 1;
        
        if(source[posSource]=='*')
        {
            posSource += 1;
            if(T().estVrai)
            {
                c.estVrai = 1;
                c.valeur = T().valeur;
                calcul *= T().valeur;
                return c;   
            }
        }       
    }

    posSource = poslLocal;

    if(E().estVrai)
    {
        c.estVrai = 1;
        c.valeur = E().valeur;
        calcul += E().valeur;
        return c;
    }
    c.estVrai = 0;
    return c; 
}

res F()
{
    int poslLocal = posSource;
    res c;
    if(source[posSource]=='(')
    {

        calcul += T().valeur;
        
        posSource += 1;
        
        if(E().estVrai)
        {
            posSource += 1;
            if(source[posSource]==')')
            {
                c.estVrai = 1;
                c.valeur = atoi(&source[posSource]);
                return c;   
            }
        }       
    }

    posSource = poslLocal;

    if(T().estVrai)
    {
        c.estVrai = 1;
        c.valeur = T().valeur;
        calcul += T().valeur;
        return c;
    }
    c.estVrai = 0;
    return c; 
}

res CHIFFRE()
{
    res c; 
    if(source[posSource]=='0')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        return c;
    }
    if(source[posSource]=='1')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        return c;
    }
    if(source[posSource]=='2')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        return c;
    }
    if(source[posSource]=='3')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        return c;
    }
    if(source[posSource]=='4')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        return c;
    }
    if(source[posSource]=='5')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        return c;
    }
    if(source[posSource]=='6')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        return c;
    }
    if(source[posSource]=='7')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        return c;
    }
    if(source[posSource]=='8')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        return c;
    }
    if(source[posSource]=='9')
    {
        c.estVrai = 1;
        c.valeur = atoi(&source[posSource]);
        return c;
    }
    c.estVrai = 0;
    c.valeur = atoi(&source[posSource]);
    return c;
}

int main()
{
    source[0] = '4';
    source[1] = '+';
    source[2] = '3';
    source[3] = '*';
    source[4] = '5';

    if(E().estVrai)
    {
        printf("expression correcte\n");
        printf("%d \n", calcul);
    }
    else
    {
        printf("expression incorrecte\n");
    } 

}