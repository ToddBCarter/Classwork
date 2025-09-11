include "stdio.h"

int main(void)
{
	int a, b, c, d, e;
	int Att[6];
	a = 0;
	printf ("Roll for stats!");
	scanf("%i", b);
	for(a = 0; a <= 6; a++){		
		Att[a] = ((rand() % 6 + 2) + (rand() % 6 + 2) + (rand() % 6 + 2));
		printf("\nStr = %i\nDex = %i\nCon = %i\nInt = %i\nWis = %i\nCha = %i", Att[a]); 
	}		
	return(0);
}