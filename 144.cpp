#include <bits/stdc++.h>
using namespace std ;
//简单的结构体排序
 struct P 
{
int i;
int j;
int d;
} p[20000];//数组记得开大一点
bool cmp(const P &x, const P &y)   //这个结构用sort
//要么自己写比较函数和 sort函数    不然一定要按照此格式写比较函数 然后直接用 qsort
{
    int dd = y.d - x.d ;
    int ii = x.i - y.i;
     int jj = x.j - y.j;
    if(dd!=0)  return dd<0;
    else if(ii!=0)  return ii<0;
   else if(jj!=0)  return jj<0;
   else return 0;
}

int  main ()
{
    int t;
      scanf("%d",&t);
    for (int  k = 0; k < t; k++) {
          int m,n;
           //cin>>n>>m;
           scanf("%d %d",&n,&m);
			//memset(&p,0,sizeof(p[0])*200);
           /* for (int z=0;z<201;z++)
               {p[z].i=0;
               p[z].j=0;
               p[z].d=0;} */


            for (int z=0;z<m;z++)
               {//cin>>p[z].i>>p[z].j>>p[z].d;
                   scanf("%d %d %d",&p[z].i,&p[z].j,&p[z].d);
                       //     cout<<p[z].i<<p[z].j<<p[z].d<<endl;
               }
         // qsort(p, m,sizeof(p[0]), cmp);
         sort(p,p+m,cmp);

		printf("case #%d:\n",k);
      //  cout << "case #" << k << ":\n";
        for (int z=0;z<m;z++)
               {     printf("(%d,%d,%d)\n",p[z].i,p[z].j,p[z].d);}//神奇 不能用print
                   //cout<<"("<<p[z].i<<","<<p[z].j<<","<<p[z].d<<")"<<endl;
	}

    return 0;
}

/* 

3
10 12
1 7 30
1 2 28
2 4 20
2 5 10
2 3 10
3 10 10
7 5 20
5 10 70
8 5 20
8 6 40
7 6 35
6 9 10
2 1
1 2 30
4 6
1 3 30
2 3 19
1 2 30
1 4 19
2 4 50
4 3 30

1
10 12
1 7 30
1 2 28
2 4 20
2 5 10
2 3 10
3 10 10
7 5 20
5 10 70
8 5 20
8 6 40
7 6 35
6 9 10




 */


//sort 结构体排序
/* struct st
{
	int a1;
	int b1;
}arr[100];
bool  cmp(const st &x, const st &y)
{
	return x.b1<y.b1;//从小到大排<，若要从大到小排则>
}
int main()
{
	int i;
	for (i=0;i<3;i++)
	  cin>>arr[i].a1>>arr[i].b1;//对结构体进行输入 
	  sort(arr,arr+3,cmp);
	for (i=0;i<3;i++)
	  cout<<arr[i].a1<<" "<<arr[i].b1<<endl;
      return 0;
} */