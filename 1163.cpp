#include <iostream>
using namespace std;
int max(int x, int y)
{
	if (x > y) return x;
	else return y;
}
int main()
{
	int n, a[102][102], b[102][102], result;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
			cin >> a[i][j];
	}
	b[0][0] = a[0][0];
	for (int i = 1; i < n; ++i)
	{
		b[i][0] = a[i][0] + b[i-1][0];
		b[i][i] = a[i][i] + b[i-1][i-1];
		for (int j = 1; j < i; ++j)
		{
			b[i][j] = a[i][j] + max(b[i-1][j-1], b[i-1][j]);
		}
	} 
	result = 0;
	for (int i = 0; i < n; ++i)
		result = max(result, b[n-1][i]);
	cout << result;
	return 0;
}