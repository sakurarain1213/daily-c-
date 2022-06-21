#include <bits/stdc++.h>
using namespace std;


void f(int x)
{

stack <char >c;
string s;
cin>>s;
int n=s.length();
for(int i=0;i<n;i++)
{
    c.push(s[i]);
}
bool t=true;

while(n>1&&t)
{
    char temp1=c.top();
     c.pop();
    char temp2=c.top();
if(temp1!=temp2)
    {
         c.pop();
         n-=2;
    }
else {t=false;}//c.push(temp1);


}

cout<<n<<endl;



}




int  main ()
{
int x;
cin>>x;
while(x>0)
{
    f(x);
    x--;
}
return 0;
}