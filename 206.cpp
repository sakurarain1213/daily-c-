
/*优先队列 一个大小为k的最大堆
里面放一个 pair 对，由距离原点的距离，和该点在原数组中的下标组成，
这样优先队列就可以按照到原点的距离排队，
距离大的就在队首  当个数超过k个了之后
将队首的元素移除即可，最后把剩下的k个点存入结果 res 中
：*/
#include <bits/stdc++.h>
using namespace std;
//针对pair点的自定义排序和优先队列

//calculate angle
bool angle(float x1, float y1, float x2, float y2)
{
float t=acos((x1*x2+y1*y2)/pow(x1*x1+y1*y1,0.5)/pow(x2*x2+y2*y2,0.5));
return t>0;
}

struct cmp
{
  bool operator()(pair<int, int>&a,pair<int, int>&b)
{
    if(a.first*a.first+a.second*a.second!=b.first*b.first+b.second*b.second)
       { return a.first*a.first+a.second*a.second>b.first*b.first+b.second*b.second;}
       else{
              int x1=a.first,y1=a.second,x2=b.first,y2=b.second;
              if(x1>0&&y1>0||x2>0&&y2<0)return false;
              else if(x1>0&&y1<0||x2>0&&y2>0) return true;
              else return y1<y2;
       }

   //按照象限排序本质是按照旋转角排序
}
};

int main() {
     priority_queue<pair<int, int>,vector<pair<int, int> >,cmp> pq;
        pair<int, int> t;
 int k;int cnt=0;
cin>>k;
int x,y;int a[1001]={0},b[1001]={0};

while(cin>>a[cnt]>>b[cnt])
{
cnt++;
if(cin.get()=='\n')break;
}

        for (int i = 0; i <cnt; ++i)
            {pq.push({a[i], b[i]});}

    while(k)
    {
        t=pq.top();
        cout<<t.first<<' '<<t.second<<' ';
        pq.pop();
        k--;
    }
    return 0;
}
/*2
3 3 5 -1 -2 4*/
/* 【输入】第一行K值，K为正整数，K小于1000；
第二行，n个点的坐标值(x,y)。
【输出】K个离原点最近的坐标点信息。（若存在多个点与原点距离相等，则按照第1象限Quadrant，第2象限，第3象限，第4象限来取。）
例如：
【输入】
2
3 3 5 -1 -2 4//坐标点(3,3),(5,-1),(-2,4),
【输出】
3 3 -2 4//坐标点(3,3),(-2,4)按照由近及远来排序
 */