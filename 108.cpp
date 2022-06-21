#include <bits/stdc++.h>
using namespace std;
//dfs 全排列的公式法
/* void p(int *p,int n)
{
for(int i=0;i<n;i++)
{
   cout<<*(p+i)<<" ";
}
cout<<endl;
}

 unsigned long long int jc (int n)
            {
              unsigned long long int jiecheng;jiecheng=1;int i;
             for (i=1;i<=n;i++)
            {  jiecheng=jiecheng*i;}
             return jiecheng;
             }

int  main ()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
    a[i]=i+1;
}
int count=1;
cout<<count<<":";
p(a,n);
while(next_permutation(a,a+n)&&count<10)
{
     count++;
     cout<<count<<":";
     p(a,n);
}
 cout<<jc(n);

return 0;
} */



//递归函数 回溯法
//递归函数每次return只会回到上一层 不是完全结束 为关键  所以要void   形参一般是每次有解的深度 这里是x 也可以叫step deep


/* 
dfs(para1, para2, ...)
 {
     if()//满足状态，返回
     {
         ....
         return ;
     } 
     //递归向下，继续搜索
     for(....)
        dfs(depth+1, ....) ;

    return ;
 }

 */





int n;int cnt=1;
int a[1000];
int b[1000];//用来判断是否已经用过  或者直接在 递归函数内部加一个flag就行
void s(int x)
{
if(x==n+1)
{
cout<<cnt<<endl;cnt++;//这里可以输出数组
}
//else  是不需要的

    for(int  i=0;i<x;i++)
    {
    if(b[i]==0) 
    {a[x]=i;
      b[i]=1;
      s(x+1);       //递归
      b[i]==0  ;   //注意再次清零
    }
  


    }







return;
}


int  main ()
{
cin>>n;
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));

for(int i=0;i<n;i++)
{
    a[i]=i+1;
}

cout<<cnt<<":";

return 0;
} 