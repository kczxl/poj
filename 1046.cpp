#include <iostream>
using namespace std;
int main()
{
	int a[16][3],b[3],result[3],min,buff;
	for (int i = 0; i < 16; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> a[i][j];
	while(1)
	{
		for (int i = 0; i < 3; ++i)
			cin >> b[i];
		if (b[1] == -1) break;
		min = 300000;
		for (int i = 0; i < 16; ++i)
		{
			buff = 0;
			for (int j = 0; j < 3; ++j)
				buff += (a[i][j]-b[j])*(a[i][j]-b[j]);
			if (buff < min)
			{
				min = buff;
				for (int j =0; j < 3; ++j)
					result[j] = a[i][j];
			}
		}
		cout << "(" << b[0] << "," << b[1] << "," << b[2] << ") maps to (" << result[0] << "," << result[1] << "," << result[2] << ")" <<endl;
	}
	return 0;
}