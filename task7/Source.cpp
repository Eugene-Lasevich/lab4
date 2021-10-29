#include<iostream>
#include<iomanip>
using namespace std;

int** arrCreate(const int row, const int col)
{
	int** arr = new int* [row];
	for (int i = 0; i < row; ++i)
		arr[i] = new int[col];

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			//cout << "Enter the item in position i = " << i + 1 << " j = " << j + 1 << endl;
			//cin >> arr[i][j];
			arr[i][j] = rand() % 10;
			//cout << '\n';
		}
	}
	return arr;
}

int** arr_Create(const int row, const int col)
{
	int** arr = new int* [row];
	for (int i = 0; i < row; ++i)
		arr[i] = new int[col];
	return arr;
}

void out_array(int** arr, const int row, const int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; ++j)
		{
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << '\n';
	}

}



int main()
{
	cout << "the program will rebuild the matrix" << endl << endl;

	cout << "Enter the numbers of rows " << endl;
	//cin >>row;
	int row = 0;
	while (true)
	{
		cin >> row;
		if (!cin)
		{
			cout << "Enter invalid value" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}


	cout << "Enter the numbers of columns " << endl;
	//cin >>column;
	int column = 0;
	while (true)
	{
		cin >> column;
		if (!cin)
		{
			cout << "Enter invalid value" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}


	int** Array = arrCreate(row, column);
	int** Array1 = arr_Create(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; ++j)
		{
			Array1[i][j] = Array[i][j];
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; ++j)
		{
			int max = Array[0][0];
			for (int i_tmp = 0; i_tmp <= i; i_tmp++)
			{
				for (int j_tmp = 0; j_tmp <= j; ++j_tmp)
				{
					if (max < Array[i_tmp][j_tmp])
					{
						max = Array[i_tmp][j_tmp];
					}
					Array1[i][j] = max;
				}
			}
			
		}
		cout << '\n';
	}

	out_array(Array, row, column);
	cout << endl << endl << endl;
	out_array(Array1, row, column);

	for (int i = 0; i < row; ++i)
	{
		delete[] Array[i];
	}
	delete[] Array;

	for (int i = 0; i < row; ++i)
	{
		delete[] Array1[i];
	}
	delete[] Array1;
	return 0;

}