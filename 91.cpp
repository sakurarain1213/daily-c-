#include <bits/stdc++.h>
using namespace std;


int min(int a,int b)
{
 string c="";int d;
 for(int i=2;i<a;i++)
 { c="0"+c;}
c="1"+c;
c=c+to_string(b);
d=stoi(c);
//while(d%3!=0)
//{ d++;}
return d;
}

int max(int a,int b)
{
 string c=""; int d;
 for(int i=1;i<a;i++)
 {  c="9"+c; }
c=c+to_string(b);
d=stoi(c);
return d;
}

void f(int x)
{
int a,b;
cin>>a>>b;   int t=0;
for(int i=min(a,b);i<=max(a,b);i+=10)
{ 
    if(i%3==0)t++; 
}

cout<<"case #" << x << ":\n";
cout<<t<<endl;

}





int  main ()
{
int x;
cin>>x;
for(int i=0;i<x;i++)
{
    f(i);
    }

//cout<<max(a,b);
return 0;
}