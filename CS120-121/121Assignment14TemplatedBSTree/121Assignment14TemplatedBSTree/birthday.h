/*The second class requested by the assignment.
The birthday class will check if the day/month/year are valid
based on leap years, how many days are in each month, and the
maximum human lifespan.  If it finds a discrepency, it will
set that particular value to 1 (or year to 1970), rather than 
doing anything fancy.*/

class birthday
{
private:
	int day, month, year;
public:
	birthday();
	eC set(int, int, int);

	/*Inline print function.*/
	void print(){cout << month << "-" << day << "-" << year;};

	/*Assignment 14 overloads.*/
	bool operator>(birthday);
	bool operator<(birthday);
	bool operator==(birthday);
	bool operator!=(birthday);
	bool operator= (birthday);

};

birthday::birthday()
{
	day = 1;
	month = 1;
	year = 1970;
}

eC birthday::set(int d, int m, int y)
{
	/*First we check if we have a valid month.*/
	if (m < 1 || m > 12)
	{
		cout << "Invalid month, setting month to 1." << endl;
		month = 1;
	}
	else
	{
		month = m;
	}

	/*Then we check months that have 31 days.*/
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if (d < 1 || d > 31)
		{
			cout << "Invalid day, should be most 31, setting day to 1." << endl;
			day = 1;
		}
		else
		{
			day = d;
		}
	}

	/*Then we check months that have 30 days.*/
	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		if (d < 1 || d > 30)
		{
			cout << "Invalid day, should be most 30, setting day to 1." << endl;
			day = 1;
		}
		else
		{
			day = d;
		}
	}

	/*Then we check February.  This entire if-else block is just for February, as
	it has to check if the year is a leap year.
	Leap years occur with two rules:  Either a multiple of four, or it's
	a multiple of both 400 and 100.*/
	if (m == 2 && ((y % 4) == 0 || ((y % 100 == 0) && (y % 400 == 0))))
	{
		if (d < 1 || d > 29)
		{
			cout << "Invalid day, it's a leap year, setting day to 1." << endl;
			day = 1;
		}
		else
		{
			day = d;
		}
	}
	else if (m == 2 && !((y % 4) == 0 || ((y % 100 == 0) && (y % 400 == 0))))
	{
		if (d < 1 || d > 28)
		{
			cout << "Invalid day, it's not a leap year, setting day to 1." << endl;
			day = 1;
		}
		else
		{
			day = d;
		}
	}

	/*Last, we check if we even had a valid year to begin with.*/
	if (y <= 1902)  /*Oldest human on record was ~120 years old.*/
	{
		cout << "Invalid year, setting year to 1970." << endl;
		year = 1970;
	}
	else
	{
		year = y;
	}

	return success;
}


/*>>>>>>>>>>>>>>>>>>>>>>>>>Greater Than>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

bool birthday::operator>(birthday b)
{
	if (year > b.year)
	{
		return true;
	}
	else if (year == b.year)
	{
		if (month > b.month)
		{
			return true;
		}
		else if (month == b.month)
		{
			if (day > b.day)
			{
				return true;
			}
		}
	}
	return false;
}

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<Less Than<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

bool birthday::operator<(birthday b)
{
	if (year < b.year)
	{
		return true;
	}
	else if (year == b.year)
	{
		if (month < b.month)
		{
			return true;
		}
		else if (month == b.month)
		{
			if (day < b.day)
			{
				return true;
			}
		}
	}
	return false;
}

/*== == == == == == == == ==Is Equivalent To== == == == == == == == == == ==*/

bool birthday::operator==(birthday b)
{
	if (year == b.year && month == b.month && day == b.day)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*!=!=!=!=!=!=!=!=!=!=!=!=!=Does Not Equal!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=*/

bool birthday::operator!=(birthday b)
{
	if (year != b.year && month != b.month && day != b.day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*==========================Set Equal To================================*/

bool birthday::operator=(birthday b)
{
	day = b.day;
	month = b.month;
	year = b.year;

	return true;
}

