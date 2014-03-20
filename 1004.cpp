#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a[12], result = 0;
	for (int i = 0; i < 12; ++i)
	{
		cin >> a[i];
		result = a[i] + result;
	}
	result = result / 12;
	cout <<'$' << fixed << setprecision(2)<< result << endl;
	return 0;
}