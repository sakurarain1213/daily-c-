#include <bits/stdc++.h>
using namespace std;
//排序上机//堆排序 
//本质上STL的优先队列就是大根堆

int a[2001];
void adjustDown(int key, int length) {
    a[length-1]= a[key];
    int  j;
        for (j =key*2; j <=length; j*=2)
        {
            if (j<length && a[j]<a[j+1]) {
                j++;
            }
            if (a[0] >=a[j]) {
                break;
            }
            else {
                a[key] = a[j];
                key = j;
            }
           
        }
        a[key] = a[0];
}

void build_heap(int length) {
    for (int i = length/2; i >0; i--)
    {
        adjustDown(i,length);
    }
}

void heap_sort(int length) {
    build_heap(length);
    for (int i =length; i>0; i--)
    {
        cout << a[1] << " ";
        swap(a[1], a[i]);
        adjustDown(1,i-1);
    }
}

int main(){
//priority_queue<int> pq;
//priority_queue<int, vector<int>, greater<int>> xxxx 小根堆
int n;cin>>n;
for(int i=0;i<n;i++)
{cin>>a[i];}
//本质上建堆输出需要随时调整全堆位置 ，不是静态建好的  而且动态的stl也不对 不知道为什么



 build_heap(n-1);
for(int i=0;i<n;i++)
{cout<<a[i]<<" ";}
cout<<endl;

sort(a,a+n); //  my_heap_sort(10);
//sort(a.begin(),a.end());
for(int i=0;i<n;i++)
{cout<<a[i]<<" ";}

return 0;} 
/*
3
9 6 1
*/