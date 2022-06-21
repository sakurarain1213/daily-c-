
#include <bits/stdc++.h>
using namespace std;
//stl的 链表实现 



int  main ()
{

list <int > l;
list <int > ::iterator i;
int t;
string operat;
scanf("%d",&t);
l.push_back(t);l.push_back(1);l.push_back(2);
for(i=l.begin();i!=l.end();i++)
{
   l.insert(i,100); 
}
for(i=l.begin();i!=l.end();i++)
{
  cout<<*i<<"   ";
}




return 0;
}