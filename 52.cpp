#include <bits/stdc++.h>
using namespace std;

void f(int x)
{
string s;//分割字符串为单词的方法  利用string 本身读入就终止   所以第二种是substr
getline(cin,s);
istringstream is(s);
string temp;
string a[100];
int i=0;
while(is>>temp)
{
//cout<<temp<<endl;
a[i]=temp;
i++;
}

 int j=i;
 while(j>=0)
{cout<<a[j];j--;} 
 


sort(a,a+i-1);
cout <<"case #"<<x<<":"<<endl;
for(int n=0;n<i;n++)
{
   if(a[n+1]!=a[i]) cout <<a[n]<<" ";
}
cout<<endl;

}


int  main ()
{

int x;
scanf("%d\n",&x);
for(int k=0;k<x;k++)
{
f(k);

}



return 0;
}