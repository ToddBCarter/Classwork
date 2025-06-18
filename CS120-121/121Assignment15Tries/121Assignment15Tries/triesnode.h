const int length = 26;

class node
{
private:
public:
	bool endofstr;
	node* children[length];

	node();

	/*Insert uses two functions.  One receives the string to be inserted
	and then passes its pieces along to the recursive function. */
	void nInsert(string);
	void nInsert(const char[], int, int);

	/*Print also uses two functions, one to receive the print command,
	and the other to recursively print out the trie.*/
	void nPrint();
	void nPrinter(string);

	/*These node functions correspond with their tries.h counterparts.*/
	bool nFind(string);
	int nCount();
};

node::node()
{
	endofstr = false;
	for (int i = 0; i < length; i++)
	{
		children[i] = NULL;
	}
}

/*A secondary function is used to take the string and break it
down into individual chars and the length, as well as passing
over the starting location in the trie of 0.*/
void node::nInsert(string s)
{
	nInsert(s.c_str(), s.length(), 0);
}

/*Insert uses the length of the string to be inserted to find
the endofstring location, and it converts each char of the string
into an ascii-relevant integer to determine their location.*/
void node::nInsert(const char sPiece[], int len, int dep)
{
	int asciiLoc = int(sPiece[dep]) - 97;

	/*First, check if this is the last string in the line.
	The asciiLoc value at this point is -97.*/
	if (len == dep)
	{
		endofstr = true;
		return;
	}

	if (children[asciiLoc] == NULL)
	{
		children[asciiLoc] = new node();
	}
	children[asciiLoc]->nInsert(sPiece, len, (dep + 1));
}

/*nPrint() relies on being able to pass a string to itself,
so to make that happen, a secondary function is used for
the initial print command to enable the recursion.*/
void node::nPrint()
{
	nPrinter("");
}

/*This version of print builds a string based on active members of the pointer
array.  The string has characters added using push_back which builds the string,
and then to allow for repeating letters, pop_back is used to remove the final
character from the string which reduces the string down to whatever letter the
for loop index is indicating.*/
void node::nPrinter(string s)
{
	int chk = 0;
	char d;

	if (endofstr == 1)  /*First, checking if an endofstring has been reached.*/
	{
		cout << s << endl;
	}
	for (int i = 0; i < length; i++)
	{
		d = 'a' + i;
		
		if (children[i] != NULL) 
		{
			s.push_back(d);
			children[i]->nPrinter(s);
			s.pop_back();		
		}
	}
}

/*Find uses a returning boolean chk variable to track
if an endofstring has been reached.  The string to be searched
for is recursively passed to the function, and each time a 
matching letter is found, the first character of the string
is removed.  Then, the chk variable will only become true
when both an end of string is encountered and when the string
has been completely erased, and chk is returned up the recursions.*/
bool node::nFind(string s)
{		
	char d;
	bool chk = 0;

	if (endofstr == 1 && s.length() == 0)
	{
		chk = 1;
	}
	for (int i = 0; i < length; i++)
	{
		if (children[i] != NULL)
		{
			d = char(i + 97);

			if (d == s[0])
			{
				s.erase(0, 1);
				chk = chk + children[i]->nFind(s);
			}
		}
	}
	return chk;
}

/*nCount uses a chk variable to keep track of how many
times the recursion has enountered an endofstring.  Chk is
only incremented when an endofstring is found and then is
returned up the recursions.*/
int node::nCount()
{
	int chk = 0;

	if (endofstr == 1)
	{
		chk++;
	}
	for (int i = 0; i < length; i++)
	{
		if (children[i] != NULL)
		{
			chk = chk + children[i]->nCount();
		}
	}
	return chk;
}



