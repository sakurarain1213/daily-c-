 #include <bits/stdc++.h>
using namespace std;
 int beginx,beginy,endx,endy;
//深搜dfs 的迷宫应用   个人解法

bool ok=false;
int a[102][102];//记录迷宫本身
int f[102][102];//用于记录是否经历
int m,n;//最大边长
 int step=0;//记录花费的步数
int dx[4] = {0,-1,0,1};   // 方向数组 
int dy[4] = {-1,0,1,0};
int mini=9999;
void dfs(int x,int y)//参数只需要记录当前坐标
{

    //边界点需要判断？不用 从1 1开始记录 四周自动是0
   if(x==endx&&y==endy)
   {
     ok=true;
     if(mini>step) mini=step;
       return;//问题在这里 找到终点了 回溯一步而已 然后又回到终点  在终点左右反复 导致爆栈
   }

     for(int k=0;k<=3;k++)
      {//每一步 搜四个方向
      //  int tx=x+dx[k];int ty=y+dy[k];
        if(  a[x+dx[k]][y+dy[k]]==1  &&   f[x+dx[k]][y+dy[k]]==0  )
        {
           f[x+dx[k]][y+dy[k]]=1;
           step++;//步数+1

           dfs(x+dx[k],y+dy[k]);
           f[x+dx[k]][y+dy[k]]=0;
           step--;//回溯之后步数也要减
           
        } 
        else continue;
    

   } 
   
   return;  //这一句 可要可不要需要
}

int main() {
 memset(f,0,sizeof(f));
 memset(a,0,sizeof(a));
cin>>m>>n;
for(int i=1;i<=m;i++)
{
for(int j=1;j<=n;j++)
{
    cin>>a[i][j];
}
}

/*  for(int i=0;i<=m+1;i++)
{
for(int j=0;j<=n+1;j++)
{
   cout<<a[i][j]<<" ";
}
cout<<endl;
}    */
cin>> beginx>>beginy>>endx>>endy;
f[beginx][beginy]=1;

dfs( beginx,beginy);
if(ok==false) cout<<-1;
else cout<<mini;

    return 0;
}  

/*  example
5 6
1 0 0 1 0 1
1 1 1 0 1 1
0 0 0 1 1 0
1 1 1 1 1 0
1 1 1 0 1 1
3 4
4 4

 */