#include <bits/stdc++.h>
using namespace std;
//颜色排序
//第一种是计数三个元素分别的个数，最后一个for循环覆盖原先的数组。
//第二种是两个值维护0和2的位置，遍历数组，如果是0，往左边移动，如果是2，往右边移动。
int main(){
vector<int > a;
int t;int cnt=0;
while(cin>>t)
{
    a.push_back(t);//这个时候不要a【cnt++】=t
    if(cin.get()=='\n') break;
}
  int n = a.size();
 // cout<<n;
        int l = 0, r = n-1;
        //双指针
        for (int i=0; i<n; ++i) {
            if (i == r+1) break;
            if (a[i] == 0) {
                swap(a[l++], a[i]);
            }else if (a[i] == 2) {
                swap(a[r--], a[i]);
                i--;
            }
        }
 for (int i=0; i<n; ++i) 
 {
     cout<<a[i]<<" ";
 }




return 0;} 

/* 【输入】2 0 2 1 1 0
【输出】0 0 1 1 2 2 */