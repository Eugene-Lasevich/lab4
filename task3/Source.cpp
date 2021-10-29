#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << "The program rearranges rows and columns \
until the largest element is in the upper left corner " << endl << endl;


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

	double **Array = new double *[row];
	for (int i = 0; i <row; ++i)
	{
		Array[i] = new double[column];
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			cout << "Enter the item in position i = " << i+1 << " j = " << j+1 << endl;
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
			Array[i][j] = n;
			//cin >> Array[i][j];
			cout << '\n';
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



	/////////////////////
	double max=Array[0][0];
	int i_max=0, j_max=0;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			if (Array[i][j] > max)
			{
				max = Array[i][j];
				i_max = i, j_max = j;
			}
		}
	}
	cout << '\n';


	for (int i = 0; i < row; ++i)
	{
		double tmp = Array[i][0];
		Array[i][0] = Array[i][j_max];
		Array[i][j_max] = tmp;	
	}
	
	cout << '\n';
	cout << " Modified matrix by column " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; ++j)
		{
			cout << setw(3) << Array[i][j] << " ";
		}
		cout << '\n';
	}
	//////////
	for (int j = 0; j < column; ++j)
	{
		double tmp = Array[0][j];
		Array[0][j] = Array[i_max][j];
		Array[i_max][j] = tmp;
	}

	cout << '\n';
	cout << " Modified matrix " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; ++j)
		{
			cout << setw(3) << Array[i][j] << " ";
		}
		cout << '\n';
	}


	///////////////////

	for (int i = 0; i < row; ++i)
	{
		delete[] Array[i];
	}
	delete[] Array;
}