#pragma once
#include "lexicalUnit.h"

class descriptors
{
	lexicalUnit Table[100];
	int number;

public:
	descriptors();
	~descriptors();
	int add(lexicalUnit& lu);
	int del(char* pIdentificator);
	int search(char* pIdentificator);
	void print();

};
