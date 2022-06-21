#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        long long men,women,child;
        int head,flag=0;
        long long cash;
        scanf("%d %lld",&head,&cash);
        printf("case #%d:\n",i);
        for(men=0;men<=head;men++)
        for(women=0;women<=head;women++)
        for(child=0;child<=head;child++)
        if(3*men+2*women+child==cash)
        if(men+women+child==head)
        {
            flag=1;printf("%lld %lld %lld\n",men,women,child);
        }

        if(flag==0) printf("-1\n");
    }
    return 0;
}

