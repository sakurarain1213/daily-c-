#include <bits/stdc++.h>
using namespace std;
//函数可以借用指针来返回数组
//或者改变同一片地址的值就行

void solve(int*arr, int N,int* t/*传入t的地址*/)//t=1才停止
{
   *t=1;
    for(int i = 0; i < N; i++)
    {
        int count = 0;
        for(int j = i+1; j < N; j++)
        {
            if(arr[j] < arr[i])
                count++;
        }
        if(arr[i] != count)
        {
            arr[i] = count;
           *t= 0;
        }
    }
}

void f(int x)
{

int n;
cin>>n;
int a[1000];
memset(a,0,sizeof(a));
for(int i=0;i<n;i++)
{
   cin>>a[i];
}
int t=0;
solve(a,n,&t);

while(t==0)
{
 solve(a,n,&t);
}
cout<<"case #" << x << ":\n";
for(int j=0;j<n;j++)
{
   cout<<a[j]<<" ";
}
    cout<<endl;

}
int  main ()
{
    int x;
cin>>x;
for(int i=0;i<x;i++)
{f(i);
}
return 0;
}
/* 3
10
5 44 19 6 49 1 27 19 50 20
10
3 2 7 10 9 8 8 5 1 5
10
12 12 19 19 7 10 9 6 18 9
 */