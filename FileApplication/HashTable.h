#pragma once
#include "lexicalUnit.h"
class HashTable
{
	lexicalUnit Table[128];

public:
	HashTable();
	int HashFunction(char* pidentificator);
	int search(char* pIdentificator);
	int add(lexicalUnit& lu);
	int del(char* pidentificator);
	void print();
	~HashTable();
};