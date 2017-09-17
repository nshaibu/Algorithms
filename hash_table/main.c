/*
 * main.c
 *
 *  Created on: Aug 12, 2017
 *      Author: nafiu
 */

#include <stdio.h>
#include "./include/hash.h"
#include "./include/linked_list.h"

int main(void){

	int buff[] = { 410, 1, 2, 45, -1, 78, 12, 74, 45, 84, 85, 78, 12, 23, 89, 15, 14, 17, 78, 18, 20, 56, 1, 45, 47,  45, 74, 12, 74, 54, 12, 74, 42, 89, 100, 200, 150, 42, 254, 23, 32, 321, 41, 52, 45, 85, 74, 78, 56, 85, 96, 25, 852, 456, 159, 86, 753, 15, 45, 85, 95, 7, 85, 9, 52, 25, 45, 78, 98, 78, 25, 20, 54, 63, 86, 110, 125, 85, 78, -1};

	hashPtr table = initHash(20);
	int i = 0;
	while (buff[i] != -1) {
		insertInHash(table, folding_algorithm , buff[i]);
		i++;
	}
	printf("%d\n", isElementInHash(table, folding_algorithm, 45));
	showASCIIHash(table);
	showHashStats(table);

	destroyHash(table);

	NodePtr head;
	initList(&head);

	insertNode(&head, 20);
	insertNode(&head, 45);
	insertNode(&head, 4);
	insertNode(&head, 145);
	insertNode(&head, 42);
	showList(&head);

	linked_list_destroy(&head);
	return 0;
}
