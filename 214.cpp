#include <bits/stdc++.h>

using namespace std;

template<class T>
class BinTreeNode {
public:
	T data;
	BinTreeNode<T> *leftChild, *rightChild;
	BinTreeNode() : //构造方法
			leftChild(NULL), rightChild(NULL) {
	}
	BinTreeNode(T x) { //重载构造方法
		leftChild = NULL;
		rightChild = NULL;
		data = x;
	}
	BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL) : //重载构造方法
			data(x), leftChild(l), rightChild(r) {
	}
 
};
template<class T>
class BinaryTree {
 
public:
	friend class BinTreeNode<T> ;
	BinaryTree(); //构造方法
	BinaryTree(T value); //重载构造方法
	~BinaryTree(); //析构方法
	BinTreeNode<T>* CreateBinaryTree(); //前序遍历创建二叉树，输入0结尾，由PreOrderCreate调用
	BinTreeNode<T> *CreateByPreIn(T *VLR, T*LVR, int n); //利用前序遍历和中序遍历创建二叉树
	void LevelCreateTree(int a); //层次遍历创建完全二叉树
	void PreOrderCreate(); //调用CreateBinaryTree创建二叉树
	void CreateByPI(int); //调用CreateByPreIn创建二叉树
	bool isEmpty(); //判断是否为空
	void inOrder(BinTreeNode<T> *p); //中序遍历
	void preOrder(BinTreeNode<T> *p); //前序遍历
	void postOrder(BinTreeNode<T> *p); //后序遍历
	void visit(BinTreeNode<T> *p); //访问输出
	BinTreeNode<T> *Parent(BinTreeNode<T> *current); //获得父节点
	BinTreeNode<T> *LeftChild(BinTreeNode<T> *current); //获得左子节点
	BinTreeNode<T> *RightChild(BinTreeNode<T> *current); //获得右子节点
	BinTreeNode<T> *getRoot() const; //获得根节点
	int Height(); //返回二叉树高度
	int Size(); //返回二叉树节点数
	int max(int, int); //辅助方法，求大值
	int TreeHeight(BinTreeNode<T> *root); //计算树高度，由Height调用
	int getSize(BinTreeNode<T> *p); //计算节点数，由Size调用
	void levelOrder(BinTreeNode<T> *p); //层次遍历
	void Traverse(BinTreeNode<T> *subTree, ostream& out); //输出
	void destroy(BinTreeNode<T> *subTree); //销毁
protected:
 
	T RefValue;
	BinTreeNode<T> *root;
	friend ostream& operator <<(ostream& out, BinaryTree<T> *Tree) { //运算符重载
		out << "前序遍历输出" << endl;
		Tree->Traverse(Tree->root, out);
		out << endl;
		return out;
 
	}
 
};
template<class T>
BinaryTree<T>::BinaryTree() {
	root = NULL;
}
 
template<class T>
BinaryTree<T>::BinaryTree(T value) {
	root->data = value;
}
template<class T>
BinaryTree<T>::~BinaryTree() {
	destroy(root);
}
template<class T>
void BinaryTree<T>::visit(BinTreeNode<T> *p) {
	cout << p->data << " ";
}
template<class T>
BinTreeNode<T> * BinaryTree<T>::CreateBinaryTree() {
	BinTreeNode<T> *nodeP = new BinTreeNode<T>;
	T data;
	cin >> data;
	if (data == '0') {
		nodeP = NULL;
	} else {
		nodeP->data = data;
		cout << "请输入" << nodeP->data << "的左节点" << endl;
		nodeP->leftChild = CreateBinaryTree();
		cout << "请输入" << nodeP->data << "的右节点" << endl;
		nodeP->rightChild = CreateBinaryTree();
	}
 
	return nodeP;
}
 
template<class T>
void BinaryTree<T>::destroy(BinTreeNode<T> *subTree) {
	if (subTree != NULL) {
		destroy(subTree->leftChild);
		destroy(subTree->rightChild);
		delete subTree;
	}
}
template<class T>
void BinaryTree<T>::LevelCreateTree(int a) {
	queue<BinTreeNode<T>*> *que = new queue<BinTreeNode<T>*>;
	int count = 1;
	BinTreeNode<T> *node = new BinTreeNode<T>;
	root = new BinTreeNode<T>;
	node = root;
	cin >> root->data;
	que->push(node);
	while (!que->empty()) {
		node = que->front();
		que->pop();
		if (node->leftChild == NULL) {
			BinTreeNode<T> *l = new BinTreeNode<T>;
			cin >> l->data;
			node->leftChild = l;
			que->push(l);
			count++;
			if (count == a)
				break;
		}
		if (node->rightChild == NULL) {
			BinTreeNode<T> *r = new BinTreeNode<T>;
			cin >> r->data;
			node->rightChild = r;
			que->push(r);
			count++;
			if (count == a)
				break;
		}
	}
}
 
template<class T>
int BinaryTree<T>::max(int m, int n) {
	if (m > n)
		return m;
	else
		return n;
}
 
template<class T>
int BinaryTree<T>::Size() {
 
	return getSize(root);
 
}
 
template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T> *subTree, ostream &out) {
	if (subTree != NULL) {
		out << subTree->data << " ";
		Traverse(subTree->leftChild, out);
		Traverse(subTree->rightChild, out);
	}
}
 
template<class T>
BinTreeNode<T> *BinaryTree<T>::LeftChild(BinTreeNode<T> *current) {
	return (current != NULL) ? current->leftChild : NULL;
}
 
template<class T>
void BinaryTree<T>::preOrder(BinTreeNode<T> *p) {
	if (p != NULL) {
		cout << p->data << " ";
		preOrder(p->leftChild);
		preOrder(p->rightChild);
	}
}
template<class T>
void BinaryTree<T>::postOrder(BinTreeNode<T> *p) {
	if (p != NULL) {
		postOrder(p->leftChild);
		postOrder(p->rightChild);
		cout << p->data << " ";
	}
}
template<class T>
int BinaryTree<T>::Height() {
	return TreeHeight(root);
}
 
template<class T>
void BinaryTree<T>::PreOrderCreate() {
	cout << "请输入根节点" << endl;
	root = CreateBinaryTree();
}
 
template<class T>
void BinaryTree<T>::inOrder(BinTreeNode<T> *p) {
	if (p != NULL) {
		inOrder(p->leftChild);
		cout << p->data << " ";
		inOrder(p->rightChild);
	}
}
 
template<class T>
BinTreeNode<T> *BinaryTree<T>::getRoot() const {
	return root;
}
 
template<class T>
bool BinaryTree<T>::isEmpty() {
	return root == NULL;
}
 
template<class T>
void BinaryTree<T>::CreateByPI(int n) {
	T *a = new T[n];
	T *b = new T[n];
	int i = 0;
	cout<<"请再输入前序序列:"<<endl;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout<<"请再输入中序序列："<<endl;
	for (i = 0; i < n; i++) {
		cin >> b[i];
	}
	root = CreateByPreIn(a, b, n);
}
 
template<class T>
int BinaryTree<T>::getSize(BinTreeNode<T> *p) {
	int con = 0;
	if (p != NULL) {
		con++;
		con += getSize(p->leftChild);
		con += getSize(p->rightChild);
	}
	return con;
}
 
template<class T>
BinTreeNode<T> *BinaryTree<T>::RightChild(BinTreeNode<T> *current) {
	return (current != NULL) ? current->rightChild : NULL;
}
 
template<class T>
int BinaryTree<T>::TreeHeight(BinTreeNode<T> *root) {
	if (root == NULL
	)
		return 0;
	else
		return 1
				+ max(TreeHeight(root->leftChild), TreeHeight(root->rightChild));
}
 
template<class T>
void postOrder(BinTreeNode<T> *p) {
	if (p != NULL) {
		postOrder(p->leftChild);
		postOrder(p->rightChild);
		cout << p->data << " ";
 
	}
}

template<class T>
BinTreeNode<T> *BinaryTree<T>::CreateByPreIn(T *VLR, T *LVR, int n) {
	if (n == 0)
		return NULL;
	int k = 0;
	while (VLR[0] != LVR[k])
		k++;
	BinTreeNode<T> *t = new BinTreeNode<T>();
	t->data = VLR[0];
	t->leftChild = CreateByPreIn(VLR + 1, LVR, k);
	t->rightChild = CreateByPreIn(VLR + k + 1, LVR + k + 1, n - k - 1);
	return t;
}
 
template<class T>
void BinaryTree<T>::levelOrder(BinTreeNode<T> *p) {
	queue<BinTreeNode<T>*> *Q = new queue<BinTreeNode<T>*>;
	p = root;
	Q->push(p);
	while (!Q->empty()) {
		p = Q->front();
		Q->pop();
		cout << p->data << " ";
		if (p->leftChild != NULL
		)
			Q->push(p->leftChild);
		if (p->rightChild != NULL
		)
			Q->push(p->rightChild);
	}

}
int main()
{
/* cout << "请输入要创建二叉树的节点数" << endl; */
	int a;
	cin >> a;
	if (a==0) return 0;
	if(a==1)
	{
    int t;cin>>t;
	cout<<0<< endl<<t<< endl<<t<< endl<<t;
    return 0;
	}
	/* cout << "请按照节点顺序输入" << a << "个二叉树数据" << endl; */
	BinaryTree<int> *tree = new BinaryTree<int>;
	tree->LevelCreateTree(a);
	//	cout << endl << "二叉树的高度:" << endl;
	cout << tree->Height()-1 << endl;
//	cout << "前序遍历输出:" << endl;
	tree->preOrder(tree->getRoot());cout <<endl;
//	cout << endl << "中序遍历输出:" << endl;
	tree->inOrder(tree->getRoot());cout <<endl;
//	cout << endl << "后序遍历输出:" << endl;
	tree->postOrder(tree->getRoot());cout <<endl;
/* 	cout << endl << "层次遍历输出:" << endl;
	tree->levelOrder(tree->getRoot()); */
/* 
	cout << "二叉树的节点数:" << endl;
	cout << tree->Size() << endl;
	cout << "请输入某一二叉树的前序序列和中序序列" << endl;
	cout << "请先输入节点个数：" << endl;
	int x = 0;
	cin >> x;
	tree->CreateByPI(x);
	cout << "前序遍历输出:" << endl;
	tree->preOrder(tree->getRoot());
	cout << endl << "中序遍历输出:" << endl;
	tree->inOrder(tree->getRoot());
	cout << endl << "后序遍历输出:" << endl;
	tree->postOrder(tree->getRoot());
	cout << endl << "层次遍历输出:" << endl;
	tree->levelOrder(tree->getRoot());
	cout << endl << "二叉树的高度:" << endl;
	cout << tree->Height() << endl;
	cout << "二叉树的节点数:" << endl;
	cout << tree->Size() << endl;
 */
 return 0;
}  

/* 
【输入】
10 0 1 2 3 4 5 6 7 8 909

【输出】
3
0 1 3 7 8 4 9 2 5 6
7 3 8 1 9 4 0 5 2 6
7 8 3 9 4 1 5 6 2 0

 */