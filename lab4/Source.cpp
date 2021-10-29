#include<iostream>
using namespace std;

int main()
{
	cout << "the program changes the maximum and minimum values in places" << endl << endl;

	const int length = 5;
	int Array[length];

	cout << "Enter array elements " << endl;
	for (int i = 0; i < length; i++)
	{
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
		Array[i] = n;
	}

	int min = Array[0], index1;
	for (int i = 1; i < length; i++)
	{
		if (min > Array[i])
		{
			min = Array[i];
			index1 = i;
		}

		else
		{
			index1 = 0;
		}
	}

	int max = Array[0], index2;
	for (int k = 1; k < length; k++)
	{
		if (max < Array[k])
		{
			max = Array[k];
			index2 = k;
		}

		else
		{
			index2 = 0;
		}
	}

	int tmp = Array[index1];
	Array[index1] = Array[index2];
	Array[index2] = tmp;

	for (int i = 0; i < length; i++)
	{
		cout << Array[i] << " ";
	}


}