/*
 ============================================================================
 Name        : pthread.c
 Author      : nafiu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <semaphore.h>

struct thread_funcs {
	void *(*th)(void*);
};

struct pid_fstream {
	pid_t pid;
	FILE *fstream_for_w;
	FILE *filestream_for_r;
	char buff[13];
};


const char *ch_write="Nafiu Shaibu";
int size_ch=13;

#define SIZE_OF_FILE size_ch * 1 * 2

char *filename="/home/nafiu/Desktop/bigfile.txt";

sem_t sem_b;
sem_t sem_e;

pthread_mutex_t mu;
pthread_mutex_t rmu;


void *write_th1_b(void *sig){
	struct pid_fstream *data=(struct pid_fstream *)sig;
	pid_t pid=(pid_t)data->pid;
	FILE *file=(FILE*)data->fstream_for_w;

	int j=0;

	for (int i=0; i<(SIZE_OF_FILE/(2*size_ch)); i++){
		pthread_mutex_lock(&mu);
		fseek(file, j, SEEK_SET);
		fputs(ch_write, file);
		pthread_mutex_unlock(&mu);

		printf("[Process:%d|Thread:1|Thread: %d|File:begin_w]\n", pid, i);
		j+=size_ch;
		sem_post(&sem_b);
	}


	pthread_exit(0);
}

void *write_th2_e(void *sig){
	struct pid_fstream *data=(struct pid_fstream *)sig;
	pid_t pid=(pid_t)data->pid;
	FILE *file=(FILE*)data->fstream_for_w;

	fseek(file, SIZE_OF_FILE-size_ch, SEEK_CUR);

	for (int i=0,j=1; i<((SIZE_OF_FILE)/(2*size_ch)); i++){
		pthread_mutex_lock(&mu);
		fputs("zhaidu nuruu", file);
		fseek(file, (size_ch * j++), SEEK_END);
		pthread_mutex_unlock(&mu);

		fprintf(stdout, "[Process:%d|Thread:2|Thread: %d|File:end_w]\n", pid, i);

		sem_post(&sem_e);
	}

	pthread_exit(0);
}

void *read_th1_b(void *sig){
	struct pid_fstream *data=(struct pid_fstream *)sig;
	pid_t pid=(pid_t)data->pid;
	FILE *file=(FILE*)data->filestream_for_r;

	char *buff=(char*)data->buff;
	int j=0;

	for (int i=0; i<((SIZE_OF_FILE)/(2*size_ch)); i++) {
		sem_wait(&sem_b);

		pthread_mutex_lock(&rmu);
		fseek(file, j, SEEK_SET);
		fgets(buff, size_ch, file);

		j+=size_ch;
		fprintf(stdout, "[Process:%d|Thread:1|Thread: %d|File:begin_r] %s\n", pid, i, buff);
		//buff=NULL;
		pthread_mutex_unlock(&rmu);
	}

	pthread_exit(0);
}

void *read_th2_e(void *sig){
	struct pid_fstream *data=(struct pid_fstream *)sig;
	FILE *file=(FILE*)data->filestream_for_r;
	pid_t pid=(pid_t)data->pid;

	char *buff=(char*)data->buff;

	//fseek(file, (SIZE_OF_FILE-size_ch), SEEK_CUR);

	for (int i=0, j=1, sizes=((SIZE_OF_FILE)/(2 * size_ch)); i<sizes; i++){
		sem_wait(&sem_e);

		pthread_mutex_lock(&rmu);
		fseek(file, sizes+(size_ch * j++), SEEK_CUR);
		fgets(buff, size_ch, file);

		fprintf(stdout, "[Process:%d|Thread:2|Thread: %d|File:end_r] %s\n", pid, i, buff);
		//buff=NULL;
		pthread_mutex_unlock(&rmu);
	}

	pthread_exit(0);
}

int main(void) {
	(void)unlink(filename);
	signal(SIGINT, SIG_DFL);

	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_mutex_init(&mu, NULL);
	pthread_mutex_init(&rmu, NULL);

	sem_init(&sem_b, 0, 2);
	sem_init(&sem_e, 0, 2);

	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	pthread_attr_setschedpolicy(&attr, SCHED_OTHER);
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

	pthread_t tid[4];
	struct thread_funcs thr[4];

	struct pid_fstream *data=malloc(sizeof(struct pid_fstream));
	if (data == NULL){
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	thr[0].th=write_th1_b;
	thr[1].th=write_th2_e;
	thr[2].th=read_th1_b;
	thr[3].th=read_th2_e;

	FILE *wfile=fopen(filename, "w+b");
	FILE *rfile=fopen(filename, "rb");
	if (!wfile && !rfile){
		perror("error1");
		exit(1);
	}

	data->pid=getpid();
	data->fstream_for_w=wfile;
	data->filestream_for_r=rfile;
	strcpy(data->buff, "\0");

	for (int i=0; i<4; i++) {
		if (pthread_create(&tid[i], NULL, thr[i].th, (void*)data)){
			fprintf(stderr, "thread failed\n");
			exit(1);
		}
	}

	printf("hello main\n");

	for (int i=0; i<4; i++) pthread_join(tid[i], NULL);

	unlink(filename);
	fclose(wfile);
	fclose(rfile);

	free(data);

	sem_destroy(&sem_b);
	sem_destroy(&sem_e);

	pthread_mutex_destroy(&mu);
	pthread_mutex_destroy(&rmu);

	return EXIT_SUCCESS;
}
