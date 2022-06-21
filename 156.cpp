#include <bits/stdc++.h>
using namespace std ;
/*Dfs找素数环 */

/* 判断素数的函数    巧妙  */
/* 首先 6x 肯定不是质数，因为它能被 6 整除；
其次 6x+2 肯定也不是质数，因为它还能被2整除；
依次类推，6x+3 肯定能被 3 整除；
6x+4 肯定能被 2 整除。
那么，就只有 6x+1 和 6x+5 (即等同于6x-1) 可能是质数了。
所以循环的步长可以设为 6，然后每次只判断 6 两侧的数即可。 */

bool isPrime(int num) {
    if (num <= 3) {
        return num > 1;
    }
    // 不在6的倍数两侧的一定不是质数
    if (num % 6 != 1 && num % 6 != 5) {
        return false;
    }
    int s =sqrt(num);
    for (int i = 5; i <= s; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
/* int n;

int C[100];//记录数据
int a[100];//记录是否用过

void dfs(int cur)
{
	if(cur == n)
		{	// 递归边界. 
           for(int  j=1;j<=n;j++) 
           {  printf("%d ",C[j]+1); } //输出
           cout<<endl;
        }

	else
		for(int i = 1; i <= n; i++)
		{
			int ok = 1; 
			if(a[i]==0){C[cur] = i;a[i]=1;} 	//i没用过 当前位置放数字i
            else {ok=0;continue;}
			for(int j = 1; j <= cur-1; j++)	// 0~cur-1行验证 
				 {  if( isPrime(C[1]+C[cur])==false || isPrime(C[j]+C[j+1])==false  ) //不满足环状两两和
				    {ok = 0;break;}}  
			if(ok) 
            {
              dfs(cur+1);
            a[i]=0;//清除
            }
		}
}
 
int main()
{ 
    memset(a,0,sizeof(a));
	cin>>n;
	    dfs(1);
	return 0;
}
 */  
/* int n;
int used[1000];
int num[1000];
int sum;

void dfs(int x)
{// x当前位置，num[x]代表最后一个被采用数的值
    if(x == n && isPrime(num[1]+num[n]) == 1)
    {//递归结束条件：x=n时表示已经有n个数形成素数环(满足题目要求)
    //并且 1+num[n] 的和为素数(num[1]=1，num[n]是第n个被采用的数)
    //因为是一个环，所以最后一个被采用的数num[n]会和第一个数num[1]相邻，所以两者之和需要为素数
        sum++;//素数环个数加1
//        
        for(int i = 1; i <= n; i++)//如果需要输出素数环，用这个循环
        {
            if(i == 1)
            {
                printf("%d", num[i]);
            }
            else
            {
                printf(" %d", num[i]);
            }
        }
        cout << endl;//输出完一个素数环后要换行
//        
        return;
    }
    else
    {
        for(int i = 2; i <= n; i++)
        {//从数值2开始遍历，每一层dfs都遍历，寻找所有的素数环
            if(used[i] == 0 && isPrime(i + num[x]))//num[x]表示第x个被采用数的值
            {//如果数值i未被使用并且与 最后一个被录入环中的数 和为素数
                num[x + 1] = i;//记录环中第x+1个数的值为 i
                used[i] = 1;//标记数值i被使用
                dfs(x + 1);//继续搜索环中第x+1个数字
                used[i] = 0;//递归回来后，used[i]置0，表示数值i未被使用，
                //虽然数值i之前已经被用过找环了，但是回来置0可以继续搜索其他可能的环
            }
        }
    }
    return;
}
int main()
{
  
    sum = 0;
    memset(used, 0, sizeof(used));//初始化记录数组，令used[1]到used[n]都置0
    memset(num, 0, sizeof(num));
    num[1] = 1;//数值1作为素数环的第一个数
    used[1] = 1;//数值1被使用，标记为1
    cin >> n;
    if(n % 2 == 1)  sum = 0;//当n为奇数时，有奇数个数字，则必会出现两个奇数相加的情况，由于两个奇数的和不为素数，所以素数环不成立。
    else  dfs(1);//第一个数固定为 1
    cout << "素数环的数量:" << sum << endl;
    return 0;
}
 */



int a[21], book[21], n;
bool f = false;
bool isP(int n) {
	if (n <= 2) return true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) return false;
	}
	return true;
}
void show(int *b, int len) {
	for (int i = 0; i < len; i++) printf("%d ", b[i]);
	puts("");
}
void dfs(int step) {
	if (step == n && isP(a[0]+a[step-1])) {//可以一次性用a[i]+a[(i+1)/n] 
		f = true;show(a, step);return;
	}
	for (int i = 2; i <= n; i++) {
		if (book[i] == 0) {
			book[i] = 1;
			a[step] = i;
			if (step >= 1) {
				if (!isP(a[step-1]+a[step])){
					book[i] = 0;
					continue;
				}
			}
			dfs(step+1);
			book[i] = 0;
		}
	}
}
int main() {
	int count = 1;
	while(1) {
		memset(a, 0, sizeof(a));
		memset(book, 0, sizeof(book));
		f = false;
		scanf("%d", &n);
		if (n == 0) break;
		printf("Case %d:\n", count++);
		a[0] = 1;
		if (n == 1) {
			f = true;puts("1");
		}
		if (n%2 == 0)dfs(1);
		if (!f) puts("No Answer");
	}	
}
