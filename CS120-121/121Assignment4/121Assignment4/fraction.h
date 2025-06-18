enum eC {fail, success, dividebyzero};

class fraction {
private:
	int num = 0, den = 0;
public:
	fraction(int, int);
	fraction();
	~fraction();
	eC set(int, int);
	void print();

	void reducifier(); //This is the extra credit function.

	fraction operator*(fraction);
	fraction operator*(int);
	friend fraction operator* (int,fraction);

	fraction operator+(fraction);
	fraction operator+(int);
	friend fraction operator+ (int, fraction);

	fraction operator-(fraction);
	fraction operator-(int);
	friend fraction operator- (int, fraction);
};

fraction::fraction()
{
	num = 1;
	den = 1;
}

fraction::~fraction()
{
	//cout << "Eliminating fraction: ";
	//print();
	//cout << endl;
}

fraction::fraction(int nu, int de)
{
	if (de == 0)
	{
		num = nu;
		de = 1;
		cout << "You tried to divide by zero!  Denominator set to 1." << endl;
	}
	else
	{
		num = nu;
		den = de;
	}
}

eC fraction::set(int nu, int de)
{
	if (de == 0)
	{
		num = nu;
		den = 1;
		cout << "You tried to divide by zero!" << endl;
		return dividebyzero;
	}
	else
	{
		num = nu;
		den = de;
	}
}

/*For the sake of cleanliness, print won't bother printing a fraction that
has a one on the bottom, and in that case will instead only print the numerator.*/
void fraction::print()
{
	if (den == 1)
	{
		cout << num;
	}
	else
	{
		cout << num << "/" << den;
	}
}

/*The fraction reducer uses the largest possible number that can result
from combining the denominator and numerator, then steps down from that
value one at a time to check each possible divisor.  Since this won't
fully reduce a fraction like 12/20 on a single pass due to ordering of
different divisors, a recursion is introduced to run this function 
repeatedly until fully reduced.*/
void fraction::reducifier()
{
	for (int i = den * num; i > 1; i--)
	{
		if (den % i == 0 && num % i == 0)
		{
			den = den / i;
			num = num / i;
			reducifier();
		}
	}
}


/***************************Multiplication**********************************/

fraction fraction::operator*(fraction f)
{
	fraction ans;

	ans.num = num * f.num;
	ans.den = den * f.den;

	ans.reducifier();

	return ans;
}

fraction fraction::operator*(int x)
{
	fraction ans;

	ans.num = num * x;
	ans.den = den * 1;

	ans.reducifier();

	return ans;
}

fraction operator*(int x, fraction f)
{
	fraction ans;

	ans.num = f.num * x;
	ans.den = f.den;

	ans.reducifier();

	return ans;
}

/*+++++++++++++++++++++++++++++++Addition++++++++++++++++++++++++++++++*/

fraction fraction::operator+(fraction f)
{
	fraction ans1, ans2;

	ans1.den = den * f.den;

	ans1.num = num * f.den;
	ans2.num = f.num * den;
	
	ans1.num = ans1.num + ans2.num;

	ans1.reducifier();

	return ans1;
}

fraction fraction::operator+(int x)
{
	fraction ans;

	ans.num = (x * den) + num;
	ans.den = den;

	ans.reducifier();

	return ans;
}

fraction operator+(int x, fraction y)
{	
	fraction ans;

	ans.num = (x * y.den) + y.num;
	ans.den = y.den;

	ans.reducifier();

	return ans;
}

/*----------------------------Subtraction----------------------------------*/

fraction fraction::operator-(fraction f)
{
	fraction ans1, ans2;

	ans1.den = den * f.den;

	ans1.num = num * f.den;
	ans2.num = f.num * den;

	ans1.num = ans1.num - ans2.num;

	ans1.reducifier();

	return ans1;
}

fraction fraction::operator-(int x)
{
	fraction ans;

	ans.num = num - (den * x);
	ans.den = den;

	ans.reducifier();

	return ans;
}

fraction operator-(int x, fraction y)
{
	fraction ans;

	ans.num = (x * y.den) - y.num;
	ans.den = y.den;

	ans.reducifier();

	return ans;
}

