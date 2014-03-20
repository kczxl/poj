#include <iostream>
#include <math.h>
using namespace std;  
long a,b;
int main()
{
 while(cin>>a>>b)
 {
  long c;
  if(a>b)c=a,a=b,b=c;
  long x=(a+1.0)*2/(1.0+sqrt(5.0));
  long y=(a+0.0)*2/(1.0+sqrt(5.0));
  if(x==y)cout<<1<<endl;
  else if(x>y&&b==a+x)cout<<0<<endl;
  else cout<<1<<endl;
 }
}