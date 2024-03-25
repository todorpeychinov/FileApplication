
#include "HashTable.h"
#include "string.h"

HashTable::HashTable()
{
}

int HashTable::HashFunction(char* pIdentificator)
{
	int index = 0;
	for (int i = 0; pIdentificator[i] != 0; i++)
	{
		index += pIdentificator[i];
	}
	return index % 128;
}

int HashTable::search(char* pIdentificator)
{
	int j = HashFunction(pIdentificator);

	for (int i = j; ; i++)
	{

		if (strcmp(Table[i].getIdentificator(), pIdentificator) == 0)
			return i;
		if (Table[i].getIdentificator()[0] == 0)
			return i + 200;
		if (i == 127)
			i = 0;
		if (i == j - 1)
			return -1;

	}

	
}

int HashTable::add(lexicalUnit& lu)
{
	int index = search(lu.getIdentificator());
	if (index < 0)
		return -1;
	else if (index > 200)
		index -= 200;
	
	Table[index] = lu;
	return 1;

}

int HashTable::del(char* pIdentificator)
{
	int index = search(pIdentificator);
	if ((index < 0) || (index > 200))
		return -1;
	Table[index].getIdentificator()[0] = 0;
	return 1;
		
}

void HashTable::print()
{
	for (int i = 0; i < 127; i++)
	{
		if (Table[i].getIdentificator()[0])
		{
			Table[i].print();
		}
	}
}

HashTable::~HashTable()
{

}
