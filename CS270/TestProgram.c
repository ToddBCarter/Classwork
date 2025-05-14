
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//#include<conio.h>  //No conio or windows.h on the school system :(
//#include<windows.h>  //Maybe make my own?
//#include<curses.h>  //Nope
//#include<ncurses.h>  //Not this either
#include<termios.h>

//nt raceCount = 35;
//int classCount = 30;

static struct termios old, current;

void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
int _myGetch(int echo)
{
   char ch;
   initTermios(echo);
   ch = getchar();
   resetTermios();
   return ch;
   
}

int myGetch(void)
{
   return _myGetch(0);
}

int _myGetch(void)
{
   return _myGetch(1);
}



/*Player class struct.  Should hold and update the data
for the player's class by way of its members.  This then
could allow the player to change class or have their class
be affected.*/
typedef struct playerClasses{
   uint classID;  //The ID of the requested class, corresponding to classNames[].
   uint attModOne, attModTwo;
   //int classCount;
   char* classNames[30];
   char* BonusList[];  //Only one flexible array per struct, because FU
   
  /* classNames[0] = "You picked WRONG";  //This all needs to go into a function
   classNames[1] = "Barbarian";     //Since data has to be added to an object after declaration
   classNames[2] = "Bard";  //This will be in an intialization function
   classNames[3] = "Cleric";
   classNames[4] = "Druid";
   classnames[5] = "Fighter";
   classNames[6] = "Monk";
   classNames[7] = "Paladin";
   classNames[8] = "Ranger";
   classNames[9] = "Rogue";
   classNames[10] = "Sorcerer";
   classNames[11] = "Wizard";
   classNames[12] = "Arcanist";
   classNames[13] = "Bloodrager";
   classNames[14] = "Brawler";
   classnames[15] = "Hunter";
   classNames[16] = "Investigator"
   classNames[17] = "Shaman";
   classNames[18] = "Skald";
   classNames[19] = "Slayer";
   classNames[20] = "Swashbuckler";
   classNames[21] = "Warpriest";
   classNames[22] = "Alchemist";
   classNames[23] = "Cavalier";
   classNames[24] = "Inquisitor";
   classNames[25] = "Oracle";
   classNames[26] = "Summoner";
   classNames[27] = "Witch";
   classNames[28] = "Randomize";
   */
   
   
   
   
	
}playerClass;



//Maybe the classes should be functions?
//Functions that modify the player?
//No, functions should modify the various structs being used by the player
//This would be better in C++, might stop this particular line of reasoning here.



/*This is the playable race struct.  It should contain all the
information for a playable race.
This may include NPC races and less standard races, though those
may be put into their own struct at some point.*/
typedef struct playerRaces{
   uint raceID;
   uint raceModOne, raceModTwo;
   //int raceCount;
   char* raceNames[35];
   char* BonusList[];
   
   
   
   
   
   
}playerRace;




//Player Character struct.  Should define and maintain
//everything needed for the player character specifically.
//There could also be an NPC struct if needed.
//This may also include functions of various types, such as one
//that will print out the character sheet.
typedef struct PlayerCharacters{
	//uint HP, Str, Dex, Con, Int, Wis, Cha;
	uint PCClassID;
	uint PCRaceID;
	//char *class[];
	//char *race[];  //Could there be a way to make a 
	//race struct that attaches to and modifies the player struct?
	//Same goes for class.

   playerClass PCclass;
   //PCclass = { .classID = 1 };  //Maybe like this
   playerRace PCRace;
   //PCRace = { .raceID = 1 };    //Access nested members with . and -> multiple times
	
}playerCharacter;



/*This should be the primary world cell struct.
These objects should make up the multidimensional array 
that will compose the world environment.
Other possibile vars:
	- NPCs, using the character structs
	- String array containing descriptions?
	- Data for the _getch function to read?*/
typedef struct worldCells{
   uint x;
   unit y;
   char*[] mapData;
 
}worldCell;




int main(int argc, char *argv[])
{
   long int x = 255;
   long int y = 255;
   long int z = 255;
   int run = 1;
   char test[y];
   worldCell worldMap[x][y][z];
   //printf("run is: %d", run);
   while (run == 1)
   {
      system("clear");
      //printf("Welcome to the game.  It is a gamelike game.  Here we go.\n\n");
      //printf("Would you like to play the game?\n");
      //printf("Please enter Y or N and hit enter.\n\n");
   
      //fgets (test, sizeof(test), stdin);  //correct syntax for fgets to take from command line
      //scanf("%s", test);
      //printf("\ntest[0] is: %c\n\n", test[0]);
	  
	  int testG;
	  
	  printf("\n\nrun is: %d\n\n", run);
	  
	  run = _getch();
	  
	  //printf("run is: %d", run);
	  
	  printf("\n\nrun is: %d\n", run);
	  run = run * (test[0] == 'Y'); //branchless lmao this one works
	  //The comparator might only be able to do a single character instead of a string
	  //run = run * (test == "yes"); //does not work, strings r bad
	  //This will be easier when using _getch()... probably.
	  
	  printf("\n\nrun is: %d\n\n", run);
      printf("Test is: %s\n\n", test);
	  
	  
	  //run = 0;
   }
   
   
	  //system("clear");  //This method of clearing only in stdlib
      //printf("system: clear\n"); //not sure if this actually worked, but maybe
   
   return 0;

void introSequence()
{
   //printf("Hello, welcome to the game\n\n");
   
   system("clear");
   printf("Welcome to the game.  It is a gamelike game.  Here we go.\n\n");
   printf("Would you like to play the game?\n");
   printf("Please enter Y or N and hit enter.\n\n");

   fgets (test, sizeof(test), stdin);  //correct syntax for fgets to take from command line
   //scanf("%s", test);
   printf("\ntest[0] is: %c\n\n", test[0]);
   
   int userInput = _getch(); //Check that this is meant to be an int, but probs
   //UP = 72, Down = 80, Left = 75, Right = 77
   
   //menuArrows(userInput);
   
   //Need to start figuring out the exact specs of the interface for this...
   //Maybe this time go with printed directional arrows?
   //Highlighting NSWE arrows might go slower...
   
   printf("userInput is: %d", userInput);
   
   
   
   
   
   
	  
	
}


void chooseClass()   //may need to take arguments
{

	char* classNames[];  //Only one flexible per, may not need here

   	
	
}


void moveArrows(int listLength, int columnNumber)
{
   int len = listLength;
   int col = columnNumber;
   
   


}



void displayInterface()
{
   int width = 100;
   int height = 50;
   for (int i = 0; i < width; i++)
   {
      printf("*");
   }
   printf("\n");
   
   


}