/*This is probably largely unneeded.
The nodes could handle carrying this
information just as well.  
Included just in case it's a requirement.*/
class record {
public:
	string name, data;
	record();
};

record::record()
{
	name = "";
	data = "";
}