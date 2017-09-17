/*
 * List.cpp
 *
 *  Created on: Sep 2, 2017
 *      Author: nafiu
 */

#include <iostream>
#include <cstdlib>
#include <new>
#include <exception>
#include "List.h"


List::List() {
	this->_node = nullptr;
	this->head = nullptr;
	this->mid = nullptr;
	this->tail = nullptr;
	this->height = 0;
}

List::List(const List& other) {
	NodePtr previous_node;
	height=other.height_list();

	try {
		for (NodePtr curr = other.get_head(); curr != nullptr; curr=curr->next) {
			NodePtr node = new Node;
			node->data = curr->data;

			if (curr == other.get_head()) {
				node->prev = nullptr;
				node->next = nullptr;
				set_head(node);
				previous_node = node;
			}
			else {
				previous_node->next = node;
				node->next = nullptr;
				node->prev = previous_node;

				previous_node = node;

				if (curr == other.get_mid()) set_mid(node);
				else if (curr == other.get_tail()) set_tail(node);
			}
		}
	} catch(std::bad_alloc &e) { std::cerr << e.what() << std::endl; }
}

List& List::operator=(const List& other) {
	List *tmp;
	try {
		tmp = new List;
		NodePtr previous_node;

		tmp->height = other.height_list();

		for (NodePtr curr = other.get_head(); curr != nullptr; curr = curr->next) {
			NodePtr node = new Node;
			node->data = curr->data;

			if (curr == other.get_head()) {
				node->next = nullptr;
				node->prev = nullptr;

				tmp->set_head(node);
				previous_node = node;
			}
			else {
				previous_node->next = node;
				node->prev = previous_node;
				node->next = nullptr;

				previous_node = node;

				if (curr == other.get_mid()) tmp->set_mid(node);
				else if (curr == other.get_tail()) tmp->set_tail(node);
			}

		}


	}catch(std::bad_alloc &e) { std::cerr << e.what() << std::endl; }

	return *tmp;
}

bool List::isEmpty() {
	return this->head == nullptr;
}

void List::insertfromhead(NodePtr _node) {
	NodePtr curr = get_head();

#ifndef __LIST_STRING
	while (curr != nullptr && curr->data <= _node->data) curr = curr->next;
#else
	while (curr != nullptr && strcmp(curr->data.c_str(), _node->data.c_str()) <= 0) curr = curr->next;
#endif
	if (curr != nullptr) {
		_node->next = curr;
		_node->prev = curr->prev;

		if (curr->prev != nullptr && curr->prev->next != nullptr) curr->prev->next = _node;//previous node point to the inserting node
		curr->prev = _node;
		if (curr == get_head()) set_head(_node);
	}
}

void List::insertfromtail(NodePtr _node) {
	NodePtr curr = get_tail();

#ifndef __LIST_STRING
	while (curr != nullptr && curr->data >= _node->data) curr = curr->prev;
#else
	while (curr != nullptr && strcmp(curr->data.c_str(), _node->data.c_str()) >= 0) curr = curr->prev;
#endif
	if (curr != nullptr) {
		_node->next = curr->next;
		_node->prev = curr;

		if (curr->next != nullptr) curr->next->prev = _node; // node to the right of curr node re-point to the inserting node
		curr->next = _node;
		if (curr == get_tail()) set_tail(_node);
	}
}

bool List::insertList(DATA data) {

try {
	NodePtr node = new Node;

	node->data = data;

	if ((*this).isEmpty()) {
		node->next = nullptr;
		node->prev = nullptr;

		set_head(node);
		set_mid(node);
		set_tail(node);
	}
	else {
		if ((height_list() > 2) && (height_list()%2) != 0) { //determining whether to shift the mid-point pointer
#ifndef __LIST_STRING
			if (get_mid()->data < data) set_mid((mid->next)? mid->next:mid); //shift mid-point to the left
			else set_mid((mid->prev)? mid->prev:mid); //shift to right
#else
			if (strcmp(get_mid()->data.c_str(), data.c_str()) < 0) set_mid((mid->next)? mid->next:mid); //shift mid-point to the left
			else set_mid((mid->prev)? mid->prev:mid); //shift to right
#endif
		}

#if !defined(__LIST_STRING)
		if (get_mid()->data < data) insertfromtail(node);
		else insertfromhead(node);
#else
		if (strcmp(get_mid()->data.c_str(), data.c_str()) < 0) insertfromtail(node);
		else insertfromhead(node);
#endif
	}

	incr_height();
}catch(std::bad_alloc &e){
	std::cerr << e.what() << std::endl;
}

	return true;
}

void List::printForward() {
	std::cout << "[ ";
	for (NodePtr curr = get_head(); curr != nullptr; curr=curr->next) std::cout << curr->data << " ";
	std::cout << "]\n";
}

void List::printReverse() {
	std::cout << "[ ";
	for (NodePtr curr = get_tail(); curr != nullptr; curr=curr->prev) std::cout << curr->data << " ";
	std::cout << "]\n";
}

List::~List() {

	for (NodePtr curr = get_head(); curr != nullptr;) {
		NodePtr tmp = curr;
		curr = curr->next;
		delete tmp;
	}
}

