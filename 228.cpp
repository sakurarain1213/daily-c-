#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
    //面向过程解法
int pre[N], n, m;
vector<int> sor;
int find(int x)
{
    int l = 0, r = n-1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(sor[mid] >= x) r = mid;
        else l = mid + 1;
    }
    if(sor[l] == x) return l;
    //else return -1;
}
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &pre[i]);
        sor.push_back(pre[i]);
    }
    sort(sor.begin(),sor.end());
   

        int a,b;
        scanf("%d%d", &a, &b);
        int f_a = find(a), f_b = find(b);
        if(f_a != -1 && f_b != -1)
        {
            int father;
            for(int i = 0; i < n; i++)
            {
                if((a >= pre[i] && b <= pre[i]) || (a <= pre[i] && b >= pre[i]))
                {
                    father = pre[i];
                    break;
                }
            }
            if(a != father && b != father) 
            {/* printf("LCA of %d and %d is %d.\n", a,b,father); */
            printf("%d",father);
            }
            else if(a == father && b != father)
            {/* printf("%d is an ancestor of %d.\n", a, b); */
              printf("%d",father);
            } 
            else 
            {
           /*  printf("%d is an ancestor of %d.\n", b, a); */
            printf("%d",b);
            }
        }
        else if(f_a == -1 && f_b == -1) printf("ERROR: %d and %d are not found.\n", a,b);
        else if(f_a == -1) printf("ERROR: %d is not found.\n", a);
        else if(f_b == -1) printf("ERROR: %d is not found.\n", b);
    

    return 0;
}

/* 
8 6 2 8 4 3 5 7 9
2 8 

8 6 2 8 4 3 5 7 9
2 4


*/