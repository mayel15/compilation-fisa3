%{
// THIAM - ALMAJJO - DOULKOM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
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
lance {printf("%s : verbe \n", yytext); return verbe;}
je |
tu |
il |
elle {printf("%s : sujet \n", yytext); return sujet;};
grand |
petit |
geant |
rapide {printf("%s : adjectif \n", yytext); return adjectif;}
tellement |
enormement |
trop |
rapidement {printf("%s : adverbe \n", yytext); return adverbe;}
[a-z.A-Z]++ {printf("%s : inconnu \n", yytext);}
. | 
\n ; 
%%

