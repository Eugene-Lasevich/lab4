#include<iostream>
#include<iomanip>
using namespace std;

char** Create(int row,int column)
{
	char** arr = new char* [row];
	for (int i = 0; i < row; ++i) {
		arr[i] = new char[column];
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{			
			arr[i][j] = '.';
		}
	}
	return arr;
}

void out_array(char** arr, const int row, const int column)
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
	cout << "sapper" << endl;
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
	cout << endl;

	int bombs;
	bombs = rand() % (row * column)/2;
	//cin >> bombs;
	
	char** Array = Create(row, column);

	for (int i = 0; i < bombs; i++)
	{
		int i_tmp = rand() % row, j_tmp = rand() % column;
		Array[i_tmp][j_tmp] = '*';
	}


	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; ++j)
		{
			cout << setw(3) << Array[i][j] << " ";
		}
		cout << '\n';
	}
	cout << endl << endl;
	//////////////////////////////


	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; ++j)
		{
			if (Array[i][j] == '*')
			{
				continue;
			}
			if (i - 1 < 0)
			{
				if (j - 1 < 0)
				{


					if (Array[i + 1][j] == '*' || Array[i + 1][j + 1] == '*' || \
						Array[i][j + 1] == '*')
					{
						int count = 0;
					

						if (Array[i + 1][j] == '*')
						{
							count++;
						}

						if (Array[i + 1][j + 1] == '*')
						{
							count++;
						}

						if (Array[i][j + 1] == '*')
						{
							count++;
						}

						if (count > 0)
						{
							Array[i][j] = count + 48;
						}
						continue;

					}
				}
			
				if (j + 1 >= column)
				{

					if (Array[i + 1][j] == '*' || Array[i + 1][j - 1] == '*' || \
						Array[i][j - 1] == '*')
					{
						int count = 0;

						if (Array[i + 1][j] == '*')
						{
							count++;
						}

						if (Array[i + 1][j - 1] == '*')
						{
							count++;
						}

						if (Array[i][j - 1] == '*')
						{
							count++;
						}

						if (count > 0)
						{
							Array[i][j] = count + 48;
						}
						continue;
					}


				}

				if (Array[i][j - 1] == '*' || Array[i + 1][j - 1] == '*' || \
					Array[i + 1][j] == '*' || Array[i + 1][j + 1] == '*' || Array[i][j + 1] == '*')
				{



					int count = 0;

					if (Array[i][j - 1] == '*')
					{
						count++;
					}

					if (Array[i + 1][j - 1] == '*')
					{
						count++;
					}

					if (Array[i + 1][j] == '*')
					{
						count++;
					}
				
				
					if (Array[i + 1][j + 1] == '*')
					{
						count++;
					}

					if (Array[i][j + 1] == '*')
					{
						count++;
					}

					if (count > 0)
					{
						Array[i][j] = count + 48;
					}
					continue;

				}

			}

			if (i + 1 >= row)
			{
				if (j - 1 < 0)
				{
	

					if (Array[i - 1][j] == '*' || Array[i - 1][j + 1] == '*' || \
						Array[i][j + 1] == '*')
					{

						int count = 0;

						if (Array[i - 1][j] == '*')
						{
							count++;
						}

						if (Array[i - 1][j + 1] == '*')
						{
							count++;
						}

						if (Array[i][j + 1] == '*')
						{
							count++;
						}

						if (count > 0)
						{
							Array[i][j] = count + 48;
						}
						continue;
					}
					
				}

				if (j + 1 >= column)
				{


					if (Array[i][j - 1] =='*'|| Array[i - 1][j - 1] =='*'||  \
					 Array[i - 1][j] == '*')
					{
						int count = 0;

						if (Array[i][j - 1] == '*')
						{
							count++;
						}

						if (Array[i - 1][j - 1] == '*')
						{
							count++;
						}

						if (Array[i - 1][j] == '*')
						{
							count++;
						}

						if (count > 0)
						{
							Array[i][j] = count + 48;
						}
						continue;
					}


				}

				if (Array[i][j - 1] == '*' || Array[i - 1][j - 1] == '*' || \
					Array[i - 1][j] == '*' || Array[i - 1][j + 1] == '*' || Array[i][j + 1] == '*')
				{

					int count = 0;

					if (Array[i][j - 1] == '*')
					{
						count++;
					}

					if (Array[i - 1][j - 1] == '*')
					{
						count++;
					}

					if (Array[i - 1][j] == '*')
					{
						count++;
					}


					if (Array[i - 1][j + 1] == '*')
					{
						count++;
					}

					if (Array[i][j + 1] == '*')
					{
						count++;
					}

					if (count > 0)
					{
						Array[i][j] = count + 48;
					}
					continue;

				}

			}


			if (j - 1 < 0 && i > 0 && i < row-1)
			{

				if (Array[i - 1][j] == '*'|| Array[i - 1][j + 1] == '*'|| \
					Array[i][j + 1] =='*'|| Array[i + 1][j + 1]=='*'|| Array[i + 1][j]=='*')
				{

					int count = 0;

					if (Array[i - 1][j] == '*')
					{
						count++;
					}

					if (Array[i - 1][j + 1] == '*')
					{
						count++;
					}

					if (Array[i][j + 1] == '*')
					{
						count++;
					}


					if (Array[i + 1][j + 1] == '*')
					{
						count++;
					}

					if (Array[i + 1][j] == '*')
					{
						count++;
					}

					if (count > 0)
					{
						Array[i][j] = count + 48;
					}
					continue;
				}



			}

			if (j >= column - 1 && i > 0 && i < row-1)
			{
				
				if (Array[i - 1][j] == '*' || Array[i - 1][j - 1] == '*' || \
					Array[i][j - 1] == '*' || Array[i + 1][j - 1] == '*' || Array[i + 1][j] == '*')
				{
					int count = 0;

					if (Array[i - 1][j] == '*')
					{
						count++;
					}

					if (Array[i - 1][j - 1] == '*')
					{
						count++;
					}

					if (Array[i][j - 1] == '*')
					{
						count++;
					}


					if (Array[i + 1][j - 1] == '*')
					{
						count++;
					}

					if (Array[i + 1][j] == '*')
					{
						count++;
					}

					if (count > 0)
					{
						Array[i][j] = count + 48;
					}
					continue;
				}

			}

			if (i >= 1 && i < row - 1 && j >= 1 && j <= column - 1)
			{
				
				if (Array[i - 1][j - 1] == '*' || Array[i - 1][j + 1] == '*' || Array[i - 1][j] == '*' || \
					Array[i][j - 1] == '*' || Array[i][j + 1] == '*' || Array[i + 1][j - 1] == '*' || \
					Array[i + 1][j] == '*' || Array[i + 1][j + 1] == '*')
				{

					int count = 0;

					if (Array[i - 1][j - 1] == '*')
					{
						count++;
					}

					if (Array[i - 1][j + 1] == '*')
					{
						count++;
					}

					if (Array[i - 1][j] == '*')
					{
						count++;
					}


					if (Array[i][j - 1] == '*')
					{
						count++;
					}

					if  (Array[i][j + 1] == '*')
					{
						count++;
					}


					if (Array[i + 1][j - 1] == '*')
					{
						count++;
					}


					if (Array[i + 1][j + 1] == '*')
					{
						count++;
					}

					if (Array[i + 1][j] == '*')
					{
						count++;
					}

					if (count > 0)
					{
						Array[i][j] = count + 48;
					}
					continue;
				


				}


			}


		}
	}

	//////////////////////////////
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; ++j)
		{
			cout << setw(3) << Array[i][j] << " ";
		}
		cout << '\n';
	}

	for (int i = 0; i < row; ++i)
	{
		delete[] Array[i];
	}
	delete[] Array;
	return 0;

}