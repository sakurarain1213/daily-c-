 #include <bits/stdc++.h>
using namespace std;

//记录过程的dfs迷宫


int dx[5]={0,0,-1,0,1};        //介值（注意：有优先级   ）
int dy[5]={0,-1,0,1,0};
int a[20][20],ans[10000][3],vis[20][20],n,m,a1,a2,b1,b2,k=1,total=0;   
 //a是同map数组，ans存的是答案，vis判断点去过，k是当前答案长度，total用来判断有没有答案  

void write(int c)           //输出函数
{
//  cout<<'(',a1<<','<<a2')'<<"->";
    for (int i = 1; i <= c; i++)
        cout<<'('<<ans[i][1]<<','<<ans[i][2]<<")->";
    cout<<'('<<b1<<','<<b2<<')'<<endl;
    total++;             //方案数++
}

void search(int x,int y)        //x，y是当前的位置
{
    if (x == b1 && y == b2)      //找到目标点了
        {
            cout<<k;write(k-1);      //从k-1个开始输出
            return;          //回溯
        } 
     else             //没找到就继续找
      {
          for (int i = 1; i <= 4; i++)          //四个方向开始搜
            if (a[x+dx[i]][y+dy[i]] == 0 || vis[x+dx[i]][y+dy[i]] == 1) continue;   //要跳过的条件
           else       //反之就是可以走
             {
                   ans[k][1] = x;      //记录x轴答案
                  ans[k][2] = y;      //y轴答案
                  k++;                //答案的长度+1；
                 vis[x+dx[i]][y+dy[i]] = 1;     //打标记
                 search(x+dx[i],y+dy[i]);       //向前搜
                 vis[x+dx[i]][y+dy[i]] = 0;     //回溯
                  k--;
            }
      }
}

int main()
{
    memset(a,0,sizeof(a));        
    memset(vis,0,sizeof(vis));    

    cin>>n>>m;                       //输入
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin>>a[i][j];
    cin>>a1>>a2>>b1>>b2;       //起点和终点
    vis[a1][a2] = 1;    //起点要标记！
    search(a1,a2);      //从给出的点开始搜
    if (total == 0) cout<<-1;     //无解情况的输出
    return 0;      //完美的结束程序
}

/*  example
5 6
1 0 0 1 0 1
1 1 1 0 1 1
0 0 1 0 1 0
1 0 1 1 1 0
1 1 1 0 1 1

1 1 
4 1

 */