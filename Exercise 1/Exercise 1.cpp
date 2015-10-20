// By Yanzhengyang @2015-10-17 21:17
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

template<class Type>
struct BTnode
{
	Type value;
	BTnode *left;
	BTnode *right;
};

template<class Type>
void print(BTnode<Type> n, int type)
{
	if (type == 0) 											//中序遍历
	{
		if (n.left != NULL)
		{
			print(*n.left, type);
		}

		cout << n.value;

		if (n.right != NULL)
		{
			print(*n.right, type);
		}
	}

	if (type == 1) 											//先序遍历
	{
		cout << n.value;

		if (n.left != NULL)
		{
			print(*n.left, type);
		}

		if (n.right != NULL)
		{
			print(*n.right, type);
		}

	}

	if (type == 2) 											//后序遍历
	{
		if (n.left != NULL)
		{
			print(*n.left, type);
		}

		if (n.right != NULL)
		{
			print(*n.right, type);
		}

		cout << n.value;


	}

	else return;

}

template<class Type>
void destroy(BTnode<Type> *n)
{
	if(n == NULL)
		return;
	destroy(n->left);
	destroy(n->right);
	delete n;
	n = NULL;
	return;

}



BTnode<string>* stringToNode(string a, string b)
{
	if (a.length() == 0)									//传入无字符参数时直接返回NULL
	{
		return NULL;
	}

	if (a.length() == 1)									//传入单字符参数时直接返回无子节点
	{
		BTnode<string> *root = new BTnode<string>;
		root->value = a;
		root->left = root->right = NULL;					//不加这个很蛋疼
		return root;
	}

	BTnode<string> *root = new BTnode<string>;
	root->value = a[0]; 									//先序遍历的节点加入到根节点中

	int i = 0;
	while (b.substr(i, 1) != root->value)
	{
		i++;
	}

	string temp1 = a.substr(1, i);  						//分割左子树的先序遍历字符串
	string temp2 = b.substr(0, i);							//分割左子树的中序遍历字符串

	string temp3 = a.substr(i + 1, a.length() - i - 1);		//分割右子树的先序遍历字符串
	string temp4 = b.substr(i + 1, b.length() - i - 1);		//分割右子树的中序遍历字符串

	root->left = stringToNode(temp1, temp2); 				//递归返回左子树
	root->right = stringToNode(temp3, temp4); 				//递归返回右子树
	return root;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	string a,b;

	while(cin >> a >> b)
	{

		cout << "PreOrderInput:\t" << a << endl << "InOrderInput:\t" << b << endl;

		BTnode<string> *t;
		t= stringToNode(a, b);

		cout << "PreOrder: \t";

		print(*t, 1);
		cout << endl;

		cout << "InOrder: \t";
		print(*t, 0);
		cout << endl;

		cout << "PostOrder: \t";
		print(*t, 2);
		cout << endl << endl;

		//destroy(t);
	}
	return 0;
}
