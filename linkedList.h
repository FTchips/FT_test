#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

# define TYPE      double
# define TYPE_SIZE sizeof(TYPE)

struct LinkedList;

void  initLinkedList(struct LinkedList *l);
void  freeLinkedList(struct LinkedList *l);

int   isEmptyLinkedList(struct LinkedList *l);
void  pushLinkedList(struct LinkedList *l, TYPE val);
TYPE  topLinkedList(struct LinkedList *l);
void  popLinkedList(struct LinkedList *l);

/* Bag */

void addLinkedList(struct LinkedList *l, TYPE val);
void containsLinkedList( struct LinkedList *l, TYPE val);
void removeLinkedList( struct LinkedList *l, TYPE val);
#endif

