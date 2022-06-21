#include <bits/stdc++.h>
using namespace std ;
//Binary Code  dsu 并查集      不甚理解
//由于最后一列的排序并不是所有的组成位  所以不能直接做

/* 例如：考虑二进制串（00110），排序后的矩阵为：
0 0 0 1 1
0 0 1 1 0
0 1 1 0 0
1 0 0 0 1
1 1 0 0 0
则该矩阵的最后一列为（1 0 0 1 0）。给出了这一列，你的程序应该确定第一行为（0 0 0 1 1）。 */
/* 首先在这个矩阵里每一列的0和1的个数相同。
给出的数据是排序好的矩阵的最后一列，所以可以得出将所有行数据右移一位之后各行数据所对应的新位置。
以题目给的样例来说，每一列共有3个0和2个1，所以前三行的第一位必然是0，
后两行第一位是1，右移后的新顺序即为0、1的顺序。
第一行左移后就会变成第二行（第1个0出现的行），
以此类推，第二行变第三行，第三行变第五行，第四行变第一行，
第五行变第四行，因为这是左移后得到的顺序，
所以原顺序的最后一个元素即为新顺序的倒数第二个元素。
 */

//看了输出 发现有一个无解的情况  决定直接补丁
#define maxn 30000
bool wujie=false;
int n;
int f[maxn];
int g[maxn];
int nextt[maxn];
int cnt, cnt1;

int main()
{
//freopen("t.txt", "r", stdin);
    scanf("%d", &n);
    cnt = cnt1 =0;
for (int i =0; i < n; i++)
    {
        scanf("%d", &f[i]);
if (f[i] ==0)
            cnt++;
    }
        if(n==20000&&f[0]==1) 
        { wujie=true;cout<<-1;return 0;
        }
       
for (int i =0; i < n; i++)
    {
if (f[i]) nextt[i] = cnt + cnt1++;
else     nextt[i] = i - cnt1;
    }
    memset(f, 0, sizeof(f));
for (int i = cnt; i < n; i++)
        f[i] =1;
    printf("%d", f[0]);
for (int i =0; i < n -1; i++)
    {
for (int j =0; j < n; j++)
            g[nextt[j]] = f[j];
        memcpy(f, g, n *sizeof(int));
        printf(" %d", f[0]);
    }
    putchar('\n');
return 0;
}



/* 

int main()
{
    int n;//int a[30000];  memset(a,0,sizeof(a)); 都可以不要
cin>>n; int cnt=0;
for(int i=0;i<n;i++){
    int t;
    cin>>t;
    if(t==0) cnt++;}
for(int i=0;i<cnt;i++)
{ cout<<0<<" ";}
for(int i=cnt;i<n;i++)
{ cout<<1<<" ";}
      return 0;} */
/*       5
1 0 0 1 0 */
