%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int yylex();
void yyerror(char *msg);
%}

%union{
   float f;
}

%token <f> NUM
%type <f> P E X T F


%%

S : P         {printf("%f\n", $1);}
  ;

P : E '#' P   {$$ = $1 + $3 + 1; printf("%f # %f\n", $1, $3);}
  | E         {$$ = $1; printf("%f\n", $1);}
  ;

E : E '+' X   {$$ = $1 + $3; printf("%f + %f\n", $1, $3);}
  | E '-' X   {$$ = $1 - $3; printf("%f - %f\n", $1, $3);}
  | X         {$$ = $1; printf("%f\n", $1);}
  ;

X : X '<' T   {$$ = powf($1, $3); printf("%f < %f\n", $1, $3);}
  | T         {$$ = $1; printf("%f\n", $1);}
  ;

T : T '*' F   {$$ = $1 * $3; printf("%f * %f\n", $1, $3);}
  | T '/' F   {$$ = $1 / $3; printf("%f / %f\n", $1, $3);}
  | F         {$$ = $1; printf("%f\n", $1);}
  ;

F : '(' P ')' {$$ = $2; printf("(%f)\n", $2);}
  | '-' F     {$$ = -$2; printf("-%f\n", $2);}
  | NUM       {$$ = $1; printf("%f\n", $1);}
  ;

%%

void yyerror(char *msg)
{
   fprintf(stderr, "%s\n", msg);
   exit(1);
}

int main()
{
   yyparse();
   return 0;
}