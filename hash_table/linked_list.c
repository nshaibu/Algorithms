/*
 * linked_list.c
 *
 *  Created on: Aug 11, 2017
 *      Author: nafiu
 */


#include <stdlib.h>
#include <string.h>
#include "./include/linked_list.h"

/*
void swap(NodePtr a, NodePtr b) {
	NodePtr tmp ;
}
*/

void initList(NodePtr *tmp) {
	*tmp = NULL;
}

int isempty(const NodePtr *head){
	return *head == NULL;
}

unsigned int sizeList(const NodePtr *head) {
	unsigned int count = 0;
	for (NodePtr tmp=*head; tmp != NULL; tmp = tmp->next) count++;

	return count;
}

int insertNode(NodePtr *head, DATA data) {
	NodePtr curr = *head, prev = *head;

	NodePtr node = (NodePtr)malloc(sizeof(NodeData));
	if (node == NULL){
		perror("mem_error");
		exit(EXIT_FAILURE);
	}

	if (isempty(head)){
#if defined(__STACK_STRING)
		strcpy(node->data, data);
#else
		node->data = data;
#endif
		node->next = NULL;
		*head = node;
	}
	else {
		while (curr != NULL){
#if !defined(__STACK_STRING)
			if (curr->data <= data) {
#else
			if (strcmp(curr->data, data) <= 0) {
#endif
#if defined(__STACK_STRING)
				strcpy(node->data, data);
#else
				node->data = data;
#endif
				node->next = curr->next;
				curr->next = node;
				break;
			}
			else {
#if defined(__STACK_STRING)
				strcpy(node->data, data);
#else
				node->data = data;
#endif
				node->next = curr;
				if (prev != *head) prev->next = node;
				else *head = node;
				break;
			}

			prev = curr;
			curr = curr->next;
		}
	}


	return EXIT_SUCCESS;
}

int find(const NodePtr *head, DATA key) {
	unsigned int bool = EXIT_FAILURE;
	NodePtr curr = *head;

	while (curr != NULL){
#if !defined(__STACK_STRING)
		if (curr->data == key) {
#else
		if (strcmp(curr->data, key) == 0) {
#endif
			bool = EXIT_SUCCESS;
			break;
		}
		curr = curr->next;
	}

	return bool;
}

void showList(const NodePtr *head) {
	NodePtr curr = *head;

	if (isempty(head)) printf("%s\n", "[]");
	else {
		printf("[ ");
		while (curr != NULL) {

#if defined(__STACK_CHAR)
			printf("%c ", curr->data);
#elif defined(__STACK_STRING)
			printf("%s ", curr->data);
#elif defined(__STACK_FLOAT)
			printf("%f ", curr->data);
#elif defined(__STACK_DOUBLE)
			printf("%g ", curr->data);
#else
			printf("%ld ", curr->data);
#endif
			curr = curr->next;
		}
		printf("]\n");
	}
}

void linked_list_destroy(NodePtr *head) {
	for (NodePtr tmp = *head; tmp != NULL;){
		NodePtr next_tmp = tmp->next;
		free(tmp);
		tmp = next_tmp;
	}
}
