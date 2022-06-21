 #include <bits/stdc++.h>
using namespace std;
//dfs 套模板的寻路
 int beginx,beginy,endx,endy;
bool ok=false;
int a[1002][1002];
int f[1002][1002];
int m,n;
 int step=0;
int dx[4] = {-1,0,1,0};  
int dy[4] = {0,1,0,-1};
int mini=2e5;
void dfs(int x,int y)
{
   if(a[x][y]!=1) 
		return;
   if(x==endx&&y==endy)
   {
     ok=true;
     if(mini>step) mini=step;
       return;
   }
     for(int k=0;k<=3;k++)
      {
        if(  a[x+dx[k]][y+dy[k]]==1  &&   f[x+dx[k]][y+dy[k]]==0  )
        {
           f[x+dx[k]][y+dy[k]]=1;
           step++;
           dfs(x+dx[k],y+dy[k]);
           f[x+dx[k]][y+dy[k]]=0;
           step--;
        } 
        else continue;
   } 
}

int main() {
 memset(f,0,sizeof(f));
 memset(a,0,sizeof(a));
 cin>>m>>n;
for(int i=1;i<=m;i++){
for(int j=1;j<=n;j++){
    char t;cin>>t;
    if(t=='#') a[i][j]=0;
   else if(t=='.')   a[i][j]=1;
   else  if(t=='t')   
   {a[i][j]=1; endx=i;endy=j;}
   else  if(t=='s')   
   {a[i][j]=1; beginx=i;beginy=j;}}}
f[beginx][beginy]=1;
dfs( beginx,beginy);
if(ok==false) cout<<-1<<" ";
else cout<<mini<<" ";
    return 0;
}  
/*  example

5 4
s.##
#...
.##.
....
##t.
 */