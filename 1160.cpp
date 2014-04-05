#include <iostream>
using namespace std;
int min(int a,int b) 
{
    if(a < b)  return a;
    else return b;
}
int dp[310][31];
int sum[310][310];
int V,P;
int pos[310];
int main()
{
    cin >> V >> P;
    for(int i = 1; i <= V; ++i)
        cin >> pos[i];
    for(int i=1 ; i< V ; i++)
    {
        for(int j=i+1 ; j<= V ; j++)
        {
            sum[i][j] = sum[i][j-1]+pos[j]-pos[(i+j)/2];
        }
    }
        for(int i = 1; i <= V; ++i)
        {
            dp[i][i] = 0;
            dp[i][1] = sum[1][i];
        }
    for(int j = 2; j <= P; ++j)
    { 
        for(int i = j+1; i <= V; ++i)
        {
            dp[i][j] = 9999999;
            for(int k = j-1; k < i; ++k)
                dp[i][j] = min(dp[i][j],dp[k][j-1]+sum[k+1][i]);
        }
    }
    cout << dp[V][P];
    return 0;
}