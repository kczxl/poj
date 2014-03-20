#include <iostream>
using namespace std;
int main()
{
	int len, num, a[100],x;
	int A, T, C, G;
	char str[100][50], buff[50];
	cin >> len >> num;
	for (int i = 0; i < num; ++i)
	{
		A = 0; T = 0; C = 0; G = 0;
		for (int j = 0; j < len; ++j)
		{
			cin >> str[i][j];
			if (str[i][j] == 'A')
				++A;
			if (str[i][j] == 'T')
				++T;
			if (str[i][j] == 'G')
				++G;
			if (str[i][j] == 'C')
				++C;
		}
		a[i] = 0;
		for (int j = 0; j < len; ++j)
		{
			if (str[i][j] == 'T')
			{
				a[i] = a[i] + A + G + C;
				--T;
			}
			else
			{
				if (str[i][j] == 'G')
				{
					a[i] = a[i] + A + C;
					--G;
				}
				else
				{
					if (str[i][j] == 'C')
					{
						a[i] = a[i] + A;
						--C;
					}
					else --A;
				}
			}
		}
	}
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num - 1 - i; ++j)
		{
			if (a[j] > a[j+1])
			{
				x = a[j];
				a[j] = a[j+1];
				a[j+1] = x;
				for (int k = 0; k < len; ++k)
				{
					buff[k] = str[j][k];
					str[j][k] = str[j+1][k];
					str[j+1][k] = buff[k];
				}
			}
		}
	}
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j<len; ++j)
			cout << str[i][j];
		cout << endl;
	}
	return 0;
}