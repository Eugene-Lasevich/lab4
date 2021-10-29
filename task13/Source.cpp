#include<iostream>
using namespace std;

int main()
{
	cout << "the program calculates the optimal amount" << endl << endl;
	cout << "enter the number of extension cords" << endl;
	int n = 0;
	while (true)
	{
		cin >> n;
		if (!cin)
		{
			cout << "Enter invalid value" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}

	int* Array = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "enter the number of sockets i = " << i+1 << endl;
		cin >> Array[i];
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count+= Array[i];
	}

	cout <<"number of sockets " << count - (n - 1);
	delete[] Array;
}