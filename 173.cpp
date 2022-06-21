#include <bits/stdc++.h>
using namespace std;
//排序上机 //快排课本实现 尾轴
int main(){
int a[2001];
int n;cin>>n;
for(int i=0;i<n;i++)
{cin>>a[i];}
/* 
int left=1;int right=n;
    //取最后一个元素作为枢纽
 int pivot= a[0];
    int i = left;
    int j = right-1;
    while(true)
    {
        //从前向后扫描，找到第一个小于枢纽的值，
        //在到达数组末尾前，必定结果循环,因为最后一个值为centre
        while(a[i] <pivot)
            ++i;
        //从后向前扫描，此时要检查下标，防止数组越界
        while(j >= left && a[j] >pivot)
            --j;
        //如果没有完成一趟交换，则交换
        if(i < j)
            swap(a[i++],a[j--]);
        else
            break;
    }
 */

 //a
swap(a[0],a[n-1]);
int n1=0,n2=0;
int mi[1001],ma[1001];
for(int i=1;i<n;i++)
{
    if(a[i]<=a[0]) {mi[n1]=a[i];n1++;}
    else {ma[n2]=a[i];n2++;}
}
 for(int i=0;i<n1;i++)
{cout<<mi[i]<<" ";}cout<<endl;
for(int i=0;i<n2;i++)
{cout<<ma[i]<<" ";}cout<<endl; 
for(int i=1;i<=n1;i++)
{
    a[i]=mi[i-1];
}
for(int i=n1+1;i<=n2+n1+1;i++)
{
    a[i]=ma[i-1-n1];
}
//cout<<n1<<n2;
 for(int i=0;i<n;i++)
{cout<<a[i]<<" ";}
cout<<endl; 
 swap(a[0],a[n1]);
 


for(int i=0;i<n;i++)
{cout<<a[i]<<" ";}
cout<<endl;
sort(a,a+n);
for(int i=0;i<n;i++)
{cout<<a[i]<<" ";}

return 0;} 
/*
5
6 3 8 2 5
【输出】
2 3 5 8 6
2 3 5 6 8


7
15 9 6 7 3 2 8
*/