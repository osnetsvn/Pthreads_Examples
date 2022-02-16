#include <stdio.h>       /* standard I/O routines                 */
#include <pthread.h>     /* pthread functions and data structures */

/* function to be executed by the new thread */
void* PrintHello(void* data)
{
    int my_data = (int)data;     	/* data received by thread */

<<<<<<< HEAD

=======
>>>>>>> 3a9f1610dd813327dce85191d555b0cec0d122eb
    printf("Hello from new thread - got %d\n", my_data);
    pthread_exit(NULL);			/* terminate the thread */
}

/* like any C program, program's execution begins in main */
int main(int argc, char* argv[])
{
    int        rc;         	/* return value                           */
    pthread_t  thread_id;     	/* thread's ID (just an integer)          */
    int        t = 1;  /* data passed to the new thread          */

    /* create a new thread that will execute 'PrintHello' */

    rc = pthread_create(&thread_id, NULL, PrintHello, (void*)t);  
    if(rc)			/* could not create thread */
    {
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }

    printf("\n Created new thread (%u) ... \n", thread_id);
    
    pthread_exit(NULL);		/* terminate the thread */
}


