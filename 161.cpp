#include <bits/stdc++.h>
//全是字符串的结构体多级排序 在于分割字符   由于数据量太大 所以一定要动态分配内存
//复杂处理
using namespace std;


struct Address
{  char* user, *main;};

int cmp(const void *a,const void *b)
{
    struct Address x,y;
    x=*((struct Address *)a);
    y=*((struct Address *)b);
    if(strcmp(x.main,y.main)==0) return strcmp(y.user,x.user);
    return strcmp(x.main,y.main);
}

int main()
{
    long long int n,count=0;
    scanf("%lld",&n);
    getchar();
    struct Address *ip=NULL;
    while(count<n)
    {
        long long int counts=0;
        char ch;
        char* temp=NULL;
        char* tempuser=NULL;
        char* tempmain=NULL;
        do
        {
            ch=getchar();
            counts++;
            temp=(char*)realloc(temp, sizeof(char)*(counts+1));
            temp[counts-1]=ch;
        }while(ch!='\n');
        temp[counts]='\0';
        count++;
        ip=(struct Address *)realloc(ip,n*sizeof(struct Address));
        ip[count-1].user=NULL;
        ip[count-1].main=NULL;
        long long int i,j,len=strlen(temp);
        for(i=0;temp[i]!='@';i++)
        {
            tempuser=(char *)realloc(tempuser,sizeof(char)*(i+1));
            tempuser[i]=temp[i];
        }
        tempuser=(char *)realloc(tempuser,sizeof(char)*(i+2));
        tempuser[i]='\0';
        i++;
        for(j=0;i<len;i++,j++)
        {
            tempmain=(char *)realloc(tempmain,sizeof(char)*(j+1));
            tempmain[j]=temp[i];
        }
        tempmain=(char *)realloc(tempmain,sizeof(char)*(j+2));
        tempmain[j]='\0';
        ip[count-1].user=(char *)realloc(ip[count-1].user,
                         sizeof(char)*(strlen(tempuser) + 1));
        ip[count-1].main=(char *)realloc(ip[count-1].main,
                         sizeof(char)*(strlen(tempmain) + 1));
        strcpy(ip[count-1].user,tempuser);
        strcpy(ip[count-1].main,tempmain);
        free(tempuser);
        free(tempmain);
        free(temp);
    }
    qsort(ip,n,sizeof(ip[0]),cmp);
    int j;
    for(j=0;j<n;j++)
    {
        printf("%s@%s",ip[j].user,ip[j].main);
    }
    free(ip);
    return 0;
}


/* 
用结构体存储数据，在读取数据时候用strtok函数分离用户名和主机域名，保存用户名和主机域名，然后利用qsort函数排序。（目测要用hash表来处理，加快查询速度 */
/* 
#include <bits/stdc++.h>
//全是字符串的结构体多级排序 在于分割字符
由于数据量太大 所以一定要动态分配内存
using namespace std;
struct address{
	char username[9999];
	char adminname[9999];
}arr[40000];

int cmp(const void* a,const void* b){
	address add1=*(address*)a,add2=*(address*)b;
	if(strcmp(add1.adminname,add2.adminname)!=0)
		return strcmp(add1.adminname,add2.adminname);
	else
		return strcmp(add2.username,add1.username);
}

int main()
{
    int n;
    cin>>n;
    getchar();
    for(int i=0;i<n;i++){
    	char s[9999];
    	cin.getline(s,9999);
    	strcpy(arr[i].username,strtok(s, "@"));
    	strcpy(arr[i].adminname,strtok(NULL, "@"));//分割方法
	}
	qsort(arr,n,sizeof(arr[0]),cmp);
	for(int i=0;i<n;i++){
    	printf("%s@%s\n",arr[i].username,arr[i].adminname);
	}
    return 0;
} */


/* 8
23485@qq.com
rieruer@163.com
39489384@qq.com
eruie@ecnu.edu.cn
rtff@163.com
84934804@qq.com
fdll@ecnu.edu.cn
598695@qq.com
 */