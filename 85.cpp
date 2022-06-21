#include <bits/stdc++.h>
using namespace std;
// 链表 约瑟夫环

int  main ()
{
list<int > l;
list <int > :: iterator i=l.begin();
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)
{    l.push_back(i);
}
i++;
while (l.size()>1)//注意不能只有一个元素 这样头尾会重合
{
    for(int x=1;x<m;x++)
  {    ++i;
    if(i==l.end())   i=l.begin();
  }
//cout<<*i<<" ";
//注意直接用erase的时候迭代器变量会失效 所以需要i=l.erase(i);此时i会自动++
i=l.erase(i);
if(i==l.end())   i=l.begin();
/*  cout<<"    ";
for( temp=l.begin(); temp!=l.end(); temp++)
{ cout<<* temp<<" ";} */
}
cout<<l.front();//最后剩一个人 输出
return 0;
}