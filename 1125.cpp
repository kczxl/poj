#include <iostream>  
using namespace std;  
  const int inf=20;
int dist[101][101];  
  
int i,j,k;  
int n;
  
void floyd()  
{  
    for(k=1;k<=n;k++)  
        for(i=1;i<=n;i++)                                                   
            for(j=1;j<=n;j++)      
                if(i!=j && dist[i][j] > dist[i][k] + dist[k][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
  
    int maxlength;  
    int min_in_max=inf;  
    int flag_source;  
  
    for(i=1;i<=n;i++)                    
    {  
        maxlength=0;  
        for(j=1;j<=n;j++)  
            if(i!=j && maxlength<dist[i][j])   
                maxlength=dist[i][j];  
        if(min_in_max>maxlength)  
        {  
            min_in_max=maxlength;      
            flag_source=i;            
        }  
    }  
    if(min_in_max<inf)  
        cout<<flag_source<<' '<<min_in_max<<endl;  
    else  
        cout<<"disjoint"<<endl;  
    return;  
}  
  
int main(void)  
{  
    while(1)  
    {  
        memset(dist,inf,sizeof(dist));  
        cin>>n;       
        if(!n)break;  
  
        for(i=1;i<=n;i++)  
        {  
            int pair;  
            cin>>pair;  
            for(j=1;j<=pair;j++)  
            {  
                int cat,time;      
                cin>>cat>>time;  
                dist[i][cat]=time;  
            }  
        }  
        floyd();  
    }  
    return 0;  
} 