#include<iostream>
using namespace std;

int log10(int a)
{
	int n = 0;
	while (a / 10 != 0)
	{
		a /= 10;
		n++;
	}
	return n;
}

int sum_arr(int* arr, int n)
{
	int sum = 0,my_sum=0;
	for (int j = 0; j < n; j++)
	{
		int el = arr[j];
	
		for (int i = j+1; i < n; i++)
		{
			int tmp_sum = el + arr[i];
			if (log10(tmp_sum) > log10(el) && log10(tmp_sum) > log10(arr[i]))
			{
				my_sum += log10(tmp_sum);
			}
			//sum += el + arr[i];
		}
	}
	return my_sum;

}

int main()
{
	int n;
	cin >> n;
	//cout << log10(n);
	
	int* Array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> Array[i];
	}
	cout << sum_arr(Array, n);

}