#include<bits/stdc++.h>
using namespace std;//除了最高位 后续补成同位数的string比

bool cmp(char *a ,char *b){
   long long numA= 0 ,numB = 0;
   sscanf(a,"%lld",&numA);//将字符转换成数字
   sscanf(b,"%lld",&numB);
   char firstA = a[0];
   char firstB = b[0];
   if(!iswdigit(firstA)){//判断最高位是不是数字
      a++;
   }
   if(!(iswdigit(firstB))){
      b++;
   }
   if(*a != *b){
      return *a-*b>0;//先按照最高位的值从大到小进行排序。
   }
   return numA - numB < 0;//若两个数的最高位的值相同，则按照数本身值由小到大排序。

}

void solve(int i){
   int n;
   cin >>n;
   char *arr[n];
   for(int i =0 ;i  < n ;i ++){
      arr[i] = new char[22];
   }
   for(int i =0 ;i < n ;i ++){
      cin >> arr[i];
   }

   sort(arr,arr+n,cmp);

   cout << "case #" << i << ":"<<endl;
   for(int i= 0;i < n;i++){
      cout << arr[i] <<" ";
   }

}

int main()
{
   int t;
   cin >> t;
   for(int i = 0 ;i <t ;i++){
      solve(i);
      cout << endl;
   }
    return 0;
}
