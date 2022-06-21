#include <bits/stdc++.h>
using namespace std;//已知循环小数求分式 本质上就是*10的循环长度次方 作差 解方程求原来的小数

/* 纯循环小数:一个循环节有几个数,分母就有几个9,分子则为一个循环节上的数
例.0.3=3/9,+0.347=347/999
混循环小数：循环节有几个数,分母就有几个9,不循环的有几个数,分母再添几个0
例.0.32=(32-3)/90,+0.2134=(2134-21)/9900 */
long long t;
string s;

int main() {
    cin >> t;
    for (long long k = 0; k < t; k++) {
        cin >> s;
        cout << "case #" << k << ":\n";
        //整数部分
        long long zheng = 0;
        long long i = 0;
        for (i = 0; s[i] != '.'; i++) {
            zheng *= 10;
            zheng += s[i] - '0';
        }
        long long cnt1 = 0, cnt2 = 0, num1 = 0, num2 = 0;
        long long fenzi = 0, fenmu = 0;
        i++;
        if (s.find('[') == s.npos) {
            long long len = s.length() - i;
            fenmu = 1;
            while (len--) {
                fenzi *= 10;
                fenmu *= 10;
                fenzi += s[i] - '0';
                i++;
            }
            long long tmp = __gcd(fenzi, fenmu);
            fenzi /= tmp, fenmu /= tmp;
            fenzi += zheng * fenmu;
            cout << fenzi << "/" << fenmu << endl;
            continue;
        }
        while (s[i] != '[') {
            cnt1++;
            num1 *= 10;
            num1 += s[i] - '0';
            i++;
        }
        i++;
        num2 += num1;
        while (s[i] != ']') {
            cnt2++;
            num2 *= 10;
            num2 += s[i] - '0';
            i++;
        }
        fenzi = num2 - num1;
        fenmu = 0;
        while (cnt2--) {
            fenmu *= 10;
            fenmu += 9;
        }
        while (cnt1--) {
            fenmu *= 10;
        }
        long long tmp = __gcd(fenzi, fenmu);
        fenzi /= tmp, fenmu /= tmp;
        fenzi += zheng * fenmu;
        cout << fenzi << "/" << fenmu << endl;
    }
    return 0;
}

/* 
4
0.5
0.[6]
11.0[8]
1.[142857]
 */






/* int main(){  可以 但是数据量大就不行
	 int i,j,len,t1,t2,t3,t4,t5,T,flag,sum1,sum2;
	char str[200];int cnt=0;
	scanf("%d",&T);
	while(T--){
        
		flag=t1=t2=t4=t5=sum1=sum2=0;
		scanf("%s",str);
		len=strlen(str);
       int pos;
        for(i=0;i<len;i++)
        {
            if(str[i]=='.') {pos=i;break;}
        }
       int zhengshu=0;
        for(i=0;i<pos;i++)
        {
           zhengshu=zhengshu*10+str[i]-'0';
        }

		for(i=pos+1;i<len;i++){//去掉整数部分的零和小数点，直接从小数部分也就是2开始循环
			if(str[i]=='['||str[i]==']'){
				flag=1;//判断是否包含循环体
			}
			if(flag==1&&str[i]>='0'&&str[i]<='9')
				sum2++;//计算循环体的位数，方便计算分母有多少个9 
			if(flag==0){
				t4=t4*10+str[i]-'0';//非循环体组成的整数
				sum1++;//非循环体位数，方便计算在分母上添几个零
			} 
			if(str[i]>='0'&&str[i]<='9')
				t5=t5*10+str[i]-'0';//小数点后所有数组成的整数 
		}

              printf("case #%d:\n",cnt);
              cnt++;

		if(flag==0){
			for(i=2;i<len;i++){
				t1=t1*10+(str[i]-'0');//没有循环体时，计算出分子
			}
			t2=pow(10,len-2);
            t1+=zhengshu*t2;//再加上整数部分
			t3=__gcd(t1,t2); //求出两数的最大公约数
			printf("%d/%d\n",t1/t3,t2/t3);
		}
		else{
			t1=t5-t4;//有循环体时分子的值
			for(i=1;i<=sum2;i++)
				t2=t2*10+9;//计算9的个数
			t2=t2*pow(10,sum1); 
            t1+=zhengshu*t2;//再加上整数部分
			t3=__gcd(t1,t2);
			printf("%d/%d\n",t1/t3,t2/t3);
		}
	}
	return 0;
}  */
/* 
4
0.5
0.[6]
11.0[8]
1.[142857]
 */