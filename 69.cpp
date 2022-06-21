
#include <bits/stdc++.h>
using namespace std;
//stl的 链表实现 且元素是结构体
struct T
{
   int x;//组名
   int y;//值
};


void f(int count )
{
    int o[1000];
    int O=0;
list <T> l;
//int count=1;
string operat;
list <T> ::iterator i;//迭代器 
cin>>operat;

while(operat!="STOP")
{


   if(operat=="ENQUEUE")
{
 int havein=0;//判断是否已经入队
      // 
    int a,b;cin>>a>>b;
   // cout<<a<<b;
    T temp;
    temp.x=a;temp.y=b;
for(i=l.end();i!=l.begin();i--)
  {
    if(!havein&&i->x==a &&i!=l.end()) //迭代器表示结构体元素时需要用->
    { i++;
      l.insert(i,temp);havein=1;
      break;
    }
    else if(!havein&&i->x==a &&i==l.end())
    {
     l.push_back(temp);havein=1;
     break;
    }
  }
//循环结束后i已经等于begin  此时再看看是不是同组
if(!havein&&i==l.begin()&&i->x!=a)//找不到同一组
  {
    l.push_back(temp);havein=1;
  }

else if(!havein&&i==l.begin()&&i->x==a)
 {     i++;
      l.insert(i,temp);havein=1;
    }

//
//

/*  for(i=l.begin();i!=l.end();i++){

  cout<<i->x<<" " <<i->y<<endl;
}  */
////
}

 if(operat=="DEQUEUE")
{
//cout<<l.front().y<<endl;
o[O]=l.front().y;O++;
l.pop_front();

}


cin>>operat;//还要再读 不要忘了


}
 cout<<"Scenario #"<<count<<endl;
/* for(int r=0;r<O;r++)
cout<<o[r]<<endl;
 */

}
int  main ()
{
int t;
int count=1;
scanf("%d",&t);
while(t!=0)
{
  f(count);count++;scanf("%d",&t);
}



return 0;
}

/* 
1
ENQUEUE 1 1
ENQUEUE 1 2
ENQUEUE 2 100
ENQUEUE 2 200
ENQUEUE 1 300
ENQUEUE 1 4000
DEQUEUE
1
DEQUEUE
2
DEQUEUE
1



2
ENQUEUE 1 101
ENQUEUE 2 201
ENQUEUE 1 102
ENQUEUE 2 202
ENQUEUE 1 103
ENQUEUE 2 203
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP


2
ENQUEUE 1 101
ENQUEUE 2 201
ENQUEUE 1 102
ENQUEUE 1 103
ENQUEUE 1 104
ENQUEUE 1 105
DEQUEUE
DEQUEUE
ENQUEUE 2 202
ENQUEUE 2 203
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP


 */