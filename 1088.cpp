#include <iostream>
using namespace std;
int height[100][100], dis[100][100], sort1[10000][3];
int main()
{
	int row, col, buff;
	cin >> row >> col;
	int len = 0;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			cin >> sort1[len][2];
			dis[i][j] = 0;
			sort1[len][0] = i;
			sort1[len][1] = j;
			height[i][j] = sort1[len][2];
			++len;
		}
	for (int i = 0; i < len-1; ++i)
		for (int j = 0; j < len-1-i; ++j)
		{
			if (sort1[j][2] > sort1[j+1][2])
			{
				buff = sort1[j][2]; sort1[j][2] = sort1[j+1][2]; sort1[j+1][2] = buff;
				buff = sort1[j][1]; sort1[j][1] = sort1[j+1][1]; sort1[j+1][1] = buff;
				buff = sort1[j][0]; sort1[j][0] = sort1[j+1][0]; sort1[j+1][0] = buff;
			}
		}
	/*
	for (int i = 0; i < len ; ++i)
		cout << sort1[i][2] << ' ' << sort1[i][0] << ' ' << sort1[i][1] <<endl;
	*/
	for (int i = 0; i < len; ++i)
	{
		buff = 0;
		if (sort1[i][0] != 0 && dis[sort1[i][0]-1][sort1[i][1]] > buff && sort1[i][2] > height[sort1[i][0]-1][sort1[i][1]]) buff = dis[sort1[i][0]-1][sort1[i][1]];
		if (sort1[i][0] != (row-1) && dis[sort1[i][0]+1][sort1[i][1]] > buff && sort1[i][2] > height[sort1[i][0]+1][sort1[i][1]]) buff = dis[sort1[i][0]+1][sort1[i][1]];
		if (sort1[i][1] != 0 && dis[sort1[i][0]][sort1[i][1]-1] > buff && sort1[i][2] > height[sort1[i][0]][sort1[i][1]-1]) buff = dis[sort1[i][0]][sort1[i][1]-1];
		if (sort1[i][1] != (col-1) && dis[sort1[i][0]][sort1[i][1]+1] > buff && sort1[i][2] > height[sort1[i][0]][sort1[i][1]+1]) buff = dis[sort1[i][0]][sort1[i][1]+1];
		dis[sort1[i][0]][sort1[i][1]] = buff + 1;
		//cout << dis[sort1[i][0]][sort1[i][1]] << ' ';
	}
	int max = 0;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			if (dis[i][j] > max)
				max = dis[i][j];
		}
	cout << max;
	return 0;
}