#include <pthread.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

static pthread_mutex_t bsem;
static pthread_cond_t waitTurn = PTHREAD_COND_INITIALIZER;
static int turn;
static int nthreads;
struct inargserver
{
    int prio
    pthread_mutex_t bsem;
    pthread_cond_t waitTurn;
    int turn;
    int nthreads;
};
void *print_in_reverse_order_odd_then_even(void *void_ptr_argv)
{
	int threadID = *((int *) void_ptr_argv);
	pthread_mutex_lock(&bsem);
	while(turn!=threadID)
		pthread_cond_wait(&waitTurn,&bsem);
	pthread_mutex_unlock(&bsem);
	std::cout << "I am Thread " << threadID << std::endl;
	pthread_mutex_lock(&bsem);
	turn = turn + 2;
	if (turn == nthreads+1)
	{
		if ((nthreads-1)%2!=0)
 			turn = 0;
		else
			turn = 1;
	}
	pthread_cond_broadcast(&waitTurn);
	pthread_mutex_unlock(&bsem);
	return NULL;
}
//g++ evenodd.cpp -pthread -o evenodd
//./evenodd
int main()
{
	std::cin >> nthreads;
	pthread_mutex_init(&bsem, NULL); // Initialize access to 1
	pthread_t *tid= new pthread_t[nthreads];
	int *threadNumber=new int[nthreads];
	
	//Determine the starting thread (thread with the highest odd number)
	if ((nthreads-1)%2!=0) //even
		turn = 1;
	else //odd
		turn = 0;
	for(int i=0;i<nthreads;i++)
	{
		threadNumber[i]=i;
		pthread_create(&tid[i],nullptr,print_in_reverse_order_odd_then_even,(void *) &threadNumber[i]);
	}
	// Wait for the other threads to finish.
	for (int i = 0; i < nthreads; i++)
		pthread_join(tid[i], NULL);
	delete [] threadNumber;
	delete [] tid;
	return 0;
}