#include <bits/stdc++.h>
using namespace std;
 struct qu//区间 结构
{
  int begin;
  int end;
};
    bool comp(const qu& a, const qu& b)
    { return a.begin < b.begin;} //按照起点从小到大排
int main(){
vector <qu> a ;//区间构成的数组 
vector <qu> ans;
 int n; int x,y; qu temp;
    cin>>n;   if(n==0) return 0;
    while(n--)//debug  此后就不要用n了  它已经=0
    {
        cin>>x>>y;
        temp.begin=x;temp.end=y;
        a.push_back(temp);
    }
       sort(a.begin(),a.end(),comp);

     //  cout<<a.back().begin;
       ans.push_back(a[0]);
        for(int i=1;i<a.size();i++){     //这段核心代码有问题  不要用n  用a.size()
            if(a[i].begin <=  ans.back().end) 
                  { ans.back().end =  max (a[i].end,ans.back().end); }
            else
               {ans.push_back(a[i]);  }}
  for(auto it: ans)         //迭代器it  print  ans
 { cout<<it.begin<<" "<<it.end<<" ";}                      
return 0;} 
/*4
1 3 2 6 15 18 8 10
*/
//合并区间问题   
/* 根据区间左侧排序，遍历vector逐个比较或合并。
sort函数按qu的start值从小到大排，但vector数据类型是qu 自定义比较函数  
vector第一个元素push 到res中，遍历给定的区间，每次都与res中最后一个元素进行比较，
若是区间的左侧小于res中的右侧值，则有重叠区域（因为原给定的区间已经按照左侧值排序）将这个区间合并，更新res尾元素；
否则，没有重叠区域，直接将该区间加到res，直到遍历完 */
/* 另外一个版本
vector<pair<int,int> > temp,ans;
int main()
{
    int n,i=0;
    cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        temp.push_back({x,y});
    }
    sort(temp.begin(),temp.end());
    int st=-2e9,ed=-2e9;
    for(auto &x:temp)
    {
        if(ed<x.first)
        {
            if(st!=-2e9) ans.push_back({st,ed});
            st=x.first,ed=x.second;
        }
        else
        {
            ed=max(x.second,ed);
        }
    }
    if(st!=-2e9&&ed!=-2e9)
    ans.push_back({st,ed});
    cout<<ans.size()<<endl;
} */



