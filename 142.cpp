#include <bits/stdc++.h>
using namespace std;
#define M 100
#define N 100
//********** Specification of SortLines**********

/***************************************************************/
/*                                                             */
/*  DON'T MODIFY main function ANYWAY!                         */
/*                                                             */
/***************************************************************/

//********** Specification of SortLines **********

int sumrow(int (&p)[N][M], int n, int m)
{
int ans=0;
for(int i=0;i<m;i++)
{ ans+=p[n][i];}
return ans;
}


/* 
int cmp(const void *a, const void *b)//能否在一个cmp里实现不同优先级的排序  待研究 不如乖乖写
{
	int  *m, *n;
	m = (int *)a;
	n = (int  *)b;

        return *n-*m;
} */

void swap(int *a,int *b,int m) {
	for(int i = 0; i < m; i++) {
		int t=a[i];
		a[i]=b[i];
		b[i]=t;
	}
}


void SortLines(int (&p)[N][M], int n, int m)//对二维数组的引用   也可以用指针 此时应该是int (*p)[M]
/* PreCondition:
p points to a two-dimensional array with n lines and
m integers in each line
PostCondition:
array is sorted satisfying to the specification
*/
{   //TODO: your function definition


for(int i = 0; i < n; i++) {//模拟冒泡
		for(int j = i+1; j < n; j++) {
			int sum1=sumrow(p,i,m);
			int sum2=sumrow(p,j,m);
			if(sum1>sum2) {
				sum1=sum2;
				swap(p[i],p[j],m);
			} else if(sum1==sum2) {
				int z=0;//计数
				while(p[i][z]==p[j][z]&&z<m)
					z++;
				if(z<m&&p[i][z]>p[j][z])//类比字符串比较大小
					swap(p[i],p[j],m);
			}
		}
	}


}
//a是n行m列int
int main()
{
    int a[N][M];
    int n,m,i,j;
    int t,cas;
    scanf("%d",&cas);
    for(t=0; t<cas; t++)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        for (i=0; i<n; i++)
            for (j=0; j<m; j++)
                scanf("%d",&a[i][j]);
        /***** function SortLines is called here *****/
        SortLines(a,n,m);
        /****************************************/
        printf("case #%d:\n",t);
        for (i=0; i<n; i++)
            for (j=0; j<m; j++)
                printf("%d%c",a[i][j],j<m-1?' ':'\n');
    }
    return 0;
}

/* 
1
3 3
9 8 7
7 8 9
1 2 1 */