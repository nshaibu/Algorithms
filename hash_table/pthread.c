/*
 ============================================================================
 Name        : pthread.c
 Author      : nafiu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#define _POSIX_THREAD_ATTR_STACKSIZE

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

extern int errno;

void *threadfunc(void *args){
		pthread_attr_t *attr_=(pthread_attr_t *)args;
		int detstate;
		size_t stsize;
		struct sched_param sched;

		pthread_attr_getdetachstate(attr_, &detstate);
		pthread_attr_getstacksize(attr_, &stsize);
		pthread_attr_getschedparam(attr_, &sched);
		printf("Hello world thread %d--%d--%d \n", detstate, (int)stsize, sched.sched_priority);
		pthread_exit(NULL);
}

int main(void) {

	pthread_t tid;
	pthread_attr_t attr;
	struct sched_param sched_var;
	sched_var.sched_priority=4;


	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
	pthread_attr_setschedpolicy(&attr, SCHED_OTHER);
	pthread_attr_setschedparam(&attr, &sched_var);
	pthread_attr_setstacksize(&attr, 20);

	if (pthread_create(&tid, &attr, threadfunc, &attr)){
		fprintf(stderr, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("Hello world main\n");

	pthread_join(tid, NULL);
	exit(0);
}
