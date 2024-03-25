#include "BinTree.h"

BinTree::BinTree()
{
	root = NULL;
}

BinTree::~BinTree()
{
	delete root;
}


void BinTree::add(node*& pnode,lexicalUnit* lexUnit)
{
	if (pnode == NULL)
	{
		pnode = new node(lexUnit);
	}
	else
	{
		if (strcmp(lexUnit->getIdentificator(), pnode->lexUnit->getIdentificator()) < 0)
		{
			add(pnode->left, lexUnit);
		}
		else
		{
			add(pnode->right, lexUnit);
		}
	}

}

void BinTree::del(node*& pnode, char* pIdentificator)
{
	if (pnode == NULL)
		printf("Error! There is no such element!\n");
	else
	{

		if (strcmp(pIdentificator, pnode->lexUnit->getIdentificator()) < 0)
		{
			del(pnode->left, pIdentificator);
		}
		else if (strcmp(pIdentificator, pnode->lexUnit->getIdentificator()) > 0)
		{
			del(pnode->right, pIdentificator);
		}
		else
		{	

			

			if (pnode->left != NULL && pnode->right != NULL)
			{
				node* temp = pnode->right;
				while (temp->left != NULL)
					temp = temp->left;
				pnode->lexUnit = temp->lexUnit;
				del(pnode->right, pnode->lexUnit->getIdentificator());
			}
			else
			{
				node* tmp = pnode;
				if (pnode->left)
					pnode = pnode->left;
				else
					pnode = pnode->right;
				delete pnode;
			}
		}
	}
}

node* BinTree::search(node* pnode, char* pIdentificator)
{
	if (pnode == NULL || strcmp(pIdentificator, pnode->lexUnit->getIdentificator()) == 0)
	{
		return pnode;
	}

	if (strcmp(pIdentificator, pnode->lexUnit->getIdentificator()) < 0)
	{
		return search(pnode->left, pIdentificator);
	}
	else
	{
		return search(pnode->right, pIdentificator);
	}
}

void BinTree::print(node* pnode)
{
	if (pnode != NULL)
	{
		print(pnode->left);
		pnode->lexUnit->print();
		print(pnode->right);
	}

}

int BinTree::add(lexicalUnit* lu)
{
	add(root, lu);
	return 1;
}

void BinTree::print()
{
	print(root);
}

int BinTree::del(char* pIdentificator)
{
	del(root, pIdentificator);
	return 1;
}

node* BinTree::search(char* pIdentificator)
{
	return search(root, pIdentificator);
}


