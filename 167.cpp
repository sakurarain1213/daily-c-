#include <bits/stdc++.h>
using namespace std;
//本质上建立字典序的比较
int com(int a, int b){//比较函数
return to_string(a) + to_string(b) > 
to_string(b) + to_string(a);}// 在class solution 时 [](参数){函数体} 匿名函数
int main(){
vector<int> a;  string ans;int t;
        while(cin>>t){
            a.push_back(t);
             if(cin.get()=='\n') break;}
    sort(a.begin(), a.end(), com); 
        for(auto it: a){           //迭代器
            ans += to_string(it);}
      if(a[0]== 0) cout<< "0" ; // 特例 [0,0] ans=0  不是00
      else cout<<ans;
return 0;}
//3 30 34 5 9