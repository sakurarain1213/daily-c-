#include <bits/stdc++.h>
using namespace std;
//堆排序  要按照课本

int main()
{
   int a[2001]; 
   priority_queue<int> pq;
   vector<int > t;//临时存储 用于输出。
int n;cin>>n;
for(int i=0;i<n;i++)
{cin>>a[i];pq.push(a[i]); /*t.push_back(a[i]); */}

    while( !pq.empty() ){
      t.push_back(pq.top());
    //  cout<<t.back();
       pq.pop(); 
    }       
//改变print输出顺序  （换子树）即可

 for(int i = 1; i < n-1; i+=2)
 {
swap(t[i],t[i+1]);
 }

  for(int i = 0; i < n; ++i)
  cout <<t[i] << ' ';

/* for(int i=1;i<=(int)(log(n))+1;i++)
{  
      if(i==(int)(log(n))+1)
      {
              for(int j=n;j>=pow(2,i-1);j--)
              cout<<t[j-1]<<' ';
             // cout<<"aaa"<<endl;
      }
      else 
      {
              for(int j=pow(2,i)-1;j>=pow(2,i-1);j--)
              cout<<t[j-1]<<' ';
                   //  cout<<"bbb"<<endl;
      }
} */
 

cout<<endl;
sort(a, a+n);
 for(int i = 0; i < n; ++i)
  cout << a[i] << ' ';

    return 0; }





/* 
5
6 3 8 2 5

7
6 3 8 9 5 1 2


【输出】
8 5 6 2 3//输入序列构造的初始大根堆
2 3 5 6 8

 */


/*这个版本挺好的 只是和oj的建堆顺序不一样罢了  子树互换 本质上就是每层下标倒序


 void adjust_heap(int arr[], int root, int length){
        int left = 2*root + 1;
        int right = 2*root + 2;
        int max = root;
        if( left < length && arr[left] > arr[max])
                max = left;
        if( right < length && arr[right] > arr[max])
                max = right;
        if(max != root){
                swap(arr[max], arr[root]);
                adjust_heap(arr, max, length);
        }
}

void heap_sort(int* arr, int len){
		//初始化建堆：
        for(int i = len/2 -1; i >= 0; --i)
                adjust_heap(arr, i, len);
         //排序重建堆     
        for(int i = len - 1; i >= 0; i--){
                swap(arr[0], arr[i]);           //堆顶元素和末尾元素进行交换
                adjust_heap(arr, 0 , i);        // 对顶点进行一次堆排序
        }
}

int main(){
int a[2001];
int n;cin>>n;
for(int i=0;i<n;i++)
{cin>>a[i]; }
adjust_heap(a,0,n);
        for(int i = 0; i < n; ++i)
                cout << a[i] << ' ';
        cout << endl;
  heap_sort(a, n);
        for(int i = 0; i < n; ++i)
                cout << a[i] << ' ';
        return 0;
} */