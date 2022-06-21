#include <bits/stdc++.h>
using namespace std;//高精度乘法

int n;
char ans[2005];
int tot;
 
void cheng(char p[], char a[]){
	int c[2005];
	memset(c, 0, sizeof(c));
	int lenp = strlen(p), lena = strlen(a);
	lenp = min(lenp, 1000), lena = min(lena, 1000);
	for (int i = 0; i < lenp; i++){
		for (int j = 0; j < lena; j++){
			c[i + j] += (p[i] - '0') * (a[j] - '0');
			if(c[i + j] > 9){
				c[i + j + 1] += c[i + j] / 10;
				c[i + j] %= 10;
			}
		}
	}
	int cnt = lena + lenp;
	while(c[cnt] == 0 && cnt > 0) cnt--;
	for (int i = 0; i <= cnt; i++){
		p[i] = c[i] + '0';
	}
	p[cnt + 1] = '\0';
	tot = cnt;
}
 

void f(int x)
{

//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
 
	scanf("%s %d", ans, &n);
	if(!n){//指数等于0时
    printf("case #%d:\n",x);
		printf("1\n");//别忘记输出

		return ;
	}
	int id;
	reverse(ans, ans + strlen(ans));
	char p[2005];
	strcpy(p, "1");
	while(n){
		if(n & 1){//n>=1时
			cheng(p, ans);
			id = tot;
		}
		cheng(ans, ans);
		n >>= 1;//自己乘自己 指数翻倍即可
	}
	if(id >= 1000) id = 999;


printf("case #%d:\n",x);
	for (int i = id; i >= 0; i--){
		printf("%c", p[i]);
	}
	printf("\n");
}

int main()
{
    int x;
    cin>>x;
    for(int t=0;t<x;t++)
    {
        	f(t);
    }
	return 0;
}
/**/