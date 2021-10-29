#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	cout << "the program smooths the matrix" << endl << endl;

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

	if (row < 2 || column < 2)
	{
		cout << "incorect enter" << endl;
		main();
	}

	double** Array = new double* [row];
	for (int i = 0; i < row; ++i)
	{
		Array[i] = new double[column];
	}

	double** Array1 = new double* [row];
	for (int i = 0; i < row; ++i)
	{
		Array1[i] = new double[column];
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			//cout << "Enter the item in position i = " << i + 1 << " j = " << j + 1 << endl;
			//cin >> Array[i][j];
			Array[i][j] = rand() % 20;
			//cout << '\n';
		}
	}

	cout << '\n';
	cout << " original matrix " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; ++j)
		{
			cout << setw(3) << Array[i][j] << " ";
		}
		cout << '\n';
	}


	//////////////////////

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; ++j)
		{
			if (i - 1 < 0)
			{
				if (j - 1 < 0)
				{
					Array1[i][j] = round((Array[i + 1][j] + Array[i + 1][j + 1] + \
					Array[i][j + 1]) / 3);
					
						//cout << 1 << endl;
						continue;

					
				}

				if (j + 1 >= column)
				{
					Array1[i][j] = round((Array[i + 1][j] + Array[i + 1][j - 1] + \
						Array[i][j - 1]) / 3);
					
						// cout << 2 << endl;
						continue;

					
				}

				Array1[i][j] = round((Array[i][j - 1] + Array[i + 1][j - 1] + \
				Array[i + 1][j] + Array[i + 1][j + 1] + Array[i][j + 1]) / 5);
				
					//cout << 3 << endl;
					continue;

				
			}

			if (i + 1 >= row)
			{
				if (j - 1 < 0)
				{
					Array1[i][j] = round((Array[i - 1][j] + Array[i - 1][j + 1] + \
						Array[i][j + 1]) / 3);
					
						//cout << 4 << endl;
						continue;

					
				}

				if (j + 1 >= column)
				{
					Array1[i][j] = round((Array[i][j - 1] + Array[i - 1][j - 1]  \
						+ Array[i - 1][j]) / 3);
					
						//cout << 5 << endl;
						continue;

					
				}

				Array1[i][j] = round((Array[i][j - 1] + Array[i - 1][j - 1] + \
					Array[i - 1][j] + Array[i - 1][j + 1] + Array[i][j + 1]) / 5);
				
					//cout << 6 << endl;
					continue;

				
			}


			if (j - 1 < 0 && i != 0 && i != row)
			{
				Array1[i][j] = round((Array[i - 1][j] + Array[i - 1][j + 1] + \
					Array[i][j + 1] + Array[i + 1][j + 1] + Array[i + 1][j]) / 5);
				
					//cout << 7 << endl;

					continue;
				

			}

			if (j >= column - 1 && i > 0 && i < row)
			{
				Array1[i][j] = round((Array[i - 1][j] + Array[i - 1][j - 1] + \
					Array[i][j - 1] + Array[i + 1][j - 1] + Array[i + 1][j])/5);
				
					//cout << 8 << endl;
					continue;
				

			}

			if (i >= 1 && i < row - 1 && j >= 1 && j <= column - 1)
			{
			 Array1[i][j] = round((Array[i - 1][j - 1] + Array[i - 1][j + 1] + Array[i-1][j]+ \
					Array[i][j - 1] + Array[i][j + 1] + Array[i + 1][j - 1] + \
					Array[i + 1][j] + Array[i + 1][j + 1]) / 8);
				
					//cout << 9 << endl;
					continue;
				
			}


		}
	}
	/////////////////////
	cout << endl << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; ++j)
		{
			cout << setw(3) << Array1[i][j] << " ";
		}
		cout << '\n';
	}

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