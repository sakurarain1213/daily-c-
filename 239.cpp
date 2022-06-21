//对string查找的方法
//详情见https://www.cnblogs.com/hfang/p/16396506.html
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
const long long maxn = 1e6  ;
struct Node
{
    string name;
    int x,y;
}p[maxn];
int n,m;
bool cmp(Node a,Node b){return a.name<b.name;}
void binary(string goal)
{
    int l=1,r=m;
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(goal<p[mid].name) r=mid;
        if(goal>p[mid].name) l=mid+1;
        if(goal==p[mid].name) break;    
    }
    if(p[(l+r)>>1].name!=goal) printf("NULL\n");
    else printf("%d %d\n",p[(l+r)>>1].x,p[(l+r)>>1].y);
}
string s;
char *str= (char*)malloc(sizeof(char)); 
Node tmp[maxn];
void mergesort(int l,int r){
    if(l >= r ) return;
    int mid =(l + r) >>1;
    mergesort(l,mid);
    mergesort(mid+1,r);
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j<=r){
        if(p[i].name < p[j].name) tmp[k++] = p[i++];
        else tmp[k++] = p[j++];
    }
    while(i <= mid) tmp[k++] = p[i++];
    while(j <= r) tmp[k++] = p[j++];
    for(int i = l,j = 0;i<=r;i++,j++){
        p[i] = tmp[j];
    }
}
int main()
{
     cin>>m>>n;
     for(int i=1;i<=m;i++)
     {
         scanf("%s %d%d",str,&p[i].x,&p[i].y);
         p[i].name=str;
         scanf("%s",str);
    }
    mergesort(1,m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str); 
        s=str;
        binary(s);
    }
    free(str);
    return 0;
}