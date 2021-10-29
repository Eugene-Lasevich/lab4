#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << "counts the number of local minimums" << endl << endl;

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

	int n = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; ++j)
		{											
			if (i - 1 < 0)
			{
				if (j - 1 < 0)
				{
					if (Array[i][j] < Array[i + 1][j] && Array[i][j] < Array[i + 1][j + 1] && \
						Array[i][j] < Array[i][j + 1])
					{
						n += 1;
						//cout << 1 << endl;
						cout << "Array[" << i +1 << "]" << "[" << j+1  << "]" << " = " << Array[i][j] << endl;
						continue;
						
					}
				}

				if (j + 1 > column)
				{
					if (Array[i][j] < Array[i + 1][j] && Array[i][j] < Array[i + 1][j - 1] && \
						Array[i][j] < Array[i][j - 1])
					{
						//cout << 2 << endl;
						cout << "Array[" << i+1  << "]" << "[" << j+1  << "]" << " = " << Array[i][j] << endl;
						n += 1;
						continue;
					
					}
				}

				if (Array[i][j] < Array[i][j-1] && Array[i][j] < Array[i +1][j - 1] && \
					Array[i][j] < Array[i+1][j]&& Array[i][j] < Array[i + 1][j+1] && Array[i][j] < Array[i][j + 1])
				{
					//cout << 3 << endl;
					cout << "Array[" << i+1  << "]" << "[" << j+1 << "]" << " = " << Array[i][j] << endl;					n += 1;
					continue;
			
				}
			}

			if (i+1>= row)
			{
				if (j - 1 < 0)
				{
					if (Array[i][j] < Array[i-1][j] && Array[i][j] < Array[i -1][j + 1] && \
						Array[i][j] < Array[i][j + 1])
					{
						n += 1;
						//cout << 4 << endl;
						cout << "Array[" << i +1 << "]" << "[" << j+1  << "]" << " = " << Array[i][j] << endl;
						continue;
				
					}
				}

				if (j + 1 >= column)
				{
					if (Array[i][j] < Array[i][j-1] && Array[i][j] < Array[i-1][j - 1] && \
						Array[i][j] < Array[i-1][j])
					{
						//cout << 5 << endl;
						cout << "Array[" << i+1 << "]" << "[" << j+1  << "]" << " = " << Array[i][j] << endl;	
						n += 1;
						continue;
					
					}
				}

				if (Array[i][j] < Array[i][j - 1] && Array[i][j] < Array[i - 1][j - 1] && \
					Array[i][j] < Array[i - 1][j] && Array[i][j] < Array[i - 1][j + 1] && Array[i][j] < Array[i][j + 1])
				{
					//cout << 6 << endl;
					cout << "Array[" << i+1  << "]" << "[" << j+1  << "]" << " = " << Array[i][j] << endl;					
					n += 1;
					continue;
			
				}
			}


			if (j - 1 < 0 && i != 0 && i != row)
			{								
					if (Array[i][j] < Array[i - 1][j] && Array[i][j] < Array[i - 1][j + 1] && \
						Array[i][j] < Array[i][j + 1] && Array[i][j] < Array[i + 1][j + 1] && Array[i][j] < Array[i + 1][j])
					{
						n += 1;
						//cout << 7 << endl;
						cout << "Array[" << i+1  << "]" << "[" << j+1  << "]" << " = " << Array[i][j] << endl;
				
						continue;
					}
					
			}

			if (j  >= column-1 && i >0 && i < row)
			{
				if (Array[i][j] < Array[i-1][j] && Array[i][j] < Array[i - 1][j - 1] && \
					Array[i][j] < Array[i][j-1]&& Array[i][j] < Array[i + 1][j - 1]&& Array[i][j] < Array[i + 1][j])
				{
					//cout << 8 << endl;
					cout << "Array[" << i+1  << "]" << "[" << j +1 << "]" << " = " << Array[i][j] << endl;
					n += 1;
				
					continue;
				}

			}

			if (i >= 1 && i < row-1 && j>=1 && j <= column-1)
			{
				if (Array[i][j] < Array[i - 1][j - 1] && Array[i][j] < Array[i - 1][j + 1] && Array[i][j] < Array[i][j - 1]&& \
					Array[i][j] < Array[i][j - 1] && Array[i][j] < Array[i][j + 1] && Array[i][j] < Array[i + 1][j - 1] && \
					Array[i][j] < Array[i + 1][j] && Array[i][j] < Array[i + 1][j + 1])
				{
					//cout << 9 << endl;
					cout << "Array[" << i+1  << "]" << "[" << j+1  << "]" << " = " << Array[i][j] << endl;
					n += 1;
				
					continue;
				}
			}
			
			
		}
	}
	cout << "n = " << n << endl;
	/////////////////////

	for (int i = 0; i < row; ++i)
	{
		delete[] Array[i];
	}
	delete[] Array;
	return 0;
}