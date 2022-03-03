#include<iostream>
using namespace std;
struct Miles 
{
	int mile;
	Miles(int distmile)
	{
		mile = distmile;
	}
};

struct Kilometres
{
	int km;
	Kilometres(int km1)
	{
		km = km1;
	}
};

class Distance
{
private:
	int dist;

public:
	Distance(int distm)
	{
		dist = distm;
	}

	Distance()
	{
		dist = 0;
	}	

	Distance(Kilometres kilmet)
	{
		dist = kilmet.km * 1000;
	}

	Distance(Miles mildist)
	{
		dist = mildist.mile * 1609;
	}

	Distance& operator=(const Distance &right)
	{
		if (this == &right)
		{
			return *this;
		}
		else
		{
			dist = right.dist;
			return *this;
		}
	}

	Distance& operator+(const Distance& right)
	{
		Distance result;
		result.dist = this->dist + right.dist;
		return result;
 	}

	Distance& operator-(const Distance& right)
	{
		if (this->dist < right.dist)
		{
			cout << "ERROR. 1st number be nust bigger then 2nd";
		}
		else
		{
			Distance result;
			result.dist = this->dist - right.dist;
			return result;
		}
	}

	Distance& operator*(const int number)
	{
		Distance result;
		result.dist = this->dist * number;
		return result;
	}

	bool operator==(const Distance& right)
	{
		if (this->dist == right.dist)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const Distance& right)
	{
		if (this->dist == right.dist)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator>(const Distance& right)
	{
		if (this->dist > right.dist)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<(const Distance& right)
	{
		if (this->dist < right.dist)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<=(const Distance& right)
	{
		if (this->dist <= right.dist)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>=(const Distance& right)
	{
		if (this->dist > right.dist)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int ToMiles()
	{
		int m;
		m = dist / 1600;
		return m;
	}

	int ToKilometres()
	{
		int km;
		km = dist / 1000;
		return km;
	}


	void print()
	{
		std::cout << " Distance = " << this->dist << "(metres)\n";
	}

	//void printmiles()
	//{
	//	std::cout << "\nDistance = " << ToMiles(this) << "(miles)";
	//}

};

int main()
{
	Distance a(5000);
	Distance b(4000);
	Distance c = a + b;
	Distance d = a - b;
	//c = a + b;
	cout << "\na+b ";
	c.print();

	//c = a - b;
	cout << "\na-b ";
	c.print();

	c = a;
	cout << "\nc ";
	c.print();

	if (a == c) cout << "\na and c equal\n";
	if (a != b) cout << "\na and b not equal\n";
	if (a > b) cout << "\na bigger b\n";



	return 0;
}