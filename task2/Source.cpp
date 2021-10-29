#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << "the sum of negative elements above the side diagonal" << endl << endl;

	const int row = 4, column = 3;
	int Array[row][column] =
	{
		{1,2,3},
		{-5,-5,-9},
		{5,7,14},
		{-5,17,45}
	};

	cout << "original matrix " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; ++j)
		{
			cout << setw(2)<< Array[i][j] << " ";

			if (j == 2)
			{
				cout << endl;
				break;
			}
		}
	}

	cout << endl;
	cout << "matrix elements above the side diagonal " << endl;
	int sum = 0;
		for (int i = 0; i < row ; ++i)
		{
			for (int j = 0; j<column-i; ++j)
			{
				cout <<setw(2)<<Array[i][j];
				if (Array[i][j] < 0)
				{
					sum += Array[i][j];
				}
			}
			cout << '\n';
		}
		cout << "sum of negative elements " << sum << endl;



		/*const int row = 3, column = 4;
		int Array[row][column]=
		{
			{1,-7,3,-5},
			{-5,-5,-9,14},
			{5,7,14,1},
		};

		cout << "original matrix " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; ++j)
			{
				cout << setw(2) << Array[i][j] << " ";

				if (j == 3)
				{
					cout << endl;
					break;
				}
			}
		}

		cout << endl;
		cout << "matrix elements above the side diagonal " << endl;
		int sum = 0;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < column - (i+2); ++j)
			{
				cout << setw(2) << Array[i][j];
				if (Array[i][j] < 0)
				{
					sum += Array[i][j];
				}
			}
			cout << '\n';
		}
		cout << "sum of negative elements " << sum << endl;*/
		
}