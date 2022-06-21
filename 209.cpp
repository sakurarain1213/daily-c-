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
//其实就是补了这一段
template<class T>
bool hasPathSum(BinTreeNode<T>* root, int sum) {
	if (root == NULL)
		return false;
	if (root->leftChild == NULL && root->rightChild == NULL)
	{
		if (root->data == sum)
			return true;
		else
			return false;
	}
	else if (root->leftChild == NULL && root->rightChild != NULL)
		return hasPathSum(root->rightChild, sum - root->data);
	else if (root->leftChild != NULL && root->rightChild == NULL)
		return hasPathSum(root->leftChild, sum - root->data);
	else
		return hasPathSum(root->leftChild, sum - root->data)||hasPathSum(root->rightChild, sum - root->data);
}
int main()
{
	int a,sum;
	cin >> a;
	if (a==0) 
	{cout<<0<<" false";return 0;}
	if(a==1)
	{
    int t;cin>>t;cin>>sum;
	if(t==sum)
	cout<<0<<" true";
	else
	cout<<0<<" false";
    return 0;
	}
	BinaryTree<int> *tree = new BinaryTree<int>;
	tree->LevelCreateTree(a);

	cin>>sum;
	//	cout << endl << "二叉树的高度:" << endl;
	cout << tree->Height()-1 <<' ';
    if(hasPathSum(tree->getRoot(), sum)==true) cout<<"true";
	else cout<<"false";

 return 0;
}  

/* 
7 1 2 2 3 4 4 3
7

6 1 3 2 3 4 7
10
 */