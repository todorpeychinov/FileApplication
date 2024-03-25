#include "DihotTable.h"
#include "string.h"

DihotTable::DihotTable()
{
	number = 0;
}

int DihotTable::add(lexicalUnit& lu)
{
	if (number < 100)
	{
		int index = search(lu.getIdentificator());
		if (index >= 100)
		{
			index = index - 100;
			for (int j = number; j > index; j--)
				Table[j] = Table[j - 1];
			Table[index] = lu;
			number++;
			return 1;
		}

	}
	return 0;
}

int DihotTable::search(char* pIdentificator)
{
	int min = 0;
	int max = number;
	int mid = 0;
	
	while (max >= min)
	{
		mid = (max + min) / 2;

		if (strcmp(pIdentificator, Table[mid].getIdentificator()) < 0)
		{
			max = mid - 1;
			mid = (min + max) / 2;

		}


		else if (strcmp(pIdentificator, Table[mid].getIdentificator()) > 0)
		{
			min = mid + 1;
			mid = (min + max) / 2;
		}

		else if (strcmp(pIdentificator, Table[mid].getIdentificator()) == 0)
			return mid;
		
	}
	return mid + 100;

}



int DihotTable::del(char* pIdentificator)
{
	if (number != 0)
	{
		int index = search(pIdentificator);

		if (index < 100)
		{
			for (int i = index; i < number - 1; i++)
			{
				Table[i] = Table[i + 1];
			}
			number--;
			return 1;
		}
		return 0;
		
	}
	return 0;
}

void DihotTable::print()
{
	for (int i = 0; i < number; i++)
	{
		Table[i].print();
	}
}

DihotTable::~DihotTable()
{
}