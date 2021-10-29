#include<iostream>
#include<algorithm>
using namespace std;


int delete_array(int* array, const int &size)
{

	sort(array, array + size);

	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] == array[j])
			{
				count++;
				break;

			}

		}
	}

	int new_size = size - count;
	int* Array1 = new int[new_size];


	int count1 = 0;
	for (int i = 0; i < size; i++)
	{

		if (i < size - 1 && array[i + 1] == array[i])
		{
			count1++;
			continue;
		}
		Array1[i - count1] = array[i];
	}

	for (int i = 0; i < new_size; i++)
	{
		cout << Array1[i] << " ";

	}
	cout << endl;
	cout << "New size = " << new_size;

	return *Array1;
	
}

int main()
{
	cout << "the program calls a function that removes duplicate elements" << endl << endl;
	cout << "Enter the size of the array" << endl;
	int size = 0;
	while (true)
	{
		cin >> size;
		if (!cin)
		{
			cout << "Enter invalid value" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}

	cout << endl;
	int* array = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
		//array[i] = rand() % 10;
	}

	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";

	}
	cout << endl;

	delete_array(array, size);
	delete[] array;
}
