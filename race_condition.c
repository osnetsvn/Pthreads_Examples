#define _GNU_SOURCE
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>


void *counter_increment (void *arg);



int thread_count;
long *thread_index;
long counter = 0;




int main (int argc, char **argv)
{
	char *str_thread_count;
	int r, trunc; 
	pthread_t *tid;


	thread_count = atoi(argv[1]);



	thread_index = (long *) malloc(sizeof(long)*thread_count);
	tid = (pthread_t*) malloc(sizeof(pthread_t)*thread_count);


	if(tid == NULL)
		perror ("Cannot allocate memory for threads\n");

	
       
	for (int i = 0; i < thread_count; i++) {
		thread_index[i] = i;
	
		if ((r = pthread_create (&tid [i], NULL, counter_increment, (void*)&thread_index[i])) != 0) {

			perror("Cannot create multiple threads\n");
		}
		
	}


	// Wait for threads to terminate
	for (int i = 0; i < thread_count; i++) {
		if ((r = pthread_join (tid [i], NULL)) != 0) {

			perror("Cannot join multiple threads\n");
		}
	}

	
       
	printf("Counter Sum: %ld\n", counter);
         

	
	exit (0);
}


void *counter_increment(void *args){

	int id = *(int *)args;
	
	//Unprotected Shared Global variable causes race condition
	counter ++;

	return NULL;
	
}

