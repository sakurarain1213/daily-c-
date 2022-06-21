 #include <bits/stdc++.h>
using namespace std;
//dfs 套模板的寻路
//dfs 可以不要step参数 也可以要 见118      其它题的dfs也可以有返回值
 int beginx,beginy,endx,endy;
//深搜dfs 的迷宫应用   个人解法
bool ok=false;
int a[102][102];//记录迷宫本身
int f[102][102];//用于记录是否经历
int m,n;//最大边长
 int step=1;//记录花费的步数
int dx[4] = {-1,0,1,0};   // 方向数组 
int dy[4] = {0,1,0,-1};
int mini=9999;
void dfs(int x,int y)//参数只需要记录当前坐标
{
   if(a[x][y]!=1) //此路不通
		return;
    //边界点需要判断？不用 从1 1开始记录 四周自动是0
   if(x==endx&&y==endy)
   {
     ok=true;
     if(mini>step) mini=step;
       return;
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
  // return; //这一句 可要可不要需要
}

int main() {
 memset(f,0,sizeof(f));
 memset(a,0,sizeof(a));

for(int i=1;i<=12;i++)
{
for(int j=1;j<=12;j++)
{
    char t;cin>>t;
    if(t=='W') a[i][j]=0;
   else if(t=='O')   a[i][j]=1;
   else  if(t=='E')   
   {a[i][j]=1; endx=i;endy=j;
   }
}
}


/*  for(int i=0;i<=13;i++)
{
for(int j=0;j<=13;j++)
{
   cout<<a[i][j]<<" ";
}
cout<<endl;
}   
 */
 

for (int q=1;q<=3;q++)
{
scanf(" (%d,%d)",&beginx,&beginy);//注意读取格式前有一个空格
//cin>>beginx>>beginy;
 //cout<<beginx<<beginy<<"     ";  
beginx++; beginy++;   //坐标要偏移
 //cout<<beginx<<beginy;   
f[beginx][beginy]=1;
dfs( beginx,beginy);

if(ok==false) cout<<-1<<" ";
else cout<<mini<<" ";

//归零工作
step=1;
 memset(f,0,sizeof(f));
ok=false;
mini=9999;//!
}

    return 0;
}  

/*  example



O W O W O W O O W O W O
O W O W W W W O W O O E
O W W W O O O O O O O O
W W W O O O O W W W O W
O O O O W W W O O O O O
O O W O W O W O W O W W
O W W O O O W W O O O W
O O W O O W W W O O O O
O O O W O O O O W W W W
W W W O O O O W W W O O
O W W W W O O O O O W W
W W W O O O O O W W W W
(0,9) (5,7) (7,8)


O W O W O W O O W O W O
O W O W W W W O W O O O
O W W W O O O O O O O O
W W W O O O O W W W O W
O O O O W W W O O O O O
O O W O W O W O W O W W
O W W O O O W W O O O W
O O W O O W W W O O O O
O O O W O W W O W W W W
W W W W W O O W W W O O
O W W W W O O O O O W W
W W W E O O O O W W W W
(9,6) (5,7) (7,8)


O W O W O W O O W O W O
O W O W W W W O W O O E
O W W W O O O O O O O O
W W W O O O O W W W O W
O O O O W W W O O O O O
O O W O W O W O W O W W
O W W O O O W W O O O W
O O W O O W W W O O O O
O O O W O O O O W W W W
W W W O O O O W W W O O
O W W W W O O O O O W W
W W W O O O O O W W W W
(0,0) (5,7) (7,8)
 */