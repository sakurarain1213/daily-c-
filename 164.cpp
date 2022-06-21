#include <bits/stdc++.h>
using namespace std;

list<int>l,lt;
list<int> ::iterator i,j;
int main(){
int n,t;
cin>>n;
int nn=n;
double cnt=1.0*n/2;
while(nn)
{
cin>>t;l.push_back(t);
if(nn>cnt+0.5) lt.push_back(t);
    nn--;
}
/*  for(j=lt.begin();j!=lt.end();j++)
{
    cout<<*j<<" "<<endl;
}  */

lt.sort();
for(j=lt.begin();j!=lt.end();j++)
{
    cout<<*j<<" ";
}
i=l.begin();
for(int k=0;k<cnt+1;k++)
{i++;}
 if(n%2==1){i--;i--;}//微妙的debug
else  i--;
for(;i!=l.end();i++)
{ cout<<*i<<" ";}

l.sort();
cout<<endl;
for(i=l.begin();i!=l.end();i++)
{   cout<<*i<<" ";}
return 0;}

/* 
5
9 3 8 2 5

3 9 8 2 5//输出有序序列长度为2（5/2）时的结果
2 3 5 8 9


6
4 5 2 7 1 7

14
1 6 7 8 9 0 9 8 7 6 5 4 3 2


 */