/*
 * List.h
 *
 *  Created on: Sep 2, 2017
 *      Author: nafiu
 */

#ifndef LIST_H_
#define LIST_H_

#include <cstring>

//#define __LIST_STRING
#define DATA long int

#if defined(__LIST_CHAR)
#undef DATA
#define DATA char
#endif

#ifdef __LIST_STRING
#undef DATA
#define DATA std::string
#endif

#ifdef __LIST_FLOAT
#undef DATA
#define DATA float
#endif

#ifdef __LIST_DOUBLE
#undef DATA
#define DATA double
#endif

typedef struct node {
	DATA data;
	struct node *next;
	struct node *prev;
} *NodePtr, Node;


class List {
private:
	NodePtr _node;
	NodePtr head, mid, tail;
	unsigned height;
public:

	List();
	List(const List&);
	List& operator=(const List&);

	void set_head(NodePtr hd) { this->head = hd; }
	void set_mid(NodePtr md) { this->mid = md; }
	void set_tail(NodePtr tl) { this->tail = tl; }

	NodePtr get_head() const { return this->head; }
	const NodePtr get_mid() const { return this->mid; }
	const NodePtr get_tail() const { return this->tail; }

	unsigned height_list() const { return this->height; }
	void incr_height() { ++(this->height); }

	bool insertList(DATA data);
	void insertfromhead(NodePtr _node);
	void insertfromtail(NodePtr);

	void printForward();
	void printReverse();
	bool isEmpty();

	virtual ~List();
};

#endif /* LIST_H_ */
