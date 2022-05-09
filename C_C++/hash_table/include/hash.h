/*
 * hash.h
 *
 *  Created on: Aug 13, 2017
 *      Author: nafiu
 */

#ifndef HASH_H_
#define HASH_H_

#include <stdio.h>
#include "./linked_list.h"

#define MAX_STRING 25

typedef struct hash_table {
	NodePtr head;
	unsigned int hash_size;
} *hashPtr, hash_t;

extern hashPtr initHash(int _height);
extern void insertInHash(hashPtr __table, int (*__algorithm)(int , DATA), DATA data);
extern int isElementInHash(hashPtr __table, int (*__algorithm)(int , DATA), DATA data);
extern void showASCIIHash(hashPtr __table);
extern void destroyHash(hashPtr __table);
extern void showHashStats(hashPtr);

//algorithms
extern int remainder_algorithm(int _heihht, DATA data);
extern int folding_algorithm(int _height, DATA data);
extern int mid_square_algorithm(int _height, DATA data);


#endif /* HASH_H_ */
