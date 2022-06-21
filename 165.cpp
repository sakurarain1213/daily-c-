#include <bits/stdc++.h>
using namespace std;

//int INCRGAP = 2;
void shellSort(int a[],int len,int gap)
{
    int insertNum = 0;
   // unsigned gap = len/INCRGAP; // 步长初始化
   // while(gap) // while gap>=1
  //  {
        for (unsigned i = gap; i < len; ++i) // 分组，在每个子序列中进行插入排序
        {
            insertNum = a[i];//将当前的元素值先存起来方便后面插入
            unsigned j = i;
            while (j >= gap && insertNum < a[j-gap])//寻找插入位置
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = insertNum;
       }
        //gap /=INCRGAP;
    // }
  for(int  i=0;i<len;i++)
    {cout<<a[i]<<" ";}
cout<<endl;

}
int main()
{
    int n,m;int i;
    cin>>n>>m;
    int a[1001] ; memset(a,0,sizeof(a));
    for( i=0;i<n;i++)
    {cin>>a[i];}
      int gap[11] ; memset(gap,0,sizeof(gap));
        for( i=0;i<m;i++)
    {cin>>gap[i];}

   for( i=0;i<m;i++)
    { shellSort(a,n,gap[i]);}

    return 0;
}
/* 
希尔排序

7 3        
26 33 35 29 19 12 22
5 3 1

 //7个整数，3个分组
 //整数序列

 12 22 35 29 19 26 33 // increment为5的排序结果
12 19 26 29 22 35 33 // increment为3的排序结果
12 19 22 26 29 33 35 // increment为1的排序结果
 */