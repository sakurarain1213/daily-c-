#include <bits/stdc++.h>

using namespace std ;

/* void quickSort(int s[], int l, int r)//自定义快速排序函数  思想 找基准值
{
    if (l< r)
    {      
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j]>= x) // 从右向左找第一个小于x的数
                j--; 
            if(i < j)
                s[i++] = s[j];
            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数
                i++; 
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1); // 递归调用
        quickSort(s, i + 1, r);
    }
} */


int cmp_int1(const void* _a , const void* _b)//参数格式固定
{
    int* a = (int*)_a;    //强制类型转换
    int* b = (int*)_b;
    return *a - *b;
}
int cmp_int2(const void* _a , const void* _b)//参数格式固定
{
    int* a = (int*)_a;    //强制类型转换
    int* b = (int*)_b;
    return  *b-*a;
}




int  main ()
{
char s;scanf("%c\n",&s);

     int n;//输入任意n个数字的处理方法
 int a[101];int count=0;
    while(cin>>n)
    {
        a[count++]=n;
        if(cin.get()=='\n')//
            break;
    }
if (s=='A')
qsort(a,count,sizeof(a[0]),cmp_int1); //qsort不能用不定长数组
else
qsort(a,count,sizeof(a[0]),cmp_int2); //qsort不能用不定长数组
cout<<a[0]<<" ";
for(int i=1;i<count;i++)
{
   if(a[i]!=a[i-1]) cout<< a[i]<<" ";
}
//去重复可以用朴素if遍历 也可以用函数

return 0;
}