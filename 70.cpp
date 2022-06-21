#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
//映射的使用
const int maxn=1005;

int main()
{   int t,T=0;
    while(scanf("%d",&t)&&t){
        map<int,int> text;
      /*   for(int i=0;i<t;i++){
            int n,m;
            cin>>n;
            while(n--){
                cin>>m;
                text[m]=i;
            }
        } */
        printf("Scenario #%d\n",++T);
        queue<int> Q;
        queue<int> q[maxn];

        while(true){
            char a[10];
            scanf("%s",a);
            if(a[0]=='S') break;
            else{
                int n,m;
                if(a[0]=='E'){



                    cin>>m>>n;text[n]=m;
                    if(q[text[n]].size()==0) Q.push(n);
                    q[text[n]].push(n);

                }
                else{


                    n=Q.front();
                    cout<<q[text[n]].front()<<endl;
                    q[text[n]].pop();
                    if(q[text[n]].empty()) Q.pop();       //The key point!
                }
            }
        }
       
    }
    return 0;
}