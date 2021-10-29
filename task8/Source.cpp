#include<iostream>
using namespace std;

int main()
{
	cout << "The program replaces all elements between the minimum and maximum values with zeros, if there are more than half of zeros, it removes them, keeping the order of other elements" << endl << endl;
	
	cout << "Enter length of array" << endl;
	
	int length = 0;
	while (true)
	{
		cin >> length;
		if (!cin)
		{
			cout << "Enter invalid value" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}

	double* Array = new double[length];
	cout << endl;


	//setting a dynamic array
	for (int i = 0; i < length; ++i)
	{
		cout << "Enter Array[i]; i =  " << i << endl;

		int n1 = 0;
		while (true)
		{
			cin >> n1;
			if (!cin)
			{
				cout << "Enter invalid value" << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
		}
		 Array[i] = n1;
	}

	//finding the minimum and maximum value
	int max = Array[0], min = Array[0], i_min= 0, i_max =0;
	for (int i = 1; i < length; ++i)
	{
		if (Array[i] > max)
		{
			max = Array[i];
			i_max = i;
		}

		if (Array[i] < min)
		{
			min = Array[i];
			i_min = i;
		}
	}
	cout  << endl << endl;


	//Outputting the original array
	cout << "source array" << endl;
	for (int i = 0; i < length; ++i)
	{
		cout << Array[i] << " ";
	}cout << endl << endl;;

	//replace with zeros if mini before
	cout << "array with zeros" << endl;
	if (i_max > i_min)
	{
		for (int i = i_min+1; i < i_max; ++i)
		{
			Array[i] = 0;
		}

		for (int i = 0; i < length; ++i)
		{
			cout << Array[i] << " ";
		}
		cout << endl << endl;
	}

	if (i_max < i_min)
	{
		for (int i = i_max+1; i < i_min; ++i)
		{
			Array[i] = 0;
		}

		for (int i = 0; i < length; ++i)
		{
			cout << Array[i]<< " ";
		}
		cout << endl<<endl;
	}

	int n = 0;
	for (int i = 0; i < length; ++i)
	{
		if (Array[i] == 0)
		{
			++n;
		}
	}

	cout << "Final array" << endl;
	if (n <= length / 2)
	{
		for (int i = 0; i < length; ++i)
		{
			cout << Array[i] << " ";
		}
		return 0;
	}

	int* NewArray = new int[length - n];
	int  k = 0;
	for (int i = 0; i < length; ++i)
	{
		if (Array[i] == 0)
		{
			++k;
			continue;
		}
		NewArray[i-k] = Array[i];
		//cout << "NewArray = " << NewArray[i];
	}

	delete[] Array;

	for (int i = 0; i < length - n; ++i)
	{
		cout << NewArray[i]<<" ";
	}
	delete[] NewArray;
	return 0;
}