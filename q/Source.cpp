#include<iostream>
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

	cout << "Constructs a magic square of odd dimension, except for 3 + 6k, k = 1,2,3 ..." << endl << endl;
	
	cout << "Enter the dimension of the square" << endl;

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

	if (n == 2)
	{
		cout << "Can't build a magic square" << endl << endl;
		return 0;
	}

	int** square = arr_Create(n);

	if (n % 2 == 1 && n!=3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				square[i][j] = 1 + ((i + j - 1 + (n - 1) / 2) % n) * n + ((i + 2 * j + 2) % n);
			}
		}
		out_array(square, n);
		return 0;
	}

	int number = 1, i = 0, j = n / 2;
	while (number <8)
	{
		if (i<0 || j>n)
		{
	

			if (i < 0 && j >= n)
			{

				i = (n - 1);
				j = 0;
				if (square[i][j] != 0)
				{
					i = 1;
					j = n - 1;
				}
				square[i][j] = number;
				number++;
				i--, j++;
			

			}

			if (i < 0)
			{
				if (square[n-1][j] == 0)
				{
					i = (n - 1);
					square[i][j] = number;
					number++;
					i--, j++;
				}
	
	
			}
		
			if (j >= n)
			{

				j = 0;
				square[i][j] = number;
				number++;
				i--, j++;

				if (i >= 0 && j >= 0)
				{
					if (square[i][j] != 0)
					{
						i += 2;
						j--;
					}
				}
				if (i < 0)
				{
					i = n - 1;
				}
			}


		}

			square[i][j] = number;
			number++;
			i--, j++;

	}
	
	out_array(square, n);

	for (int i = 0; i < n; ++i)
	{
		delete[] square[i];
	}
	delete[] square;
	return 0;
}