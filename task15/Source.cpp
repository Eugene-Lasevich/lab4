#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;


int** arr_Create(const int row)
{
	int** arr = new int* [row];
	for (int i = 0; i < row; ++i)
		arr[i] = new int[row];

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			//cout << "Enter the item in position i = " << i + 1 << " j = " << j + 1 << endl;
			//cin >> arr[i][j];
			arr[i][j] = 0;
			//cout << '\n';
		}
	}
	return arr;
}

void out_array(int** arr, const int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; ++j)
		{
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << '\n';
	}

}


int main()
{
	cout << "fills the table and prints the row and column" << endl << endl;
	cout << "Enter the number" << endl;

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

	int size;
	size = ceil(sqrt(n));
	int** arr = arr_Create(size);

	int count = 1;

	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i <= j; i++)
		{
			arr[i][j] = count;
			count++;
			if (i == j)
			{
				for (int j_tmp = j-1; j_tmp >= 0; j_tmp--)
				{
					arr[i][j_tmp] = count;
					count++;
				}
			}
		}
	}

out_array(arr, size);

cout << endl;
for (int i = 0; i < size; i++)
{
	for (int j = 0; j < size; j++)
	{
		if (arr[i][j] == n)
		{
			cout << "i = " << i + 1 << " j = " << j + 1 << endl;
			cout << "number = " << arr[i][j];

			for (int i = 0; i < n; ++i)
			{
				delete[] arr[i];
			}
			delete[] arr;
			return 0;
		}
	}
}

}


