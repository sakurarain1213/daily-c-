#include <bits/stdc++.h>
using namespace std;
#define TElemType string
//链式二叉查找树数据结构

map <string,string> mp;

typedef struct BSTNode
{
	TElemType data;//数据域
	struct BSTNode *lchild, *rchild;//左右孩子
}BSTNode, *BSTree;

//二叉查找树插入 参数T，二叉查找树根节点 作用：插入数据data,保证中序非严格递增（即可重复）
int BST_Insert(BSTree &T, TElemType data)
{
	if (T == NULL)//树为空
	{
		T = (BSTree)malloc(sizeof(BSTNode));//申请结点空间
		T->data = data;                     //赋值
		T->lchild = NULL;                   //左右孩子为空
		T->rchild = NULL;
		return 1;
	}
	else if (data < T->data)               //比当前节点数据小，插入左子树
	{
		return BST_Insert(T->lchild,data);
	}
	else                                   //这里规定二叉查找树可以重复，等于及大于当前结点时，插入右子树
	{
		return BST_Insert(T->rchild,data);
	}
}
//二叉查找树查找 参数 BSTree T, TElemType key，作用查找key是否存在于二叉查找树中，若存在，返回指向该结点的指针，否则，返回空
BSTNode * BST_Search(BSTree T, TElemType key)
{
   BSTNode *cur = T; //当前结点指针cur
   while (cur&&key!=cur->data)
   {
          cout<<cur->data<<' ';                      //按照要求 增加即时输出

	   if (key<cur->data)     //比当前结点数据小
	   {
		   cur = cur->lchild;
	   }
	   else                  //比当前结点数据大
	   {
		   cur = cur->rchild;
	   }
   }
   return cur;
}
//二叉查找树删除 参数 BSTree T, TElemType key，作用查找key是否存在于二叉查找树中，若存在，删除，返回true,否则，返回false
bool BST_Delete(BSTree &T, TElemType key)
{
	BSTNode*  cur = T;
	BSTNode*  cur_par = NULL;//当前结点的双亲结点
	while (cur&&key != cur->data)
	{
		if (key<cur->data)     //比当前结点数据小
		{
			cur_par = cur;    //记录双亲结点
			cur = cur->lchild;
		}
		else                  //比当前结点数据大
		{
			cur_par = cur;    //记录双亲结点
			cur = cur->rchild;
		}
	}
	if (cur)//找到 分情况删除 叶子结点（度为0） 单支结点（度为1） 双支结点（度为2）
	{
		if (cur->lchild==NULL&&cur->rchild==NULL)//叶子结点
		{
			if (cur == T)//根节点
			{
				T = NULL;
			}
			else if (cur_par->lchild == cur)//要删除的是cur_par的左孩子
			{
				cur_par->lchild = NULL;
			}
			else
			{
				cur_par->rchild = NULL;
			}
		}
		else if (cur->lchild == NULL || cur->rchild == NULL)//单支结点
		{
			if (cur == T)//根节点
			{
				if (cur->lchild)//有左孩子
				{
					T = cur->lchild;
				}
				else
				{
					T = cur->rchild;
				}
			}
			else //非根结点，双亲结点指向要删除结点的子结点即可
			{
				if (cur_par->lchild == cur&&cur->lchild)//cur为cur的双亲结点的左孩子，且有左孩子
				{
					cur_par->lchild = cur->lchild;
				}
				else if (cur_par->lchild == cur&&cur->rchild)
				{
					cur_par->lchild = cur->rchild;
				}
				else if (cur_par->rchild == cur&&cur->lchild)
				{
					cur_par->rchild = cur->lchild;
				} 
				else{
					cur_par->rchild = cur->rchild;
				}
			}
		}
		else //双支结点  可以选择与直接前驱交换数据域，然后删除直接前驱。
			//或者，与直接后继交换数据域，删除直接后继。这里选择后者。//应该改成前者  debug一下
	/* 	{
			BSTNode* temp = cur;//记录需要删除的结点，接下来要与直接后继交换数据域
			cur_par = cur;      //用cur找到temp的直接后继 则cur为temp右子树的最左孩子
			cur = cur->rchild;  //右子树
			while (cur->lchild)//找到直接后继，即右子树的最左孩子（最小值）
			{
				cur_par = cur;
				cur=cur->lchild;
			}
			temp->data = cur->data;//交换数据域
			if (cur_par == temp)//待删除结点的右子树没有左子树，即右子树根节点即为待删除结点后继
			{
				cur_par->rchild = cur->rchild;
			}
			else               //待删除结点的右子树有左子树
			{
				cur_par->lchild = cur->rchild;//将cur的右子树给双亲结点
			}		
		} */

        	{
			BSTNode* temp = cur;//记录需要删除的结点，接下来要与直接后继交换数据域
			cur_par = cur;      //用cur找到temp的直接后继 则cur为temp右子树的最左孩子   应该是左树的最右孩子
			cur = cur->lchild;  //右子树
			while (cur->rchild)//找到直接后继，即右子树的最左孩子（最小值）
			{
				cur_par = cur;
				cur=cur->rchild;
			}
			temp->data = cur->data;//交换数据域
			if (cur_par == temp)//待删除结点的右子树没有左子树，即右子树根节点即为待删除结点后继
			{
				cur_par->lchild = cur->lchild;
			}
			else               //待删除结点的右子树有左子树
			{
				cur_par->rchild= cur->lchild;//将cur的右子树给双亲结点
			}		
		    }
		free(cur);
		return true;
	}//if
	return false;
}


//调用BST_Insert进行二叉查找树的创建
void CreateBSTree(BSTree &T,int n)//n是插入个数
{
	string s;string other; 
	while(n--)
    {
      cin>>s>>other;
      mp[s]=other;//
      BST_Insert(T,s);
    }
/* 	printf("二叉查找树先序遍历序列:");
	PreOrder(T); */
}

//插入 调用BST_Insert
void InsertBSTree(BSTree &T)
{
	TElemType data;
//	printf("请输入要插入的数据：\n");
	cin >> data;
	BST_Insert(T,data);
	//printf("插入成功！！！\n");
}
//删除 调用BST_Delete
void DeleteBSTree(BSTree &T,int n)//删除个数
{
	TElemType key;
	//printf("请输入要删除的数据：\n");
    while(n--)
    {
       cin >> key;
	if (BST_Delete(T, key))
	{
	//	printf("删除成功！\n");
	}
	else
	{
	//	printf("未找到！\n");
	} 
    }
	
}
//查找 调用BST_Search
void SearchBSTree(BSTree T)
{
	TElemType data;
	BSTNode *p;
	//printf("请输入要查找的数据：\n");
	cin >> data;
	p = BST_Search(T, data);
	if (p) 
	{
		cout<<data<<' '<<mp[data]<<endl;//printf("该数据存在！！！\n");    输出有要求   map就在这里取巧用一下
	}
	else
    {   cout<<"NULL"<<endl;}            //有输出要求
		//printf("该数据不存在！！！\n");
}
//菜单
/* void menu()
{
	printf("********1.创建    2.遍历*********\n");
	printf("********3.插入    4.查找*********\n");
	printf("********5.删除    6.退出*********\n");
} */
//主函数
int main()
{
	BSTree T = NULL;//int choice = 0;
int n1,n2;
cin>>n1;
CreateBSTree(T,n1);
cin>>n2;
DeleteBSTree(T,n2);

		//case 3:InsertBSTree(T);break;

SearchBSTree(T);//自带cin
SearchBSTree(T);//自带cin
	return 0;
}

/* 
【输入】
6 train 火车 eye 眼睛 hello 你好 computer 电脑 wait 等待 zebra 斑马
1 eye
hello
eye
//插入
//删除
//查询目标1
//查询目标2
【输出】
train computer hello 你好//从根节点train开始，经过左孩子computer，然后右孩子，查找成功
train computer hello NULL//不存在


第1行，插入的单词数量，插入二叉查找树的单词信息，若干条包含key（string）和other（string）的序列；（单词数量小于2000）
第2行，删除的单词数量，从二叉查找树中删除的单词清单；（若为多个单词，会用空格隔开）（请用其前驱节点代替删除节点）
第3行，查询目标target1（英文单词）
第4行，查询目标target2（英文单词）

 */


















/* 
//先序遍历-递归
void PreOrder(BSTree T)
{
	if (T != NULL)
	{
		cout<<T->data<<" ";
		PreOrder(T->lchild);//递归先序遍历左右子树
		PreOrder(T->rchild);
	}
}
//中序遍历-递归
void InOrder(BSTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);//递归中序遍历左右子树
		cout << T->data << " ";
		InOrder(T->rchild);
	}
}
//后序遍历-递归
void PostOrder(BSTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);//递归后序遍历左右子树
		PostOrder(T->rchild);
		cout << T->data << " ";
	}
}
//层序遍历 借助队列
void LevelOrder(BSTree T)
{
	queue<BSTNode> q;//借助队列
	if (T != NULL)
	{
		BSTNode temp;//暂存要出队的结点
		q.push(*T);//根结点入队
		while (!q.empty())//队列非空
		{
			temp = q.front();
			q.pop();
			cout << temp.data << " ";
			if (temp.lchild != NULL) q.push(*temp.lchild);//队列先进先出，先入左孩子
			if (temp.rchild != NULL) q.push(*temp.rchild);
		}
	}
} */


//遍历功能函数 调用PreOrder InOrder PostOrder LevelOrder
/* void Traverse(BSTree T)
{
	int choice;
	while (1)
	{
		printf("********1.先序遍历    2.中序遍历*********\n");
		printf("********3.后序遍历    4.层次遍历*********\n");
		printf("********5.返回上一单元\n");
		printf("请输入菜单序号：\n");
		scanf("%d", &choice);
		if (5 == choice) break;                  
		switch (choice)
		{
	 	case 1: {printf("二叉查找树先序遍历序列:");PreOrder(T);printf("\n");}break;
		case 2: {printf("二叉查找树中序遍历序列:");InOrder(T);printf("\n");}break;
		case 3: {printf("二叉查找树后序遍历序列:");PostOrder(T);printf("\n");}break;
		case 4: {printf("二叉查找树层次遍历序列:");LevelOrder(T);printf("\n");}break; 
		default:printf("输入错误！！！\n");break;
		}
	}
} */