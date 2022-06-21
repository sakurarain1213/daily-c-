/*
浮点数取模  求float a mod  float b
*/
#include<iostream>
using namespace std;

//思路：输入的时候用字符串，不然会有精度损失。
//按位存成一个数组
int main()
{
   string a,b;
    cin >> a >> b;
    int len1 = a.length();
    int len2 =b.length();
    long long aq = 0, bq = 0;
    for(int i = 0; i < len1; i++)
    {
        if(a[i] == '.') continue;
            aq = aq * 10 + a[i] - '0';
    }
    for(int i = 0; i < len2; i++)
    {
        if(b[i] == '.') continue;
            bq = bq * 10 + b[i] - '0';
    }
    long long cnt = aq % bq;
    long double ans = cnt / 1e9;
    printf("%.9Lf\n",ans);
}

//本人的中途版本是直接乘10的9次方变成大数 会有精度损失  所以按位存更加保险
/* int main() {
	double a,b;
    cin>>a>>b;
    a*=1e9; b*=1e9;
    while(a>=b)
    {
        a-=b;
    }
cout<<a/1e9;
	return 0;
}
 */