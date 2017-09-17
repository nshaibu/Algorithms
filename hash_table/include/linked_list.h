/*
 * linked_list.h
 *
 *  Created on: Aug 11, 2017
 *      Author: nafiu
 */


#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>

#define DATA long int

#if defined(__STACK_CHAR)
#undef DATA
#define DATA char
#endif

#ifdef __STACK_STRING
#undef DATA
#define DATA char *
#endif

#ifdef __STACK_FLOAT
#undef DATA
#define DATA float
#endif

#ifdef __STACK_DOUBLE
#undef DATA
#define DATA double
#endif

#define MAX_CHAR 25

typedef struct Node {
#if !defined(__STACK_STRING)
	DATA data;
#else
	char data[MAX_CHAR];
#endif

	struct Node *next;
} *NodePtr, NodeData;


extern void initList(NodePtr *head);
extern unsigned int sizeList(const NodePtr *head);
extern int insertNode(NodePtr *head, DATA data);
extern void showList(const NodePtr *head);
extern int isempty(const NodePtr *head);
extern int find(const NodePtr *head, DATA key);
extern void linked_list_destroy(NodePtr *head);


#endif /* LINKED_LIST_H_ */
