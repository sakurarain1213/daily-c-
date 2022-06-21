#include <bits/stdc++.h>
using namespace std ;

//打印输出
void p(int a[61]){
    int j;

        for(j=1;j<61;j++){
            if(a[j]==1)
               cout<<"*";
            else
                cout<<"-";
        }
       cout<<endl;
     
}

int f(int a[61],int x){//自定义函数一定要按照调用次序写 或者先声明
    int i;
    int cnt=0;//记数
    for(i=x-2;i<=x+2;i++)
    {if(a[i]==1)cnt++;}
    cnt-=a[x];
    return cnt;
}


void update(int a[61]){
    int i;
    int b[61];
    //分布情况b是基于上一代a的值的复制  a再参照自己也就是b 重新赋值
    for(i=0;i<61;i++)
    {
    {b[i]=a[i];}
    }//a复制到b

    for(i=1;i<61;i++)
    {
       
            if(a[i]==1){//游戏规则
                if(f(b,i)<=1||f(b,i)==3)
                    a[i]=0;
            }
            else{
                if(f(b,i)==2||f(b,i)==3)
                    a[i]=1;
            }
        
    }
}



int  main ()
{
int a[61];
memset(a,0,sizeof(a));
int x,n,i;
  while(cin>>x)
    {if(x==-1)break;
        else  a[x]=1;
    }



    cin>>n;//迭代次数
    for(int i=0;i<n;i++){
        update(a);
    }
    p(a);

return 0;
}