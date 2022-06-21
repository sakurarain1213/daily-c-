#include <bits/stdc++.h>
using namespace std;
//由于会出现重复value 所以用结构体排序 不能用map
//由于要按照输入顺序再输出 搞个链表即可
struct tt{
    string s;
    int v;
}t[200];
int comp(const tt &a,const tt &b)
{ return a.v>b.v;}
list <tt> l;
list <tt> ::iterator it;
int  main ()
{
int n;int max=-1;
cin>>n;
  for (int i=0;i<n;i++)     
       { cin>>t[i].s>>t[i].v;
       tt temp;
       temp.s=t[i].s;temp.v=t[i].v;
       if(temp.v>max) max=temp.v;
       l.push_back(temp);
       }
 for ( it=l.begin();it!=l.end();it++)     
          {  if(it->v==max)cout<<it->s<<endl;  }
return 0;}

/* 结构体与sort排序的完美结合
struct student
{
    float score;
    int id;
}a[101];
int comp(const student &a,const student &b)
{
    return a.score>b.score;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;++i)      
        cin>>a[i].id>>a[i].score;
    sort(a+1,a+n+1,comp);
    cout<<a[k].id<<' '<<a[k].score<<endl;
 */


/* 10
www.youtube.com 10
www.google.com 10
www.google.com.hk 3
www.alibaba.com 13
www.taobao.com 5
www.bad.com 13
www.good.com 7
www.baidu.com 8
www.university.edu.cn 13
www.ecnu.edu.cn 13 */