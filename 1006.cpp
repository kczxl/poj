#include <iostream>
using namespace std;
int main()
{
	int a[4], n = 0, j, day;
	while (1)
	{
		++n;
		for (int i = 0; i < 4; ++i)
			cin >> a[i];
		if (a[0] == -1) break;
		j = 0;
		while (1)
		{
			day = a[0] + 23 * j;
			if (((day-a[1])%28 == 0) && ((day-a[2])%33 == 0) && (day > a[3]))
				break;
			else
			{
				++j;
			}
		}
		day = day - a[3];
		if (day > 21252) day = day % 21252;
		cout << "Case " << n << ": " << "the next triple peak occurs in " << day << " days." <<endl;
	}
	return 0;
}