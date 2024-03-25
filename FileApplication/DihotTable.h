#pragma once
#include "lexicalUnit.h"

class DihotTable
{
	lexicalUnit Table[100];
	int number;

public:
	DihotTable();
	~DihotTable();
	int add(lexicalUnit& lu);
	int del(char* pIdentificator);
	int search(char* pIdentificator);
	void print();

};
