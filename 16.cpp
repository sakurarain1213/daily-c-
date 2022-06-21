#include <bits/stdc++.h>
using namespace std;
struct inf
{
    char stuNo[51];
    int amount;
    int qNo[11];
    int score;
};



int stuc(struct inf p1, struct inf p2)
{
    int n = p1.score - p2.score;
    if(n < 0)
        return 1;
    if(n > 0)
        return -1;
    if(strcmp(p1.stuNo, p2.stuNo) > 0)
        return 1;
    if(strcmp(p1.stuNo, p2.stuNo) < 0)
        return -1;
    return 0;
}

void Sort(struct inf *a, int n)
{
    int i,j,first;
    inf temp;
    for(i=0; i<n-1; i++)
    {
        first = i;
        for(j=i+1; j<n; j++)
        {
            if(stuc(a[first], a[j]) > 0)
            {
                first = j;
            }
        }
        temp = a[i];
        a[i] = a[first];
        a[first] = temp;
    }
}


void f(int n)//整体封装
{
   int N,M,G;
    int i,j;
    scanf("%d %d %d",&N,&M,&G);
    //每题的分
    int standard[M];
    for(i=0; i<M; i++)
    {
        scanf("%d",&standard[i]);
    }
    struct inf stu[N];
    //输入
    for(i=0; i<N; i++)
    {
        scanf("%s",stu[i].stuNo);
        scanf("%d",&stu[i].amount);
        for(j=0; j<stu[i].amount; j++)
            scanf("%d",&stu[i].qNo[j]);
    }
    //算分
    for(i=0; i<N; i++)
    {
        j=0;
        stu[i].score = 0;
        while(j != stu[i].amount)
        {
            int s = stu[i].qNo[j]-1;
            stu[i].score += standard[s];
            j++;
        }
    }
    Sort(stu, N);
    //统计合格人数
    int cnt=0;
    for(i=0; i<N; i++)
    {
        if(stu[i].score>=G)
        {
            cnt++;
        }
    }
    cout <<"case #"<<n<<":"<<endl;
    printf("%d\n",cnt);
    for(i=0; i<cnt; i++)
    {
        printf("%s %d\n",stu[i].stuNo,stu[i].score);
    }


}


int main()
{
   int n;
   cin >>n;
   for (int i=0;i<n;i++)
   {
        f(i);
   }
  
    return 0;
}