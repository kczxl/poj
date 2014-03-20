#include <iostream>
using namespace std;
int max(int a[101], int n);
int max_two(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int main()
{
	int n, matri[101][101], a[101], result;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> matri[0][i];
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> matri[i][j];
			matri[i][j] = matri[i-1][j] + matri[i][j];
			//cout << matri[i][j] <<' ';
		}
		//cout << endl;
	}
	result = -120;
	//cout << result;
	for (int i = 0; i < n; ++i)
	{
		if (result < max(matri[i], n))
			result = max(matri[i], n);
		//cout << result << endl;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				a[k] = matri[j][k] - matri[i][k];
			}
			if (result < max(a, n))
				result = max(a, n);
		}
	}
	cout << result;
	return 0;
}
int max(int a[101], int n)
{
	//cout << "**" << a[n] << endl;
	int b[101], c[101];
	b[0] = a[0];
	c[0] = a[0];
	for (int i = 1; i < n; ++i)
	{
		b[i] = max_two(a[i], a[i]+b[i-1]);
		c[i] = max_two(c[i-1], b[i]);
	}
	return c[n-1];
}