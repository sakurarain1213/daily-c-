#include <bits/stdc++.h>
using namespace std;

/* 计算 sin(20.86的100次方 ) 周期是2pi  可以随时mod 2 pi    但是取模和乘法都有误差
这里有之前实训课上的float mod 运算 
或者全程用高精度类来算
 */
class Number
{
public:
	//运算容器
	static int digits1[10001];
	static int digits2[10001];
	static int digitsR[10001];
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

int Number::digits1[10001];
int Number::digits2[10001];
int Number::digitsR[10001];


//为了mod pi  生成一个10的倍数函数
Number f(int n)
{
	Number t;
	string s="1";
	for(int i=0;i<n;i++)
	{s+="0";}
	t=s;
	return t;
}



/*a[i].GetFullNumber()<<endl; */
int main()
{
 Number a1("20.86"),ans("1.0"),k(2);
 //	Number pi("3.141592653589793238462643383279502884197169399375105820974944");
Number pi("3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273");
 // Number pi("3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196");
    string s="5.04085498670713701243586216963788693630759010028405007072294540733859247289460615107912703891005636969980573956179067248178115345783048944870144197887124388747138569087802009944265242611961724693197151589040560198820567212137616112461514428497860771439833658283174179160747582999106065210205454757655505231206726372916149998463268333503550399367176605866771923004934204548452264379179287610323369984";
     string ss="5.040854986707137012435862169637886936307590100284050070722945407338591269057623265169290343957848055272614685105862935828282961260313427159084905152910427641739646933063395410109474183645179026804147676105200957676771989019537619711827154844469329786833590798008753859743382403093414827751303737048982407988381515460380426583576881942233135036256669018794132821196425274216688351877492252724684939181438518543917867619465268460403879282938902578710380925431530599212591299426809832036982901746696192";
   //试一试math库里的pi
  // Number pi(M_PI);  //不够精确
  
     Number pi2=k*pi;
   //  cout<<pi2.GetFullNumber()<<endl;
//pi的精度决定答案的精度    //132.200   小数点前后的位数
//pi在小数点后两百位之后  答案稳定在5.04085498670713701243586216963788693630759010028405007072294540733859
//cout<<pi.GetFullNumber()<<endl;

    for(int i=0;i<100;i++)
    {
    ans=ans*a1;
   /*  while(ans.sign==1)
    {
    ans=ans-pi2;
        //相当于mod pi
    } */
   // ans=ans+pi2;//恢复成正数 
    }
for (int i=133;i>=0;i--)
{
while(ans.sign==1)
{
	ans=ans-pi2*f(i);
}
	ans=ans+pi2*f(i);
}

cout<<ans.GetFullNumber()<<endl;
//cout<<setiosflags(ios::fixed)<<setprecision(16)<<
cout<<fixed<<setprecision(16)<<sin(2.558475486199386840118868236412191427355972475245106470187580753839473947305697696173310917389494823644023286970717635965917813193565598121206170834451673380318421220252438505574934048011325703183175996715299784531568597375836587094992330640711611943275296019908506663885122832228939804093196484699204);
//答案0.5506286641660718

//2.558475486199386840118868236412191427355972475245106470187580753839473947305697696173310917389494823644023286970717635965917813193565598121206170834451673380318421220252438505574934048011325703183175996715299784531568597375836587094992330640711611943275296019908506663885122832228939804093196484699204  答案


//cout<<fixed<<setprecision(16)<<sin(4.566328398777125602773976073301635059305414097321575887033791760357839386415413571554990978684493746006940933220387867559545238065962680718278359332708863646084740566398183871240177929233804046483138281472);
//用math库的pi算出来是-0.9893521033731734
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


/* 
π=3. 1415926535 8979323846 2643383279 5028841971 6939937510
5820974944 5923078164 0628620899 8628034825 3421170679
8214808651 3282306647 0938446095 5058223172 5359408128
4811174502 8410270193 8521105559 6446229489 5493038196
4428810975 6659334461 2847564823 3786783165 2712019091
4564856692 3460348610 4543266482 1339360726 0249141273
7245870066 0631558817 4881520920 9628292540 9171536436
7892590360 0113305305 4882046652 1384146951 9415116094
3305727036 5759591953 0921861173 8193261179 3105118548
0744623799 6274956735 1885752724 8912279381 8301194912
9833673362 4406566430 8602139494 6395224737 1907021798
6094370277 0539217176 2931767523 8467481846 7669405132
0005681271 4526356082 7785771342 7577896091 7363717872
1468440901 2249534301 4654958537 1050792279 6892589235
4201995611 2129021960 8640344181 5981362977 4771309960
5187072113 4999999837 2978049951 0597317328 1609631859
5024459455 3469083026 4252230825 3344685035 2619311881
7101000313 7838752886 5875332083 8142061717 7669147303
5982534904 2875546873 1159562863 8823537875 9375195778
1857780532 1712268066 1300192787 6611195909 2164201989
3809525720 1065485863 2788659361 5338182796 8230301952
0353018529 6899577362 2599413891 2497217752 8347913151
5574857242 4541506959 5082953311 6861727855 8890750983
8175463746 4939319255 0604009277 0167113900 9848824012
8583616035 6370766010 4710181942 9555961989 4676783744
9448255379 7747268471 0404753464 6208046684 2590694912
9331367702 8989152104 7521620569 6602405803 8150193511
2533824300 3558764024 7496473263 9141992726 0426992279
6782354781 6360093417 2164121992 4586315030 2861829745
5570674983 8505494588 5869269956 9092721079 7509302955
3211653449 8720275596 0236480665 4991198818 3479775356
6369807426 5425278625 5181841757 4672890977 7727938000
8164706001 6145249192 1732172147 7235014144 1973568548
1613611573 5255213347 5741849468 4385233239 0739414333
4547762416 8625189835 6948556209 9219222184 2725502542
5688767179 0494601653 4668049886 2723279178 6085784383
8279679766 8145410095 3883786360 9506800642 2512520511
7392984896 0841284886 2694560424 1965285022 2106611863
0674427862 2039194945 0471237137 8696095636 4371917287
4677646575 7396241389 0865832645 9958133904 7802759009
9465764078 9512694683 9835259570 9825822620 5224894077
2671947826 8482601476 9909026401 3639443745 5305068203
4962524517 4939965143 1429809190 6592509372 2169646151
5709858387 4105978859 5977297549 8930161753 9284681382
6868386894 2774155991 8559252459 5395943104 9972524680
8459872736 4469584865 3836736222 6260991246 0805124388
4390451244 1365497627 8079771569 1435997700 1296160894
4169486855 5848406353 4220722258 2848864815 8456028506
0168427394 5226746767 8895252138 5225499546 6672782398
6456596116 3548862305 7745649803 5593634568 1743241125
1507606947 9451096596 0940252288 7971089314 5669136867
2287489405 6010150330 8617928680 9208747609 1782493858
9009714909 6759852613 6554978189 3129784821 6829989487
2265880485 7564014270 4775551323 7964145152 3746234364
5428584447 9526586782 1051141354 7357395231 1342716610
2135969536 2314429524 8493718711 0145765403 5902799344
0374200731 0578539062 1983874478 0847848968 3321445713
8687519435 0643021845 3191048481 0053706146 8067491927
8191197939 9520614196 6342875444 0643745123 7181921799
9839101591 9561814675 1426912397 4894090718 6494231961
5679452080 9514655022 5231603881 9301420937 6213785595
6638937787 0830390697 9207734672 2182562599 6615014215
0306803844 7734549202 6054146659 2520149744 2850732518
6660021324 3408819071 0486331734 6496514539 0579626856
1005508106 6587969981 6357473638 4052571459 1028970641
4011097120 6280439039 7595156771 5770042033 7869936007
2305587631 7635942187 3125147120 5329281918 2618612586
7321579198 4148488291 6447060957 5270695722 0917567116
7229109816 9091528017 3506712748 5832228718 3520935396
5725121083 5791513698 8209144421 0067510334 6711031412
6711136990 8658516398 3150197016 5151168517 1437657618
3515565088 4909989859 9823873455 2833163550 7647918535
8932261854 8963213293 3089857064 2046752590 7091548141
6549859461 6371802709 8199430992 4488957571 2828905923
2332609729 9712084433 5732654893 8239119325 9746366730
5836041428 1388303203 8249037589 8524374417 0291327656
1809377344 4030707469 2112019130 2033038019 7621101100
4492932151 6084244485 9637669838 9522868478 3123552658
2131449576 8572624334 4189303968 6426243410 7732269780
2807318915 4411010446 8232527162 0105265227 2111660396
6655730925 4711055785 3763466820 6531098965 2691862056
4769312570 5863566201 8558100729 3606598764 8611791045
3348850346 1136576867 5324944166 8039626579 7877185560
8455296541 2665408530 6143444318 5867697514 5661406800
7002378776 5913440171 2749470420 5622305389 9456131407
1127000407 8547332699 3908145466 4645880797 2708266830
6343285878 5698305235 8089330657 5740679545 7163775254
2021149557 6158140025 0126228594 1302164715 5097925923
0990796547 3761255176 5675135751 7829666454 7791745011
2996148903 0463994713 2962107340 4375189573 5961458901
9389713111 7904297828 5647503203 1986915140 2870808599
0480109412 1472213179 4764777262 2414254854 5403321571
8530614228 8137585043 0633217518 2979866223 7172159160
7716692547 4873898665 4949450114 6540628433 6639379003
9769265672 1463853067 3609657120 9180763832 7166416274
8888007869 2560290228 4721040317 2118608204 1900042296
6171196377 9213375751 1495950156 6049631862 9472654736
4252308177 0367515906 7350235072 8354056704 0386743513
6222247715 8915049530 9844489333 0963408780 7693259939
7805419341 4473774418 4263129860 8099888687 4132604721
5695162396 5864573021 6315981931 9516735381 2974167729
4786724229 2465436680 0980676928 2382806899 6400482435
4037014163 1496589794 0924323789 6907069779 4223625082
2168895738 3798623001 5937764716 5122893578 6015881617
5578297352 3344604281 5126272037 3431465319 7777416031
9906655418 7639792933 4419521541 3418994854 4473456738
3162499341 9131814809 2777710386 3877343177 2075456545
3220777092 1201905166 0962804909 2636019759 8828161332
3166636528 6193266863 3606273567 6303544776 2803504507
7723554710 5859548702 7908143562 4014517180 6246436267
9456127531 8134078330 3362542327 8394497538 2437205835
3114771199 2606381334 6776879695 9703098339 1307710987
0408591337 4641442822 7726346594 7047458784 7787201927
7152807317 6790770715 7213444730 6057007334 9243693113
8350493163 1284042512 1925651798 0694113528 0131470130
4781643788 5185290928 5452011658 3934196562 1349143415
9562586586 5570552690 4965209858 0338507224 2648293972
8584783163 0577775606 8887644624 8246857926 0395352773
4803048029 0058760758 2510474709 1643961362 6760449256
2742042083 2085661190 6254543372 1315359584 5068772460
2901618766 7952406163 4252257719 5429162991 9306455377
9914037340 4328752628 8896399587 9475729174 6426357455
2540790914 5135711136 9410911939 3251910760 2082520261
8798531887 7058429725 9167781314 9699009019 2116971737
2784768472 6860849003 3770242429 1651300500 5168323364
3503895170 2989392233 4517220138 1280696501 1784408745
1960121228 5993716231 3017114448 4640903890 6449544400
6198690754 8516026327 5052983491 8740786680 8818338510
2283345085 0486082503 9302133219 7155184306 3545500766
8282949304 1377655279 3975175461 3953984683 3936383047
4611996653 8581538420 5685338621 8672523340 2830871123
2827892125 0771262946 3229563989 8989358211 6745627010
2183564622 0134967151 8819097303 8119800497 3407239610
3685406643 1939509790 1906996395 5245300545 0580685501
9567302292 1913933918 5680344903 9820595510 0226353536
1920419947 4553859381 0234395544 9597783779 0237421617
2711172364 3435439478 2218185286 2408514006 6604433258
8856986705 4315470696 5747458550 3323233421 0730154594
0516553790 6866273337 9958511562 5784322988 2737231989
8757141595 7811196358 3300594087 3068121602 8764962867
 */