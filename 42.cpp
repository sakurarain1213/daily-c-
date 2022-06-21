//中序波兰式求解 
//要补全括号 然后将所有运算符向右移出无匹配的第一个右括号，去掉括号即为后序表式式
/* 举例：
原式：a+b*(c+d/e)
补全括号：(a+(b*(c+(d/e))))
操作符右移：(a(b(c(de)/)+)*)+
去掉括号：abcde/+*+ */

//算法
/*  需要两个栈
利用运算符栈(OPTR)和数据栈(OPND)将中表达式转化为后表达式。
    (1)首先，需要分配2个栈，
    栈s1用于临时存储运算符（含一个结束符号），  此运算符在栈内遵循越往栈顶 优先级越高的原则；
    栈s2用于输入逆波兰式，
   为方便起见，栈s1需先放入一个优先级最低的运算符，在这里假定为'#'；
　　(2)从中缀式的左端开始逐个读取字符x，逐序进行步骤：
　　　　　　1.若x是操作数，将x直接压入栈s2；
　　　　　　2.若x是运算符，则分情况讨论：
　　　　　　　　　　若x是'('，则入栈s1；
　　　　　　　　　　若x是')'，则将s1中往前最近的'('之间的运算符，逐个出栈，依次压入栈s2，此时抛弃'('；
　　　　　　　　　　若x是除'('和')'外的运算符，则再分如下情况讨论：
　　　　　　　　　　       　若当前栈s1的栈顶元素为'('，则将x直接压入栈s1；
　　　　　　　　　　　     　若当前栈s1的栈顶元素不为'('，则将x与栈s1的栈顶元素比较，
                                         若x的优先级大于栈s1栈顶运算符优先级，则将x直接压入栈s1。
                                         否则，s1的栈顶运算符弹出 压入s2，直到栈s1的栈顶运算符优先级别低于（不包括等于）x的优先级，
                                                                      或栈s2的栈顶运算符为'('，此时再则将x压入栈s1;
　　(3)在进行完(2)后，检查栈s1是否为空，若不为空，则将栈中元素依次弹出并压入栈s2中（不包括'#'）；　　　　　　 
　　(4)完成上述步骤后，栈s2便为逆波兰式输出结果。但是栈s2应做一下逆序处理，因为此时表达式的首字符位于栈底；
 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define max 100
char ex[max];        /*存储后序表达式*/

/*函数功能：将中序表达式转化为后序表达式*/
void trans() {
	char str[max];   /*表达式字符串*/
	char stack[max]; /*运算符栈*/
	char ch;         /*当前字符*/
	int sum, i, j, t, top = 0; /*sum用来统计字符串的长度*/
	/*t是数字栈栈顶指针*/
	/*top是数字栈栈顶指针*/
	printf("*****************************************\n");
	printf("*输入一个求值的表达式，以#结束。*\n");
	printf("******************************************\n");
	printf("算数表达式：");

	i = 0;
	/*这个循环语句，获取一个用户输入的合法的表达式*/
	do {
		i++;
		scanf("%c", &str[i]);
	} while (str[i] != '#' && i != max);

	sum = i;
	t = 1;
	i = 1;
	ch = str[i];
	i++;
	//while循环，当前的字符不是#
	while (ch != '#') {
		//将该字符与运算符栈顶的运算符的优先关系相比较。
		//如果该字符优先关系高于此运算符栈顶的运算符，则将该运算符入栈。
		//括号的运算优先级高。
		switch (ch) {
		case '(':            /*判定为左括号，入符号栈*/
			top++;           /*栈顶指针+1*/
			stack[top] = ch;
			break;

		case ')': /*判定为右括号*/
			while (stack[top] != '(') {
				ex[t] = stack[top];/*把符号栈的栈顶元素压入另一个栈中*/
				top--;             /*符号栈的栈顶指针-1*/
				t++;               /*数字栈的栈顶指针+1*/
			}
			top--;
			break;
		case '+': /*判定为加减号*/
		case '-':
			while (top != 0 && stack[top] != '(') {
				ex[t] = stack[top];/*把符号栈的栈顶元素压入数字栈中*/
				top--;             /*符号栈的栈顶指针-1*/
				t++;               /*数字栈的栈顶指针+1*/
			}
			top++;
			stack[top] = ch;       /*不执行那个while循环的话，直接压入符号栈*/
			break;
		case '*': /*判定为乘除号*/
		case '/':
			while (stack[top] == '*' || stack[top] == '/') {
				ex[t] = stack[top];/*把符号栈的栈顶元素压入数字栈中*/
				top--;             /*符号栈的栈顶指针-1*/
				t++;               /*数字栈的栈顶指针+1*/
			}
			top++;
			stack[top] = ch;
			break;
		case ' ':/*滤去空格*/
			break;
		default:/*默认直接把数字压入数字栈*/
			while (ch >= '0' && ch <= '9') { /*判定为数字*/
				ex[t] = ch;                  /*把数字压入数字栈*/
				t++;                         /*数字栈栈顶指针+1*/
				/*这边的代码写得很巧妙*/
				ch = str[i];                 /*从字符串中取一个字符*/
				i++;                         /*字符数组下标+1*/
			}
			i--;
			ex[t] = '#';                     /*为每个数字加一个分隔符*/
			t++;
		}
		ch = str[i];
		i++;
	}
	/*把符号栈剩下的元素压进去*/
	while (top != 0) {
		ex[t] = stack[top];
		t++;
		top--;
	}
	ex[t] = '#';
	printf("\n原来的中序表达式：");
	for (j = 1; j < sum; j++)
		printf("%c", str[j]);
	printf("\n后缀表达式：");
	for (j = 1; j < t; j++)
		printf("%c", ex[j]);
}
void compvalue() { /*计算后缀表达式的值*/
	float stack[max], d; /*作为栈使用*/
	char ch;
	int t = 1, top = 0; /*t为ex下标，top为stack下标*/
	ch = ex[t];
	t++;
	//从左到右检查字符串
	while (ch != '#') {/*滤去#*/
		switch (ch) {
			//发现运算符，用栈顶的两个元素进行运算。
		case '+':
			stack[top - 1] = stack[top - 1] + stack[top];
			top--;
			break;
		case '-':
			stack[top - 1] = stack[top - 1] - stack[top];
			top--;
			break;
		case '*':
			stack[top - 1] = stack[top - 1] * stack[top];
			top--;
			break;

		case '/':
			if (stack[top] != 0)
				stack[top - 1] = stack[top - 1] / stack[top];
			else {
				printf("\n\t除零错误!\n");
				//exit(0);                   /*异常退出*/
			}
			top--;
			break;
		default:
			d = 0;
			while (ch >= '0' && ch <= '9') {
				d = 10 * d + ch - '0'; /*将数字字符转化为对应的数值*/
				ch = ex[t];
				t++;
			}
			top++;
			stack[top] = d;
		}
		ch = ex[t];
		t++;
	}
	printf("\n\t计算结果:%g\n", stack[top]);
}

int main() {
	trans();      //转化成逆波兰式
	compvalue();  //计算值
	return 0;
}