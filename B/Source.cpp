#include<iostream>
using namespace std;

int main()
{	
	int year, year_copy;
	cin >> year;

	year_copy = year;

	int count_2 = 0, count_1 = 0, count_0 = 0;
	while (year_copy != 0)
	{
		if (year_copy % 10 == 0)
		{
			count_0++;
		}

		if (year_copy % 10 == 1)
		{
			count_1++;
		}

		if (year_copy % 10 == 2)
		{
			count_2++;
		}
		year_copy /= 10;
	}	

	if (count_0 == 1 && count_2 == 2 && count_1 == 1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

}