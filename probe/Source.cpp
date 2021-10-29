#include<iostream>
#include<iomanip>
using namespace std;


int **arrCreate(const int row, const int col)
{
    int **arr = new int* [row];
    for (int i = 0; i < row; ++i)
        arr[i] = new int[col];

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << "Enter the item in position i = " << i + 1 << " j = " << j + 1 << endl;
			cin >> arr[i][j];
			cout << '\n';
		}
	}
	return arr;
}

void out_array(int **arr, const int row, const int column)
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
	int row, column;
	cout<<""
	cin >> row >> column;
	int **Array = arrCreate(row, column);

	out_array(Array, row, column);
	
	
}