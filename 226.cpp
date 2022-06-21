#include <bits/stdc++.h>
using namespace std;

template<class T>
class BSTNode
{
public:
	T val;
	BSTNode <T> *left, *right;
	//BSTNode(T key):
		//val(key){}
};
 template<class T>
class BSTree
{
public:
	BSTNode <T>*root;
	BSTree();
	void insert(BSTree<T>*t,T key);
	void InOrder(BSTNode<T> *t);
	void BSTdelete(T key);
    BSTNode<T> *Search(BSTNode<T> *t, const T &key);

	//void insert(BSTNode<T>* &t,T key);
	
 private:
};
 template<class T>
BSTree<T>::BSTree()
{
	root =NULL;
}
 template<class T>
void BSTree<T>::insert(BSTree<T>*t,T key)
{
	if (!t)
		BSTNode<T> *t = new BSTNode<T>;
	else if (key < t->root->val)
		insert(t->root->left, key);
	else if (key > t->root->val)
		insert(t->root->right, key);
	else
		cout << "不要插入相同的键值" << endl;
}
 
/*插入算法*/ 

/* void BSTree<T>::insert(T key)
{
	insert(root->left, key);
} */

/* void BSTree<T>::InOrder(BSTNode <T>*t)
{
	if (t)
	{
		InOrder(t->left);
		cout << "<"<<t->val << ">";
		InOrder(t->right);
	}
} */

/*找到需要删除数值所在的节点*/ 



/* AVLNode<T>* AVLTree<T>::search(const T x, AVLNode<T>*ptr) {
    if (ptr == NULL)return NULL;
    else if (x < ptr->data){cout<< ptr->data<<" ";return search(x, ptr->left);}
    else if (x > ptr->data){cout<< ptr->data<<" ";return search(x, ptr->right);}
    else {cout<< ptr->data<<" ";return ptr;}
} */


/* BSTNode<T>* BSTree<T>::find_equal(BSTNode<T>* t,const T key)
{
	if (!t)
	{
		cout << "二叉树中不存在改数值！" << endl;
		return NULL;
	}
	if (key < t->val)
		find_equal(t->left, const T key);
	else if (key > t->val)
		find_equal(t->right,const T key);
	else
		return t;
} */
template<class T>
BSTNode<T>* Search(BSTNode<T> *t, const T &key)
	{
		if (t == nullptr || t->data == key)
			return t;
		if (key < t->data)
			return Search(t->left, key);
		else
			return Search(t->right, key);
	}
  template<class T>
void BSTree<T>::BSTdelete(T key)
{
	BSTNode<T> *&p = find_equal(root->left, key);
	if (p)
	{
		BSTNode<T> *t = p;
		if (t->left&&t->right)
		{
			//左右子树都不为空
			BSTNode<T> *y = t;
			BSTNode<T> *x = t->right;
			while (x->left)
			{
				y = x;
				x = x->left;
			}
			if (y == t)  //y与t重合的情况
				y->right = x->right;
			else
				y->left = x->left;
			p = x;
			x->left = t->left;
			x->right = t->right;
		}
		else
		{
			//只有一个儿子
			p = t->left ? t->left : t->right;
		}
		delete t;
	}
}




int main()
{
BSTree<int> tree;
int n,t;
cin>>n;
while(n--)
{
    cin>>t;
    tree.insert(&tree,t);
}
int p,q;
cin>>p,q;
	tree.InOrder(tree.root->left);
//lowestCommonAncestor;

	return 0;
}
/* 8 6 2 8 4 3 5 7 9
2 8 */

/*  	BSTree tree;
	int key,count ;
	cout << "1、添加树     2、输入要删除的数字    3、退出" << endl;
	cin >> count;
	while (count != 3)
	{
		if (count == 1)
		{
			cout << "请输入要添加的数据：" << endl;
			cin >> key;
			tree.insert(key);
		}
		if (count == 2)
		{
			cout << "请输入要删除的数据：" << endl;
			cin >> key;
			tree.BSTdelete(key);
		}
		cout << "\n搜索树中序遍历结果:" << endl;
		cout << "{";
		tree.InOrder(tree.root->left);
		cout << "}" << endl;
 
		cout << "1、添加树     2、输入要删除的数字    3、退出" << endl;
		cin >> count;
	}
	cout << "退出！" << endl; */