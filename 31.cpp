#include <bits/stdc++.h>
using namespace std;
//由于八进制小数=10进制*8取整 再取小数部分*8……正序往0.之后写 所以8 to 10 
//可以用高精度 每次对齐0. *125 (1/8)  ，也可以逐位运算 运算方法有点难
void f(int n)
{
char str1[1010], ans[1010];
    cin>>str1;
    memset(ans,0,sizeof(ans));
        int num,tmp,k=0,length = strlen(str1);
        int j;
        for(int i = length - 1; i > 1 ; i--)
        {
            num = str1[i]-'0';//num :八进制小数的当前位，同时也是后续的余数
            	//除8的高精度计算
			//num也就是余数要除尽。
            for( j = 0;j<k||num>0;j++ )
            {
                int z ;
                if(j<k)
                    z = ans[j]-'0';
                else
                    z = 0;
                tmp = num*10+z;
                ans[j] = tmp/8 +'0';//商
                num = tmp%8; //余数
            }
            k = j;//十进制小数的位数k
        }
         printf("case #%d:\n",n);
        printf("0.%s\n",ans);

}
int main()
{
    int n;
    cin>>n;
for (int i=0;i<n;i++)
{f(i);}
    return 0;
}








