#include <stdlib.h>
#include "hashMap.h"
#include "structs.h"

int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
	return r;
}

void initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

void freeMap (struct hashMap * ht)
{  /*write this*/

}

void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  /*write this*/

}

ValueType* atMap (struct hashMap * ht, KeyType k)
{ /*write this?*/

}

int containsKey (struct hashMap * ht, KeyType k)
{  /*write this */

}

void removeKey (struct hashMap * ht, KeyType k)
{  /*write this */

}

int sizeMap (struct hashMap *ht)
{  /*write this*/

	
}

int capacityMap(struct hashMap *ht)
{  /*write this*/

	
}

int emptyBuckets(struct hashMap *ht)
{  /*write this*/

}

float tableLoad(struct hashMap *ht)
{  /*write this*/

	
}
