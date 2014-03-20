#include <iostream>
#include <string>
#include <stack>
using namespace std;
string a;
int main()
{
    stack<string> x;
    stack<string> y;
    x.push("http://www.acm.org/");
    while(cin>>a,a!="QUIT")
    {
        if(a=="VISIT")
        {
            cin>>a;
            x.push(a);
            while(!y.empty()) y.pop();
            cout<<a<<endl;
        }
        else if(a=="BACK")
        {
            a=x.top();x.pop();
            if(x.empty())
            {
                cout<<"Ignored"<<endl;
                x.push(a);
            }
            else
            {
                cout<<x.top()<<endl;
                y.push(a);
            }
        }
        else if(a=="FORWARD")
        {
            if(y.empty())
            {
                cout<<"Ignored"<<endl;
            }
            else
            {
                cout<<y.top()<<endl;
                x.push(y.top());
                y.pop();
            }
        }
    }
    return 0;
}
