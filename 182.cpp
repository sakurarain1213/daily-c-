#include <bits/stdc++.h>
using namespace std;
//排序上机//堆排序 
//本质上STL的优先队列就是大根堆  但是教材上的大根堆子树顺序和stl要反一下 print解决就行


int main(){
int n=4;
cout<<(int)(log(n));

return 0;} 


/* 
5
6 3 8 2 5 

7
1 2 3 4 5 6 7

*/








/*
6 3 8 2 5 -1
2
12 7 9 -1
//初始序列
//从优先级队列中删除2个元素
//依次插入3个新的值，插入12时，先把12追加到堆的尾部，然后再自下而上的调整堆。
【输出】
8 5 6 2 3
5 2 3                //删除了2个元素8，6后的优先级队列
12 7 9 2 5 3            //依次插入12，7，9后的堆
*/



/* class pq
{
    private:
        vector<int> data;         
    public:
        void push( int t ){ 
            data.push_back(t); 
            push_heap( data.begin(), data.end());
			//在vector中加好了（push_back），再使用这个函数重新调整一下堆
        }         
        void pop(){
            pop_heap( data.begin(), data.end() );
            //使用后，root 结点就被放到了vector的最后，再使用vector的pop_back()删除
            data.pop_back();
        }         
        int top() { return data.front(); }
        int size() { return data.size(); }
        bool empty() { return data.empty(); }
};   */