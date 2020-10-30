// LabWork291219.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

struct TMyBinItem
{
	int value;
	TMyBinItem* parent;
	TMyBinItem* left;
	TMyBinItem* right;
};

class TMyTree
{
public:
	TMyTree()
	{
		root = NULL;
	}

	~TMyTree()
	{
	
	}
	void Insert(int value)
	{
		if (root == NULL)
		{
			TMyBinItem* newItem = new TMyBinItem;
			newItem->value = value;
			newItem->parent = newItem->left = newItem->right = NULL;
			root = newItem;
			return;
		}

		TMyBinItem* curItem = root;
		while (true)
		{
			if (value <= curItem->value)
			{
				if (curItem->left != NULL)
					curItem = curItem->left;
				else
					break;			
			}
			else
			{
				if (curItem->right != NULL)
					curItem = curItem->right;
				else
					break;
			}
		}

		TMyBinItem* newItem = new TMyBinItem;
		newItem->value = value;
		newItem->parent = curItem;
		
		newItem->left = newItem->right = NULL;

		if (value <= curItem->value)
			curItem->left = newItem;
		else
			curItem->right = newItem;

	}

	void out(TMyBinItem* item)
	{
		if (item != NULL)
		{
			if (item->left != NULL)
				out(item->left);

			cout << item->value << " ";

			if (item->right != NULL)
				out(item->right);
		}
	}

	TMyBinItem* getRoot() 
	{
		return root;
	}

	TMyBinItem* Search(int value)
	{
		TMyBinItem* curItem = root;
		while ((curItem != NULL) && (curItem->value != value))
		{
			if (value < curItem->value)
				curItem = curItem->left;
			else
				curItem = curItem->right;
		}
		return curItem;
	}


private:
	TMyBinItem* root;
};

int main()
{
	TMyTree tree;
	tree.Insert(15);
	tree.Insert(5);
	tree.Insert(14);
	tree.Insert(1);
	tree.Insert(8);
	tree.Insert(-1);
	tree.Insert(22);


	cout << "\n";
	tree.out(tree.getRoot());
	
	cout << "\n";
	tree.out(tree.Search(5));

}
