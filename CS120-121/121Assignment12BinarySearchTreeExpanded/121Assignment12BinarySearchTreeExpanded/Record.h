/*This is the same record class used in the previous assignment,
except now it includes the data member for species.*/
class record {
public:
	string name, data;
	string species;
	record();
};

record::record()
{
	species = "";
	name = "";
	data = "";
}