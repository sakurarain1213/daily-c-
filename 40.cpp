#include <bits/stdc++.h>
using namespace std ;

int  main ()
{
int n;
cin>>n;
stack <int> a;
for(int j=0;j<n;j++)
{
char ss[1000];
scanf("%s",ss);
int i;
for( i=0;i<strlen(ss);i++)
{

if(ss[i]=='I')a.push(0);
else if(ss[i]=='O'&&a.size()>0)a.pop();
else(i=INT_MAX);

}
if(i==strlen(ss)) cout<<"true"<<endl;
else cout<<"false"<<endl;
while(!a.empty())
{ a.pop();}
}


return 0;
}