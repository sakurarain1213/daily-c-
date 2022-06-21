#include <bits/stdc++.h>
using namespace std;

//测试 链表的迭代器可以凭空++ 再赋值

struct T
{
int x;//系数
int y;//指数
};

int  main ()
{

list <T> a;

list <T> ::iterator i;

int x;

i=a.begin();
T temp;
temp.x=1;temp.y=2;
a.push_back(temp);
temp.x=3;temp.y=4;
a.push_back(temp);
temp.x=3;temp.y=6;
a.push_back(temp);
a.pop_front();
cout<<a.front().x;
for(i=a.begin();i!=a.end();i++)
{
    cout<<i->y;
}


return 0;
}