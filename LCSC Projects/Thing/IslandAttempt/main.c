#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int xx, yy, zz;
int globalSec, globalMin, globalHour, globalDay, globalMo, globalYr, season;
int conMod, dexMod, strMod, intMod, wisMod, chaMod;
int ranRaceBonus;
int dragonColor;

globalYr = 306;
globalMo = 5;
globalDay = 12;

char leftArrows[5] = { '>','>','>','>','\0' };
char rightArrows[5] = { '<','<','<','<','\0' };
char menuYes[4] = { 'Y','e','s','\0' };
char menuNo[3] = { 'N','o','\0' };
char thirtyspaces[31] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
char thirteenspaces[14] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
char twelvespaces[14] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
char elevenspaces[12] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
char tenspaces[11] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
char ninespaces[10] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
char eightspaces[9] = { ' ',' ',' ',' ',' ',' ',' ',' ','\0' };
char sevenspaces[8] = { ' ',' ',' ',' ',' ',' ',' ','\0' };
char sixspaces[7] = { ' ',' ',' ',' ',' ',' ','\0' };
char fivespaces[6] = { ' ',' ',' ',' ',' ','\0' };
char fourspaces[5] = { ' ',' ',' ',' ','\0' };
char threespaces[4] = { ' ',' ',' ','\0' };
char twospaces[3] = { ' ',' ','\0' };
char sspace[2] = { ' ','\0' };
char nospace[1] = {'\0' };

int menuArrows (int selection, int minimum, int maximum)
{
	int a, b, mn, mx, sele;
	do
	{
		b = getch();
		sele = selection;
		mn = minimum;
		mx = maximum;
		//printf("\ninner opti is %i\n" , opti);
		//printf("\na is %i\n" , a);
		if (a == 224)
		{
				//printf("\narrow code is %i\n" , a);
			if (b == 80) //arrow down shift+P
			{
				//printf("\ndownarrow code is %i\n" , b);
				//printf("\nopti is %i\n" , opti);
				sele = sele + 1;
				if (sele > mx)
				{
					sele = mn;
				}
				//printf("\nopti is %i\n" , opti);
				return (sele);
			}else if (b == 72) //arrow up shift+H
			{
				//printf("\nuparrow code is %i\n" , b);
				sele = sele - 1;
				if (sele < mn)
				{
					sele = mx;
				}
				return (sele);
			}else if (b == 75) //arrow left shift+K
			{
				//printf("\nleftarrow code is %i\n" , b);
				return (sele);
				 
			}else if (b == 77) //arrow right shit+M
			{
				//printf("\nrightarrow code is %i\n" , b);
				return (sele);
				
			}
		}
		
		if (b == 13)
		{
			//globalSec = globalSec + 3;
			//dateCheck();
			sele = 404;
			dateCheck();
			return (sele);
		}
		a = b;
	}while (b != 13);
		
}

int dateCheck()
{	
	if (globalSec > 59)
	{
		globalMin = globalMin + 1;
		globalSec = 0;
	}
	
	if (globalMin > 59)
	{
		globalHour = globalHour + 1;
		globalMin = 0;
	}
	
	if (globalHour > 23)
	{
		globalDay = globalDay + 1;
		globalHour = 0;
	}
	
	if (globalDay > 29)
	{
		globalMo = globalMo + 1;
		globalDay = 0;
	}
	
	if (globalMo > 11)
	{
		globalYr = globalYr + 1;
		globalMo = 0;
	}	
}

int moveMent (int movement)
{
	int a, b, move;
	do
	{
		b = getch();
		move = movement;
		//printf("\ninner move is %i\n" , move);
		//printf("\na is %i\n" , a);
		if (a == 224)
		{
				//printf("\narrow code is %i\n" , a);
			if (b == 80) //arrow down shift+P
			{
				//printf("\ndownarrow code is %i\n" , b);
				//printf("\nmove is %i\n" , move);
				move = move + 1;
				if (move > 7)
				{
					move = 1;
				}
				//printf("\nmove is %i\n" , move);
				return (move);
			}else if (b == 72) //arrow up shift+H
			{
				//printf("\nuparrow code is %i\n" , b);
				move = move - 1;
				if (move < 1)
				{
					move = 7;
				}
				return (move);
			}else if (b == 75) //arrow left shift+K
			{
				//printf("\nleftarrow code is %i\n" , b);
				return (move);
				 
			}else if (b == 77) //arrow right shit+M
			{
				//printf("\nrightarrow code is %i\n" , b);
				return (move);
				
			}
		}
		
		if (b == 13)
		{
			globalSec = globalSec + 3;
			dateCheck();
			move = 13;
			return (move);
		}
		
		//printf("\nb code is %i\n" , b);		
		
		a = b;
	}while (b != 13);
		
}

int inputName()
{
	int namingArray[50], a, b, c, d, e, f, g;
	char nameArray[255], run, running;
	
	running = 'y';
	run = 'y';
	e = 0;
	
	namingArray[0] = menuYes;
	namingArray[1] = menuNo;
	namingArray[2] = leftArrows;
	namingArray[3] = rightArrows;
	namingArray[4] = fourspaces;
	namingArray[5] = sspace;
	
	FILE*CharacterName;
	
	CharacterName = fopen("CharacterName.txt" , "w");
	
	do
	{
		printf("\nPlease input your name.\n");
		fgets(nameArray, 255, stdin);
		system("cls");
		run = 'y';
		running = 'y';
		
		do
		{
			printf("Your name will be %s\n" , nameArray);
			printf("Do you want to change that?\n");
			for(a = 0; a <= 1; a++)
			{
				b = 4;
				c = 4;
				
				if (e == a)
				{
					d = e;
					b = 2;
					c = 3;
				}
				
				printf("%s %s %s\n" , namingArray[b], namingArray[a], namingArray[c]);
			}
			int mn = 0;
			int mx = 1;
			
			e = menuArrows(e, mn, mx);
			if (e == 404)
			{
				if (d == 0)
				{
					run = 'g';
					running = 'y';
					e = 0;
				}else if (d == 1)
				{
					running = 'g';
					run = 'g';
				}
			}
			system("cls");
			
		}while (run == 'y'); 
		
	}while (running == 'y');	
	
	fprintf(CharacterName , "%s" , nameArray);
	fclose(CharacterName);	
}

int genderRoll(int levelChoice)
{
	int gCho, a, b, c, d, e, f, g, h, i, k, m, mn, mx, M, F, getInp[35], genArr[20], yesNoArr[10];
	char j, userInp[35];
	FILE*CharacterSheet;
	char run = 'y';
	char ynrun = 'y';
	
	char yes[5] = { 'Y','e','s',' ','\0' };
	char no[5] = { 'N','o',' ',' ','\0' };
	char arrowsL[5] = { '<','<','<','<','\0' };
	char arrowsR[5] = { '>','>','>','>','\0' };
	char spaces[5] = { ' ',' ',' ',' ','\0' };
	char male[5] = { 'M','a','l','e','\0' };
	char female[7] = { 'F','e','m','a','l','e','\0' };
	char rndm[7] = { 'R','a','n','d','o','m','\0' };
	
	yesNoArr[1] = yes;
	yesNoArr[2] = no;
	genArr[3] = male;
	genArr[2] = female;
	genArr[1] = rndm;
	
	genArr[5] = arrowsL;
	genArr[6] = arrowsR;
	genArr[7] = spaces;
	
	//gCho = 'q';
	
	e = 1;
	
	do
	{
		system("cls");
		printf("What gender?\n");
		for (a = 1; a <= 3; a++)
		{
			b = 7;
			c = 7;
			if (e == a)
			{
				b = 6;
				c = 5;
				gCho = e;
			}			
			printf(" %s %s %s \n" , genArr[b], genArr[a], genArr[c]);
		}
		mn = 1;
		mx = 3;
		e = menuArrows(e, mn, mx);
		if (e == 404)
		{
			f = 2;
			do
			{
				ynrun = 'y';
				e = 1;
				system("cls");
				if (gCho == 3)
				{
					printf("Your gender will be: %s\n" , genArr[3]);
				}else if (gCho == 2)
				{
					printf("Your gender will be: %s\n" , genArr[2]);
				}else if (gCho == 1)
				{
					do
					{
						gCho = rand()% 3 + 1;
					}while(gCho == 1);
					printf("Your random gender will be: %s\n" , genArr[gCho]);
				}
				printf("\Do you want to change that?\n");
				
				for(a = 1; a <= 2; a++)
				{
					c = 7;
					d = 7;
					if (f == a)
					{
						c = 6;
						d = 5;
						g = f;
					}
					printf("  %s %s %s\n" , genArr[c], yesNoArr[a], genArr[d]);
				}
				
				mn = 1;
				mx = 2;
				f = menuArrows(f, mn, mx);
				system("cls");
				//printf("\nf is %i\n" , f);
				if (f == 404)
				{
					f = 2;
					if (g == 2)
					{
						ynrun = 'g';
						run = 'g';
					}else if (g == 1)
					{
						ynrun = 'g';
						run = 'y';
						e = 1;
					}
				}				
			}while (ynrun == 'y');				
		}		
	}while(run == 'y');
	
	CharacterSheet = fopen("CharacterSheet.txt" , "a");
	gCho = gCho - 1;
	fprintf(CharacterSheet, "%i " , gCho);
	fclose(CharacterSheet);
	
	return(gCho);
}

int ageRoll (int raceRoll)
{
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, mn, mx, aCho, age, rr, scanfRet, getInp[35], ageArr[10];
	char useInp[35], run, ynrun;
	age = 0;
	a = 0;
	rr = raceRoll;
	FILE*CharacterSheet;
	
	char yes[5] = { 'Y','e','s',' ','\0' };
	char no[5] = { 'N','o',' ',' ','\0' };
	char arrowsL[5] = { '<','<','<','<','\0' };
	char arrowsR[5] = { '>','>','>','>','\0' };
	char spaces[5] = { ' ',' ',' ',' ','\0' };
	
	ageArr[1] = yes;
	ageArr[2] = no;
	ageArr[3] = arrowsL;
	ageArr[4] = arrowsR;
	ageArr[5] = spaces;
	
	int aa, bb[10000];
	aa = 0;	
	do
	{
		system("cls");		
		printf("Do you know what age? Enter between 1 and 10,000, or anything else for random!\n");
		run = 'y';
		fgets(getInp, 35, stdin);
		scanfRet = sscanf(getInp, "%i", &aCho);
		//printf("\naCho is: %i\n" , aCho);	
		
			if (scanfRet != 1)
			{
				if (rr == 8 || rr == 40)
				{
					age = rand() % 50 + 10;
					printf("Random age is: %i" , age);
				}else if (rr == 11 || rr == 31 || rr == 29 || rr == 28 || rr == 2 || rr == 12 || rr == 13 || rr == 36 || rr == 37)
				{
					age = rand() % 7000 + 25;
					printf("Random age is: %i" , age);
				}else if (rr == 7 || rr == 35 || rr == 43 || rr == 44 || rr == 22 || rr == 41 || rr == 42 || rr == 39 || rr == 16 || rr == 17 || rr == 18 || rr == 19 || rr == 20 || rr == 23 || rr == 24 || rr == 25 || rr == 26 || rr == 32 || rr == 33 || rr == 6 || rr == 4 || rr == 1 || rr == 10)
				{
					age = rand() % 70 + 15;
					printf("Random age is: %i" , age);
				}else if (rr == 14 || rr == 15 || rr == 21 || rr == 34 || rr == 3 || rr == 5 || rr == 9 || rr == 38 || rr == 45 || rr == 46)
				{
					age = rand() % 600 + 25;
					printf("Random age is: %i" , age);
				}else if (rr == 30 || rr == 27)
				{
					age = rand() % 10000 + 1;
					printf("Random age is: %i" , age);
				}		
			}else if (aCho > 0 && aCho <= 10000)
			{
					age = aCho;
					printf("Age is: %i" , age);
			}else if (aCho < 1 || aCho > 10000)
			{
				if (rr == 8 || rr == 40)
				{
					age = rand() % 50 + 10;
					printf("Random age is: %i" , age);
				}else if (rr == 11 || rr == 31 || rr == 29 || rr == 28 || rr == 2 || rr == 12 || rr == 13 || rr == 36 || rr == 37)
				{
					age = rand() % 7000 + 25;
					printf("Random age is: %i" , age);
				}else if (rr == 7 || rr == 35 || rr == 43 || rr == 44 || rr == 22 || rr == 41 || rr == 42 || rr == 39 || rr == 16 || rr == 17 || rr == 18 || rr == 19 || rr == 20 || rr == 23 || rr == 24 || rr == 25 || rr == 26 || rr == 32 || rr == 33 || rr == 6 || rr == 4 || rr == 1 || rr == 10)
				{
					age = rand() % 70 + 15;
					printf("Random age is: %i" , age);
				}else if (rr == 14 || rr == 15 || rr == 21 || rr == 34 || rr == 3 || rr == 5 || rr == 9 || rr == 38 || rr == 45 || rr == 46)
				{
					age = rand() % 600 + 25;
					printf("Random age is: %i" , age);
				}else if (rr == 30 || rr == 27)
				{
					age = rand() % 10000 + 1;
					printf("Random age is: %i" , age);
				}				
			}
			f = 2;			
			do
			{
				system("cls");
				printf("Your age will be: %i" , age);
				printf("\nDo you want to change your age?\n");
				ynrun = 'y';
				for(a = 1; a <= 2; a++)
				{
					c = 5;
					d = 5;
					if (f == a)
					{
						c = 4;
						d = 3;
						g = f;
					}
					printf("  %s %s %s\n" , ageArr[c], ageArr[a], ageArr[d]);
				}
				
				mn = 1;
				mx = 2;
				f = menuArrows(f, mn, mx);
				//printf("\nf is %i\n" , f);
				//Sleep(4000);
				if (f == 404)
				{					
					if (g == 2)
					{
						ynrun = 'g';
						run = 'g';
					}else if (g == 1)
					{
						ynrun = 'g';
						run = 'y';						
					}
				}				
			}while (ynrun == 'y');		
		
	}while (run == 'y');
	
	CharacterSheet = fopen("CharacterSheet.txt" , "a");
	fprintf(CharacterSheet, "%i " , age);
	fclose(CharacterSheet);	
				
	return (age);
}

int statRoll(int lvl)
{	
	int a, b, c, attRoll[3];
	
	for (a = 0; a <= 2; a++)
	{
		do
		{
			attRoll[a] = rand() % 6 + 1;
		}		
		while (attRoll[a] <= 1 || attRoll[a] >= 7);
	}
	int totalAtt = attRoll[0] + attRoll[1] + attRoll[2];
	//printf("\n\n%i   %i   %i" , attRoll[0] , attRoll[1] , attRoll[2]);	
	return (totalAtt);
}

int HDcalc (int levelChoice, int HD)
{
		int aa, a, ccHD, HPtotal, ls;
		FILE*CharacterSheet;
		ls = levelChoice;
		ccHD = HD;
		
		HPtotal = ccHD + conMod;
		aa = 2;
		for (aa = 2; aa <= ls; aa++)
		{
		a = 0;
		a = rand() % ccHD + 1;
		//printf("\nccHD is %i\n" , ccHD);
		//printf("\na is %i\n" , a);
		HPtotal = HPtotal + a + conMod;
		//printf("\nHPtotal is %i\n" , HPtotal);
		}
	return(HPtotal);
	//printf("\n%iHD -- Current HP: %i\n" , ccHD, HPtotal);
}

int classChoice(int levelChoice)
{
	int a, b, c, d, e, f, g, h, i , j, k, l, m, n, o, p, mn, mx, classRollr, HD, clRo[75], ynArr[10], hp;
	int aa, bb, cc, dd, ee, ff, gg, hh, ii, jj, kk, ll, mm, nn, oo, pp, qq, rr, ss, tt, uu, cr, yn, ny, lvl;
	char getInp[35], useInp[35], q, r, s, t, u, v, w, x, y, z, run, run2;
	
	lvl = levelChoice;

	char barb[25] = { ' ','B','a','r','b','a','r','i','a','n',' ',' ','\0' };
	char bard[25] = { ' ','B','a','r','d',' ',' ',' ',' ',' ',' ',' ','\0' };
	char cler[25] = { ' ','C','l','e','r','i','c',' ',' ',' ',' ',' ','\0' };
	char drui[25] = { ' ','D','r','u','i','d',' ',' ',' ',' ',' ',' ','\0' };
	char figh[25] = { ' ','F','i','g','h','t','e','r',' ',' ',' ',' ','\0' };
	char monk[25] = { ' ','M','o','n','k',' ',' ',' ',' ',' ',' ',' ','\0' };
	char pala[25] = { ' ','P','a','l','a','d','i','n',' ',' ',' ',' ','\0' };
	char rang[25] = { ' ','R','a','n','g','e','r',' ',' ',' ',' ',' ','\0' };
	char rogu[25] = { ' ','R','o','g','u','e',' ',' ',' ',' ',' ',' ','\0' };
	char sorc[25] = { ' ','S','o','r','c','e','r','e','r',' ',' ',' ','\0' };
	char wiza[25] = { ' ','W','i','z','a','r','d',' ',' ',' ',' ',' ','\0' };
	char arca[25] = { ' ','A','r','c','a','n','i','s','t',' ',' ',' ','\0' };
	char bloo[25] = { ' ','B','l','o','o','d','r','a','g','e','r',' ','\0' };
	char braw[25] = { ' ','B','r','a','w','l','e','r',' ',' ',' ',' ',' ',' ','\0' };
	char hunt[25] = { ' ','H','u','n','t','e','r',' ',' ',' ',' ',' ',' ',' ','\0' };
	char inve[25] = { ' ','I','n','v','e','s','t','i','g','a','t','o','r',' ','\0' };
	char sham[25] = { ' ','S','h','a','m','a','n',' ',' ',' ',' ',' ',' ',' ','\0' };
	char skal[25] = { ' ','S','k','a','l','d',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char slay[25] = { ' ','S','l','a','y','e','r',' ',' ',' ',' ',' ',' ',' ','\0' };
	char swas[25] = { ' ','S','w','a','s','h','b','u','c','k','l','e','r',' ','\0' };
	char warp[25] = { ' ','W','a','r','p','r','i','e','s','t',' ',' ',' ',' ','\0' };
	char alch[25] = { ' ','A','l','c','h','e','m','i','s','t',' ',' ',' ',' ','\0' };
	char cava[25] = { ' ','C','a','v','a','l','i','e','r',' ',' ',' ',' ',' ','\0' };
	char inqu[25] = { ' ','I','n','q','u','i','s','i','t','o','r',' ',' ',' ','\0' };
	char orac[25] = { ' ','O','r','a','c','l','e',' ',' ',' ',' ',' ',' ',' ','\0' };
	char summ[25] = { ' ','S','u','m','m','o','n','e','r',' ',' ',' ',' ',' ','\0' };
	char witc[25] = { ' ','W','i','t','c','h',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char rndo[25] = { ' ','R','a','n','d','o','m','i','z','e',' ',' ','\0' };
	
	char arrowsR[5] = { '>','>','>','>','\0' };
	char arrowsL[5] = { '<','<','<','<','\0' };
	char spaces[5] = { ' ',' ',' ',' ','\0' };
	char yes[4] = { 'Y','e','s','\0' };
	char no[3] = { 'N','o','\0' };
	
	ynArr[1] = yes;
	ynArr[2] = no;
	
	clRo[0] = rndo;
	clRo[1] = barb;
	clRo[2] = bard;
	clRo[3] = cler;
	clRo[4] = drui;
	clRo[5] = figh;
	clRo[6] = monk;
	clRo[7] = pala;
	clRo[8] = rang;
	clRo[9] = rogu;
	clRo[10] = sorc;
	clRo[11] = wiza;
	clRo[12] = arca;
	clRo[13] = bloo;
	clRo[14] = braw;
	clRo[15] = hunt;
	clRo[16] = inve;
	clRo[17] = sham;
	clRo[18] = skal;
	clRo[19] = slay;
	clRo[20] = swas;
	clRo[21] = warp;
	clRo[22] = alch;
	clRo[23] = cava;
	clRo[24] = inqu;
	clRo[25] = orac;
	clRo[26] = summ;
	clRo[27] = witc;
	//clRo[28] = rndo;
	
	clRo[29] = arrowsL;
	clRo[30] = spaces;
	clRo[31] = arrowsR;
	
	HD = 0;	
	//d = levelChoice;
	FILE*CharacterSheet;
	
	run = 'y';
	//cr = 28;
	g = 0;
	
	do
	{
		system("cls");
		run2 = 'y';
		printf("*  What class do you want to be?                      *\n");
		printf("*                                                     *\n");
		
		for (a = 0; a <= 13; a++)
		{
			b = 30;
			c = 30;
			d = 30;
			e = 30;
			f = a + 14;
			if(g == a)
			{
				b = 31;
				c = 29;
				cr = g;
			}else if(g == f)
			{
				d = 31;
				e = 29;
				cr = g;
			}
			printf("*   %s%s%s" , clRo[b], clRo[a], clRo[c]);
			printf("     %s%s%s   *\n" , clRo[d], clRo[f], clRo[e]);
		}
		printf("*                                                     *\n");
		printf("*******************************************************\n");
		mn = 0;
		mx = 27;
		g = menuArrows(g, mn, mx);
		if (g == 404)
		{
			h = 2;
			do
			{
				run2 = 'y';
				system("cls");
				if (cr > 0)
				{
					printf("Your class will be: %s\n" , clRo[cr]);
				}else if (cr == 0)
				{
					cr = rand()% 27 + 1;
					printf("Your random class will be: %s\n" , clRo[cr]);
				}				
				printf("Do you want to choose a different class?\n");
				for (a = 1; a <= 2; a++)
				{
					b = 30;
					c = 30;
					
					if(h == a)
					{
						b = 31;
						c = 29;
						g = h;
					}
					printf("   %s %s %s\n" , clRo[b], ynArr[a], clRo[c]);
					//printf("   %s%s%s\n" , clRo[d], ynArr[2], clRo[e]);
				}
				mn = 1;
				mx = 2;
				h = menuArrows(h, mn, mx);
				if (h == 404)
				{
					if (g == 1)
					{
						run = 'y';
						run2 = 'g';
						g = 0;
					}else if (g == 2)
					{
						run = 'g';
						run2 = 'g';
												
						if (cr == 1)
						{						
							HD = 12;
						}else if (cr == 2)
						{
							HD = 8;
						}else if (cr == 3)
						{
							HD = 8;						
						}else if (cr == 4)
						{
							HD = 8;
						}else if (cr == 5)
						{
							HD = 10;
						}else if (cr == 6)
						{
							HD = 8;
						}else if (cr == 7)
						{
							HD = 10;
						}else if (cr == 8)
						{
							HD = 10;
						}else if (cr == 9)
						{
							HD = 8;
						}else if (cr == 10)
						{
							HD = 6;
						}else if (cr == 11)
						{
							HD = 6;
						}else if (cr == 12)
						{
							HD = 6;
						}else if (cr == 13)
						{
							HD = 10;
						}else if (cr == 14)
						{
							HD = 10;
						}else if (cr == 15)
						{
							HD = 8;
						}else if (cr == 16)
						{
							HD = 8;
						}else if (cr == 17)
						{
							HD = 8;
						}else if (cr == 18)
						{
							HD = 8;
						}else if (cr == 19)
						{
							HD = 10;
						}else if (cr == 20)
						{
							HD = 10;
						}else if (cr == 21)
						{
							HD = 8;
						}else if (cr == 22)
						{
							HD = 8;
						}else if (cr == 23)
						{
							HD = 10;
						}else if (cr == 24)
						{
							HD = 8;
						}else if (cr == 25)
						{
							HD = 8;
						}else if (cr == 26)
						{
							HD = 8;
						}else if (cr == 27)
						{
							HD = 6;
						}					
						hp = HDcalc(lvl, HD);						
					}					
				}				
			}while(run2 == 'y');
		}
	}while(run == 'y');
	CharacterSheet = fopen("CharacterSheet.txt" , "a");
	fprintf(CharacterSheet, "%i %i %i " , HD, hp, cr);
	fclose(CharacterSheet);
	
	return(cr);
}

int raceMenu (int ee)
{
	int a, b, c, d, e, f;
	int opti[2];
	
	do
	{
		b = getch();
		//opti[0] = aa;
		f = ee;
		//printf("\ninner opti is %i\n" , opti);
		//printf("\na is %i\n" , a);
		if (a == 224)
		{
				//printf("\narrow code is %i\n" , a);
			if (b == 80) //arrow down shift+P
			{
				//printf("\ndownarrow code is %i\n" , b);
				//printf("\nopti is %i\n" , opti);
				f = f + 1;
				if (f > 48)
				{
					f = 1;
					//opti[0] = opti[0] + 1;
				}
				return(f);
			}else if (b == 72) //arrow up shift+H
			{
				//printf("\nuparrow code is %i\n" , b);
				f = f - 1;
				if (f < 1)
				{
					f = 48;
				}				
				return(f);
			}else if (b == 75) //arrow left shift+K
			{
				
				c = 47 - f;
				f = f - 15;
				if (f < 0)
				{
					f = c;
				}
				//printf("\nleftarrow code is %i\n" , b);
				return (f);
				 
			}else if (b == 77) //arrow right shit+M
			{
				c = 47 - f;
				f = f + 15;
				if (f > 47)
				{
					f = c;
				}
				//printf("\nrightarrow code is %i\n" , b);
				return (f);
				
			}
		}
		//printf("\nb code is %i\n" , b);
		//Sleep(500);
		if (b == 13)
		{
			//globalSec = globalSec + 3;
			//dateCheck();
			e = 404;
			return(e);
		}		
		a = b;
	}while (b != 13);
		
}

int racialRoll(int levelChoice)
{
	int raceRoll, dragonColor, hybridColor, a, b, c, d, e, f, g, h, i, k, l, m, n, o, p, q, r, s, t, u, aa, bb, cc, dd, ee, ff, gg, hh, ii, jj, kk, ll, mm, dddd, ddd;
	char raceAr[35], getInp[35], j, yesNo, tempArr[50]; 
	char colorAr[8];
	int raceArr[75], colorArr[25], mn, mx;
	int v = 1;
	
	e = 0;
	raceRoll = 0;
	dragonColor = rand() % 10 + 1;
	hybridColor = rand() % 10 + 1;
	
	FILE*CharacterSheet;
	
	char run = 'y';
	char runcolor = 'y';
	char yesNoLast = 'y';
	
	char greArr[25] = { ' ','G','r','e','e','n',' ',' ','\0' }; //9
	char redArr[25] = { ' ','R','e','d',' ',' ',' ',' ','\0' };
	char whiArr[25] = { ' ','W','h','i','t','e',' ',' ','\0' };
	char blaArr[25] = { ' ','B','l','a','c','k',' ',' ','\0' };
	char bluArr[25] = { ' ','B','l','u','e',' ',' ',' ','\0' };
	char golArr[25] = { ' ','G','o','l','d',' ',' ',' ','\0' };
	char silArr[25] = { ' ','S','i','l','v','e','r',' ','\0' };
	char braArr[25] = { ' ','B','r','a','s','s',' ',' ','\0' };
	char broArr[25] = { ' ','B','r','o','n','z','e',' ','\0' };
	char copArr[25] = { ' ','C','o','p','p','e','r',' ','\0' };
	char colranArr[25] = { ' ','R','a','n','d','o','m',' ','\0' };
	
	colorArr[0] = colranArr;
	colorArr[1] = blaArr;
	colorArr[2] = bluArr;
	colorArr[3] = greArr;
	colorArr[4] = redArr;
	colorArr[5] = whiArr;
	colorArr[6] = braArr;
	colorArr[7] = broArr;
	colorArr[8] = copArr;
	colorArr[9] = golArr;
	colorArr[10] = silArr;
	
	
	char humArr[25] = { ' ','H','u','m','a','n',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' }; //14
	char elfArr[25] = { ' ','E','l','f',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char dwaArr[25] = { ' ','D','w','a','r','f',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char halArr[25] = { ' ','H','a','l','f','l','i','n','g',' ',' ',' ',' ',' ',' ','\0' };
	char gnoArr[25] = { ' ','G','n','o','m','e',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char horArr[25] = { ' ','H','a','l','f','-','o','r','c',' ',' ',' ',' ',' ',' ','\0' };
	char orcArr[25] = { ' ','O','r','c',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char gobArr[25] = { ' ','G','o','b','l','i','n',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char helArr[25] = { ' ','H','a','l','f','-','e','l','f',' ',' ',' ',' ',' ',' ','\0' };
	char catArr[25] = { ' ','C','a','t','f','o','l','k',' ',' ',' ',' ',' ',' ',' ','\0' };
	char droArr[25] = { ' ','D','r','o','w',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char sylArr[25] = { ' ','S','y','l','p','h',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char tieArr[25] = { ' ','T','i','e','f','l','i','n','g',' ',' ',' ',' ',' ',' ','\0' };
	char undArr[25] = { ' ','U','n','d','i','n','e',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char ifrArr[25] = { ' ','I','f','r','i','t',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char chaArr[25] = { ' ','C','h','a','n','g','e','l','i','n','g',' ',' ',' ',' ','\0' };
	char gilArr[25] = { ' ','G','i','l','l','m','e','n',' ',' ',' ',' ',' ',' ',' ','\0' };
	char kitArr[25] = { ' ','K','i','t','s','u','n','e',' ',' ',' ',' ',' ',' ',' ','\0' };
	char merArr[25] = { ' ','M','e','r','f','o','l','k',' ',' ',' ',' ',' ',' ',' ','\0' };
	char nagArr[25] = { ' ','N','a','g','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char dueArr[25] = { ' ','D','u','e','r','g','a','r',' ',' ',' ',' ',' ',' ',' ','\0' };
	char vanArr[25] = { ' ','V','a','n','a','r','a',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char visArr[25] = { ' ','V','i','s','h','k','a','n','y','a',' ',' ',' ',' ',' ','\0' };
	char wayArr[25] = { ' ','W','a','y','a','n','g',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char equArr[25] = { ' ','E','q','u','i','n','i','s','t','r','i','a','n',' ',' ','\0' };
	char griArr[25] = { ' ','G','r','i','p','p','l','i',' ',' ',' ',' ',' ',' ',' ','\0' };
	char draArr[25] = { ' ','D','r','a','g','o','n',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char naiArr[25] = { ' ','N','a','i','a','d',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char dryArr[25] = { ' ','D','r','y','a','d',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char dhyArr[25] = { ' ','D','r','a','g','o','n',' ','H','y','b','r','i','d',' ','\0' };
	char aqeArr[25] = { ' ','A','q','u','a','t','i','c','-','e','l','f',' ',' ',' ','\0' };
	char aqoArr[25] = { ' ','A','q','u','a','t','i','c','-','o','r','c',' ',' ',' ','\0' };
	char ogrArr[25] = { ' ','O','g','r','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char nogArr[25] = { ' ','N','o','g','a','r','u','s',' ',' ',' ',' ',' ',' ',' ','\0' };
	char oreArr[25] = { ' ','O','r','e','a','d',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char aasArr[25] = { ' ','A','a','s','i','m','a','r',' ',' ',' ',' ',' ',' ',' ','\0' };
	char dhaArr[25] = { ' ','D','h','a','m','p','i','r',' ',' ',' ',' ',' ',' ',' ','\0' };
	char fetArr[25] = { ' ','F','e','t','c','h','l','i','n','g',' ',' ',' ',' ',' ','\0' };
	char hobArr[25] = { ' ','H','o','b','g','o','b','l','i','n',' ',' ',' ',' ',' ','\0' };
	char kobArr[25] = { ' ','K','o','b','o','l','d',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char ratArr[25] = { ' ','R','a','t','f','o','l','k',' ',' ',' ',' ',' ',' ',' ','\0' };
	char tenArr[25] = { ' ','T','e','n','g','u',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char samArr[25] = { ' ','S','a','m','s','a','r','a','n',' ',' ',' ',' ',' ',' ','\0' };
	char stxArr[25] = { ' ','S','t','r','i','x',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char sulArr[25] = { ' ','S','u','l','i',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	char sviArr[25] = { ' ','S','v','i','r','f','n','e','b','l','i','n',' ',' ',' ','\0' };
	//char kreArr[25] = { ' ','K','r','e','n','l','i','t',' ',' ',' ',' ',' ',' ',' ','\0' };
	char mokArr[25] = { ' ','M','o','k','u',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	
	char spacesL[25] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };	
	char arrows[5] = { '<','<','<','<','\0' };	
	
	char yes[4] = { 'Y','e','s','\0' };
	char no[3] = { 'N','o','\0' };
	char randomArr[7] = { 'R','a','n','d','o','m','\0' };
	char arrowsR[5] = { '>','>','>','>','\0' };	
		
	raceArr[1] = humArr;
	raceArr[2] = elfArr;
	raceArr[3] = dwaArr;
	raceArr[4] = halArr;
	raceArr[5] = gnoArr;
	raceArr[6] = horArr;
	raceArr[7] = orcArr;
	raceArr[8] = gobArr;
	raceArr[9] = helArr;
	raceArr[10] = catArr;
	raceArr[11] = droArr;
	raceArr[12] = sylArr;
	raceArr[13] = tieArr;
	raceArr[14] = undArr;
	raceArr[15] = ifrArr;
	raceArr[16] = chaArr;
	raceArr[17] = gilArr;
	raceArr[18] = kitArr;
	raceArr[19] = merArr;
	raceArr[20] = nagArr;
	raceArr[21] = dueArr;
	raceArr[22] = vanArr;
	raceArr[23] = visArr;
	raceArr[24] = wayArr;
	raceArr[25] = equArr;
	raceArr[26] = griArr;	
	raceArr[27] = draArr;
	raceArr[28] = naiArr;
	raceArr[29] = dryArr;
	raceArr[30] = mokArr;
	raceArr[31] = aqeArr;	
	raceArr[32] = aqoArr;
	raceArr[33] = ogrArr;
	raceArr[34] = nogArr;
	raceArr[35] = oreArr;
	raceArr[36] = aasArr;	
	raceArr[37] = dhaArr;
	raceArr[38] = fetArr;
	raceArr[39] = hobArr;
	raceArr[40] = kobArr;
	raceArr[41] = ratArr;
	raceArr[42] = tenArr;
	raceArr[43] = samArr;
	raceArr[44] = stxArr;
	raceArr[45] = sulArr;
	raceArr[46] = sviArr;
	
	raceArr[47] = fourspaces;
	raceArr[48] = dhyArr;
	raceArr[49] = arrows;
	raceArr[50] = sspace;
	raceArr[51] = yes;
	raceArr[52] = no;
	raceArr[53] = randomArr;
	raceArr[54] = arrowsR;
	raceArr[55] = thirtyspaces;	
	
	a = 1;
	//b = 1;
	e = 47;
	g = 1;
			
	do
	{		
		system("cls");
		printf("*******************************************************************************\n"); //80
		printf("*  What race do you want to be?                                               *\n");          
		printf("*                                                                             *\n");
		
		//printf("j begin is %i\n" , j);
		//printf("b for is %i\n" , b);
		//printf("e begin is %i\n" , e);
		
		k = 47;
		kk = 47;
		l = 47;
		ll = 47;
		
		if (e == 47)
		{
			k = 49;
			kk = 54;
			j = e;
		}else if (e == 48)
		{
			l = 49;
			ll = 54;
			j = e;
		}
		
		printf("*                              %s%s%s                                 *\n" , raceArr[kk], raceArr[53], raceArr[k]); //80
		printf("*                         %s%s%s                             *\n" , raceArr[ll], raceArr[48], raceArr[l]);
		
		for (b = 1; b <= 15; b++)
		{			
			
			d = 47;
			c = 47;
			i = 47;
			dd = 47;
			cc = 47;
			ii = 47;
			
			g = b + 15;
			h = b + 30;	

			if (e == b)
			{
				c = 49;
				cc = 54;
				j = e;
			}else if (e == g)
			{				
				d = 49;
				dd = 54;
				j = g;
			}else if (e == h)
			{				
				i = 49;
				ii = 54;
				j = h;
			}
			//printf("a for is %i\n" , a);
			//printf("b for is %i\n" , b);
			//printf("f for is %i\n" , f);
			//printf("c for is %i\n" , c);
			//printf("d for is %i\n" , d);
			printf("*   %s%s%s" , raceArr[cc], raceArr[b], raceArr[c]); //26			
			
			//aa = sizeof(humArr);
			//printf("\naa is %i\n" , aa);
			
			printf(" %s%s%s" , raceArr[dd], raceArr[g], raceArr[d]); //23			
			
			printf(" %s%s%s   *\n" , raceArr[ii], raceArr[h], raceArr[i]); //27   //80
			//printf("*  %s %i %s %s  *\n" , skillNamArr[2][b], skillArrT[2][b], skillNamArr[d][19]);
			//printf("*  %s%i%s%s%i%s  *\n" , skillNamArr[1][a], skillArrT[1][a], skillNamArr[c][19], skillNamArr[2][b], skillArrT[2][b], skillNamArr[d][19]);
		}
		printf("*                                                                             *\n");
		printf("*******************************************************************************\n");
		//printf("\na aft is %i\n" , a);
		//printf("\nf aft is %i\n" , f);
		//mn = 1;
		//mx = 48;
		e = raceMenu(e);
		if (e == 404)
		{
			raceRoll = j;
			yesNo = 'y';
			yesNoLast = 'y';
			
			
				system("cls");
				if (j == 47)
				{
					raceRoll = rand()% 46 + 1;
					//printf("\nYour random race will be: %s\n" , raceArr[raceRoll]);
					j = raceRoll;
					v = 2;
				}else if (j == 48 || j == 27)
				{
					e = 0;									
					do
					{
						
						system("cls");
						runcolor = 'y';
						printf("****************************************************************************\n"); //80
						printf("*  Choose your color.                                                      *\n");
						printf("*                                                                          *\n");
						
						
						
						for (b = 0; b <= 10; b++)
						{							
							d = 47;
							dd = 47;
							if (e == b)
							{
								d = 49;
								dd = 54;
								ee = e;
							}
							//printf("\ne is %i\n" , e);
							printf("*      %s%s%s                                                    *\n" , raceArr[dd], colorArr[b], raceArr[d]);
						}
						mn = 0;
						mx = 10;
						e = menuArrows(e, mn, mx);
						if (e == 404)
						{
							v = 2;
							do
							{
								system("cls");
								dragonColor = ee;
								if(ee == 0)
								{
									dragonColor = rand()% 10 + 1;
									printf("Your random color will be: ");
								}else if (ee != 0)
								{
									printf("Your color will be: ");
								}
								
								if (dragonColor == 1)
								{
									printf("Black.\n");
								}else if (dragonColor == 2)
								{
									printf("Blue.\n");
								}else if (dragonColor == 3)
								{
									printf("Green.\n");
								}else if (dragonColor == 4)
								{
									printf("Red.\n");
								}else if (dragonColor == 5)
								{
									printf("White.\n");
								}else if (dragonColor == 6)
								{
									printf("Brass.\n");
								}else if (dragonColor == 7)
								{
									printf("Bronze.\n");
								}else if (dragonColor == 8)
								{
									printf("Copper.\n");
								}else if (dragonColor == 9)
								{
									printf("Gold.\n");
								}else if (dragonColor == 10)
								{
									printf("Silver.\n");
								}
								
								c = 47;
								d = 47;
								q = 47;
								r = 47;
								
								if (v == 1)
								{
									c = 49;
									q = 54;
									k = 1;
								}else if (v == 2)
								{
									d = 49;
									r = 54;
									k = 2;
								}
								yesNo = 'y';
								printf("Do you want to change your color?\n");
								printf("*   %s %s %s   \n", raceArr[q], raceArr[51], raceArr[c]);
								printf("*   %s %s %s   ", raceArr[r], raceArr[52], raceArr[d]);
								mn = 1;
								mx = 2;
								v = menuArrows(v, mn, mx);								
									
								if (v == 404)
								{
									if (k == 2)
									{
										yesNo = 'g';
										runcolor = 'g';
										e = 1;
										v = 2;
									}else if (k == 1)
									{
										yesNo = 'g';
										runcolor = 'y';
										e = 0;
										v = 2;
									}
								}
							}while (yesNo == 'y');
						
						}
						
					}while(runcolor == 'y');
					system("cls");
					//printf("\nraceroll is %i\n" , raceRoll);
					
					printf("Your race will be: %s%s\n" , colorArr[dragonColor], raceArr[raceRoll]);
					
				}else if (j != 47 && j != 27 && j != 48)
				{
					printf("Your race will be: %s\n" , raceArr[raceRoll]);
					v = 2;
				}
								
				if (raceRoll == 1)
				{				
					ranRaceBonus = rand() % 6 + 1;
				}else if (raceRoll == 6)
				{				
					ranRaceBonus = rand() % 6 + 1;
				}else if (raceRoll == 9)
				{				
					ranRaceBonus = rand() % 6 + 1;
				}
				
				do
				{
					system("cls");
					if (raceRoll == 48 || raceRoll == 27)
					{
						printf("Your race will be: %s%s\n" , colorArr[dragonColor], raceArr[raceRoll]);
					}else if (raceRoll != 48 && raceRoll != 27)
					{
						printf("Your race will be: %s\n" , raceArr[raceRoll]);
					}
					c = 47;
					d = 47;
					q = 47;
					r = 47;
					
					if (v == 1)
					{
						c = 49;
						q = 54;
						k = 1;
					}else if (v == 2)
					{
						d = 49;
						r = 54;
						k = 2;
					}
					
					//printf("\nv is %i\n" , v);
					printf("\nDo you want to change race?\n");
					printf("    %s %s %s   \n", raceArr[q], raceArr[51], raceArr[c]);
					printf("    %s %s %s   ", raceArr[r], raceArr[52], raceArr[d]);
					mn = 1;
					mx = 2;					
					v = menuArrows(v, mn, mx);
					system("cls");
					//printf("\nv is %i\n" , v);					
						
					if (v == 404)
					{
						if (k == 2)
						{
							yesNoLast = 'g';
							run = 'g';
						}else if (k == 1)
						{
							e = 47;
							yesNoLast = 'g';
							run = 'y';
						}
					}
					//printf("\nyesNoLast is %c\n" , yesNoLast);
					//Sleep(2000);
					
				}while (yesNoLast == 'y');
				
		}
	
	}while(run == 'y');
	
	CharacterSheet = fopen("CharacterSheet.txt" , "a");
	fprintf(CharacterSheet, "%i %i %i " , raceRoll, dragonColor, dragonColor);
	fclose(CharacterSheet);
	
	return(raceRoll);
}

int skillAssignments (int levelSelect, int classChoice, int raceRoll)
{
	int userInp[35], skillArrT[50], skillNamArr[70], skillArr[36], aq, uo, rr, w, ls, in, cc, skPts, a, b, c, d, e, m, n, o, p, k, j, g, scanchka, aa, bb, ccc, dd, ee, ff, Acro, Appr, Bluff, Climb, Craft, Dipl, Disa, Disg, Esca, Fly, Hand, Heal, Intim, Ling, Perc, Perf, Prof, Ride, Sens, Slei, Spell, Stea, Surv, Swim, UseM;
	char f, h, i, l, getInp[35], yesNo, run;
	int KnowArc, KnowDun, KnowEng, KnowGeo, KnowHis, KnowLoc, KnowNat, KnowNob, KnowPla, KnowRel, mn, mx;
	
	FILE*CharacterSheet;
	
	aq = 1;
	b = 0;
	
	//g = 'g';
	f = 'g';
	run = 'y';
	yesNo = 'y';
	
	rr = raceRoll;
	cc = classChoice;
	ls = levelSelect;
	in = intMod;
	skPts = 0;
	
	//char acroArr[10], apprArr[8], bluffArr[5], climbArr[5], craftArr[5], diplArr[9], disaArr[14], disgArr[8], escaArr[13], flyArr[3], handArr[13], char healArr[4], intimArr[10];
	//lingArr[10], percArr[10], perfArr[7], profArr[10], rideArr[4], sensArr[30], sleiArr[20], spellArr[20], steaArr[20], survArr[20], swimArr[8], useMArr[20];
	
	char acroArr[25] = { '(','1',')','A','c','r','o','b','a','t','i','c','s','-','-','-','-','-','-','-','-','-','-','-','\0' }; //24
	char apprArr[25] = { '(','2',')','A','p','p','r','a','i','s','e','-','-','-','-','-','-','-','-','-','-','-','-','-','\0' };
	char bluffArr[25] = { '(','3',')','B','l','u','f','f','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','\0' };
	char climbArr[25] = { '(','4',')','C','l','i','m','b','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','\0' };
	char craftArr[25] = { '(','5',')','C','r','a','f','t','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','\0' };
	char diplArr[25] = { '(','6',')','D','i','p','l','o','m','a','c','y','-','-','-','-','-','-','-','-','-','-','-','-','\0' };
	char disaArr[25] = { '(','7',')','D','i','s','a','b','l','e',' ','D','e','v','i','c','e','-','-','-','-','-','-','-','\0' };
	char disgArr[25] = { '(','8',')','D','i','s','g','u','i','s','e','-','-','-','-','-','-','-','-','-','-','-','-','-','\0' };
	char escaArr[25] = { '(','9',')','E','s','c','a','p','e',' ','A','r','t','i','s','t','-','-','-','-','-','-','-','-','\0' };
	char flyArr[25] = { '(','1','0',')','F','l','y','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','\0' };
	char handArr[25] = { '(','1','1',')','H','a','n','d','l','e',' ','A','n','i','m','a','l','-','-','-','-','-','-','-','\0' };
	char healArr[25] = { '(','1','2',')','H','e','a','l','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','\0' };
	char intimArr[25] = { '(','1','3',')','I','n','t','i','m','i','d','a','t','e','-','-','-','-','-','-','-','-','-','-','\0' };
	char knowArcArr[25] = { '(','1','4',')','K','n','o','w','l','e','d','g','e',' ','(','A','r','c','a','n','a',')','-','-','\0' };
	char knowDunArr[25] = { '(','1','5',')','K','n','o','w','l','e','d','g','e',' ','(','D','u','n','g','.',')','-','-','-','\0' };
	char knowEngArr[25] = { '(','1','6',')','K','n','o','w','l','e','d','g','e',' ','(','E','n','g','.',')','-','-','-','-','\0' };
	char knowGeoArr[25] = { '(','1','7',')','K','n','o','w','l','e','d','g','e',' ','(','G','e','o','.',')','-','-','-','-','\0' };
	char knowHisArr[25] = { '(','1','8',')','K','n','o','w','l','e','d','g','e',' ','(','H','i','s','t','.',')','-','-','-','\0' };
	char knowLocArr[25] = { '(','1','9',')','K','n','o','w','l','e','d','g','e',' ','(','L','o','c','a','l',')','-','-','-','\0' };
	char knowNatArr[25] = { '(','2','0',')','K','n','o','w','l','e','d','g','e',' ','(','N','a','t','u','r','e',')','-','-','\0' };
	char knowNobArr[25] = { '(','2','1',')','K','n','o','w','l','e','d','g','e',' ','(','N','o','b','.',')','-','-','-','-','\0' }; 
	char knowPlaArr[25] = { '(','2','2',')','K','n','o','w','l','e','d','g','e',' ','(','P','l','a','n','e','s',')','-','-','\0' };
	char knowRelArr[25] = { '(','2','3',')','K','n','o','w','l','e','d','g','e',' ','(','R','e','l','.',')','-','-','-','-','\0' };
	char lingArr[25] = { '(','2','4',')','L','i','n','g','u','i','s','t','i','c','s','-','-','-','-','-','-','-','-','-','\0' };
	char percArr[25] = { '(','2','5',')','P','e','r','c','e','p','t','i','o','n','-','-','-','-','-','-','-','-','-','-','\0' };
	char perfArr[25] = { '(','2','6',')','P','e','r','f','o','r','m','-','-','-','-','-','-','-','-','-','-','-','-','-','\0' };
	char profArr[25] = { '(','2','7',')','P','r','o','f','e','s','s','i','o','n','-','-','-','-','-','-','-','-','-','-','\0' };
	char rideArr[25] = { '(','2','8',')','R','i','d','e','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','\0' };
	char sensArr[25] = { '(','2','9',')','S','e','n','s','e',' ','M','o','t','i','v','e','-','-','-','-','-','-','-','-','\0' };
	char sleiArr[25] = { '(','3','0',')','S','l','e','i','g','h','t',' ','o','f',' ','H','a','n','d','-','-','-','-','-','\0' };
	char spellArr[25] = { '(','3','1',')','S','p','e','l','l','c','r','a','f','t','-','-','-','-','-','-','-','-','-','-','\0' };
	char steaArr[25] = { '(','3','2',')','S','t','e','a','l','t','h','-','-','-','-','-','-','-','-','-','-','-','-','-','\0' };
	char survArr[25] = { '(','3','3',')','S','u','r','v','i','v','a','l','-','-','-','-','-','-','-','-','-','-','-','-','\0' };
	char swimArr[25] = { '(','3','4',')','S','w','i','m','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','\0' };
	char useMArr[25] = { '(','3','5',')','U','s','e',' ','M','a','g','i','c',' ','D','e','v','i','c','e','-','-','-','-','\0' };
	char rndmArr[25] = { '-','-','-','-','-','-','-','R','a','n','d','o','m','i','z','e','!','-','-','-','-','-','-','-','\0' };
	
	
	char arrows[8] = { '<','<','<','<',' ',' ',' ','\0' };
	char arrowstwo[7] = { '<','<','<','<',' ',' ','\0' };
	char arrowsone[6] = { '<','<','<','<',' ','\0' };
	char arrowsonly[5] = { '<','<','<','<','\0' };
	char yes[4] = { 'Y','e','s','\0' };
	char no[3] = { 'N','o',' ','\0' };
	
	char spacesL[25] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0' };
	
	//printf("\n%s\n" , handArr);
	
	skillNamArr[0] = rndmArr;
	skillNamArr[1] = acroArr;  //importante
	skillNamArr[2] = apprArr;
	skillNamArr[3] = bluffArr;
	skillNamArr[4] = climbArr;
	skillNamArr[5] = craftArr;
	skillNamArr[6] = diplArr;
	skillNamArr[7] = disaArr;
	//printf("\n%s\n" ][skillArr[6]);
	skillNamArr[8] = disgArr;
	skillNamArr[9] = escaArr;
	skillNamArr[10] = flyArr;
	skillNamArr[11] = handArr;
	skillNamArr[12] = healArr;
	skillNamArr[13] = intimArr;
	skillNamArr[14] = knowArcArr;
	skillNamArr[15] = knowDunArr;
	skillNamArr[16] = knowEngArr;
	skillNamArr[17] = knowGeoArr;
	skillNamArr[18] = knowHisArr;
	skillNamArr[19] = knowLocArr;
	skillNamArr[20] = knowNatArr;
	skillNamArr[21] = knowNobArr;
	skillNamArr[22] = knowPlaArr;
	skillNamArr[23] = knowRelArr;
	skillNamArr[24] = lingArr;
	skillNamArr[25] = percArr;
	skillNamArr[26] = perfArr;
	skillNamArr[27] = profArr;
	skillNamArr[28] = rideArr;
	skillNamArr[29] = sensArr;
	skillNamArr[30] = sleiArr;
	skillNamArr[31] = spellArr;
	skillNamArr[32] = steaArr;
	skillNamArr[33] = survArr;
	skillNamArr[34] = swimArr;
	skillNamArr[35] = useMArr;	
	skillNamArr[36] = spacesL;
	
	skillNamArr[37] = fivespaces;
	skillNamArr[38] = arrows;
	skillNamArr[39] = twospaces;
	skillNamArr[40] = yes;
	skillNamArr[41] = no;
	skillNamArr[42] = fourspaces;
	skillNamArr[43] = threespaces;
	skillNamArr[44] = arrowstwo;
	skillNamArr[45] = arrowsone;
	skillNamArr[46] = arrowsonly;
	
	a = 1;
	b = 2;
	
	//printf("\n%s\n" , skillNamArr[1][b]);
	skillArrT[36] = sspace;
	//system("cls");
	
	a = 1;
	//b = 1;
	e = 0;
	g = 1;
	
	//int skMenu[2] = { 0 };
	
	//printf("\na is %i\n" , a);
	//printf("\nf early is %i\n" , f);
	do
	{
		if (cc == 1 || cc == 4 || cc == 6 || cc == 13 || cc == 14 || cc == 17 || cc == 18 || cc == 20 || cc == 22 || cc == 23 || cc == 25)
		{
			skPts = (4 + in) * ls;
		}else if (cc == 2 || cc == 8 || cc == 15 || cc == 16 || cc == 19 || cc == 24)
		{
			skPts = (6 + in) * ls;
		}else if (cc == 3 || cc == 5 || cc == 7 || cc == 10 || cc == 11 || cc == 12 || cc == 21 || cc == 26 || cc == 27)
		{
			skPts = (2 + in) * ls;
		}else if (cc == 9)
		{
			skPts = (8 + in) * ls;
		}
		
		if (rr == 1)
		{
			skPts = skPts + ls;
		}
		
		if (skPts <= 0)
		{
			skPts = 0;
		}
		
		for (p = 0; p <= 35; p++)
		{		
			skillArrT[p] = 0;
		}
		
		do
		{
			system("cls");
			
			printf("********************************************************************************\n"); 
			if (skPts <= 9)
			{
				printf("*  You have %i skill points to allocate:                                        *\n" , skPts); 
			}else if (skPts > 9)
			{
				printf("*  You have %i skill points to allocate:                                       *\n" , skPts);   
			}else if (skPts > 99)
			{
				printf("*  You have %i skill points to allocate:                                      *\n" , skPts);  
			}			   
			printf("*                                                                              *\n"); 
			
			//printf("j begin is %i\n" , j);
			//printf("b for is %i\n" , b);
			//printf("e begin is %i\n" , e);
			for (b = 0; b <= 17; b++)
			{
				h = 0;
				
				c = 37;	
				d = 37;
				
				g = b + 18;
				
				if (skillArrT[b] > 9)
				{
					c = 42;
				}else if (skillArrT[b] > 99)
				{
					c = 43;
				}
				if (skillArrT[g] > 9)
				{
					d = 42;
				}else if (skillArrT[g] > 99)
				{
					d = 43;
				}
				
				if (e == b)
				{
					c = 45;
					j = e;
					if (skillArrT[b] > 9)
					{
						c = 46;
					}
				}else if (e == g)
				{
					d = 45;
					j = g;
					if (skillArrT[g] > 9)
					{
						d = 46;
					}
				} 
				//printf("a for is %i\n" , a);
				//printf("b for is %i\n" , b);
				//printf("f for is %i\n" , f);
				//printf("c for is %i\n" , c);
				//printf("d for is %i\n" , d);
				
				
				printf("*   %s %i %s   *" , skillNamArr[b],  skillArrT[b], skillNamArr[c]);
				
				printf("*   %s %i %s   *\n" , skillNamArr[g], skillArrT[g], skillNamArr[d]);
								
				//printf("*  %s %i %s %s  *\n" , skillNamArr[2][b], skillArrT[2][b], skillNamArr[d][19]);
				//printf("*  %s%i%s%s%i%s  *\n" , skillNamArr[1][a], skillArrT[1][a], skillNamArr[c][19], skillNamArr[2][b], skillArrT[2][b], skillNamArr[d][19]);
			}
			printf("*                                                                              *\n");
			printf("********************************************************************************\n"); 
			printf("Str mod is %i || Dex mod is %i || Int mod is %i || Wis mod is %i || Cha mod is %i\n" , strMod, dexMod, intMod, wisMod, chaMod);
			//printf("\na aft is %i\n" , a);
			//printf("\nf aft is %i\n" , f);
			mn = 0;
			mx = 35;
			e = menuArrows(e, mn, mx);
			if (e == 404)
			{
				if (j == 0)
				{
					int skPts2 = skPts;
					for (a = 1; a <= skPts2; a++)
					{
						k = rand()% 35 + 1;
						skillArrT[k] = skillArrT[k] + 1;
						skPts = skPts - 1;
						//printf("\nskPts is %i\n" , skPts);
						//printf("\nskillArrT is %i\n" , skillArrT[k]);
						//printf("\nk is %i\n" , k);
						//Sleep(1000);
					}
				}else if (j != 0)
				{				
					skillArrT[j] = skillArrT[j] + 1;
					skPts = skPts - 1;
					e = j;					
				}
			}
			system("cls");
			//printf("\nj end is %i\n" , j);
			//printf("\ne end is %i\n" , e);
			//printf("\nskMenu0 for is %i\n" , skMenu[0]);
			//printf("\nskMenu1 for is %i\n" , skMenu[1]);
		}while(skPts > 0);
		
		int v = 2;
		b = 1;		
		
//		yesNo = 'y';
//		v = 1;	
		
		for (b = 1; b <= 18; b++)
		{
			//g = b + 18;
			if (skillArrT[b] > 0)
			{
				if (b == 1) //acro
				{
					if (cc == 1 || cc == 2 || cc == 6 || cc == 9 || cc == 13 || cc == 14 || cc == 16 || cc == 18 || cc == 19 || cc == 20)
					{
						skillArrT[b] = skillArrT[b] + 3;
					}
					if (rr == 4 || rr == 18 || rr == 22)
					{
						skillArrT[b] = skillArrT[b] + 2;
					}
					skillArrT[b] = skillArrT[b] + dexMod;
				}else if (b == 2) //appr
				{
					if (cc == 2 || cc == 3 || cc == 9 || cc == 10 || cc == 11 || cc == 12 || cc == 16 || cc == 18 || cc == 22)
					{
						skillArrT[b] = skillArrT[b] + 3;
					}
					skillArrT[b] = skillArrT[b] + intMod;
				}else if (b == 3) //bluff
				{
					if (cc == 2 || cc == 9 || cc == 10 || cc == 16 || cc == 18 || cc == 19 || cc == 20 || cc == 23 || cc == 24)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					if (rr == 37 || rr == 13)
					{
						skillArrT[b] = skillArrT[b] + 2;
					}
					skillArrT[b] = skillArrT[b] + chaMod;
				}else if (b == 4) //climb
				{
					if (cc == 1 || cc == 2 || cc == 4 || cc == 5 || cc == 6 || cc == 8 || cc == 9 || cc == 14 || cc == 15 || cc == 16 || cc == 18 || cc == 19 || cc == 20 || cc == 21 || cc == 23 || cc == 24)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					if (rr == 4)
					{
						skillArrT[b] = skillArrT[b] + 2;
					}
					skillArrT[b] = skillArrT[b] + strMod;
				}else if (b == 5) //craft
				{				
					skillArrT[b] = skillArrT[b] + 3;
					if (rr == 5 || rr == 41 || rr == 40 || rr == 46)
					{
						skillArrT[b] = skillArrT[b] + 2;
					}
					skillArrT[b] = skillArrT[b] + intMod;
				}else if (b == 6) //diplomacy
				{
					if (cc == 2 || cc == 3|| cc == 7|| cc == 9|| cc == 16|| cc == 17|| cc == 18|| cc == 20|| cc == 21 || cc == 23 || cc == 24 || cc == 25)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					if (rr == 36 || rr == 45)
					{
						skillArrT[b] = skillArrT[b] + 2;
					}
					skillArrT[b] = skillArrT[b] + chaMod;
				}else if (b == 7) //disable
				{
					if (cc == 9 || cc == 16 || cc == 22)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					skillArrT[b] = skillArrT[b] + dexMod;
				}else if (b == 8) //disg
				{
					if (cc == 2 || cc == 9 || cc == 16 || cc == 19 || cc == 24)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					skillArrT[b] = skillArrT[b] + chaMod;
				}else if (b == 9) //esca
				{
					if (cc == 2 || cc == 6 || cc == 9 || cc == 14 || cc == 16 || cc == 18 || cc == 20)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					if (rr == 23)
					{
						skillArrT[b] = skillArrT[b] + 2;
					}
					skillArrT[b] = skillArrT[b] + dexMod;
				}else if (b == 10) //fly
				{
					if (cc == 4 || cc == 19 || cc == 11 || cc == 12 || cc == 17 || cc == 22 || cc == 26 || cc == 27)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					skillArrT[b] = skillArrT[b] + dexMod;
				}else if (b == 11) //hand
				{
					if (cc == 1 || cc == 4 || cc == 5 || cc == 7 || cc == 8 || cc == 13 || cc == 14 || cc == 15 || cc == 17 || cc == 18 || cc == 21 || cc == 23 || cc == 26)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					if (rr == 41)
					{
						skillArrT[b] = skillArrT[b] + 4;
					}else if (rr == 20)
					{
						skillArrT[b] = skillArrT[b] + 2;
					}
					skillArrT[b] = skillArrT[b] + chaMod;
				}else if (b == 12) //heal
				{
					if (cc == 3 || cc == 4 || cc == 7 || cc == 8 || cc == 15 || cc == 16 || cc == 17 || cc == 19 || cc == 21 || cc == 22 || cc == 24 || cc == 25 || cc == 27)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					skillArrT[b] = skillArrT[b] + wisMod;
				}else if (b == 13) //intimidate
				{
					if (cc == 1 || cc == 2 || cc == 5 || cc == 6 || cc == 8 || cc == 9 || cc == 10 || cc == 13 || cc == 14 || cc == 15 || cc == 16 || cc == 19 || cc == 20 || cc == 21 || cc == 23 || cc == 24 || cc == 27)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					if (rr == 6)
					{
						skillArrT[b] = skillArrT[b] + 2;
					}
					skillArrT[b] = skillArrT[b] + chaMod;
				}else if (b == 14) //know arc
				{
					if (cc == 2 || cc == 3 || cc == 10 || cc == 11 || cc == 12 || cc == 13 || cc == 16 || cc == 16 || cc == 22 || cc == 24 || cc == 26 || cc == 27)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					skillArrT[b] = skillArrT[b] + intMod;
				}else if (b == 15) //know dung
				{
					if (cc == 2 || cc == 5 || cc == 8 || cc == 9 || cc == 11 || cc == 12 || cc == 14 || cc == 15 || cc == 16 || cc == 18 || cc == 19 || cc == 24 || cc == 26)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					skillArrT[b] = skillArrT[b] + intMod;
				}else if (b == 16) //know eng
				{
					if (cc == 2 || cc == 5 || cc == 11 || cc == 12 || cc == 16 || cc == 18 || cc == 21)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					skillArrT[b] = skillArrT[b] + intMod;
				}else if (b == 17) //know geo
				{
					if (cc == 2 || cc == 4 || cc == 8 || cc == 11 || cc == 12 || cc == 15 ||cc == 16 || cc == 18 || cc == 19 || cc == 26)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					skillArrT[b] = skillArrT[b] + intMod;
				}else if (b == 18) //knowhis
				{
					if (cc == 2 || cc == 3 || cc == 6 || cc == 11 || cc == 12 ||cc == 16 || cc == 18 || cc == 25 || cc == 26 || cc == 27)
					{
					skillArrT[b] = skillArrT[b] + 3;
					}
					skillArrT[b] = skillArrT[b] + intMod;
				}
			}
		}
		
		g = 19;
		
		for (g = 19; g <= 35; g++)
		{
			if (skillArrT[g] > 0)
			{
				if (g == 19) //knowloc				
				{
					if (cc == 2 || cc == 9 || cc == 11 || cc == 12 || cc == 14 ||cc == 16 || cc == 18 || cc == 19 || cc == 20 || cc == 26)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					skillArrT[g] = skillArrT[g] + intMod;
				}else if (g == 20) //knownat
				{
					if (cc == 1 || cc == 2 || cc == 4 || cc == 8 || cc == 11 ||cc == 12 || cc == 15 || cc == 16 || cc == 17 || cc == 18 || cc == 22 || cc == 24 || cc == 26 || cc == 27)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					skillArrT[g] = skillArrT[g] + intMod;
				}else if (g == 21) //knownob
				{
					if (cc == 2 || cc == 3 || cc == 7 || cc == 11 || cc == 12 ||cc == 16 || cc == 18 || cc == 20 || cc == 26)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					skillArrT[g] = skillArrT[g] + intMod;
				}else if (g == 22) //knowpla
				{
					if (cc == 2 || cc == 3 || cc == 11 || cc == 12 ||cc == 16 || cc == 17 || cc == 18 || cc == 24 || cc == 25 || cc == 26 || cc == 27)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					if (rr == 38)
					{
						skillArrT[g] = skillArrT[g] + 2;
					}
					skillArrT[g] = skillArrT[g] + intMod;
				}else if (g == 23) //knowrel
				{
					if (cc == 2 || cc == 3 || cc == 6 || cc == 7 || cc == 11 || cc == 12 ||cc == 16 || cc == 17 || cc == 18 || cc == 21 || cc == 24 || cc == 25 || cc == 26)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					skillArrT[g] = skillArrT[g] + intMod;
				}else if (g == 24) //ling
				{
					if (cc == 2 || cc == 3 || cc == 9 || cc == 11 || cc == 12 || cc == 16 ||cc == 18 || cc == 26)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					if (rr == 42)
					{
					skillArrT[g] = skillArrT[g] + 4;
					}
					skillArrT[g] = skillArrT[g] + intMod;
				}else if (g == 25) //perception
				{
					if (cc == 1 || cc == 2 || cc == 4 || cc == 6 || cc == 8 || cc == 9 || cc == 13 || cc == 14 || cc == 15 || cc == 16 ||cc == 18 || cc == 19 || cc == 20 || cc == 22 || cc == 24)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					if (rr == 2 || rr == 3 || rr == 5 || rr == 9 || rr == 4 || rr == 36 || rr == 10 || rr == 37 || rr == 11 || rr == 41 || rr == 42 || rr == 40 || rr == 20 || rr == 46 || rr == 24 || rr == 34 || rr == 33)
					{
						skillArrT[g] = skillArrT[g] + 2;
					}
					skillArrT[g] = skillArrT[g] + wisMod;
				}else if (g == 26) //perf
				{
					if (cc == 2 || cc == 6 || cc == 9 || cc == 16 || cc == 18 || cc == 20)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					skillArrT[g] = skillArrT[g] + chaMod;
				}else if (g == 27) //prof
				{
					if (cc != 1)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					skillArrT[g] = skillArrT[g] + wisMod;
				}else if (g == 28) //ride
				{
					if (cc == 1 || cc == 4 || cc == 5 || cc == 6 || cc == 7 || cc == 8 || cc == 13 || cc == 14 || cc == 15 || cc == 17 || cc == 19 || cc == 20 || cc == 21 || cc == 23 || cc == 26)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					if (rr == 8)
					{
						skillArrT[g] = skillArrT[g] + 4;
					}
					skillArrT[g] = skillArrT[g] + dexMod;
				}else if (g == 29) //sens
				{
					if (cc == 2 || cc == 3 || cc == 6 || cc == 9 || cc == 14 || cc == 16 ||cc == 18 || cc == 19 || cc == 20 || cc == 21 || cc == 23 || cc == 24 || cc == 25)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					if (rr == 45)
					{
						skillArrT[g] = skillArrT[g] + 2;
					}
					skillArrT[g] = skillArrT[g] + wisMod;
				}else if (g == 30) //slei
				{
					if (cc == 2 || cc == 9 || cc == 16 || cc == 20 || cc == 22)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					skillArrT[g] = skillArrT[g] + dexMod;
				}else if (g == 31) //spell
				{
					if (cc == 2 || cc == 3 || cc == 4 || cc == 7 || cc == 8 || cc == 10 || cc == 11 || cc == 12 || cc == 13 || cc == 15 || cc == 16 || cc == 17 || cc == 18 || cc == 21 || cc == 22 || cc == 24 || cc == 25 || cc == 26 || cc == 27)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					skillArrT[g] = skillArrT[g] + intMod;
				}else if (g == 32) //stea
				{
					if (cc == 2 || cc == 6 || cc == 8 || cc == 9 || cc == 15 || cc == 16 || cc == 19 || cc == 24)
					{
						skillArrT[g] = skillArrT[g] + 3;
					}else if (rr == 40)
					{
						skillArrT[g] = skillArrT[g] + 3;
					}
					if (rr == 10 || rr == 38 || rr == 42 || rr == 13 || rr == 46 || rr == 22 || rr == 23 || rr == 24)
					{
						skillArrT[g] = skillArrT[g] + 2;
					}else if (rr == 8 || rr == 39)
					{
						skillArrT[g] = skillArrT[g] + 4;
					}
					skillArrT[g] = skillArrT[g] + dexMod;
				}else if (g == 33) //surv
				{
					if (cc == 1 || cc == 4 || cc == 5 || cc == 8 || cc == 13 || cc == 15 || cc == 17 || cc == 19 || cc == 21 || cc == 22 || cc == 24)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					if (rr == 10)
					{
						skillArrT[g] = skillArrT[g] + 2;
					}
					skillArrT[g] = skillArrT[g] + wisMod;
				}else if (g == 34) //swim
				{
					if (cc == 1 || cc == 4 || cc == 5 || cc == 6 || cc == 8 || cc == 9 || cc == 13 || cc == 14 || cc == 15 || cc == 18 || cc == 19 || cc == 20 || cc == 21 || cc == 23 || cc == 24)
					{
						skillArrT[g] = skillArrT[g] + 3;
					}else if (rr == 14 || rr == 17 || rr == 19 || rr == 28 || rr == 31 || rr == 32)
					{
						skillArrT[g] = skillArrT[g] + 3;
					}
					skillArrT[g] = skillArrT[g] + strMod;
				}else if (g == 35)  //usem
				{
					if (cc == 2 || cc == 9 || cc == 10 || cc == 12 || cc == 16 || cc == 18 || cc == 22 || cc == 26 || cc == 27)
					{
					skillArrT[g] = skillArrT[g] + 3;
					}
					if (rr == 41)
					{
						skillArrT[g] = skillArrT[g] + 2;
					}
					skillArrT[g] = skillArrT[g] + chaMod;
				}
			}
			//printf("a for is %i\n" , a);
			//printf("b for is %i\n" , b);
			//printf("f for is %i\n" , f);
			//printf("c for is %i\n" , c);
			//printf("d for is %i\n" , d);
			//printf("g for is %i\n" , g);			
		}
		yesNo = 'y';
		v = 1;
		do
		{
			
			printf("********************************************************************************\n");
			printf("*  After ability and racial bonuses, your skills will be:                      *\n");
			printf("*                                                                              *\n");
			
			for (b = 1; b <= 18; b++)
			{
				g = b + 18;
				
				if (skillArrT[b] < 10)
				{
					printf("*   %s %i %s   *" , skillNamArr[b],  skillArrT[b], skillNamArr[37]);
				}else if (skillArrT[b] < 100)
				{
					printf("*   %s %i %s   *" , skillNamArr[b],  skillArrT[b], skillNamArr[42]);
				}
				
				
				if (g < 36)
				{
					if (skillArrT[g] < 10)
					{
						printf("*   %s %i %s   *\n" , skillNamArr[g], skillArrT[g], skillNamArr[37]);
					}else if (skillArrT[g] < 100)
					{
						printf("*   %s %i %s   *\n" , skillNamArr[g], skillArrT[g], skillNamArr[42]);
					}
				}else if (g == 36)
				{
					printf("*   %s %s %s  *\n" , skillNamArr[g], skillNamArr[39], skillNamArr[37]);
				}
			}			
			
				c = 42;
				d = 42;
			
				if (v == 2)
				{
					c = 46;
					k = 1;
				}else if (v == 1)
				{
					d = 46;
					k = 2;
				}
				printf("*                                                                              *\n");
				printf("********************************************************************************\n");
				printf("Str mod is %i || Dex mod is %i || Int mod is %i || Wis mod is %i || Cha mod is %i\n" , strMod, dexMod, intMod, wisMod, chaMod);
				printf("********************************************************************************\n");
				printf("*   Do you want to re-allocate your points?                                    *\n");
				
				printf("*    %s %s                                                                  *\n" , skillNamArr[40] , skillNamArr[c]);
				printf("*    %s %s                                                                  *\n" , skillNamArr[41] , skillNamArr[d]);
				printf("********************************************************************************\n");
				mn = 1;
				mx = 2;
				v = menuArrows(v, mn, mx);
				
				if (v == 404)
				{
					if (k == 2)
					{
						yesNo = 'g';
						run = 'g';
					}else if (k == 1)
					{
						yesNo = 'g';
						run = 'y';
						v = 2;
						e = 0;
					}
				}
				system("cls");
				
		}while(yesNo == 'y');
		
	}while(run == 'y');
	
	d = 1;
	
	CharacterSheet = fopen("CharacterSheet.txt" , "a");
	for (d = 1; d <= 35; d++)
	{
		//printf("\n%i \n" , skillArr[d]);
		fprintf(CharacterSheet , "%i " , skillArrT[d]);
	}
	fclose(CharacterSheet);	
	
}

int savingThrows (int classChoice, int levelSelect, int raceRoll)
{	
	int fort, refl, will;
	int cc, ls, as, bs, cs, st, rr;
	
	FILE*CharacterSheet;
	
	rr = raceRoll;
	cc = classChoice;
	ls = levelSelect;
	
	as = 2;
	bs = 3;
	
	fort = 0;
	will = 0;
	refl = 0;
	
	CharacterSheet = fopen("CharacterSheet.txt" , "a");
	
	if (rr == 4)
	{
		printf("Halfling Luck!\n+1 to all saves!\n");
		fort = fort + 1;
		refl = refl + 1;
		will = will + 1;
	}
	
	if (cc == 10 || cc == 11 || cc == 12 || cc == 17 || cc == 25 || cc == 26 || cc == 27)
	{
		fort = 0;
		refl = 0;
		will = 2;
		//printf("\nfort is %i" , fort);
		for (as = 2; as <= ls; as += 2)
		{
			will = will + 1;
		}			
		for (bs = 3; bs <= ls; bs += 3)
		{
			fort = fort + 1;
			refl = refl + 1;
		}
		fort = fort + conMod;
		will = will + wisMod;
		refl = refl + dexMod;
		fprintf(CharacterSheet, "%i %i %i " , fort, refl, will);
		st = 1;
	}else if (cc == 9 || cc == 20)
	{
		fort = 0;
		refl = 2;
		will = 0;
		//printf("\nfort is %i" , fort);
		for (as = 2; as <= ls; as += 2)
		{
			refl = refl + 1;				
		}			
		for (bs = 3; bs <= ls; bs += 3)
		{
			will = will + 1;				
			fort = fort + 1;
		}
		fort = fort + conMod;
		will = will + wisMod;
		refl = refl + dexMod;
		fprintf(CharacterSheet, "%i %i %i " , fort, refl, will);
		st = 2;			
	}else if (cc == 2 || cc == 16)
	{
		fort = 0;
		refl = 2;
		will = 2;
		//printf("\nfort is %i" , fort);
		for (as = 2; as <= ls; as += 2)
		{				
			refl = refl + 1;
			will = will + 1;
		}			
		for (bs = 3; bs <= ls; bs += 3)
		{				
			
			fort = fort + 1;
		}
		fort = fort + conMod;
		will = will + wisMod;
		refl = refl + dexMod;
		fprintf(CharacterSheet, "%i %i %i " , fort, refl, will);
		st = 3;
	}else if (cc == 1 || cc == 5 || cc == 13)
	{
		fort = 2;
		refl = 0;
		will = 0;
		//printf("\nfort is %i" , fort);
		for (as = 2; as <= ls; as += 2)
		{				
			fort = fort + 1;
			//printf("\nfort is %i\n" , fort);
			//printf("\nls is %i\n" , ls);
			//printf("\nas is %i\n" , as);
		}			
		for (bs = 3; bs <= ls; bs += 3)
		{				
			refl = refl + 1;				
			will = will + 1;
		}
		fort = fort + conMod;
		will = will + wisMod;
		refl = refl + dexMod;
		fprintf(CharacterSheet, "%i %i %i " , fort, refl, will);
		st = 4;
	}else if (cc == 3 || cc == 4 || cc == 7 || cc == 18 || cc == 21 || cc == 24)
	{
		fort = 2;
		refl = 0;
		will = 2;
		//printf("\nfort is %i" , fort);
		for (as = 2; as <= ls; as += 2)
		{				
			fort = fort + 1;
			will = will + 1;
		}			
		for (bs = 3; bs <= ls; bs += 3)
		{				
			refl = refl + 1;			
		}
		fort = fort + conMod;
		will = will + wisMod;
		refl = refl + dexMod;
		fprintf(CharacterSheet, "%i %i %i " , fort, refl, will);
		st = 5;
	}else if (cc == 8 || cc == 14 || cc == 15 || cc == 19 || cc == 22)
	{
		fort = 2;
		refl = 2;
		will = 0;
		//printf("\nfort is %i" , fort);
		for (as = 2; as <= ls; as += 2)
		{				
			fort = fort + 1;
			refl = refl + 1;
		}			
		for (bs = 3; bs <= ls; bs += 3)
		{				
			will = will + 1;				
		}
		fort = fort + conMod;
		will = will + wisMod;
		refl = refl + dexMod;
		fprintf(CharacterSheet, "%i %i %i " , fort, refl, will);
		st = 6;
	}else if (cc == 6)
	{
		fort = 2;
		refl = 2;
		will = 2;
		//printf("\nfort is %i" , fort);
		for (as = 2; as <= ls; as += 2)
		{				
			fort = fort + 1;
			refl = refl + 1;
			will = will + 1;
		}
		fort = fort + conMod;
		will = will + wisMod;
		refl = refl + dexMod;
		fprintf(CharacterSheet, "%i %i %i " , fort, refl, will);
		st = 7;
	}
	
	fclose(CharacterSheet);
	printf("\nYour saving throws after bonuses are:\nFortitude: %i\nReflex: %i\nWill: %i\n" , fort, refl, will);
	Sleep(750);
}

int baseAtkB (int classChoice, int levelSelect)
{
	int cc, ls, a, b, c, d;
	float bab, bab2, bab3, bab4;
	
	FILE*CharacterSheet;
	
	cc = classChoice;
	ls = levelSelect;
	
	a = 2;
	b = 2;
	c = 2;
	d = 2;	
	
	CharacterSheet = fopen("CharacterSheet.txt" , "a");
	
	if (cc == 1 || cc == 5 || cc == 7 || cc == 8 || cc == 13 || cc == 14 || cc == 19 || cc == 20 || cc == 23)
	{
		bab = 1.0;
		bab2 = 0.0;
		bab3 = 0.0;
		bab4 = 0.0;
		for (a = 2; a <= ls; a++)
		{
			bab = bab + 1;
		}
		printf("\nYour Base Attack Bonus is: %4.0f\n" , bab);
		if (ls > 5)
		{
			bab2 = 1;
			for (b = 7; b <= ls; b++)
			{
				bab2 = bab2 + 1;
			}
			printf("Your second Base Attack Bonus is: %4.0f\n" , bab2);
		}
		
		if (ls > 10)
		{
			bab3 = 1;
			for (c = 12; c <= ls; c++)
			{
				bab3 = bab3 + 1;
			}
			printf("Your third Base Attack Bonus is: %4.0f\n" , bab3);
		}
		
		if (ls > 15)
		{
			bab4 = 1;
			for (d = 17; d <= ls; d++)
			{
				bab4 = bab4 + 1;
			}
			printf("Your fourth Base Attack Bonus is: %4.0f\n" , bab4);
		}
	}else if (cc == 2 || cc == 3 || cc == 4 || cc == 6 || cc == 9 || cc == 15 || cc == 16 || cc == 17 || cc == 18 || cc == 21 || cc == 22 || cc == 24 || cc == 25 || cc == 26 || cc == 27)
	{
		bab = 0.25;
		bab2 = 0.0;
		bab3 = 0.0;
		bab4 = 0.0;
		
		for (a = 2; a <= ls; a++)
		{
			//printf("\nYour nf Base Attack Bonus is: %4.0f\n" , bab);
			bab = bab + 0.75;
		}
		printf("\nYour Base Attack Bonus is: %4.0f\n" , bab);
		if (ls > 7)
		{
			bab2 = 0.5;
			for (b = 9; b <= ls; b++)
			{
				//printf("Your nf second Base Attack Bonus is: %4.0f\n" , bab2);
				bab2 = bab2 + 0.75;
			}
			printf("Your second Base Attack Bonus is: %4.0f\n" , bab2);
		}
		if (ls > 14)
		{
			bab3 = 0.75;
			for (c = 16; c <= ls; c++)
			{
				//printf("Your nf third Base Attack Bonus is: %4.0f\n" , bab3);
				bab3 = bab3 + 0.75;
			}
			printf("Your third Base Attack Bonus is: %4.0f\n" , bab3);
		}	
	}else if (cc == 10 || cc == 11 || cc == 12)
	{
		bab = 0.0;
		bab2 = 0.0;
		bab3 = 0.0;
		bab4 = 0.0;
		for (a = 2; a <= ls; a += 2)
		{
			bab = bab + 1;
		}
		printf("\nYour Base Attack Bonus is: %4.0f\n" , bab);
		if (ls > 11)
		{
			bab2 = 1;
			for (b = 13; b <= ls; b += 2)
			{
				bab2 = bab2 + 1;
			}
			printf("Your second Base Attack Bonus is: %4.0f\n" , bab2);
		}
		
	}
	fprintf(CharacterSheet, "%4.4f %4.4f %4.4f %4.4f " , bab, bab2, bab3, bab4);
	fclose(CharacterSheet);
}

int spellSlots(int classChoice, int levelSelect)
{
	int cc, ls, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v;
	float spelDay[10] = { 0.0 };
	float speDay[10] = { 0.0 };
	float lvlInc, fa, fb, fc, fd, fe;
	
	FILE*CharacterSheet;
	
	
	cc = classChoice;
	ls = levelSelect;
	
	a = 2;	
	
	if (cc == 2 || cc == 15 || cc == 16 || cc == 18 || cc == 22 || cc == 24 || cc == 26 ) //bard, hunter, invest, skald, alchemist, inquisitor, summoner
	{	
		if (ls > 0 && ls <= 20)
		{
			speDay[0] = 1;
			for (a = 2; a <= 3; a++)
			{
				speDay[0] = speDay[0] + 1;
			}
			if (ls > 3)
			{
				speDay[1] = 1;
				speDay[0] = 3;
				//printf("qqqLevel Two Spells per Day:  %4.0f\n" , speDay[1]);
				for (b = 5; b <= 6; b++)
				{
					speDay[0] = 4;
					speDay[1] = speDay[1] + 1;
				}
				if (ls > 6)
				{
					speDay[2] = 1;
					speDay[1] = 3;
					for (c = 8; c <= 9; c++)
					{
						speDay[0] = speDay[0] + 0.3;
						speDay[1] = 4;
						speDay[2] = speDay[2] + 1;
					}
					if (ls > 9)
					{
						speDay[3] = 1;
						speDay[2] = 3;
						for (d = 11; d <= 12; d++)
						{
							speDay[1] = speDay[1] + 0.3;
							speDay[2] = 4;
							speDay[3] = speDay[3] + 1;
						}
						if (ls > 12)
						{
							speDay[4] = 1;
							speDay[3] = 3;
							for (e = 14; e <= 15; e++)
							{
								speDay[2] = speDay[2] + 0.3;
								speDay[3] = 4;
								speDay[4] = speDay[4] + 1;
							}
							if (ls > 15)
							{
								speDay[5] = 1;
								speDay[4] = 3;
								for (f = 17; f <= 20; f++)
								{
									speDay[3] = speDay[3] + 0.2;
									speDay[4] = speDay[4] + 0.5;
									speDay[5] = speDay[5] + 1;
								}
							}	
						}
					}
				}	
			}
		}
		i = 1;
		if (cc == 2 || cc == 18 || cc == 26)
		{			
			for (h = 0; h <= (chaMod - 1); h++)
			{
				speDay[h] = speDay[h] + 1;
			}					
			if (chaMod > 4)
			{
				for (h = 0; h <= (chaMod - 5); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}					
			if (chaMod > 8)
			{
				for (h = 0; h <= (chaMod - 9); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			
			if (ls < 4)
			{
				speDay[1] = 0;
			}else if (ls < 7)
			{
				speDay[2] = 0;
			}else if (ls < 10)
			{
				speDay[3] = 0;
			}else if (ls < 13)
			{
				speDay[4] = 0;
			}else if (ls < 16)
			{
				speDay[5] = 0;
			}
			
			printf("\nLevel One Spells per Day:  %4.0f\n" , speDay[0]);
			printf("Level Two Spells per Day:  %4.0f\n" , speDay[1]);
			printf("Level Three Spells per Day:  %4.0f\n" , speDay[2]);
			printf("Level Four Spells per Day:  %4.0f\n" , speDay[3]);
			printf("Level Five Spells per Day:  %4.0f\n" , speDay[4]);
			printf("Level Six Spells per Day:  %4.0f\n" , speDay[5]);
		}else if (cc == 15 || cc == 24)
		{
			for (h = 0; h <= (wisMod - 1); h++)
			{
				speDay[h] = speDay[h] + 1;
			}					
			if (wisMod > 4)
			{
				for (h = 0; h <= (wisMod - 5); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			if (wisMod > 8)
			{
				for (h = 0; h <= (wisMod - 9); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			
			if (ls < 4)
			{
				speDay[1] = 0;
			}else if (ls < 7)
			{
				speDay[2] = 0;
			}else if (ls < 10)
			{
				speDay[3] = 0;
			}else if (ls < 13)
			{
				speDay[4] = 0;
			}else if (ls < 16)
			{
				speDay[5] = 0;
			}
			printf("\nLevel One Spells per Day:  %4.0f\n" , speDay[0]);
			printf("Level Two Spells per Day:  %4.0f\n" , speDay[1]);
			printf("Level Three Spells per Day:  %4.0f\n" , speDay[2]);
			printf("Level Four Spells per Day:  %4.0f\n" , speDay[3]);
			printf("Level Five Spells per Day:  %4.0f\n" , speDay[4]);
			printf("Level Six Spells per Day:  %4.0f\n" , speDay[5]);
		}else if (cc == 16 || cc == 22)
		{
			for (h = 0; h <= (intMod - 1); h++)
			{
				speDay[h] = speDay[h] + 1;
			}					
			if (intMod > 4)
			{
				for (h = 0; h <= (intMod - 5); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			if (intMod > 8)
			{
				for (h = 0; h <= (intMod - 9); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			
			if (ls < 4)
			{
				speDay[1] = 0;
			}else if (ls < 7)
			{
				speDay[2] = 0;
			}else if (ls < 10)
			{
				speDay[3] = 0;
			}else if (ls < 13)
			{
				speDay[4] = 0;
			}else if (ls < 16)
			{
				speDay[5] = 0;
			}
			printf("\nLevel One Extracts per Day:  %4.0f\n" , speDay[0]);
			printf("Level Two Extracts per Day:  %4.0f\n" , speDay[1]);
			printf("Level Three Extracts per Day:  %4.0f\n" , speDay[2]);
			printf("Level Four Extracts per Day:  %4.0f\n" , speDay[3]);
			printf("Level Five Extracts per Day:  %4.0f\n" , speDay[4]);
			printf("Level Six Extracts per Day:  %4.0f\n" , speDay[5]);
		}
		
		//2 3 4 4 4 4 5 5 5 5 6 (11) -
		//4 7 10 13 16
		if (cc == 2 || cc == 15 || cc == 18 || cc == 23)
		{
			fc = 1;
			spelDay[0] = 4;
			spelDay[1] = 2;
			fa = 2;
			
			//printf("\nCantrips known:         %4.0f" , spelDay[0]);
			//printf("\nls is %i\n" , ls);

			if (ls > 1)
			{
				spelDay[0] = 5;
				spelDay[1] = 3;
			//printf("\nCantrips known:         %4.0f" , spelDay[0]);
				for (b = 3; b <= ls; b += 4)
				{				
					//fc = fa * 0.78;				
					spelDay[0] = 6;
					spelDay[1] = spelDay[1] + 1;					
					//fa = fc;
				}
			}
			
			if (ls > 3)
			{
				//fa = 1;
				spelDay[2] = 2;
				if (ls > 4)
				{
					spelDay[2] = 3;
					for (b = 6; b <= ls; b += 4)
					{				
						//fc = fa * 0.78;				
						spelDay[2] = spelDay[2] + 1;
						//fa = fc;
					}
				}
			}
				
			if (ls > 6)
			{
				//fa = 1;
				spelDay[3] = 2;
				if (ls > 7)
				{
					spelDay[3] = 3;
					for (b = 9; b <= ls; b += 4)
					{				
						//fc = fa * 0.78;				
						spelDay[3] = spelDay[3] + 1;
						//fa = fc;
					}
				}
			}
					
			if (ls > 9)
			{
				//fa = 1;
				spelDay[4] = 2;
				if (ls > 10)
				{
					spelDay[4] = 3;
					for (b = 12; b <= ls; b += 4)
					{				
						//fc = fa * 0.78;				
						spelDay[4] = spelDay[4] + 1;
						//fa = fc;
					}
				}
			}
				
			if (ls > 12)
			{
				//fa = 1;
				spelDay[5] = 2;
				if (ls > 13)
				{
					spelDay[5] = 3;
					for (b = 15; b <= ls; b += 4)
					{				
						//fc = fa * 0.78;				
						spelDay[5] = spelDay[5] + 1;
						//fa = fc;
					}
				}
			}
			
			if (ls > 15)
			{
				//fa = 1;
				spelDay[6] = 2;
				if (ls > 16)
				{
					spelDay[6] = 3;
					for (b = 18; b <= ls; b += 4)
					{				
						//fc = fa * 0.78;				
						spelDay[6] = spelDay[6] + 1;
						//fa = fc;
					}
				}
			}
			
			    
				
				
			if (spelDay[0] > 6)
			{
				spelDay[0] = 6;
			}
			printf("\nNumber of Cantrips known:   %4.0f" , spelDay[0]);
			for (d = 1; d <= 6; d++)
			{
				if (spelDay[d] > 6)
				{
					spelDay[d] = 6;
				}
				printf("\nLevel %i Spells known:  %4.0f" , d, spelDay[d]);
			}
			
		}
				
	}else if (cc == 7 || cc == 8) //paladin, ranger
	{
		if (ls > 0 && ls <= 20)
		{
			speDay[0] = 0;
			if (ls > 4)
			{
				for (a = 5; a <= ls; a += 4)
				{
					speDay[0] = speDay[0] + 1;
				}
			}
			if (ls > 6)
			{
				for (b = 7; b <= ls; b += 4)
				{
					speDay[1] = speDay[1] + 1;
				}
			}
			if (ls > 10)
			{
				for (c = 11; c <= ls; c += 4)
				{
					speDay[2] = speDay[2] + 1;
				}
			}
			if (ls > 13)
			{
				speDay[3] = 1;
				if (ls > 17)
				{
					speDay[3] = 2;
					if (ls == 20)
					{
						speDay[3] = 3;
					}
				}
			}
		}
		
		if (cc == 7)
		{
			for (h = 0; h <= (chaMod - 1); h++)
			{
				speDay[h] = speDay[h] + 1;
			}					
			if (chaMod > 4)
			{
				for (h = 0; h <= (chaMod - 5); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			if (chaMod > 8)
			{
				for (h = 0; h <= (chaMod - 9); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
		}else if (cc == 8)
		{
			for (h = 0; h <= (wisMod - 1); h++)
			{
				speDay[h] = speDay[h] + 1;
			}					
			if (wisMod > 4)
			{
				for (h = 0; h <= (wisMod - 5); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			if (wisMod > 8)
			{
				for (h = 0; h <= (wisMod - 9); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
		}
		
		if (ls < 4)
		{
			speDay[0] = 0;
		}else if (ls < 7)
		{
			speDay[1] = 0;
		}else if (ls < 10)
		{
			speDay[2] = 0;
		}else if (ls < 13)
		{
			speDay[3] = 0;
		}
		
		printf("\nLevel One Spells per Day:  %4.0f\n" , speDay[0]);
		printf("Level Two Spells per Day:  %4.0f\n" , speDay[1]);
		printf("Level Three Spells per Day:  %4.0f\n" , speDay[2]);
		printf("Level Four Spells per Day:  %4.0f\n" , speDay[3]);		
		
	}else if (cc == 11 || cc == 17 || cc == 4 || cc == 3 || cc == 27) //wizard, shaman, druid, cleric, witch
	{
		if (ls > 0 && ls <= 20)
		{
			speDay[0] = 3;
			speDay[1] = 1;
			fb = 1;	
			for (a = 2; a <= ls; a++)
			{
				//printf("\na is %i\n" , a);							
				fc = fb * 0.77;
				fb = fc;
				//printf("\nfb is %4.4f\n" , fb);
				speDay[0] = 4;
				speDay[1] = speDay[1] + fc;
			}
			if (ls > 2)
			{
				speDay[2] = 1;
				fb = 1.0;
				for (a = 4; a <= ls; a++)
				{									
					fc = fb * 0.77;
					fb = fc;					
					speDay[2] = speDay[2] + fc;
				}
			}
			if (ls > 4)
			{
				speDay[3] = 1;
				fb = 1.0;
				for (a = 6; a <= ls; a++)
				{									
					fc = fb * 0.77;
					fb = fc;					
					speDay[3] = speDay[3] + fc;
				}
			}
			if (ls > 6)
			{
				speDay[4] = 1;
				fb = 1.0;	
				for (a = 8; a <= ls; a++)
				{								
					fc = fb * 0.77;
					fb = fc;					
					speDay[4] = speDay[4] + fc;
				}
			}
			if (ls > 8)
			{
				speDay[5] = 1;
				fb = 1.0;
				for (a = 10; a <= ls; a++)
				{									
					fc = fb * 0.77;
					fb = fc;					
					speDay[5] = speDay[5] + fc;
				}
			}
			if (ls > 10)
			{
				speDay[6] = 1;
				fb = 1.0;
				for (a = 12; a <= ls; a++)
				{									
					fc = fb * 0.77;
					fb = fc;					
					speDay[6] = speDay[6] + fc;
				}
			}
			if (ls > 12)
			{
				speDay[7] = 1;
				fb = 1.0;	
				for (a = 14; a <= ls; a++)
				{								
					fc = fb * 0.77;
					fb = fc;						
					speDay[7] = speDay[7] + fc;
				}
			}
			if (ls > 14)
			{
				speDay[8] = 1;
				//fb = 1.0;	
				for (a = 16; a <= ls; a += 2)
				{								
					//fc = fb * 0.77;
					//fb = fc;
					speDay[8] = speDay[8] + 1;
				}
			}
			if (ls > 16)
			{
				speDay[9] = 1;
				//fb = 1.0;	
				for (a = 18; a <= ls; a++)
				{								
					//fc = fb * 0.77;
					//fb = fc;					
					speDay[9] = speDay[9] + 1;
				}
			}
			
		}
		if (cc == 11 || cc == 27) //wizard, witch
		{
			for (h = 1; h <= (intMod - 1); h++)
			{
				speDay[h] = speDay[h] + 1;
			}					
			if (intMod > 4)
			{
				for (h = 1; h <= (intMod - 5); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			if (intMod > 8)
			{
				for (h = 1; h <= (intMod - 9); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			if (ls < 3)
			{
				speDay[2] = 0;
			}else if (ls < 5)
			{
				speDay[3] = 0;
			}else if (ls < 7)
			{
				speDay[4] = 0;
			}else if (ls < 9)
			{
				speDay[5] = 0;
			}else if (ls < 11)
			{
				speDay[6] = 0;
			}else if (ls < 13)
			{
				speDay[7] = 0;
			}else if (ls < 15)
			{
				speDay[8] = 0;
			}
			
			printf("\nCantrips prepared per Day:  %4.0f\n" , speDay[0]);
			printf("Level One Spells per Day:  %4.0f\n" , speDay[1]);
			printf("Level Two Spells per Day:  %4.0f\n" , speDay[2]);
			printf("Level Three Spells per Day:  %4.0f\n" , speDay[3]);
			printf("Level Four Spells per Day:  %4.0f\n" , speDay[4]);
			printf("Level Five Spells per Day:  %4.0f\n" , speDay[5]);
			printf("Level Six Spells per Day:  %4.0f\n" , speDay[6]);			
			printf("Level Seven Spells per Day:  %4.0f\n" , speDay[7]);
			printf("Level Eight Spells per Day:  %4.0f\n" , speDay[8]);
			printf("Level Nine Spells per Day:  %4.0f\n" , speDay[9]);
			
		}else if (cc == 17 || cc == 4)
		{
			for (h = 1; h <= (wisMod - 1); h++)
			{
				speDay[h] = speDay[h] + 1;
			}					
			if (wisMod > 4)
			{
				for (h = 1; h <= (wisMod - 5); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			if (wisMod > 8)
			{
				for (h = 1; h <= (wisMod - 9); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			if (ls < 3)
			{
				speDay[2] = 0;
			}else if (ls < 5)
			{
				speDay[3] = 0;
			}else if (ls < 7)
			{
				speDay[4] = 0;
			}else if (ls < 9)
			{
				speDay[5] = 0;
			}else if (ls < 11)
			{
				speDay[6] = 0;
			}else if (ls < 13)
			{
				speDay[7] = 0;
			}else if (ls < 15)
			{
				speDay[8] = 0;
			}
			printf("\nOrisons prepared per Day:  %4.0f\n" , speDay[0]);
			printf("Level One Spells per Day:  %4.0f\n" , speDay[1]);
			printf("Level Two Spells per Day:  %4.0f\n" , speDay[2]);
			printf("Level Three Spells per Day:  %4.0f\n" , speDay[3]);
			printf("Level Four Spells per Day:  %4.0f\n" , speDay[4]);
			printf("Level Five Spells per Day:  %4.0f\n" , speDay[5]);
			printf("Level Six Spells per Day:  %4.0f\n" , speDay[6]);			
			printf("Level Seven Spells per Day:  %4.0f\n" , speDay[7]);
			printf("Level Eight Spells per Day:  %4.0f\n" , speDay[8]);
			printf("Level Nine Spells per Day:  %4.0f\n" , speDay[9]);
		}else if (cc == 3)
		{
			for (h = 1; h <= (wisMod - 1); h++)
			{
				speDay[h] = speDay[h] + 1;
			}					
			if (wisMod > 4)
			{
				for (h = 1; h <= (wisMod - 5); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			if (wisMod > 8)
			{
				for (h = 1; h <= (wisMod - 9); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			if (ls < 3)
			{
				speDay[2] = 0;
			}else if (ls < 5)
			{
				speDay[3] = 0;
			}else if (ls < 7)
			{
				speDay[4] = 0;
			}else if (ls < 9)
			{
				speDay[5] = 0;
			}else if (ls < 11)
			{
				speDay[6] = 0;
			}else if (ls < 13)
			{
				speDay[7] = 0;
			}else if (ls < 15)
			{
				speDay[8] = 0;
			}
			
			printf("\nOrisons prepared per Day:  %4.0f\n" , speDay[0]);
			
			for (a = 1; a <= 9; a++)
			{
				if (speDay[a] <= 0)
				{
					printf("Level %i Spells per Day:  %4.0f\n" , a, speDay[a]);
				}else if (speDay[a] > 0)
				{
				printf("Level %i Spells per Day:    %4.0f + 1 Domain\n" , a, speDay[a]);
				}				
			}
		}
		
	}else if (cc == 21) //warpriest
	{
		if (ls > 0 && ls <= 20)
		{
			speDay[0] = 3;
			speDay[1] = 1;
			fb = 1.1;	
			for (a = 2; a <= ls; a++)
			{
				//printf("\na is %i\n" , a);							
				fc = fb * 0.8;
				fb = fc;
				//printf("\nfb is %4.4f\n" , fb);
				speDay[0] = 4;
				speDay[1] = speDay[1] + fc;
			}
			if (ls > 5)
			{
				speDay[0] = 5;
			}
			if (ls > 3)
			{
				speDay[2] = 1;
				fb = 1.1;
				for (a = 5; a <= ls; a++)
				{									
					fc = fb * 0.8;
					fb = fc;					
					speDay[2] = speDay[2] + fc;
				}
			}
			if (ls > 6)
			{
				speDay[3] = 1;
				fb = 1.1;
				for (a = 8; a <= ls; a++)
				{									
					fc = fb * 0.8;
					fb = fc;					
					speDay[3] = speDay[3] + fc;
				}
			}
			if (ls > 9)
			{
				speDay[4] = 1;
				fb = 1.1;	
				for (a = 11; a <= ls; a++)
				{								
					fc = fb * 0.8;
					fb = fc;					
					speDay[4] = speDay[4] + fc;
				}
			}
			if (ls > 12)
			{
				speDay[5] = 1;
				fb = 1.1;
				for (a = 14; a <= ls; a++)
				{									
					fc = fb * 0.8;
					fb = fc;					
					speDay[5] = speDay[5] + fc;
				}
			}
			if (ls > 15)
			{
				speDay[6] = 1;
				fb = 1.1;
				for (a = 14; a <= ls; a++)
				{									
					fc = fb * 0.8;
					fb = fc;					
					speDay[6] = speDay[6] + fc;
				}
			}
			
			for (a = 0; a <= 6; a++) //limiter
			{
				if(speDay[a] > 5)
				{
					speDay[a] = 5;					
				}
			}
			
			for (h = 1; h <= (wisMod - 1); h++) //bonus spells
			{
				speDay[h] = speDay[h] + 1;
			}					
			if (wisMod > 4)
			{
				for (h = 1; h <= (wisMod - 5); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			if (wisMod > 8)
			{
				for (h = 1; h <= (wisMod - 9); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
		}
		
		if (ls < 4)
		{
			speDay[2] = 0;
		}else if (ls < 7)
		{
			speDay[3] = 0;
		}else if (ls < 10)
		{
			speDay[4] = 0;
		}else if (ls < 13)
		{
			speDay[5] = 0;
		}else if (ls < 16)
		{
			speDay[6] = 0;
		}
			
		printf("\nOrisons prepared per Day:  %4.0f\n" , speDay[0]);
		printf("Level One Spells per Day:  %4.0f\n" , speDay[1]);
		printf("Level Two Spells per Day:  %4.0f\n" , speDay[2]);
		printf("Level Three Spells per Day:  %4.0f\n" , speDay[3]);
		printf("Level Four Spells per Day:  %4.0f\n" , speDay[4]);
		printf("Level Five Spells per Day:  %4.0f\n" , speDay[5]);
		printf("Level Six Spells per Day:  %4.0f\n" , speDay[6]);
		
	}else if (cc == 12) //arcanist
	{
		if (ls > 0 && ls <= 20)
		{
			speDay[0] = 2;			
			fb = 2;
			for (a = 2; a <= ls; a++)
			{
				//printf("\na is %i\n" , a);							
				fc = fb * 0.5;
				fb = fc;
				//printf("\nfb is %4.4f\n" , fb);				
				speDay[0] = speDay[0] + fc;
			}
			if (ls > 3)
			{
				speDay[1] = 2;			
				fb = 2;
				for (a = 5; a <= ls; a++)
				{
					//printf("\na is %i\n" , a);							
					fc = fb * 0.5;
					fb = fc;
					//printf("\nfb is %4.4f\n" , fb);				
					speDay[1] = speDay[1] + fc;
				}
			}
			if (ls > 5)
			{
				speDay[2] = 2;			
				fb = 2;
				for (a = 7; a <= ls; a++)
				{
					//printf("\na is %i\n" , a);							
					fc = fb * 0.5;
					fb = fc;
					//printf("\nfb is %4.4f\n" , fb);				
					speDay[2] = speDay[2] + fc;
				}
			}
			if (ls > 7)
			{
				speDay[3] = 2;			
				fb = 2;
				for (a = 9; a <= ls; a++)
				{
					//printf("\na is %i\n" , a);							
					fc = fb * 0.5;
					fb = fc;
					//printf("\nfb is %4.4f\n" , fb);				
					speDay[3] = speDay[3] + fc;
				}
			}
			if (ls > 9)
			{
				speDay[4] = 2;			
				fb = 2;
				for (a = 11; a <= ls; a++)
				{
					//printf("\na is %i\n" , a);							
					fc = fb * 0.5;
					fb = fc;
					//printf("\nfb is %4.4f\n" , fb);				
					speDay[4] = speDay[4] + fc;
				}
			}
			if (ls > 11)
			{
				speDay[5] = 2;			
				fb = 2;
				for (a = 13; a <= ls; a++)
				{
					//printf("\na is %i\n" , a);							
					fc = fb * 0.5;
					fb = fc;
					//printf("\nfb is %4.4f\n" , fb);				
					speDay[5] = speDay[5] + fc;
				}
			}
			if (ls > 13)
			{
				speDay[6] = 2;			
				fb = 2;
				for (a = 15; a <= ls; a++)
				{
					//printf("\na is %i\n" , a);							
					fc = fb * 0.5;
					fb = fc;
					//printf("\nfb is %4.4f\n" , fb);				
					speDay[6] = speDay[6] + fc;
				}
			}
			if (ls > 15)
			{
				speDay[7] = 2;			
				fb = 2;
				for (a = 17; a <= ls; a++)
				{
					//printf("\na is %i\n" , a);							
					fc = fb * 0.5;
					fb = fc;
					//printf("\nfb is %4.4f\n" , fb);				
					speDay[7] = speDay[7] + fc;
				}
			}
			if (ls > 17)
			{
				speDay[8] = 2;			
				fb = 2;
				for (a = 19; a <= ls; a++)
				{
					//printf("\na is %i\n" , a);							
					fc = fb * 0.5;
					fb = fc;
					//printf("\nfb is %4.4f\n" , fb);				
					speDay[9] = speDay[9] + fc;
				}
			}
			
			for (h = 0; h <= (intMod - 1); h++)
			{
				speDay[h] = speDay[h] + 1;
			}					
			if (intMod > 4)
			{
				for (h = 0; h <= (intMod - 5); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			if (intMod > 8)
			{
				for (h = 0; h <= (intMod - 9); h++)
				{
					speDay[h] = speDay[h] + 1;
				}
			}
			
		if (ls < 4)
		{
			speDay[1] = 0;
		}else if (ls < 6)
		{
			speDay[2] = 0;
		}else if (ls < 8)
		{
			speDay[3] = 0;
		}else if (ls < 10)
		{
			speDay[4] = 0;
		}else if (ls < 12)
		{
			speDay[5] = 0;
		}else if (ls < 14)
		{
			speDay[6] = 0;
		}else if (ls < 16)
		{
			speDay[7] = 0;
		}else if (ls < 18)
		{
			speDay[8] = 0;
		}
			
			printf("\nLevel One Spells per Day:  %4.0f\n" , speDay[0]);
			printf("Level Two Spells per Day:  %4.0f\n" , speDay[1]);
			printf("Level Three Spells per Day:  %4.0f\n" , speDay[2]);
			printf("Level Four Spells per Day:  %4.0f\n" , speDay[3]);
			printf("Level Five Spells per Day:  %4.0f\n" , speDay[4]);
			printf("Level Six Spells per Day:  %4.0f\n" , speDay[5]);
			printf("Level Seven Spells per Day:  %4.0f\n" , speDay[6]);
			printf("Level Eight Spells per Day:  %4.0f\n" , speDay[7]);
			printf("Level Nine Spells per Day:  %4.0f\n" , speDay[8]);
		}
		
		spelDay[0] = 4;
		for (b = 2; b <= ls; b += 2)
		{
			spelDay[0] = spelDay[0] + 1;
		}
		if (spelDay[0] > 9)
		{
			spelDay[0] = 9;
		}
		
		spelDay[1] = 2;
		for (b = 3; b <= ls; b += 2)
		{
			spelDay[1] = spelDay[1] + 1;
		}
		if (spelDay[1] > 5)
		{
			spelDay[1] = 5;
		}
		
		if (ls > 3)
		{
			spelDay[2] = 1;
			for (b = 5; b <= ls; b += 2)
			{
				spelDay[2] = spelDay[2] + 1;
			}
			if (spelDay[2] > 5)
			{
				spelDay[2] = 5;
			}
		}
		
		if (ls > 5)
		{
			spelDay[3] = 1;
			for (b = 7; b <= ls; b += 2)
			{
				spelDay[3] = spelDay[3] + 1;
			}
			if (spelDay[3] > 4)
			{
				spelDay[3] = 4;
			}
		}
		
		if (ls > 7)
		{
			spelDay[4] = 1;
			for (b = 9; b <= ls; b += 2)
			{
				spelDay[4] = spelDay[4] + 1;
			}
			if (spelDay[4] > 4)
			{
				spelDay[4] = 4;
			}
		}
		
		if (ls > 9)
		{
			spelDay[5] = 1;
			for (b = 11; b <= ls; b += 2)
			{
				spelDay[5] = spelDay[5] + 1;
			}
			if (spelDay[5] > 4)
			{
				spelDay[5] = 4;
			}
		}
		
		if (ls > 11)
		{
			spelDay[6] = 1;
			for (b = 13; b <= ls; b += 2)
			{
				spelDay[6] = spelDay[6] + 1;
			}
			if (spelDay[6] > 3)
			{
				spelDay[6] = 3;
			}
		}
		
		if (ls > 13)
		{
			spelDay[7] = 1;
			for (b = 15; b <= ls; b += 2)
			{
				spelDay[7] = spelDay[7] + 1;
			}
			if (spelDay[7] > 3)
			{
				spelDay[7] = 3;
			}
		}
		
		if (ls > 15)
		{
			spelDay[8] = 1;
			for (b = 17; b <= ls; b += 2)
			{
				spelDay[8] = spelDay[8] + 1;
			}
			if (spelDay[8] > 3)
			{
				spelDay[8] = 3;
			}
		}
		
		if (ls > 17)
		{
			spelDay[9] = 1;
			for (b = 19; b <= ls; b++)
			{
				spelDay[9] = spelDay[9] + 1;
			}
			if (spelDay[9] > 3)
			{
				spelDay[9] = 3;
			}
		}		
		
		    printf("\nNumber of Cantrips prepared:  %4.0f" , spelDay[0]);
		for (d = 1; d <= 9; d++)
		{			
			printf("\nLevel %i Spells prepared:     %4.0f" , d, spelDay[d]);
		}
		
		
	}else if (cc == 13) //bloodrager
	{
		if (ls > 0 && ls <= 20)
		{
			if (ls > 3)
			{
				speDay[0] = 1;
				for (a = 9; a <= ls; a += 4)
				{
					speDay[0] = speDay[0] + 1;
				}
			}
			if (ls > 6)
			{
				speDay[1] = 1;
				for (a = 12; a <= ls; a += 4)
				{
					speDay[1] = speDay[1] + 1;
				}
			}
			if (ls > 9)
			{
				speDay[2] = 1;
				for (a = 15; a <= ls; a += 4)
				{
					speDay[2] = speDay[2] + 1;
				}
			}
			if (ls > 12)
			{
				speDay[3] = 1;
				for (a = 18; a <= ls; a += 4)
				{
					speDay[3] = speDay[3] + 1;
				}
			}
		}
		
		for (h = 0; h <= (chaMod - 1); h++)
		{
			speDay[h] = speDay[h] + 1;
		}					
		if (chaMod > 4)
		{
			for (h = 0; h <= (chaMod - 5); h++)
			{
				speDay[h] = speDay[h] + 1;
			}
		}
		if (chaMod > 8)
		{
			for (h = 0; h <= (chaMod - 9); h++)
			{
				speDay[h] = speDay[h] + 1;
			}
		}
		
		if (ls < 4)
		{
			speDay[0] = 0;
		}else if (ls < 7)
		{
			speDay[1] = 0;
		}else if (ls < 10)
		{
			speDay[2] = 0;
		}else if (ls < 13)
		{
			speDay[3] = 0;
		}
		
		printf("\nLevel One Spells per Day:  %4.0f\n" , speDay[0]);
		printf("Level Two Spells per Day:  %4.0f\n" , speDay[1]);
		printf("Level Three Spells per Day:  %4.0f\n" , speDay[2]);
		printf("Level Four Spells per Day:  %4.0f\n" , speDay[3]);
		
		if (ls > 3)
		{
			spelDay[1] = 2;
			if (ls > 4)
			{
				spelDay[1] = 3;
				for (b = 6; b <= ls; b += 3)
				{
					spelDay[1] = spelDay[1] + 1;
				}
			}
		}
		if (spelDay[1] > 6)
		{
			spelDay[1] = 6;
		}
		
		if (ls > 6)
		{
			spelDay[2] = 2;
			if (ls > 7)
			{
				spelDay[2] = 3;
				for (b = 9; b <= ls; b += 3)
				{
					spelDay[2] = spelDay[2] + 1;
				}
			}
		}
		if (spelDay[2] > 6)
		{
			spelDay[2] = 6;
		}
		
		if (ls > 9)
		{
			spelDay[3] = 2;
			if (ls > 10)
			{
				spelDay[3] = 3;
				for (b = 12; b <= ls; b += 3)
				{
					spelDay[3] = spelDay[3] + 1;
				}
			}
		}
		if (spelDay[3] > 6)
		{
			spelDay[3] = 6;
		}
		
		if (ls > 12)
		{
			spelDay[4] = 2;
			if (ls > 13)
			{
				spelDay[4] = 3;
				for (b = 15; b <= ls; b += 3)
				{
					spelDay[4] = spelDay[4] + 1;
				}
			}
		}
		if (spelDay[4] > 6)
		{
			spelDay[4] = 6;
		}
		   
		for (d = 1; d <= 4; d++)
		{			
			printf("\nLevel %i Spells prepared:     %4.0f" , d, spelDay[d]);
		}
		
		
	}else if (cc == 10 || cc == 25) //sorcerer, oracle
	{
		if (ls > 0 && ls <= 20)
		{			
			
			speDay[0] = 3;
			for (a = 2; a <= ls; a++)
			{
				speDay[0] = speDay[0] + 1;
			}
			c = 1;
			for (b = 4; b <= ls; b += 2)
			{
				speDay[c] = 3;
				
				for (a = (b + 1); a <= ls; a++)
				{
					//printf("\nc is %i\n" , c);
					//printf("\nspeday before is %4.4f\n" , speDay[c]);
					speDay[c] = speDay[c] + 1;	
					//printf("\nc is %i\n" , c);
					//printf("\nspeday after is %4.4f\n" , speDay[c]);
				}
				c = c + 1;
			}
			
			for (e = 0; e <= 10; e++)
			{
				if (speDay[e] > 6)
				{
					speDay[e] = 6;
				}
			}
			
		}
		
		for (h = 0; h <= (chaMod - 1); h++)
		{
			speDay[h] = speDay[h] + 1;
		}					
		if (chaMod > 4)
		{
			for (h = 0; h <= (chaMod - 5); h++)
			{
				speDay[h] = speDay[h] + 1;
			}
		}
		if (chaMod > 8)
		{
			for (h = 0; h <= (chaMod - 9); h++)
			{
				speDay[h] = speDay[h] + 1;
			}
		}
		
		if (ls < 4)
		{
			speDay[1] = 0;
		}else if (ls < 6)
		{
			speDay[2] = 0;
		}else if (ls < 8)
		{
			speDay[3] = 0;
		}else if (ls < 10)
		{
			speDay[4] = 0;
		}else if (ls < 12)
		{
			speDay[5] = 0;
		}else if (ls < 14)
		{
			speDay[6] = 0;
		}else if (ls < 16)
		{
			speDay[7] = 0;
		}else if (ls < 18)
		{
			speDay[8] = 0;
		}
		
		printf("\nLevel One Spells per Day:  %4.0f\n" , speDay[0]);
		printf("Level Two Spells per Day:  %4.0f\n" , speDay[1]);
		printf("Level Three Spells per Day:  %4.0f\n" , speDay[2]);
		printf("Level Four Spells per Day:  %4.0f\n" , speDay[3]);
		printf("Level Five Spells per Day:  %4.0f\n" , speDay[4]);
		printf("Level Six Spells per Day:  %4.0f\n" , speDay[5]);
		printf("Level Seven Spells per Day:  %4.0f\n" , speDay[6]);
		printf("Level Eight Spells per Day:  %4.0f\n" , speDay[7]);
		printf("Level Nine Spells per Day:  %4.0f\n" , speDay[8]);

		spelDay[0] = 4;
		for (b = 2; b <= ls; b += 2)
		{
			spelDay[0] = spelDay[0] + 1;
		}
		if (spelDay[0] > 9)
		{
			spelDay[0] = 9;
		}
		
		spelDay[1] = 2;
		for (b = 3; b <= ls; b += 2)
		{
			spelDay[1] = spelDay[1] + 1;
		}
		if (spelDay[1] > 5)
		{
			spelDay[1] = 5;
		}
		
		if (ls > 3)
		{
			spelDay[2] = 1;
			for (b = 5; b <= ls; b += 2)
			{
				spelDay[2] = spelDay[2] + 1;
			}
			if (spelDay[2] > 5)
			{
				spelDay[2] = 5;
			}
		}
		
		if (ls > 5)
		{
			spelDay[3] = 1;
			for (b = 7; b <= ls; b += 2)
			{
				spelDay[3] = spelDay[3] + 1;
			}
			if (spelDay[3] > 4)
			{
				spelDay[3] = 4;
			}
		}
		
		if (ls > 7)
		{
			spelDay[4] = 1;
			for (b = 9; b <= ls; b += 2)
			{
				spelDay[4] = spelDay[4] + 1;
			}
			if (spelDay[4] > 4)
			{
				spelDay[4] = 4;
			}
		}
		
		if (ls > 9)
		{
			spelDay[5] = 1;
			for (b = 11; b <= ls; b += 2)
			{
				spelDay[5] = spelDay[5] + 1;
			}
			if (spelDay[5] > 4)
			{
				spelDay[5] = 4;
			}
		}
		
		if (ls > 11)
		{
			spelDay[6] = 1;
			for (b = 13; b <= ls; b += 2)
			{
				spelDay[6] = spelDay[6] + 1;
			}
			if (spelDay[6] > 3)
			{
				spelDay[6] = 3;
			}
		}
		
		if (ls > 13)
		{
			spelDay[7] = 1;
			for (b = 15; b <= ls; b += 2)
			{
				spelDay[7] = spelDay[7] + 1;
			}
			if (spelDay[7] > 3)
			{
				spelDay[7] = 3;
			}
		}
		
		if (ls > 15)
		{
			spelDay[8] = 1;
			for (b = 17; b <= ls; b += 2)
			{
				spelDay[8] = spelDay[8] + 1;
			}
			if (spelDay[8] > 3)
			{
				spelDay[8] = 3;
			}
		}
		
		if (ls > 17)
		{
			spelDay[9] = 1;
			for (b = 19; b <= ls; b++)
			{
				spelDay[9] = spelDay[9] + 1;
			}
			if (spelDay[9] > 3)
			{
				spelDay[9] = 3;
			}
		}		
		if (cc == 10)
		{
			printf("\nNumber of Cantrips known:  %4.0f" , spelDay[0]);
		}else if (cc == 25)
		{
			printf("\nNumber of Orisons known:  %4.0f" , spelDay[0]);
		}
		for (d = 1; d <= 9; d++)
		{			
			printf("\nLevel %i Spells known:     %4.0f" , d, spelDay[d]);
		}
	}
	
	CharacterSheet = fopen("CharacterSheet.txt" , "a");
	for (a = 0; a <= 9; a++)
	{
		fprintf(CharacterSheet, "%4.4f " , speDay[a]);
	}
	for (a = 0; a <= 9; a++)
	{
		fprintf(CharacterSheet, "%4.4f " , spelDay[a]);
	}	
	fclose(CharacterSheet);
	
}

int characterGenerator()
{
	unsigned a, b, c, d, e, s, rr, age, end, sa, gr, ls, st, as, bs, cs, aa, bb, dd, ee, ff, gg, hh;
	char fo, qi, g, h, userInp[35], kk;
	int Att[6], Str, Str2,Str4, StrN2, Dex, Dex2, DexN2, Con, Con2, ConN2, Inte, Inte2, InteN2, Wis, Wis2, WisN2, Cha, Cha2, ChaN2, ChaN4, cc, yn, ny, mn, mx;
	float strMod2, dexMod2, conMod2, inteMod2, wisMod2, chaMod2;
	
	srand(time(NULL));
	
	FILE*CharacterSheet;
	FILE*CharacterName;
	
	age = 0;
	a = 0;
	kk = 'g';
	
	conMod = 0;
	strMod = 0;
	dexMod = 0;
	intMod = 0;
	wisMod = 0;
	chaMod = 0;
	
	CharacterSheet = fopen("CharacterSheet.txt" , "w");
	fclose(CharacterSheet);
	
	do
	{
		
		ls = 1;
		rr = racialRoll(ls);
		gr = genderRoll(ls);
		age = ageRoll(rr);	
		
		for(a = 0; a < 6; a++)
		{
			if (a == 0)
			{
				Str = statRoll(ls);
				if (rr == 33 ||rr == 7 || rr == 32)
				{
					Str = Str + 4;
				}else if (rr == 14 || rr == 18 || rr == 26 || rr == 5 || rr == 4 || rr == 8 || rr == 41 || rr == 46)
				{
					Str = Str - 2;
				}else if (rr == 35 || rr == 20 || rr == 45)
				{
					Str = Str + 2;
				}else if (ranRaceBonus == 1)
				{
					Str = Str + 2;
				}else if (rr == 33 || rr == 34 || rr == 25)
				{
					Str = Str + 6;
				}else if (rr == 30)
				{
					Str = Str + 4;					
				}else if (rr == 48 || rr == 27)
				{				
					if (age > 0 && age <= 2)
					{
						Str = Str;
					}else if (age > 2 && age <= 5)
					{
						Str = Str + 4;
					}else if (age > 5 && age <= 25)
					{
						Str = Str + 8;
					}else if (age > 25 && age <= 50)
					{
						Str = Str + 10;
					}else if (age > 50 && age <= 100)
					{
						Str = Str + 12;
					}else if (age > 100 && age <= 200)
					{
						Str = Str + 14;
					}else if (age > 200 && age <= 400)
					{
						Str = Str + 16;
					}else if (age > 400 && age <= 600)
					{
						Str = Str + 18;
					}else if (age > 600 && age <= 800)
					{
						Str = Str + 20;
					}else if (age > 800 && age <= 1000)
					{
						Str = Str + 22;
					}else if (age > 1000 && age <= 1200)
					{
						Str = Str + 24;
					}else if (age > 1200)
					{
						Str = Str + 26;
					}
						
				}else if (rr == 40)
				{
					Str = Str - 4;
				}
				//printf("\nStrength is: %i" , Str);
				strMod2 = (Str - 10) / 2;
				Str2 = Str;
				//printf("\n(strMod is = %i)" , strMod);
			}else if (a == 1)
			{			
				Dex = statRoll(ls);
				if (rr == 2 || rr == 31 || rr == 34 || rr == 15 || rr == 39 || rr == 40 || rr == 41 || rr == 42 || rr == 44 || rr == 46 || rr == 12 || rr == 13 || rr == 14 || rr == 22 || rr == 18 || rr == 19 || rr == 23 || rr == 24 || rr == 26 || rr == 4 || rr == 10 || rr == 11 || rr == 37 || rr == 38)
				{
					Dex = Dex + 2;
				}else if (ranRaceBonus == 2)
				{
					Dex = Dex + 2;
				}else if (rr == 48 || rr == 27)
				{
					if (age >= 0 && age < 2)
					{
						Dex = Dex;
					}else if (age >= 2 && age < 25)
					{
						Dex = Dex - 2;
					}else if (age >= 25 && age < 400)
					{
						Dex = Dex - 4;
					}else if (age >= 400 && age < 1000)
					{
						Dex = Dex - 6;
					}else if (age >= 1000)
					{
						Dex = Dex - 8;
					}
						
				}else if (rr == 8)
				{
					Dex = Dex + 4;
				}
				//printf("\nDexterity is: %i" , Dex);
				dexMod2 = (Dex - 10) / 2;
				Dex2 = Dex;
				//printf("\n(dexMod is = %i)" , dexMod);
			}else if (a == 2)
			{
				
				Con = statRoll(ls);
				if (rr == 3 || rr == 17 || rr == 19 || rr == 21 || rr == 5 || rr == 33 || rr == 34 || rr == 25 || rr == 38 || rr == 30)
				{
					Con = Con + 2;
				}else if (rr == 2 || rr == 12 || rr == 16 || rr == 11 || rr == 28 || rr == 29 || rr == 31 || rr == 37 || rr == 40 || rr == 42 || rr == 43)
				{
					Con = Con - 2;
				}else if (ranRaceBonus == 3)
				{
					Con = Con + 2;
				}else if (rr == 48 || rr == 27)
				{
					if (age >= 0 && age < 2)
					{
						Con = Con;
					}else if (age >= 2 && age < 5)
					{
						Con = Con + 2;
					}else if (age >= 5 && age < 25)
					{
						Con = Con + 4;
					}else if (age >= 25 && age < 100)
					{
						Con = Con + 6;
					}else if (age >= 100 && age < 400)
					{
						Con = Con + 8;
					}else if (age >= 400 && age < 800)
					{
						Con = Con + 10;
					}else if (age >= 800 && age < 1200)
					{
						Con = Con + 12;
					}else if (age >= 1200)
						Con = Con + 14;
				}			
				//printf("\nConstitution is: %i" , Con);
				conMod2 = (Con - 10) / 2;
				Con2 = Con;
				//printf("\n(conMod is = %i)" , conMod);
			}else if (a == 3)
			{
				
				Inte = statRoll(ls);
				if (rr == 12 || rr == 13 || rr == 24 || rr == 2 || rr == 28 || rr == 29 || rr == 31 || rr == 41 || rr == 43)
				{
					Inte = Inte + 2;
				}else if (ranRaceBonus == 4)
				{
					Inte = Inte + 2;
				}else if (rr == 7 || rr == 20 || rr == 32 || rr == 34 || rr == 25 || rr == 45)
				{
					Inte = Inte - 2;
				}else if (rr == 33)
				{
					Inte = Inte - 4;
				}else if (rr == 48 || rr == 27)
				{				
					if (age > 0 && age <= 2)
					{
						Inte = Inte;
					}else if (age > 2 && age <= 25)
					{
						Inte = Inte + 2;
					}else if (age > 25 && age <= 100)
					{
						Inte = Inte + 4;
					}else if (age > 100 && age <= 400)
					{
						Inte = Inte + 6;
					}else if (age > 400 && age <= 800)
					{
						Inte = Inte + 8;
					}else if (age > 800 && age <= 1200)
					{
						Inte = Inte + 10;
					}else if (age > 1200)
					{
						Inte = Inte + 12;
					}
						
				}
				Inte2 = Inte;
				//printf("\nIntelligence is: %i" , Inte);
				inteMod2 = (Inte - 10) / 2;
				//printf("\n(intMod is = %i)" , intMod);
			}else if (a == 4)
			{
				
				Wis = statRoll(ls);
				if (rr == 3 || rr == 35 || rr == 14 || rr == 22 || rr == 16 || rr == 21 || rr == 26 || rr == 29 || rr == 36 || rr == 42 || rr == 43 || rr == 46)
				{
					Wis = Wis + 2;
				}else if (ranRaceBonus == 5)
				{
					Wis = Wis + 2;
				}else if (rr == 10 || rr == 15 || rr == 7 || rr == 17 || rr == 23 || rr == 24 || rr == 32 || rr == 34 || rr == 38)
				{
					Wis = Wis - 2;
				}else if (rr == 33)
				{
					Wis = Wis - 4;
				}else if (rr == 48 || rr == 27)
				{				
					if (age > 0 && age <= 2)
					{
						Wis = Wis;
					}else if (age > 2 && age <= 25)
					{
						Wis = Wis + 2;
					}else if (age > 25 && age <= 100)
					{
						Wis = Wis + 4;
					}else if (age > 100 && age <= 400)
					{
						Wis = Wis + 6;
					}else if (age > 400 && age <= 800)
					{
						Wis = Wis + 8;
					}else if (age > 800 && age <= 1200)
					{
						Wis = Wis + 10;
					}else if (age > 1200)
					{
						Wis = Wis + 12;
					}
						
				}
				//printf("\nWisdom is: %i" , Wis);
				wisMod2 = (Wis - 10) / 2;
				Wis2 = Wis;
				//printf("\n(wisMod is = %i)" , wisMod);
			}else if (a == 5)
			{
				
				Cha = statRoll(ls);
				if (rr == 15 || rr == 16 || rr == 17 || rr == 18 || rr == 19 || rr == 23 || rr == 5 || rr == 4 || rr == 10 || rr == 11 || rr == 20 || rr == 28 || rr == 25 || rr == 36 || rr == 37 || rr == 38 || rr == 45)
				{
					Cha = Cha + 2;
				}else if (rr == 7 || rr == 35 || rr == 13 || rr == 22 || rr == 3 || rr == 32 || rr == 33 || rr == 34 || rr == 8 || rr == 44)
				{
					Cha = Cha - 2;
				}else if (rr == 21 || rr == 46)
				{
					Cha = Cha - 4;
				}else if (ranRaceBonus == 6)
				{
					Cha = Cha + 2;
				}else if (rr == 48 || rr == 27)
				{				
					if (age > 0 && age <= 2)
					{
						Cha = Cha;
					}else if (age > 2 && age <= 25)
					{
						Cha = Cha + 2;
					}else if (age > 25 && age <= 100)
					{
						Cha = Cha + 4;
					}else if (age > 100 && age <= 400)
					{
						Cha = Cha + 6;
					}else if (age > 400 && age <= 800)
					{
						Cha = Cha + 8;
					}else if (age > 800 && age <= 1200)
					{
						Cha = Cha + 10;
					}else if (age > 1200)
					{
						Cha = Cha + 12;
					}
						
				}
				//printf("\nCharisma is: %i" , Cha);
				chaMod2 = (Cha - 10) / 2;
				Cha2 = Cha;
				//printf("\n(chaMod is = %i)" , chaMod);
			}
		}
		int u = 1;
		int k, l;
		int bonusPts = 0;
		
		system("cls");
		
		do
		{			
			
			if (ls > 3)
			{
				bonusPts = 1;
				for (s = 8; s <= ls; s += 4)
				{
					bonusPts = bonusPts + 1;
				}			
			}
			do
			{
				//printf("\nu at start is %i\n" , u);
				if (bonusPts > 0)
				{
					strMod2 = ((float)Str2 - 10) / 2;
					dexMod2 = ((float)Dex2 - 10) / 2;
					conMod2 = ((float)Con2 - 10) / 2;
					inteMod2 = ((float)Inte2 - 10) / 2;
					wisMod2 = ((float)Wis2 - 10) / 2;
					chaMod2 = ((float)Cha2 - 10) / 2;
					//printf("\nstr is %i\n" , Str2);
					//printf("\nstrMod2 is %f\n" , strMod2);
					//printf("\nstrMod is %i\n" , strMod);
					if (Str2 <= 10)
					{
						strMod = round(strMod2);
					}else if(Str2 > 10)
					{
						strMod = (int)strMod2;
					}
					if (Dex2 <= 10)
					{
						dexMod = round(dexMod2);
					}else if(Dex2 > 10)
					{
						dexMod = (int)dexMod2;
					}
					if (Con2 <= 10)
					{
						conMod = round(conMod2);
					}else if(Con2 > 10)
					{
						conMod = (int)conMod2;
					}
					if (Inte2 <= 10)
					{
						intMod = round(inteMod2);
					}else if(Inte2 > 10)
					{
						intMod = (int)inteMod2;
					}
					if (Wis2 <= 10)
					{
						wisMod = round(wisMod2);
					}else if(Wis2 > 10)
					{
						wisMod = (int)wisMod2;
					}
					if (Cha2 <= 10)
					{
						chaMod = round(chaMod2);
					}else if(Cha2 > 10)
					{
						chaMod = (int)chaMod2;
					}
					system("cls");
					printf("\nStrength is:            %i\n" , Str2);
					printf("--Strength Mod is:      %i\n" , strMod);
					printf("Dexterity is:           %i\n" , Dex2);
					printf("--Dexterity Mod is:     %i\n" , dexMod);
					printf("Constitution is:        %i\n" , Con2);
					printf("--Constitution Mod is:  %i\n" , conMod);
					printf("Intelligence is:        %i\n" , Inte2);
					printf("--Intelligence Mod is:  %i\n" , intMod);
					printf("Wisdom is:              %i\n" , Wis2);
					printf("--Wisdom Mod is:        %i\n" , wisMod);
					printf("Charisma is:            %i\n" , Cha2);
					printf("--Charisma Mod is:      %i\n" , chaMod);
					printf("\nYou have %i bonus attribute point(s) to allocate.\n" , bonusPts);
					printf("Please select an attribute to raise by one point.\n");
					if (u == 1)
					{
						printf("\n*          >>>> Random <<<<            *\n");
						printf("*               Strength               *\n");
						printf("*               Dexterity              *\n");
						printf("*               Constitution           *\n");
						printf("*               Intelligence           *\n");
						printf("*               Wisdom                 *\n");
						printf("*               Charisma               *\n");
						
						k = 1;
					}else if (u == 2)
					{
						printf("\n*               Random                 *\n");
						printf("*          >>>> Strength   <<<<        *\n");
						printf("*               Dexterity              *\n");
						printf("*               Constitution           *\n");
						printf("*               Intelligence           *\n");
						printf("*               Wisdom                 *\n");
						printf("*               Charisma               *\n");
						
						k = 2;
					}else if (u == 4)
					{
						printf("\n*               Random                 *\n");
						printf("*               Strength               *\n");
						printf("*               Dexterity              *\n");
						printf("*          >>>> Constitution <<<<      *\n");
						printf("*               Intelligence           *\n");
						printf("*               Wisdom                 *\n");
						printf("*               Charisma               *\n");
						
						k = 4;
					}else if (u == 5)
					{
						printf("\n*               Random                 *\n");
						printf("*               Strength               *\n");
						printf("*               Dexterity              *\n");
						printf("*               Constitution           *\n");
						printf("*          >>>> Intelligence <<<<      *\n");
						printf("*               Wisdom                 *\n");
						printf("*               Charisma               *\n");
						
						k = 5;
					}else if (u == 6)
					{
						printf("\n*               Random                 *\n");
						printf("*               Strength               *\n");
						printf("*               Dexterity              *\n");
						printf("*               Constitution           *\n");
						printf("*               Intelligence           *\n");
						printf("*          >>>> Wisdom <<<<            *\n");
						printf("*               Charisma               *\n");
						
						k = 6;
					}else if (u == 7)
					{
						printf("\n*               Random                 *\n");
						printf("*               Strength               *\n");
						printf("*               Dexterity              *\n");
						printf("*               Constitution           *\n");
						printf("*               Intelligence           *\n");
						printf("*               Wisdom                 *\n");
						printf("*          >>>> Charisma <<<<          *\n");
						
						k = 7;
					}else if (u == 3)
					{
						printf("\n*               Random                 *\n");
						printf("*               Strength               *\n");
						printf("*          >>>> Dexterity <<<<         *\n");
						printf("*               Constitution           *\n");
						printf("*               Intelligence           *\n");
						printf("*               Wisdom                 *\n");
						printf("*               Charisma               *\n");
						
						k = 3;
					}else if (u == 404)
					{
						if (k == 1)
						{
							l = rand() % 6 + 1;
							if (l == 1)
							{
								printf("\nStrength!\n");
								Sleep(750);
								Str2 = Str2 + 1;
								bonusPts = bonusPts - 1;
								aa = 1;
							}else if (l == 2)
							{
								printf("\nDexterity!\n");
								Sleep(750);
								Dex2 = Dex2 + 1;
								bonusPts = bonusPts - 1;
								aa = 1;
							}else if (l == 3)
							{
								printf("\nConstitution!\n");
								Sleep(750);
								Con2 = Con2 + 1;
								bonusPts = bonusPts - 1;
								aa = 1;
							}else if (l == 4)
							{
								printf("\nIntelligence!\n");
								Sleep(750);
								Inte2 = Inte2 + 1;
								bonusPts = bonusPts - 1;
								aa = 1;
							}else if (l == 5)
							{
								printf("\nWisdom!\n");
								Sleep(750);
								Wis2 = Wis2 + 1;
								bonusPts = bonusPts - 1;
								aa = 1;
							}else if (l == 6)
							{
								printf("\nCharisma!\n");
								Sleep(750);
								Cha2 = Cha2 + 1;
								bonusPts = bonusPts - 1;
								aa = 1;
							}
							u = 1;
						}else if (k == 7)
						{
							Cha2 = Cha2 + 1;
							bonusPts = bonusPts - 1;
							aa = 1;
							u = 7;
						}else if (k == 6)
						{
							Wis2 = Wis2 + 1;
							bonusPts = bonusPts - 1;
							aa = 1;
							u = 6;
						}else if (k == 5)
						{
							Inte2 = Inte2 + 1;
							bonusPts = bonusPts - 1;
							aa = 1;
							u = 5;
						}else if (k == 4)
						{
							Con2 = Con2 + 1;
							bonusPts = bonusPts - 1;
							aa = 1;
							u = 4;
						}else if (k == 3)
						{
							Dex2 = Dex2 + 1;
							bonusPts = bonusPts - 1;
							aa = 1;
							u = 3;
						}else if (k == 2)
						{
							Str2 = Str2 + 1;
							bonusPts = bonusPts - 1;
							aa = 1;						
							u = 2;
						}
					}
					//printf("\nu is %i\n" , u);
					if (aa != 1)
					{
						mn = 1;
						mx = 7;
						u = menuArrows(u, mn, mx);
					}
					//printf("\nu after is %i\n" , u);
					system("cls");
					aa = 2;
					
				}
				
			}while(bonusPts > 0);
			
			strMod2 = ((float)Str2 - 10) / 2;
			dexMod2 = ((float)Dex2 - 10) / 2;
			conMod2 = ((float)Con2 - 10) / 2;
			inteMod2 = ((float)Inte2 - 10) / 2;
			wisMod2 = ((float)Wis2 - 10) / 2;
			chaMod2 = ((float)Cha2 - 10) / 2;
			//printf("str is %i" , Str);
			//printf("strMod2 is %f" , strMod2);
			//printf("strMod is %i" , strMod);
			if (Str2 <= 10)
			{
				strMod = round(strMod2);
			}else if(Str > 10)
			{
				strMod = (int)strMod2;
			}
			if (Dex2 <= 10)
			{
				dexMod = round(dexMod2);
			}else if(Dex > 10)
			{
				dexMod = (int)dexMod2;
			}
			if (Con2 <= 10)
			{
				conMod = round(conMod2);
			}else if(Con2 > 10)
			{
				conMod = (int)conMod2;
			}
			if (Inte2 <= 10)
			{
				intMod = round(inteMod2);
			}else if(Inte2 > 10)
			{
				intMod = (int)inteMod2;
			}
			if (Wis2 <= 10)
			{
				wisMod = round(wisMod2);
			}else if(Wis2 > 10)
			{
				wisMod = (int)wisMod2;
			}
			if (Cha2 <= 10)
			{
				chaMod = round(chaMod2);
			}else if(Cha2 > 10)
			{
				chaMod = (int)chaMod2;
			}
			printf("\nStrength is:            %i\n" , Str2);
			printf("--Strength Mod is:      %i\n" , strMod);
			printf("Dexterity is:           %i\n" , Dex2);
			printf("--Dexterity Mod is:     %i\n" , dexMod);
			printf("Constitution is:        %i\n" , Con2);
			printf("--Constitution Mod is:  %i\n" , conMod);
			printf("Intelligence is:        %i\n" , Inte2);
			printf("--Intelligence Mod is:  %i\n" , intMod);
			printf("Wisdom is:              %i\n" , Wis2);
			printf("--Wisdom Mod is:        %i\n" , wisMod);
			printf("Charisma is:            %i\n" , Cha2);
			printf("--Charisma Mod is:      %i\n" , chaMod);	
			yn = 1;
			ny = 1;
			if (ls > 3)
			{
				//kk = 'g';
				do
				{
					dd = 1;
					system("cls");
					printf("\nStrength is:            %i\n" , Str2);
					printf("--Strength Mod is:      %i\n" , strMod);
					printf("Dexterity is:           %i\n" , Dex2);
					printf("--Dexterity Mod is:     %i\n" , dexMod);
					printf("Constitution is:        %i\n" , Con2);
					printf("--Constitution Mod is:  %i\n" , conMod);
					printf("Intelligence is:        %i\n" , Inte2);
					printf("--Intelligence Mod is:  %i\n" , intMod);
					printf("Wisdom is:              %i\n" , Wis2);
					printf("--Wisdom Mod is:        %i\n" , wisMod);
					printf("Charisma is:            %i\n" , Cha2);
					printf("--Charisma Mod is:      %i\n" , chaMod);
					printf("\nDo you want to re-allocate your bonus points?  Y/N\n");			
					
					if (yn == 2)
					{
						printf("  Yes <<<<\n");
						printf("  No      \n");
						gg = 1;						
					}else if (yn == 1)
					{
						printf("  Yes     \n");
						printf("  No  <<<<\n");
						gg = 2;						
					}else if (yn == 404)
					{
						if (gg == 2)
						{
							ny = 2;
							kk = 'g';
							dd = 2;
							Str = Str2;
							Dex = Dex2;
							Con = Con2;
							Wis = Wis2;
							Inte = Inte2;
							Cha = Cha2;	
						}else if (gg == 1)
						{
							dd = 2;			
							ny = 2;
							kk = 'y';
							Str2 = Str;
							Dex2 = Dex;
							Con2 = Con;
							Wis2 = Wis;
							Inte2 = Inte;
							Cha2 = Cha;	
						}
					}
					if (dd == 1)
					{
						mn = 1;
						mx = 2;
						yn = menuArrows(yn, mn, mx);
					}
					
				}while(ny == 1);	
				
				//fgets(userInp, 35, stdin);
				//sscanf(userInp, "%c" , &kk);
			}
		}while(kk == 'y' || kk == 'Y');
		
		cc = classChoice(ls);
		//printf("\nclass choice is %i\n" , cc);
		
		savingThrows(cc, ls, rr);
		baseAtkB(cc, ls);
		skillAssignments(ls, cc, rr);
		spellSlots(cc, ls);
		inputName();
	

	}while(gg == 'Y' || gg == 'y');
}


int itemLists()
{
	int fruArr[30], worldAr[100][100][14], a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, worldCell, formArr[200];	
	
	location = worldAr[xx][yy][zz];
	
	FILE*chaInven;
	
	chaInven = fopen("chaInven.txt" , "w");
	
	char raspArr[10] = { 'R','a','s','p','b','e','r','r','y','\0' };
	char banaArr[7] = { 'B','a','n','a','n','a','\0' };
	char bdfrArr[11] = { 'B','r','e','a','d','f','r','u','i','t','\0' };
	char cherArr[7] = { 'C','h','e','r','r','y','\0' };
	char figArr[4] = { 'F','i','g','\0' };
	char lifArr[11] = { 'L','i','f','e',' ','f','r','u','i','t','\0' };
	
	fruArr[0] = raspArr;
	fruArr[1] = banaArr;
	fruArr[2] = bdfrArr;
	fruArr[3] = cherArr;
	fruArr[4] = figArr;
	
	formArr[0] = rightArrows;
	formArr[1] = leftArrows;
	formArr[2] = fourspaces;
	
	printf("**************************************\n");
	printf("* Items:                             *\n");
	
	if (xx == 50 && yy == 50 && zz == 0)
	{
		b = 2;
		c = 2;
		
		if (e == a)
		{
			b = 0;
			c = 1;
			e = j;
		}
		
		for (a = 0; a <= 4; a++)
		{
			printf("*  %s %s %s  *\n" , formArr[c] fruArr[a] , formArr[b]);
		}
		
		int mn = 0;
		int mx = 4;
		
		e = menuArrows(e, mn, mx);
		
		if (e == 404)
		{
			
		}
		
		
	}
	
	
	
}

int optionsMenu(int no, int so, int ea, int we, int up, int down)
{
	char action[50], actIn[50], run;
	int sleep, useInp[35], scnChk, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, worldcell, worldAr[100][100][14], location, options;
	int optionsArr[50];
	
	x = 0;
	y = 0;
	z = 0;
	g = 0;
	worldcell = 0;
		
	char optionsheader[13] = { 'O','p','t','i','o','n','s',' ','a','r','e',':','\0' };
	char mveoption[5] = { 'M','o','v','e','\0' };
	char lookoption[5] = { 'L','o','o','k','\0' };
	char passtime[10] = { 'P','a','s','s',' ','T','i','m','e','\0' };
	char inventory[10] = { 'I','n','v','e','n','t','o','r','y','\0' };
	char charSheet[20] = { 'C','h','a','r','a','c','t','e','r',' ','S','h','e','e','t','\0' };
	char exitoption[5] = { 'E','x','i','t','\0' };
	
	optionsArr[0] = optionsheader;
	optionsArr[1] = mveoption;
	optionsArr[2] = lookoption;
	optionsArr[3] = passtime;
	optionsArr[4] = inventory;
	optionsArr[5] = charSheet;
	optionsArr[6] = exitoption;
	
	optionsArr[7] = thirteenspaces;
	optionsArr[8] = elevenspaces;
	optionsArr[9] = tenspaces;
	optionsArr[10] = ninespaces;
	optionsArr[11] = leftArrows;
	optionsArr[12] = rightArrows;
	optionsArr[13] = fourspaces;
	optionsArr[14] = threespaces;
	optionsArr[15] = twospaces;
	optionsArr[16] = sspace;
	optionsArr[17] = sixspaces;
	optionsArr[18] = nospace;
	optionsArr[19] = thirtyspaces;
	optionsArr[20] = sevenspaces;
	
	
	for (x = 0; x < 100; x++)
	{
		for (y = 0; y < 100; y++)
		{
			for (z = 0; z < 14; z++)
			{
				worldAr[x][y][z] = worldcell++;
				
			}
		}		
	}
	
	location = worldAr[xx][yy][zz];
	
	options = 1;
	run = 'y';
	
	options = 1;
	
	do
	{
		locations(location);
		//printf("\nlocation is %i\n" , location);
		//printf("\noptions is %i\n" , options);
		printf("****************************************\n"); //forty dots	
		//printf("* %s %s*\n" , optionsArr[19], optionsArr[20]); //forty spaces wide			
		printf("*   %s %s         *\n", optionsArr[0], optionsArr[7]);
		
		for (w = 1; w <= 6; w++)
		{					
			r = 13;
			s = 13;
			
			if (options == w)
			{
				a = options;
				r = 11;
				s = 12;
			}
			
			if (w == 1 || w == 2 || w == 6)
			{
				t = 8;
			}else if (w == 3 || w == 4)
			{
				t = 17;
			}else if (w == 5)
			{
				t = 18;
			}
	
			printf("*        %s %s %s %s    *\n", optionsArr[r], optionsArr[w], optionsArr[s], optionsArr[t]);
			//printf("r is %i" , r);
			//printf("s is %i" , s);
		}
		//printf("* %s %s*\n" , optionsArr[19], optionsArr[20]); //forty spaces wide
		printf("****************************************\n"); //forty dots
		printf(" The time is: %i:%i:%i on Day %i of Month %i, %i A.W.W. \n" , globalHour, globalMin, globalSec, globalDay, globalMo, globalYr);
		
		//printf("options are %i" , options);
		int mn = 1;
		int mx = 6;
		options = menuArrows(options, mn, mx);
		
		if (options == 404)
		{
			if (a == 1)
			{
				options = 1;
				system("cls");
				location = playerMove(no, so, ea, we, up, down);
				return (location);
			}else if (a == 2)
			{
				//system("cls");
				//lookAround(location);
				//itemLists(location);
				printf("Coming soon.");
				Sleep(500);
				options = 1;
			}else if (a == 3)
			{
				printf("Coming soon.");
				Sleep(500);
				options = 1;
			}else if (a == 4)
			{
				printf("Coming soon.");
				Sleep(500);
				options = 1;
			}else if (a == 5)
			{
				printf("Coming soon.");
				Sleep(500);
				options = 1;
			}else if (a == 6)
			{
				return(0);
			}
			options = 1;
			system("cls");			
		}
		
		system("cls");			

	}while (run == 'y' || run == 'Y');	
	
}

int playerMove(int no, int so, int ea, int we, int up, int down)
{
	char action[50], actIn[50], run;
	int sleep, useInp[35], scnChk, a, b, c, d, e, f, g, z, worldAr[100][100][14], location;
	
	d = 0;
	e = 0;
	f = 0;
	g = 0;
	z = 0;	
	
	for (d = 0; d < 100; d++)
	{
		for (e = 0; e < 100; e++)
		{
			for (f = 0; f < 14; f++)
			{
				worldAr[d][e][f] = z++;
				
			}
		}		
	}
	
	location = worldAr[xx][yy][zz];
	
	int movement = 1;
	run = 'y';
	a = 1;
	
	do
	{
		locations(location);
		
		if (movement == 1)
		{
			printf("* Movement:                                                       *\n");			
			printf("*  >>>> Go north                                                  *\n");
			printf("*       Go south                                                  *\n");
			printf("*       Go east                                                   *\n");
			printf("*       Go west                                                   *\n");
			printf("*       Go down                                                   *\n");
			printf("*       Go up                                                     *\n");
			printf("*       Back to Options                                           *\n");
			g = 1;
		}else if (movement == 2)
		{
			printf("* Movement:                                                       *\n");
			printf("*       Go north                                                  *\n");
			printf("*  >>>> Go south                                                  *\n");
			printf("*       Go east                                                   *\n");
			printf("*       Go west                                                   *\n");
			printf("*       Go down                                                   *\n");
			printf("*       Go up                                                     *\n");
			printf("*       Back to Options                                           *\n");
			g = 2;
		}else if (movement == 3)
		{
			printf("* Movement:                                                       *\n");
			printf("*       Go north                                                  *\n");
			printf("*       Go south                                                  *\n");
			printf("*  >>>> Go east                                                   *\n");
			printf("*       Go west                                                   *\n");
			printf("*       Go down                                                   *\n");
			printf("*       Go up                                                     *\n");
			printf("*       Back to Options                                           *\n");
			g = 3;
		}else if (movement == 4)
		{
			printf("* Movement:                                                       *\n");
			printf("*       Go north                                                  *\n");
			printf("*       Go south                                                  *\n");
			printf("*       Go east                                                   *\n");
			printf("*  >>>> Go west                                                   *\n");
			printf("*       Go down                                                   *\n");
			printf("*       Go up                                                     *\n");
			printf("*       Back to Options                                           *\n");
			g = 4;
		}else if (movement == 5)
		{
			printf("* Movement:                                                       *\n");
			printf("*       Go north                                                  *\n");
			printf("*       Go south                                                  *\n");
			printf("*       Go east                                                   *\n");
			printf("*       Go west                                                   *\n");
			printf("*  >>>> Go down                                                   *\n");
			printf("*       Go up                                                     *\n");
			printf("*       Back to Options                                           *\n");
			g = 5;
		}else if (movement == 6)
		{
			printf("* Movement:                                                       *\n");
			printf("*       Go north                                                  *\n");
			printf("*       Go south                                                  *\n");
			printf("*       Go east                                                   *\n");
			printf("*       Go west                                                   *\n");
			printf("*       Go down                                                   *\n");
			printf("*  >>>> Go up                                                     *\n");
			printf("*       Back to Options                                           *\n");
			g = 6;
		}else if (movement == 7)
		{
			printf("* Movement:                                                       *\n");
			printf("*       Go north                                                  *\n");
			printf("*       Go south                                                  *\n");
			printf("*       Go east                                                   *\n");
			printf("*       Go west                                                   *\n");
			printf("*       Go down                                                   *\n");
			printf("*       Go up                                                     *\n");
			printf("*  >>>> Back to Options                                           *\n");
			g = 7;
		}else if (movement == 13)
		{			
			if (g == 1)
			{
				if (no == 1)
				{
					yy = yy + 1;
				}else if (no == 0)
				{
					printf("\nYou can't go that way.\n");
					Sleep(250);
				}
			}else if (g == 2)
			{
				if (so == 1)
				{
					yy = yy - 1;
				}else if (so == 0)
				{
					printf("\nYou can't go that way.\n");
					Sleep(500);
				}
			}else if (g == 3)
			{
				if (ea == 1)
				{
					xx = xx + 1;
				}else if (ea == 0)
				{
					printf("\nYou can't go that way.\n");
					Sleep(500);
				}
				
			}else if (g == 4)
			{
				if (we == 1)
				{
					xx = xx - 1;
				}else if (we == 0)
				{
					printf("\nYou can't go that way.\n");
					Sleep(500);
				}
				
			}else if (g == 5)
			{
				if (down == 1)
				{
					zz = zz - 1;
				}else if (down == 0)
				{
					printf("\nYou can't go that way.\n");
					Sleep(500);
				}
				
			}else if (g == 6)
			{
				if (up == 1)
				{
					zz = zz + 1;;
				}else if (up == 0)
				{
					printf("\nYou can't go that way.\n");
					Sleep(500);
				}
				
			}else if (g == 7)
			{
				system("cls");
				return(location);
			}
			//system ("cls");
			location = worldAr[xx][yy][zz];
			return(location);
			
		}
		
		//printf("\npassed movement is %i\n" , movement);
		movement = moveMent(movement);
		//printf("\nend movement is %i\n" , movement);
		
		system ("cls");
		
	}while (run == 'y' || run == 'Y');
	
	
	//fgets(action, 35, stdin);
	
	//printf("\nact0 = %c\n" , action[0]);
	//printf("\nlocation is %i  %i  %i\n" , a, b, c);
	//printf("\nlocation is %i\n" , location);	
}


int thurstonOffice(void)
{
	char action[35], actIn[35];
		
	printf("Exit\n\n");
	
	fgets (actIn, 35, stdin);
	sscanf(actIn, "%s" , &action);	
	
}

int royalPharmacy(void)
{
	char action[35], actIn[35];
		
	printf("Exit\n\n");
	
	fgets (actIn, 35, stdin);
	sscanf(actIn, "%s" , &action);	
}

int lookAround()
{
	if (xx == 50 && yy == 50 && zz == 0)
	{
		printf("The castle keep is dusty, and the sound of the nearby floodgates reverberates through the western wall.");
		printf("Around you is:");
		
	}
	
}

int locations()
{	
	//here = location;
	
	if (xx == 50 && yy == 50 && zz == 0)
	{
		//do
		//{
		//printf********************************************************************************************************************************************************************************************************\n");
		printf("You are outside the Main Door of the Dragon Fortress of Morania, within the Royal Keep.\nThe natural basalt stone of the pluton towers over the shaped stone pillar entryway,\ndwarfing even the mighty trees of the jungle.\n");
		printf("Higher up, the natural stone gives way to shaped stone blocks of the reinforced Fortress walls,\nlined with battlements and towers armed with arrays of munitions.\n");
		printf("Further up beyond that, a microcosm of the surrounding jungle took root,\nand has been enclosed by further protective walls to form the Green Crown of the Fortress.\n");
		printf("Grand green and purple draperies emblazoned with the sigil of the dragons hang around the nearly seamless stonework.\n");
		printf("The inner walls loom around you, cornered with towers topped by Morania-made Gatling guns.\nTo the north, the entrance to the cavernous halls of the Fortress lies dark and waiting.\n");
		printf("To the south, the gate to the rest of Morania is held open and ready.\n");
		
		
	}else if (xx == 50 && yy == 51 && zz == 0)
	{
		
		printf("You are within the entry hall of the Dragon Fortress.\nThe heraldry of the dragons is in much evidence, and numerous alcoves have been carved and filled with statues and gifts from worshippers.\n");
		printf("Around you are halls leading throughout the Fortress.\n");
		printf("To the north are the halls leading into the servant and worshipper living areas.\nTo the east is the feasting hall and kitchens.\n");
		printf("To the west are the bathrooms and river access.\nTo the south is the Main Entrance.\n");
		printf("A broad, split staircase curves its way upwards just ahead of you, leading to the upper halls.");
		
		
	}else if (xx == 50 && yy == 52 && zz == 0)
	{
		printf("Within the halls of the Fortress, you come to branching hallways of relatively humble doors.\nNotably, these doors often seem meant for medium sized humanoids,\nthough a large one nearby seems more accomodating.\n");
		printf("Hallways stretch to your east and west.\n");
		
	}else if (xx == 50 && yy == 49 && zz == 0)
	{				
		printf("The tropical climate of the southern edge of the Island Belt blurs the air around you,\nand the clamor of jungle life creates a racket even this deep into town.\n");				
		printf("The agrarian jungle town of Morania is further along as the road turns east.\nThe hustle and bustle of a freshly prosperous boom town echoes throughout the space the Moranian's\nhave carved into the dense forest.\n");
		printf("To the north, the Main Entrance to the Fortress rises and gives way to the natural stone of the titanic pluton\nthat makes up the bulk of the stone structure.\n");
		printf("Sunlight glints off the steel barrels of several repeating cannons defending the towers around the Entrance,\nand a guard idly glances your way.\n");
		printf("Directly south is the wall of the Cult of Morana temple compound;\nyou can just see the glow of their life fruit gardens.\n");
		printf("It'd be rude to just scale a wall into a public space with a perfectly good front door, however.\n");
		printf("Not far to the west, you can see the levy ditch of the Morana River,\nthe torrential crashing of water drowning out most other sounds\nas the river spills forth from its underground source inside the Fortress.\n");
		printf("The water blasts from a grated opening in the bulky structure of the arcane hydroelectric facility\nthat provides electricity to the town of Morania.\nThe facility is plated with armor and inaccessible from the outside.\n");
		printf("Signs indicate you are on Fortress Road.\n");
		printf("To the north is the Fortress Entry Keep.\n");
		printf("To the east, the road into downtown Morania continues.\n");
		
		
	}else if (xx == 51 && yy == 49 && zz == 0)
	{
		printf("You reach a four-way intersection along the crossroads of inner Morania.\n");
		printf("To the north runs a neatly trimmed pathway to the entrance of the Embassy,\na staging place for all foreign diplomatic matters for the King and Queen.\n");
		printf("Hewn into the side of the plutonic Fortress itself,\nthe Embassy is capable of lavishly accomodating numerous long term guests for various negotiations.\n");
		printf("To the east lies the Guild Road, which in addition to Guilds and some retail shops,\nis interspersed with intersections leading to the paths to various other Fortress-side locations.\n");
		printf("Turning south through the intersection,\nthe Fortress Road runs south alongside the Cult Temple wall,\nand further into the inner city of Morania.\n");
		printf("On the south-east corner of the intersection is Doctor Thurston's Non-Magical Medical Care.\n");
		
	}else if (xx == 51 && yy == 50 && zz == 0)
	{
		printf("You are outside the Embassy.  The stone ediface of the entrance has been magically shaped from the stone of the Fortress pluton itself.\n");
		
	}else if (xx == 51 && yy == 48 && zz == 0)
	{
		printf("You are traveling the roads of inner Morania,\nand reach the three-way intersection of Fortress Road and Main Street.\nTo your west is the garden wall of the Cult Temple.\n");
		printf("The wall is solid, though a small, polite sign indicates public entry through the Temple itself.\n");				
		printf("Along Main Street are blocks of shops, restaurants, and more.\nThere is a relatively continuous hustle and bustle as islanders and visitors to Morania meander through the shopping district.\n");
		printf("Fortress Road travels north and south, while Main Street runs east and leads deeper into downtown Morania.\n");
		printf("To your north-east is the Moranian Royal Pharmacy.\nTo your south-east is the Morania Blacksmith.\n");
		
	}else if (xx == 51 && yy == 47 && zz == 0)
	{
		printf("You come to an uneven four-way intersection, with the roads heading east and west offset from one another.\n");
		printf("Bridge Road leads to the west.\n");
	}
}

int main(void)
{	
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, z, y, x, no, so, we, ea, up, down, location, scnChk, worldCell;
	int worldAr[100][100][14], mainArray[50];
	char action[10], start[5], staCha;
	char run = 'y';
	char running = 'y';
	
	mainArray[0] = menuYes;
	mainArray[1] = menuNo;
	mainArray[2] = fourspaces;
	mainArray[3] = twospaces;
	mainArray[4] = threespaces;
	mainArray[5] = leftArrows;
	mainArray[6] = rightArrows;
	
	worldCell = 0;
	
	for (x = 0; x < 100; x++)
	{
		for (y = 0; y < 100; y++)
		{
			for (z = 0; z < 14; z++)
			{
				worldAr[x][y][z] = worldCell++;
				
			}
		}		
	}
	
	xx = 50;
	yy = 50;
	zz = 0;
	
	location = worldAr[xx][yy][zz];
	
	e = 0;	
				
	do //intro
	{
		
		printf("Welcome to Morania.\n");
		printf("Do you want to go exploring?\n");
		b = 2;
		c = 2;
		
		for (a = 0; a <= 1; a++)
		{
			if (e == a)
			{
				d = e;
				b = 5;
				c = 6;
			}else if (e != a)
			{
				d = e;
				b = 2;
				c = 2;
			}
			printf("%s %s %s\n", mainArray[b], mainArray[a], mainArray[c]);
			//printf("\ne is %i" , e);
			//printf("\na is %i" , a);
		}
		int mn = 0;
		int mx = 1;				
		e = menuArrows(e, mn, mx);
		
		if (e == 404)
		{
			if (d == 0)
			{
				running = 'g';
			}else if (d == 1)
			{
				return (0);
			}
		}
		system("cls");	
	}while (running == 'y');
	
	characterGenerator();
		
	do
	{
		if (location == worldAr[50][50][0])
		{				
			no = 1;
			so = 1;
			ea = 0;
			we = 0;
			up = 0;
			down = 0;
			location = optionsMenu(no, so, ea, we, up, down);
			system("cls");
			//system ("cls");				
			//}while(run == 'y' || run == 'Y');
			//printf("\nlocation is %i\n" , location);
			//printf("\nlocation is %i  %i  %i\n" , a, b, c);
			
		}else if (location == worldAr[50][51][0])
		{
			
			no = 1;
			so = 1;
			ea = 1;
			we = 1; 
			up = 0;
			down = 0;
			location = optionsMenu(no, so, ea, we, up, down);
			system("cls");
			//printf("\nlocation is %i\n" , location);
			//printf("\nlocation is %i  %i  %i\n" , a, b, c);
			
		}else if (location == worldAr[50][52][0])
		{
			no = 0;
			so = 1;
			ea = 0;
			we = 0;
			up = 0;
			down = 0;
			location = optionsMenu(no, so, ea, we, up, down);
			system("cls");
			//printf("\nlocation is %i\n" , location);
			
		}else if (location == worldAr[50][49][0])
		{				
			no = 1;
			so = 0;
			ea = 1;
			we = 1; //river here
			up = 0;
			down = 0;
			location = optionsMenu(no, so, ea, we, up, down);
			system("cls");
			//printf("\nlocation is %i\n" , location);
			//printf("\nlocation is %i  %i  %i\n" , a, b, c);
			
		}else if (location == worldAr[51][49][0])
		{
			no = 1;
			so = 1;
			ea = 1;
			we = 1;
			up = 0;
			down = 0;
			location = optionsMenu(no, so, ea, we, up, down);
			system("cls");
			//printf("\nlocation is %i\n" , location);
			//printf("\nlocation is %i  %i  %i\n" , a, b, c);
	
		}else if (location == worldAr[51][50][0])
		{
			no = 0;
			so = 1;
			ea = 0;
			we = 0;
			up = 0;
			down = 0;
			location = optionsMenu(no, so, ea, we, up, down);
			system("cls");
			//printf("\nlocation is %i\n" , location);
			//printf("\nlocation is %i  %i  %i\n" , a, b, c);
			
		}else if (location == worldAr[51][48][0])
		{
			no = 1;
			so = 1;
			ea = 1;
			we = 0;
			up = 0;
			down = 0;
			location = optionsMenu(no, so, ea, we, up, down);
			system("cls");
		}else if (location == worldAr[51][47][0])
		{
			no = 1;
			so = 1;
			ea = 1;
			we = 1;
			up = 0;
			down = 0;
			location = optionsMenu(no, so, ea, we, up, down);
			system("cls");
		}

	}while (run == 'y' || run == 'Y');
	
	
	
	return(0);
 
}
