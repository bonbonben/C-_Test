#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

void *PrintHello(void *threadid)
{
  long tid = (long)threadid;
  int i = 0;
  int j = 0;
  int k = 0;
  
  if (tid == 0)
  {
  	for (i = 0; i < 3; ++i)
  	{
  	  std::cout << "Hello World! Thread " << tid << std::endl;
  	  //sleep(3);
  	}
  }
  else if (tid == 1)
  {
  	for (j = 0; j < 3; ++j)
  	{
  	  printf("Hello World! Thread %d\n", tid);
  	  //sleep(3);
  	}
  }
  else if (tid == 2)
  {
  	for (k = 0; k < 3; ++k)
  	{
  	  fprintf(stdout, "Hello World! Thread %d\n", tid);
  	  //sleep(3);
  	}
  }
  return 0;
}

int main ()
{
  pthread_t threads[NUM_THREADS];
  int i;
  for( i=0; i < NUM_THREADS; i++ )
  {
    pthread_create(&threads[i], NULL, PrintHello, (void *)i);
  }
  pthread_exit(NULL);
}
