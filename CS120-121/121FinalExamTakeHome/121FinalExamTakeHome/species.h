class specie
{
private:
	string name;
	int population;
	string status;

public:

	specie();
	void set(string, int, string);
	bool operator<(specie);

	friend ostream& operator<<(ostream&, const specie&);
};

specie::specie()
{
	name = "";
	population = 0;
	status = "";
}

void specie::set(string n, int p, string s)
{
	name = n;
	population = p;
	status = s;
}

/*Turned in.*/
/*Overloading < */
bool specie::operator<(specie s)
{	
	if (population < s.population)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*Overloading << */
ostream& operator<<(ostream& os, const specie& s)
{	
	os << s.name << " has a current population of " << s.population << " and is " << s.status << endl;

	return os;
}