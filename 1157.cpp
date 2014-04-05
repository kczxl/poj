#include <iostream>
using namespace std;
int n, m, result;
int a[110][110], b[110][110];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	for (int i = 0; i < m-n; ++i)
		b[0][i] = a[0][i];
	for (int i = 1; i < n; ++i)
		for (int j = i; j < m-n+1+i; ++j)
		{
			b[i][j] = b[i-1][i-1];
			for (int k = i; k < j; ++k)
			{
				if(b[i-1][k] > b[i][j])
					b[i][j] = b[i-1][k];
			}
			b[i][j] = b[i][j] + a[i][j];
		}
	result = b[n-1][n-1];
	for(int i = n-1; i < m; ++i)
		if (b[n-1][i] > result)
			result = b[n-1][i];
	cout << result;
	return 0;
}