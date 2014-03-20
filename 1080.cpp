#include <iostream>
using namespace std;
int matri[5][5] = {{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};

int change(char a)
{
	if (a == 'A') return 0;
	if (a == 'C') return 1;
	if (a == 'G') return 2;
	if (a == 'T') return 3;
}
int max_1(int x, int y, int z)
{
	int max1;
	max1 = x;
	if (y > max1) max1 = y;
	if (z > max1) max1 = z;
	return max1;
}
int main()
{
	int num, row, col, a[102][102], x[102], y[102];
	char s;
	cin >> num;
	while(num > 0)
	{
		--num;
		cin >> row;
		for (int i = 0; i < row; ++i)
		{
			cin >> s;
			x[i] = change(s);
			//cout << x[i] <<' ';
		}
		//cout << endl;
		cin >> col;
		for (int i = 0; i < col; ++i)
		{
			cin >> s;
			y[i] = change(s);
			//cout << y[i] << ' ';
		}
		a[0][0] = 0;
		for (int i = 1; i <= col; ++i)
			a[0][i] = a[0][i-1] + matri[y[i-1]][4];
		for (int i = 1; i <= row; ++i)
			a[i][0] = a[i-1][0] + matri[x[i-1]][4];
		for (int i = 1; i <= row; ++i)
			for (int j = 1; j <= col; ++j)
				a[i][j] = max_1((a[i-1][j-1]+matri[x[i-1]][y[j-1]]), (a[i-1][j]+matri[x[i-1]][4]), (a[i][j-1]+matri[y[j-1]][4]));
		cout << a[row][col] << endl;
	}
	return 0;
}