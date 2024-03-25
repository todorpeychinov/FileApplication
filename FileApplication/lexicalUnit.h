#pragma once

class lexicalUnit
{
	char identificator[20];
	char type[20];
	char descriptor[5];
	int address;
	void setAddress(char* type);

	void setDescriptor();

public:
	static int newAddress;
	static int newDescriptor;

	lexicalUnit();
	lexicalUnit(char* pIdentificator, char* pType);
	lexicalUnit& operator=(lexicalUnit& lu);
	~lexicalUnit();
	char* getIdentificator();
	void print();
	char* getType();

};