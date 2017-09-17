/*
 * hash.c
 *
 *  Created on: Aug 13, 2017
 *      Author: nafiu
 */

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "./include/hash.h"

hashPtr initHash(int _height) {
	hashPtr table = (hashPtr)malloc(_height * sizeof(hash_t));
	if (table == NULL) {
		perror("mem_hash");
		exit(EXIT_FAILURE);
	}

	for (unsigned int i = 0; i < _height; i++){
		initList(&table[i].head);
		table[i].hash_size = _height;
	}

	return table;
}

void insertInHash(hashPtr __table, int (*__algorithm)(int , DATA), DATA data) {
	int index_ = (*__algorithm)(__table[0].hash_size, data);

	(void)insertNode(&__table[index_].head, data);
}


int isElementInHash(hashPtr __table, int (*__algorithm)(int , DATA), DATA data) {
	int index_ = (*__algorithm)(__table[0].hash_size, data);
	return find(&__table[index_].head, data);
}

void showASCIIHash(hashPtr __table) {
	NodePtr curr = NULL;

	for (unsigned int i = 0; i < __table[0].hash_size; i++) {
		curr = __table[i].head;
		printf("Hash[%d]:", i);

		if (curr != NULL) {
			while (curr != NULL) {
#if !defined(__STACK_STRING)
				printf("->%f", (float)curr->data);
#else
				strcat(_string, curr->data);
#endif
				curr = curr->next;
			}
			printf("\n");
		}
		else printf("->None\n");
	}
}

void destroyHash(hashPtr __table) {
	for (unsigned int i = 0; i < __table[0].hash_size; i++) {
		linked_list_destroy(&__table[i].head);
	}
	free(__table);
}

void showHashStats(hashPtr __table) {
	float load_factor;
	int _empty_cell = 0;

	for (unsigned int i = 0; i < __table[0].hash_size; i++) {
		if (__table[i].head == NULL) _empty_cell++;
	}

	load_factor = ((__table[0].hash_size -_empty_cell)/(float)__table[0].hash_size);

	printf("load_factor: %f, avg_cmps_for_successful_search %f\n", load_factor, (1 + load_factor/2.0));
}

int remainder_algorithm(int _height, DATA data) {
	unsigned int g_weight = 0;

#if !defined(__STACK_STRING)
	g_weight = (int)data;
#else
	unsigned int len = strlen(data), word_weight = 2;

	for (unsigned int i = 0; i < len; i++) {
		g_weight += word_weight * data[i];
		word_weight++;
	}
#endif

	return (int)(g_weight%_height);
}

int folding(char *buff) {
	int tmp[2] = {0}, g_weight = 0;

	for (int i=0, j=0, len=strlen(buff); i < len; i++, j++) {
		tmp[j] = (int)buff[i];
		if (buff[i+1] == '\0') j++;

		if (j == 1) {
			g_weight += tmp[0] + tmp[1]; j = 0;
			tmp[0] = 0;
			tmp[1] = 0;
		}
	}

	return g_weight;
}

int folding_algorithm(int _height, DATA data) {
	int g_weight = 0;
#if !defined(__STACK_STRING)
	char data_[15];
	sprintf(data_, "%d", (int)data);
	g_weight = folding(data_);
#else
	char buff[MAX_STRING], var[4];
	strcpy(buff, "");

	unsigned int len = strlen(data), word_weight = 2;
	for (int i = 0; i < len; i++) {
		sprintf(var, "%d", (word_weight * data[i]));
		strcat(buff, var);
		word_weight++;
	}

	g_weight = folding(buff);
#endif

	return (int)(g_weight%_height);
}

int mid_square_algorithm(int _height, DATA data) {
	long int g_weight = 0;
	char buf[20], tmp[4];


#if !defined(__STACK_STRING)
	sprintf(buf, "%ld", (long int)pow(data, 2.0));

#else
	char buff[MAX_STRING], var[4];
	strcpy(buff, "");

	unsigned int len = strlen(data), word_weight = 2;
	for (int i = 0; i < len; i++) {
		sprintf(var, "%d", (word_weight * data[i]));
		strcat(buff, var);
		word_weight++;
	}


	for (int i = 0, j=0; i < 4; i++) {
		if (buff[j] == '\0') buf[i] = '\0';
		else buf[i] = buff[j++];
	}

	buf[4] = '\0';
	long int str_i = strtol(buf, NULL, 10);
	sprintf(buf, "%ld",(long int)pow(str_i, 2.0) );
#endif
	int len_ = strlen(buf);
	if (len_ < 3) g_weight = strtol(buf, NULL, 10);
	else {
		if (len_%2 == 0) {
			int index_ = len_/2;
			for (unsigned int i = 0; i < 2; i++) tmp[i] = buf[index_++];
			tmp[2] = '\0';

			g_weight = strtol(tmp, NULL, 10);
		}
		else {
			int index_ = len_/2;
			tmp[0] = buf[index_ - 1];
			tmp[1] = buf[index_];
			tmp[2] = buf[index_ + 1];
			tmp[3] = '\0';

			g_weight = strtol(tmp, NULL, 10);
		}
	}

	return (int)(g_weight%_height);
}
