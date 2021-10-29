#include<iostream>
#include<iomanip>

using namespace std;

int log10(int a)
{	
	int n = 1;
	while (a / 10 != 0)
	{
		n += 1;
		a /= 10;
	}
	return n;
}

int main()
{
	cout << "the program counts the number of digits" << endl << endl;

	int n, num1;
	cout << "Enter number " << endl;

	int num = 0;
	while (true)
	{
		cin >> num;
		if (!cin)
		{
			cout << "Enter invalid value" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}

	num1 = num;

	n = log10(num);
	cout << "n = " << n << endl;

	int* Array = new int[n];
	for (int i = 0; i < n; ++i)
	{
		Array[i] = num % 10;
		num = num/10;
	} 

	/*for (int i = 0; i < n / 2; ++i)
	{
		int tmp = Array[i];
		Array[i] = Array[n -1- i];	
		Array[n - 1 - i]= tmp;
	}*/

	
	cout << "Enter the digit of the number " << endl;
	int d = 0;
	while (true)
	{
		cin >> d;
		if (!cin)
		{
			cout << "Enter invalid value" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}


	if (d == pow(10, (log10(d) - 1)) && d<=num1)
	{
		cout << "Digit number of " << pow(10, (log10(d) - 1)) << " = " << Array[log10(d) - 1];
	}
	else
	{
		cout << "Enter incorect value" << endl;
		main();
	}
	delete[] Array;
	return 0;
}

