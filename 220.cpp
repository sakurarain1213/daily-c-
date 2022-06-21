//字符串合法性  
/* 根据题意，输入均为合法的，不难发现，只有“..”的情况进行交换后语句才有可能是合法的。其他情况交换一律都是不合法的，
所以遍历字符串时只要遍历每一个字符为"."且下一个字符为"."那么这个交换就是有效的。 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e6+5;
ll x,len,j,i;
char str[M],ans[M],b;
int main()
{
	cin>>x;
	while(x--)
	{
		j=0;
		cin>>str;
		len=strlen(str);
		for(i=0;i<=len-3;i++)
		{
			if(str[i]=='.'&&str[i+1]=='.')
                ans[j++]='C';
            else
                ans[j++]='D';
		}
		ans[j++]='D';
		for(i=0;i<j;i++)
		cout<<ans[i];
		cout<<endl;
	}
}
/* 
3
DOC
DO.DOC
..DOCOCOC */
