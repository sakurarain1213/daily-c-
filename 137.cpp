/* 
解三角形 判断三边三角是否有解和解的唯一性
初中解三角形的功底要扎实，对各种情况分类讨论。

无效输入的情况：
① 题目所给的数据少于三个，无法得到一个解（计算前判断）
② 要素无法构成三角形(judge函数，计算后判断)：
1. 仍有未知项（即-1）
2. 三个角之和不等于\piπ
3. 两边之和小于第三边
4. 不满足正弦定理
求解三角形：
ASA 正弦定理   SAS 余弦   SSS余弦   AAS 正弦
判断解的个数：
已知两边和其中一边的对角不能唯一确定三角形，可能出现两解，一解或无解的情况。在本题中使用正弦定理来判断。
若已知 a、b、\alphaa、b、α，
由正弦定理可以得到sin\beta=\frac{bsin\alpha}{a}sinβ=absinα​，
若sin\beta>1sinβ>1，无解；
若sin\beta=1sinβ=1，一解；
若sin\beta<1sinβ<1两解。
在代码中则通过比较 aa 与 bsin\alphabsinα 的大小来判断。

由于题目有精度要求，所以宏定义一个小数mask。
在输入时指定cc和ee来分别储存已知的角和边的个数。
首先定义三个函数

已知三边时调用getageta函数求角
已知两边及其夹角时调用getegete函数求对边
c=2c=2 时调用 c2cc2c 函数求第三个角
e=3e=3 时调用 e2ce2c 求所有的角
之后进入主函数

读入数据并记录已知元素个数；
判断元素数量是否满足最低限度；
仅根据已知边或角的数量来处理：已知两角求第三个角或已知三边求所有角；
边角情况混合处理：
（1）已知一边及其对角(a,\alpha)(a,α)，此时可以解出来的情况有(-1,\beta)(−1,β)或(b,-1)(b,−1)；
①(-1,\beta)(−1,β)，用正弦定理求出bb;
②(b,-1)(b,−1)，此时需要根据 sin\betasinβ 来判断解的情况；
（2）已知两边和未知边的对角，直接调用 getegete 函数解出第三边；
至此我们好像已经遍历了所有情况，只需要循环至所有元素都被解出来；
调用 judgejudge 函数判断元素是否可以组成三角形，判断是否有多解；
输出。 */
#include <bits/stdc++.h> 
using namespace std; 
const long double pi=4*atan(1);
const long double mask=1e-6;
long double a[6];
long double geta(long double a,long double b,long double c)
{
	return acos((a*a+b*b-c*c)/(2*a*b));
}
long double gete(long double x,long double y,long double c)
{
	return sqrt(x*x+y*y-2*x*y*cos(c));
}
void c2c()
{
	long double t=0;
	for(int i=1;i<6;i+=2)
	{
		if(a[i]<0)
			continue;
		t+=a[i];
	}
	for(int i=1;i<6;i+=2)
		if(a[i]<0)
			a[i]=pi-t;
}
void e2c()
{
	for(int i=1;i<6;i+=2)
		if(a[i]<0)
			a[i]=geta(a[(i+1)%6],a[(i+3)%6],a[i-1]);
}
bool judge()
{
	for(int i=0;i<6;i++)
		if(a[i]<0)
			return false;
	if(fabs(a[1]+a[3]+a[5]-pi)>mask)
		return false;
	if(a[0]+a[2]<=a[4]||a[2]+a[4]<=a[0]||a[0]+a[4]<=a[2])
		return false;
	for (int i = 0; i < 4; i += 2) 
		if (fabs(a[i]*sin(a[i+3])-sin(a[i+1])*a[i+2])>mask)
			return false;
	return true;
}
int main(int argc, char** argv) 
{
	int T;
	cin >> T;
	while(T--)
	{
		int n=0,c=0,e=0;
		bool flag=false;
		for(int i=0;i<6;i++)
		{
			cin >> a[i];
			if(a[i]>0)
			{
				n++;
				if(i&1) c++;
				else e++;
			}
		}
		if(n<3)
		{
			cout << "Invalid input." << endl;
			continue;
		}
		while(n<6)
		{
			int s=n;
			if(c==2)
			{
				c2c();
				n++;
				c=3;
			}
			if(e==3)
			{
				e2c();
				n+=3-c;
				c=3;
			}
			for(int i=0;i<6;i+=2)
			{
				if(a[i]>0&&a[i+1]>0)
				{
					for(int j=0;j<6;j+=2)
					{
						if((a[j]>0&&a[j+1]>0)||(a[j]<0&&a[j+1]<0))
							continue;
						if(a[j]<0)
						{
							a[j]=a[i]/sin(a[i+1])*sin(a[j+1]);
							n++;
							e++;
						}
						else
						{
							if(a[i+1]<pi/2&&a[i]<a[j]&&a[i]>a[j]*sin(a[i+1]))
								flag=true;
							double temp=sin(a[i+1])*a[j]/a[i];
							if(temp>1||temp<0)
								continue;
							a[j+1]=asin(sin(a[i+1])*a[j]/a[i]);
							n++;
							c++;
						}
					}
				}
			}
			if(e==2)
			{
				for(int i=0;i<6;i+=2)
				{
					if(a[i]<0&&a[i+1]>0)
					{
						a[i]=gete(a[(i+2)%6],a[(i+4)%6],a[i + 1]);
						n++;
						e++;
					}
				}
			}
			if(s==n)
				break;
		}
		if(judge())
		{
			if(flag)
				cout << "More than one solution." << endl;
			else
			{
				for(int i=0;i<5;i++)
					cout << fixed << setprecision(6) << a[i] << " ";
				cout << fixed << setprecision(6) << a[5] << endl;
			}
		}
		else
			cout << "Invalid input." << endl;
 	}
	return 0;
}
/* 逐对输入各条边和各个角

4
47.9337906847 0.6543010109 78.4455517579 1.4813893731 66.5243757656 1.0059022695
62.72048064 2.26853639 -1.00000000 0.56794657 -1.00000000 -1.00000000
15.69326944 0.24714213 -1.00000000 1.80433105 66.04067877 -1.00000000
72.83685175 1.04409241 -1.00000000 -1.00000000 -1.00000000 -1.00000000

 */