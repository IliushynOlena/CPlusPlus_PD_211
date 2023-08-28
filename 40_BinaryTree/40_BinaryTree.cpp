#include <iostream>
using std::cout;
using std::cin;
using std::endl;


// sorted binary tree
class Tree
{
	struct Node
	{
		// ключ по якому відбувається розміщення елементів
		int key;
		// дані, які зберігає елемент
		int data;

		// вказівник на лівий дочірній елемент
		Node* left;
		// вказівник на правий дочірній елемент
		Node* right;

		Node(int key, int data, Node* left = nullptr, Node* right = nullptr)
			: key(key), data(data), left(left), right(right)
		{ }
	};

	Node* root;

	void Add(int key, int data, Node*& root)
	{
		if (root == nullptr)
		{
			root = new Node(key, data);
			return;
		}

		if (key > root->key)
			Add(key, data, root->right);
		else
			Add(key, data, root->left);
	}

	// [K]oren [L]ivii [P]ravii
	void PrintKLP(Node* elem) const
	{
		if (elem != nullptr)
		{
			// K
			std::cout << elem->key << ":" << elem->data << " ";
			// L
			PrintKLP(elem->left);
			// P
			PrintKLP(elem->right);
		}
	}
	// LKP
	void PrintLKP(Node* elem) const
	{
		if (elem != nullptr)
		{
			// L
			PrintLKP(elem->left);
			// K
			std::cout << elem->key << ":" << elem->data << " ";
			// P
			PrintLKP(elem->right);
		}
	}
	// PKL
	void PrintPKL(Node* elem) const
	{
		if (elem != nullptr)
		{
			// P
			PrintPKL(elem->right);
			// K
			std::cout << elem->key << ":" << elem->data << " ";
			// L
			PrintPKL(elem->left);
		}
	}

	int Search(int key, Node* root) const
	{
		if (root == nullptr) return 0;

		if (key > root->key)
			Search(key, root->right);
		else if (key < root->key)
			Search(key, root->left);
		else
			return root->data;
	}

public:
	Tree() : root(nullptr) { }

	void Add(int key, int data)
	{
		Add(key, data, root);
	}

	int Search(int key) const
	{
		return Search(key, root);
	}

	void PrintKLP() const
	{
		PrintKLP(root);
	}
	void PrintLKP() const
	{
		PrintLKP(root);
	}
	void PrintPKL() const
	{
		PrintPKL(root);
	}
};

int main()
{
	Tree tree;

	tree.Add(50, 200);
	tree.Add(17, 100);
	tree.Add(12, 12);
	tree.Add(23, 5474);
	tree.Add(19, 54);
	tree.Add(14, 44);
	tree.Add(9, 10);
	tree.Add(72, 30);
	tree.Add(76, 33);
	tree.Add(54, 45);
	tree.Add(67, 11);
	tree.Add(52, 233);
	tree.Add(100, 0);

	cout << " KLP : "; tree.PrintKLP(); cout << endl;
	cout << " LKP : "; tree.PrintLKP(); cout << endl;
	cout << " PKL : "; tree.PrintPKL(); cout << endl;

	cout << tree.Search(67) << endl;

	system("pause");
	return 0;
}