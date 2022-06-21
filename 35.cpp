#include <bits/stdc++.h>
using namespace std ;

/* 

//2.62  
 int int_shifts_are_arithmetic(void)//一个函数 检验是否进行算数右移 而不是逻辑右移
{
int x=~0;
return !(x^(x>>1));
}

//2.67
int int_size_is_32(void)
{
    int x=1<<31;//判断最高位是否第32；32位能=0  000000   但64位是000000100000
    //直接<<32会溢出 
    x<<1;
return !(0^x);
}

//2.75     利用算int最高w位的函数 算unsigned int最高w位
 unsigned unsigned_high_prod(unsigned x,unsigned y)
{
int w=32;
return signed_high_prod(x,y)+(x>>(w-1))*y+y>>(w-1)*x;
} 

//2.82
a  0   反例是 y=INT_MAX  = 011111111;    -y=-1  不一定>-x
b  1   由于数乘和 位移运算的性质 后w位在溢出时也能相等
c  0   x=1 y=0   ~x+~y+1=1111101     ~(x+y)=11111110
d  1   成立
e  1   只可能会变负 向下取整 所以<=一定成立
 
 */
/* 
int  main ()
{
cout<<int_shifts_are_arithmetic();
cout<<int_size_is_32();

return 0;
} */