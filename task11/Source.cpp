#include<iostream>
using namespace std;


int two_min(int a, int b)
{
	if (b < a)
		return b;
	else
		return a;
}

int*** arrCreate(const int n)
{
	int*** arr = new int** [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int* [n];
		for (int j = 0; j < n; j++)
			arr[i][j] = new int[n];
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				//cout << "Enter the item in position i = " << i + 1 << " j = " << j + 1 << endl;
				//cin >> arr[i][j][k];
				arr[i][j][k] = rand() % 10;
				//cout << '\n';
			}
		}
	}
	return arr;
}


int main()
{
	cout << "The program finds the minimum sum of the diagonals of a cube" << endl << endl;
	cout << "Enter size of cube" << endl;

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

	int ***Array = arrCreate(n);

	int sum1 = 0;
	for (int i = n - 1, j = 0, k = 0; i > 0, j < n, k < n; i--, j++, k++)
	{
		sum1 += Array[i][j][k];
	}
	cout << "sum1 = " << sum1 << endl;

	int sum2 = 0;
	for (int i = 0, j = 0, k = 0; i < n, j < n, k < n; i++, j++, k++)
	{
		sum2 += Array[i][j][k];
	}
	cout << "sum2 = " << sum2 << endl;

	int sum3 = 0;
	for (int i = 0, j = n - 1, k = 0; i < n, j > 0, k < n; i++, j--, k++)
	{
		sum3 += Array[i][j][k];
	}
	cout << "sum3 = " << sum3<< endl;

	int sum4 = 0;
	for (int i = n - 1, j = n - 1, k = 0; i > 0, j > 0, k < n; i--, j--, k++)
	{
		sum4 += Array[i][j][k];
	}
	cout << "sum4 = " << sum4 << endl;



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cout << Array[i][j][k] << " ";
			}
		}
	}

	cout << endl << "min sum = " << two_min(two_min(sum1, sum2), two_min(sum3, sum4)) << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			delete[] Array[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		delete[] Array[i];
	}
	delete[] Array;
	return 0;
}