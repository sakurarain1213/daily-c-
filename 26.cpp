#include <bits/stdc++.h>

using namespace std;

//返回存活邻居的个数
int f(int a[][62],int x,int y){
    int i;
    int cnt=0;//记数
    for(i=y-1;i<=y+1;i++)
    {if(a[x-1][i]==1)cnt++;}
    for(i=y-1;i<=y+1;i++)
    {if(a[x+1][i]==1)cnt++;}
    if(a[x][y-1]==1)cnt++;
    if(a[x][y+1]==1)cnt++;
    return cnt;
}

//更新迭代一次
void update(int a[][62]){
    int i,j;
    int b[22][62];
    //分布情况b是基于上一代a的值的复制  a再参照自己也就是b 重新赋值
    for(i=0;i<22;i++)
    {
    for(j=0;j<62;j++)
    {b[i][j]=a[i][j];}
    }//a复制到b

    for(i=1;i<21;i++)
    {
        for(j=1;j<61;j++)
        {
            if(a[i][j]==1){//游戏规则
                if(f(b,i,j)<=1||f(b,i,j)>=4)
                    a[i][j]=0;
            }
            else{
                if(f(b,i,j)==3)
                    a[i][j]=1;
            }
        }
    }
}
//打印输出
void p(int a[][62]){
    int i,j;
     for(i=1;i<21;i++){
        for(j=1;j<61;j++){
            if(a[i][j]==1)
               cout<<"*";
            else
                cout<<"-";
        }
       cout<<endl;
     }
}

int main()
{
    int a[22][62];//边沿数据的比较 拓展二维数组
    int x,y;
    int n,i,j;
    for(i=0;i<22;i++){
        for(j=0;j<62;j++)
            a[i][j]=0;
    }//清零
    while(cin>>x>>y)
    {if(x==-1&&y==-1)break;
        else  a[x][y]=1;
    }
    cin>>n;//迭代次数
    for(i=0;i<n;i++){
        update(a);
    }
    p(a);
    return 0;
}
