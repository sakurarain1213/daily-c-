/*
数据结构   大作业  哈希表查地理距离   尽量用不同时间复杂度的方法  制时间表

每家商户包括以下三项信息：
1. 位置x y都>0  
2. 商家名称；12位大写字符串，不含小写；
3. 菜系，6位字符串，不含小写；

输入n个数据   m个要查的数据
5 3
JEANGEORGES 260036 14362 FRENCH
HAIDILAO 283564 13179 CHAFINGDIS
KFC 84809 46822 FASTFOOD
SAKEMATE 234693 37201 JAPANESE
SUBWAY 78848 96660 FASTFOOD
HAIDILAO
SAKEMATE
SUBWAY
输出
283564 13179 // HAIDILAO
234693 37201 // SAKEMATE
78848 96660 // SUBWAY

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
//先用最快的  菜系不输出 可以不存
std::ios::sync_with_stdio(false);
 map<string,pair<string,string>> mp;
long long int m,n; pair<string,string> number;
string name,temp;
cin>>n>>m;
while(n--){
cin>>name>>number.first>>number.second>>temp;
    mp[name]=number;
}
while(m--){
    cin>>temp;
    cout<<mp[temp].first<<' '<<mp[temp].second<<endl;
}
	return 0; 
} 


//然后从最慢的顺序查找开始；

//输入是字典序的 所以可以链式加二分
/* struct T
{
   string name;
  pair<string,string> number ;
};

vector <T> a;
long long int m,n,cnt=0;T t;string ss;
cin>>n>>m;
while(n--){
cin>>t.name>>t.number.first>>t.number.second>>ss;
   a.push_back(t);cnt++;
}
while(m--){
    cin>>ss;long long int i=0,j=cnt,m=(i+j)/2;
    while(i<=j)
    {
        if(a[m].name<ss)
        {
           i=m+1;m=(i+j)/2;
        }
        else if(a[m].name>ss)
        {
           j=m-1;m=(i+j)/2;
        }
        else 
        {
            cout<<a[m].number.first<<' '<<a[m].number.second<<endl;break;
        }
    }

}
	return 0; */




