%{
// THIAM - ALMAJJO - DOULKOM
#include "y.tab.h"
%}
%%
[0-9]+ {yylval=atoi(yytext);return NOMBRE;}
[a-z]++ {yylval=yytext;return VARIABLE;}
[ \t] ; /* ignore les blancs et tabulations */
\n return 0;
. return yytext[0];
%%
