#include <bits/stdc++.h>

using namespace std;


/* 计算 sin(20.86的100次方 ) 周期是2pi  可以随时mod 2 pi    但是取模和乘法都有误差
这里有之前实训课上的float mod 运算 
思路：输入的时候用字符串，不然会有精度损失。
按位存成一个数组 */


/* kahan求和算法可以避免这种情况，它有一个数用来记住那个被截断的小数，同样做下面的计算，设有a=123456;b=2.189；计算a+b。
kahan求和算法是这样做的：sum=a+b（不准确）; temp= (a+b)-a-b;temp等于 -0.009，就是被截断的那个小数。
通过一个临时变量我们就记住了这个误差，当计算下一个加法的时候，可以把这个误差补上，并且更新误差到sum。
其实也可以这样理解，sum不是由于数太大，占用了小数的精度，而这个小数在当前一步看似是可以忽略的，但是由于，迭代的次数增加，
小数会累积成大误差，那么我们另外用的float专门记住这个误差小数 */
   // KahanSummation算法
/* float KahanSum(string input)
{
 float sum = 0.0;
    float c = 0.0  ;        //A running compensation for lost low-order bits.
    for (int i = 0;i<input.length();i++)
       float y = input[i] - c  ;  //So far, so good: c is zero.
      float  t = sum + y       ;  //Alas, sum is big, y small, so low-order digits of y are lost.
      float  c = (t - sum) - y ;  //(t - sum) recovers the high-order part of y; subtracting y recovers -(low part of y)
      float  sum = t           ;  //Algebraically, c should always be zero. Beware eagerly optimising compilers!
        //Next time around, the lost low part will be added to y in a fresh attempt.
    return sum
}

或者全程用高精度类来算
 */
class Number
{
public:
	//运算容器
	static int digits1[101];
	static int digits2[101];
	static int digitsR[101];
	//数字属性
	int sign = 1;
	int length = 0;
	int integer = 0;
	int decimal = 0;
	string numString;//储存无符号的数字（同时去除前导0和后导0，但保留小数位的有效0）
    //需要构造函数
 	 Number (){};
	/*Number (int i){};
	Number (int i,int j){};  */


	Number(const string& inputString)
	{
		constructNumber(inputString);
	}

	Number(const int& inputNumber)
	{
		string tempString = to_string(inputNumber);
		constructNumber(tempString);
	}

	Number(const long long int& inputNumber)
	{
		string tempString = to_string(inputNumber);
		constructNumber(tempString);
	}

	//精度只有大概6位，太长的浮点数应用字符串录入
	Number(const double& inputNumber)
	{
		string tempString = to_string(inputNumber);
		constructNumber(tempString);
	}

	//用于运算结果的Number对象构造，包含对-0的修正
	Number(int resultSign, int resultLength, int resultInteger, int resultDecimal, string resultString)
	{
		if (length == 1 && resultString[0] == '0')
			sign = 1;
		else
			sign = resultSign;
		length = resultLength;
		integer = resultInteger;
		decimal = resultDecimal;
		numString = resultString;
		
	}



	//用于获取函数的字面字符串值
	string GetFullNumber()
	{
		string outString;
		if (sign == -1)
		{
			outString += "-";

		}
		for (int i = 0; i < length; i++)
		{
			if (i == length - decimal)
			{
				if (i != 0)
					outString += ".";
				else
					outString += "0.";
			}
			outString += numString[i];

		}
		return outString;
	}

	Number operator + (const Number& addend)
	{
		additionSort(addend);

		int resultSign;
		int resultLength;
		int resultDecimal;
		string resultString;

		int addIndex;
		int loopTime;

		resultDecimal = decimal > addend.decimal ? decimal : addend.decimal;//先取两者最大
		loopTime = (integer > addend.integer ? integer : addend.integer) + resultDecimal;//最大小数+最大整数
		resultLength = loopTime + 1;//先取足够大

		resetDigitsR(resultLength);

		if (sign == addend.sign)
		{
			for (int i = 1; i <= loopTime; i++)
			{
				digitsR[i] += digits1[i] + digits2[i];
				digitsR[i + 1] += digitsR[i] / 10;
				digitsR[i] = digitsR[i] % 10;
			}
			resultSign = sign;
		}
		else
		{
			switch (absCompareB(addend))
			{
			case 1:
				for (int i = 1; i <= loopTime; i++)
				{
					if (digits1[i] + digitsR[i] >= digits2[i])
						digitsR[i] += digits1[i] - digits2[i];
					else
					{
						digitsR[i + 1]--;
						digitsR[i] += 10 + digits1[i] - digits2[i];
					}
				}
				resultSign = sign;
				break;
			case 0:
				digitsR[1] = 0;
				resultLength = 1;
				resultSign = 1;
			case -1:
				for (int i = 1; i <= loopTime; i++)
				{
					if (digits2[i] + digitsR[i] >= digits1[i])
						digitsR[i] += digits2[i] - digits1[i];
					else
					{
						digitsR[i + 1]--;
						digitsR[i] += 10 + digits2[i] - digits1[i];
					}
				}
				resultSign = addend.sign;
				break;
			}

		}

		addIndex = calibrateResultLength(resultLength, resultDecimal);//修正录入位置
		for (int i = resultLength + addIndex; i >= 1 + addIndex; i--)
		{
			resultString += (char)(digitsR[i] + '0');
		}

		return Number(resultSign, resultLength, resultLength - resultDecimal, resultDecimal, resultString);
	}

	Number operator - (const Number& subtractor)
	{
		additionSort(subtractor);

		int resultSign;
		int resultLength;
		int resultDecimal;
		string resultString;

		int addIndex;
		int loopTime;

		resultDecimal = decimal > subtractor.decimal ? decimal : subtractor.decimal;//先取两者最大
		loopTime = (integer > subtractor.integer ? integer : subtractor.integer) + resultDecimal;//最大小数+最大整数
		resultLength = loopTime + 1;//先取足够大

		resetDigitsR(resultLength);

		if (sign != subtractor.sign)
		{
			for (int i = 1; i <= loopTime; i++)
			{
				digitsR[i] += digits1[i] + digits2[i];
				digitsR[i + 1] += digitsR[i] / 10;
				digitsR[i] = digitsR[i] % 10;
			}
			resultSign = sign;
		}
		else
		{
			switch (absCompareB(subtractor))
			{
			case 1:
				for (int i = 1; i <= loopTime; i++)
				{
					if (digits1[i] + digitsR[i] >= digits2[i])
						digitsR[i] += digits1[i] - digits2[i];
					else
					{
						digitsR[i + 1]--;
						digitsR[i] += 10 + digits1[i] - digits2[i];
					}
				}
				resultSign = sign;
				break;
			case 0:
				digitsR[1] = 0;
				resultLength = 1;
				resultSign = 1;
				break;
			case -1:
				for (int i = 1; i <= loopTime; i++)
				{
					if (digits2[i] + digitsR[i] >= digits1[i])
						digitsR[i] += digits2[i] - digits1[i];
					else
					{
						digitsR[i + 1]--;
						digitsR[i] += 10 + digits2[i] - digits1[i];
					}
				}
				resultSign = -sign;
				break;
			}
		}

		addIndex = calibrateResultLength(resultLength, resultDecimal);//修正录入位置
		for (int i = resultLength + addIndex; i >= 1 + addIndex; i--)
		{
			resultString += (char)(digitsR[i] + '0');
		}

		return Number(resultSign, resultLength, resultLength - resultDecimal, resultDecimal, resultString);
	}

	Number operator * (const Number& factor)
	{
		multiplicationSort(factor);

		int resultSign;
		int resultLength;
		int resultDecimal;
		string resultString;

		int addIndex;
		resultDecimal = decimal + factor.decimal;//两者相加
		resultLength = length + factor.length;//先取足够大

		resetDigitsR(resultLength);

		for (int secondDigit = 1; secondDigit <= factor.length; secondDigit++)//遍历到竖式的第二个数
		{
			for (int firstDigit = 1; firstDigit <= length; firstDigit++)//遍历到竖式的第一个数
			{
				//模拟竖式中的某两位数相乘
				digitsR[firstDigit + secondDigit - 1] += digits1[firstDigit] * digits2[secondDigit];
				//处理进位
				digitsR[firstDigit + secondDigit] += digitsR[firstDigit + secondDigit - 1] / 10;
				digitsR[firstDigit + secondDigit - 1] = digitsR[firstDigit + secondDigit - 1] % 10;
			}
		}

		resultSign = sign * factor.sign;

		addIndex = calibrateResultLength(resultLength, resultDecimal);//修正录入位置
		for (int i = resultLength + addIndex; i >= 1 + addIndex; i--)
		{
			resultString += (char)(digitsR[i] + '0');
		}

		return Number(resultSign, resultLength, resultLength - resultDecimal, resultDecimal, resultString);
	}

	Number operator / (const Number& divisor)
	{
		divisionSort(divisor);

		int resultSign;
		int resultLength;
		int resultDecimal;
		string resultString;

		bool canSub;
		int addStartIndex;
		int tempIntLength;

		int checkPointFront = 1;//当前试商时被除数的最前检查点
		int checkPointTrail = divisor.length;//当前试商时被除数的最后检查点
		int divisorcheckTrail;//记录试商时除数的最后检查点
		//校正纯小数数字的检查点
		if (divisor.length == divisor.decimal)
		{
			for (int i = 0; i < divisor.length; i++)
				if (divisor.numString[i] == '0')
					checkPointTrail--;
				else
					break;
		}
		divisorcheckTrail = checkPointTrail;

		resetDigitsR(sizeof(digitsR) / sizeof(int) - 1);

		for (checkPointTrail; checkPointTrail <= 100; checkPointFront++, checkPointTrail++)
		{
			while (1)
			{
				canSub = true;
				//判断是否能够进行减法试商（够不够减）
				if (digits1[checkPointFront - 1] == 0)
				{
					//看看够不够减
					for (int i = checkPointFront, j = 1; i <= checkPointTrail; i++, j++)
					{
						//过滤掉大于的情况
						if (digits1[i] > digits2[j])
						{
							break;
						}
						//如果执行到这一句，唯一的情况就是前一位等于，且这一位小于，因此整体值为小于，不能减
						if (digits1[i] < digits2[j])
						{
							canSub = false;
							break;
						}
					}
				}
				if (canSub)
				{
					for (int i = checkPointTrail, j = divisorcheckTrail; j > 0; i--, j--)
					{
						if (digits1[i] >= digits2[j])
							digits1[i] -= digits2[j];
						else
						{
							//否则进行借位减法
							digits1[i - 1]--;
							digits1[i] = 10 + digits1[i] - digits2[j];
						}
					}
					digitsR[checkPointTrail]++;
				}
				else
				{
					break;
				}
			}
		}
		checkPointTrail--;

			tempIntLength = integer + divisor.decimal;
			resultDecimal = checkPointTrail - tempIntLength;
			resultLength = resultDecimal + tempIntLength;

		resultSign = sign * divisor.sign;

		addStartIndex = calibrateResultLengthD(resultLength, resultDecimal);//修正录入位置
		for (int i = 1 + addStartIndex; i <= resultLength + addStartIndex; i++)
		{
			resultString += (char)(digitsR[i] + '0');
		}

		return Number(resultSign, resultLength, resultLength - resultDecimal, resultDecimal, resultString);
	}

private:
	//用于构造函数中
	void constructNumber(const string& inputString)
	{
		bool decimalCount = false;
		bool frontZero = true;
		int checkLength = length = inputString.length();

		int i = 0;
		//去除正负号
		if (inputString[i] == '-')
		{
			sign = -1;
			length--;
			i++;
		}
		//去除前导0
		for (i; i < checkLength; i++)
		{
			if (inputString[i] == '0')
				length--;
			else
				break;
		}
		//其它数字录入
		for (i; i < checkLength; i++)
		{
			if (decimalCount)
			{
				decimal++;
			}
			if (inputString[i] == '.')
			{
				decimalCount = true;
				length--;
				//缩短检测次数来避免录入小数的末尾0
				for (checkLength; checkLength > i; checkLength--)
				{
					if (inputString[checkLength - 1] == '0')
						length--;
					else
						break;
				}

			}
			else
			{
				numString += inputString[i];
			}
		}
		integer = length - decimal;
	}

	//两数字绝对值比较
	int absCompareB(const Number& b)
	{
		if (integer > b.integer)
			return 1;
		else if (integer < b.integer)
			return -1;
		else if (numString > b.numString)
			return 1;
		else if (numString == b.numString)
			return 0;
		else 
			return -1;
	}

	//用于加减乘，校准结果数组中的前导0后导0带来的长度影响，返回删除的后导0个数
	int calibrateResultLength(int& length, int& decimal)
	{
		int deleteZero = 0;
		//整数部分排除前导0
		for (int i = 0; length > decimal; i++)
		{
			if (digitsR[length] == 0)
				length--;
			else
				break;
		}
		//小数部分排除后导0
		for (int i = 1; decimal != 0; i++)
		{
			if (digitsR[i] == 0)
			{
				decimal--;
				length--;
				deleteZero++;
			}
			else
				break;
		}
		if (0 == length)
		{
			length++;
		}
		return deleteZero;
	}

	//用于除，校准结果数组中的前导0后导0带来的长度影响，返回删除的前导0个数
	int calibrateResultLengthD(int& length, int& decimal)
	{
		int deleteZero = 0;
		//小数部分排除后导0
		for (int i = 1; decimal != 0; i++)
		{
			if (digitsR[length] == 0)
			{
				decimal--;
				length--;
			}
			else
				break;
		}
		//整数部分排除前导0
		for (int i = 0; length > decimal; i++)
		{
			if (digitsR[i + 1] == 0)
			{
				length--;
				deleteZero++;
			}
			else
				break;
		}
		if (0 == length)
		{
			length++;
		}
		return deleteZero;
	}

	//把结果数组前n个位数重设为0
	void resetDigitsR(int length)
	{
		for (int i = 1; i <= length; i++)
		{
			digitsR[i] = 0;
		}
	}

	void additionSort(const Number& otherNumber)
	{
		//i1,i2记录导入数据的起始位置
		int i1 = 1, i2 = 1;
		if (decimal > otherNumber.decimal)
		{
			i2 += decimal - otherNumber.decimal;
			//第二个数组某些可能用到的元素需要用0赋值
			for (int i = 1; i < i2; i++)
			{
				digits2[i] = 0;
			}
		}
		else if (decimal < otherNumber.decimal)
		{
			i1 += otherNumber.decimal - decimal;
			//第一个数组某些可能用到的元素需要用0赋值
			for (int i = 1; i < i1; i++)
			{
				digits1[i] = 0;
			}
		}
		//对数组重新赋值
		for (int j = 1; j <= length; i1++, j++)
		{
			digits1[i1] = numString[length - j] - '0';
		}
		for (int j = 1; j <= otherNumber.length; i2++, j++)
		{
			digits2[i2] = otherNumber.numString[otherNumber.length - j] - '0';
		}
		for (i1; i1 <= i2; i1++)
		{
			digits1[i1] = 0;
		}
		for (i2; i2 <= i1; i2++)
		{
			digits2[i2] = 0;
		}
	}

	void multiplicationSort(const Number& otherNumber)
	{
		for (int i = 1; i <= length; i++)
		{
			digits1[i] = numString[length - i] - '0';
		}
		for (int i = 1; i <= otherNumber.length; i++)
		{
			digits2[i] = otherNumber.numString[otherNumber.length - i] - '0';
		}
	}

	void divisionSort(const Number& otherNumber)
	{
		int arrayLength = sizeof(digits1) / sizeof(int) - 1;
		for (int i = 1; i <= arrayLength; i++)
		{
			if (i <= length)
				digits1[i] = numString[i - 1] - '0';
			else
				digits1[i] = 0;
		}
		//处理除数
		int j = 1;
		if (otherNumber.length == 0)
		{
			digits2[1] = 1;
		}
		else
		{
			//去除除数的前导0
			for (j; j <= otherNumber.length; j++)
			{
				if (otherNumber.numString[j - 1] != '0')
					break;
			}
		}
		for (int i = 1; j <= otherNumber.length;i++, j++)
		{
			digits2[i] = otherNumber.numString[j - 1] - '0';
		}

	}
};

int Number::digits1[101];
int Number::digits2[101];
int Number::digitsR[101];

/* Number a1("4.0"),a2("4.25");
Number const1=108,const2=815,const3=1500;//全局
Number f(int n)//递归计算 来代替不能形成数组的不足
{
if(n==1) return a1;
if(n==2) return a2;
return const1-const2/f(n-1)+const3/(f(n-1)*f(n-2));
} */
Number const1("108"),const2("815"),const3("1500");//全局
int main()
{
//利用类实现一个数组   不能借助stl的vector  要自己分配内存 
Number *a =new Number[100];
 Number a1("4.0"),a2("4.25");
a[1]=a1;a[2]=a2;
for(int i=3;i<100;i++)
{
a[i]= const1-const2/a[i-1]+const3/(a[i-1]*a[i-2]);

cout<<i<<endl<<a[i].GetFullNumber()<<endl; 
}

/*  */
//下面函数用于测试：
/* 
		Number pie("3.141592653589793238462643383279502884197169399375105820974944");
		Number radius = 50.2;
		Number height = 10;
		Number Vcone = pie * radius * radius * height / 3;
		cout << Vcone.GetFullNumber() << endl;

			char ch[100];
		cout << "请输入一个数字";
		cin >> ch;
		Number number(ch);
		cout << "numString存储字符值为"<< number.numString << endl;
		string copy = number.GetFullNumber();
		cout << "获取数字函数输出字符值为" << copy << endl;

		char ch[100];
		cout << "请输入一个数字";
		cin >> ch;
		Number number(ch);
		cout << "numString存储字符值为"<< number.numString << endl;
		string copy = number.GetFullNumber();
		cout << "获取数字函数输出字符值为" << copy << endl;
	


		char ch1[100];
		char ch2[100];
		cout << endl << "请输入第一个数字" << endl;
		cin >> ch1;
		cout << endl << "请输入第二个数字" << endl;
		cin >> ch2;

		Number a(ch1);
		Number b(ch2);
		Number c = a / b;
		cout << c.GetFullNumber() << endl;
 */
 return 0;
}