#include <bits/stdc++.h>
using namespace std;

/* 已知Elements [n]为整数数组，试写出实现下列运算的递归算法：
    (1) 求数组Elements中的最大整数。
       int  MaxKey (int Elements[], int n )
    (2) 求数组Elements中n个整数的和。
       int  Sum (int Elements[], int n )
    (3) 求数组Elements中n个整数的平均值。
       float  Average (int Elements[], int n )
 */

/*   (1) 求数组Elements中的最大整数。 */
 int  MaxKey (int Elements[], int n )
 {
    if(n==1) return Elements[0];
    else{
		int temp=MaxKey(Elements,n-1);
		if(temp<Elements[n-1]) return Elements[n-1];
		else return temp;}
 }

  /*  (2) 求数组Elements中n个整数的和。 */
 int  Sum (int Elements[], int n )
 {
     if(n==1) return Elements[0];
 else
 {return Sum(Elements,n-1)+Elements[n-1];}
 }

  /*   (3) 求数组Elements中n个整数的平均值。 */
 float  Average (int Elements[], int n )
 {
   if(n==1) return Elements[0];
 else
 {return   ( Average(Elements,n-1)*(n-1)   +Elements[n-1]  ) /n  ;}
 }



int main()
{


	return 0;
}