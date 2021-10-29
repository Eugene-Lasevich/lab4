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
			arr[i][j] = rand() % 10;
			//cout << '\n';
		}
	}
	return arr;
}

int** arr_Create(const int row)
{
	int** arr = new int* [row];
	for (int i = 0; i < row; ++i)
		arr[i] = new int[row];
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
	cout << "the program performs matrix multiplication" << endl << endl;

	cout << "Enter the numbers of rows1 " << endl;
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


	cout << "Enter the numbers of columns1 " << endl;
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

	cout << endl;

	cout << "Enter the numbers of rows2 " << endl;
	//cin >>row;
	int row1 = 0;
	while (true)
	{
		cin >> row1;
		if (!cin)
		{
			cout << "Enter invalid value" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}


	cout << "Enter the numbers of columns2 " << endl;
	//cin >>column;
	int column1 = 0;
	while (true)
	{
		cin >> column1;
		if (!cin)
		{
			cout << "Enter invalid value" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	cout << endl << endl;

	int** Array1= arrCreate(row1, column1);

	if (row != column1)
	{
		cout << "product of these matrices is impossible " << endl << endl;
		system("pause");
		system("cls");
		main();
	}

	int** Array2 = arr_Create(row);
	for (int j = 0; j < column1; j++)
	{
		for (int i = 0; i < row; i++)
		{	
			int tmp = 0;
			for (int m = 0, n = 0; m < column && n < row1; m++, n++)
			{
				tmp += Array[i][m] * Array1[n][j];
			}
			Array2[i][j] = tmp;
		}
	}

	out_array(Array2, row, row);
	cout << endl << endl;
	out_array(Array1, row1, column1);
	cout << "\n"<<"    " << "*\n\n";
	out_array(Array, row, column);

	for (int i = 0; i < row; ++i)
	{
		delete[] Array[i];
	}
	delete[] Array;

	
	delete[] Array1;
	for (int i = 0; i < row; ++i)
	{
		delete[] Array1[i];
	}
	delete[] Array1;

	for (int i = 0; i < row; ++i)
	{
		delete[] Array2[i];
	}
	delete[] Array2;

}