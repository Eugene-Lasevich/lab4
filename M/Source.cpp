#include<iostream>
#include<cmath>
//#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen(x, "r", stdin);
	//freopen(x, "w", stdout);
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int* Array1 = new int[n];
	int* Array2 = new int[m];

	for (int i = 0; i < n; i++)
	{
		cin >> Array1[i];
	}

	for (int j = 0; j < m; j++)
	{
		cin >> Array2[j];
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum += sqrt(abs((Array1[i]) - Array2[j]));
		}
	}
	cout << sum;
}