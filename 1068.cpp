#include <iostream>
using  namespace std;
int main()
{
	int t, a[200];
	int buff, shu;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int len;
		cin >> len;
		cin >> a[0];
		buff = a[0];
		for (int j = 1; j < len; ++j)
		{
			cin >> shu;
			a[j] = shu - buff;
			buff = shu;
		}
		for (int j = 0; j < len; ++j)
		{
			buff = 0, shu = 0;
			for (int k = j; k >= 0; --k)
			{
				buff = buff+1-a[k];
				++shu;
				if (buff <= 0)
					break;
			}
			cout << shu << ' ';
		}
		cout << endl;
	}
}