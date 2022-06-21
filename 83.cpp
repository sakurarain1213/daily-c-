#include <bits/stdc++.h>
using namespace std;

int  main ()
{

int n;
cin>>n;
int a[1000];
memset(a,0,sizeof(a));
for(int i=0;i<n;i++)
{   
    cin>>a[i];
}
int x,y;
cin>>x>>y;
int t=0;
//cout<<x<<y;
/* for(i=l.begin();i!=l.end();i++)
{
    if(*i==x)
    {   
        cout<<"123555555";
         i++;
        l.insert(i,y);
        
    }
    else i++;
}
 */
/* 
while(!l.empty())
{
    cout<<l.front()<<" ";
    l.pop_front();
} */
for(int i=0;i<n;i++)
{
if(a[i]==x)
{
cout<<i+1+t<<" ";
t++;
}

}


return 0;
}