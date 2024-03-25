#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lexicalUnit.h"

class node
{	
public:
	lexicalUnit* lexUnit;
	node* left;
	node* right;

	node(lexicalUnit* lu)
	{
		lexUnit = lu;
		left = NULL;
		right = NULL;
	}

	~node()
	{
	
	}

};

class BinTree
{
	node* root;

	node* search(node* pnode,char* pIdentificator);
	void del(node*& pnode,char* pIdentificator);
	void add(node*& node, lexicalUnit* lu);
	void print(node* pnode);

public:
	BinTree();
	~BinTree();
	int add(lexicalUnit* lu);
	int del(char* pIdentificator);
	node* search(char* Identificator);
	void print();

};