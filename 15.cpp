#include <bits/stdc++.h>

using namespace std ;

struct s
{
    string num;//c++string 的比较函数是 s1.conpare(s2);
    int score;
}a[101];


int cmp(s p1 , s p2)//结构体排序
{
    int a=p1.score-p2.score;
 if (a>0)return 1;
 else if(a<0)return -1;
 else if((p1.num).compare(p2.num)>0)return -1;
  else if((p1.num).compare(p2.num)<0)return 1;
  else return 0;
  
}


 void sort(struct s *a,int n)   //可以用qsort 也可以自定义sort函数
{
int i,j,k;
 s temp;
for (int i=0;i<n-1;i++)
{
k=i;
for (j=i+1;j<n;j++)
{if (cmp(a[k],a[j])<0) k=j;}
temp=a[i];a[i]=a[k];a[k]=temp;
}
} 



int  main ()
{
int n;
cin>>n;
for (int i=0;i<n;i++)
{
    cin>>a[i].num>>a[i].score;
}
sort(a,n);

for (int i=0;i<n;i++)//判断及格与否
{
   if (a[i].score<60) {n=i;break;}
}

for (int i=0;i<n;i++)
{
    cout<<a[i].num<<" "<< a[i].score<<endl;
}
return 0;
}