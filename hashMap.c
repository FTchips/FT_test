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
{
    struct hashLink *temp;
    struct hashLink *current;
    int i;
    for(i = 0; i < ht->tableSize )
    {
        current = ht->table;
        while(current != 0)
        {
            temp = current;
            current = current ->next;
            free(temp);
        }
    }
    free(ht->table);
    ht->count = 0;
    ht->tableSize = 0;
    free(ht);
}

void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{
    struct hashLink* temp, temp2;
    temp = atMap(ht, k);
    int index = stringHash2(k) % ht->tableSize;

    if(temp != 0)
    {
       temp->value = v;
    }
    else
    {
        temp = ht->table[index];
        if(temp != 0)
        {
            while(temp != 0)
            {
                temp2 = temp;
                temp = temp ->next;
            }
            temp = (hashLink*)malloc(sizeof(hashLink));
            temp->key = k;
            temp->value = v;
            temp->next = 0;
            temp2->next = temp;
        }
        else
        {
            ht->table[index] = (hashLink*)malloc(sizeof(hashLink));
            ht->table[index]->key = k;
            ht->table[index]->value = v;
            ht->table[index]->next = NULL;

        }
        ht->count++;
    }
}

ValueType* atMap (struct hashMap * ht, KeyType k)
{
    struct hashLink* temp;
    int index = stringHash2(k) % ht->tableSize;
    temp = ht->table[index];
    while((temp->key != k) && (temp != 0))
    {
        temp = temp->next;
    }
    return temp;
}

int containsKey (struct hashMap * ht, KeyType k)
{
    return atMap(ht, k) != 0;
}

void removeKey (struct hashMap * ht, KeyType k)
{
    struct hashLink* curr, prev;
    if(containsKey(k))
    {
        curr = ht->table[stringHash2(k) % ht->tableSize];
        while(curr->key != k)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        free(curr);
        ht->count --;
    }
}

int sizeMap (struct hashMap *ht)
{
    return ht->count;
}

int capacityMap(struct hashMap *ht)
{
    return ht->tableSize;
}

int emptyBuckets(struct hashMap *ht)
{
    int count, i;

    for(i = 0, i < ht->tableSize, i++)
    {
        if(ht->table[i] == 0)
            count++;
    }
    return count;
}

float tableLoad(struct hashMap *ht)
{
    return (float)sizeMap(ht)/(float)capacityMap(ht);
}
