#include <pthread.h>
#include <stdio.h>

void* doit(void* a){
  printf("Thread %d\n", a);
  pthread_exit(0);
}

int main(void){
  int n = 4;
  pthread_t threads[n];
  for(int i=0; i<n; i++){
    pthread_create(&threads[i], NULL, doit, (void *)i);
    pthread_join(threads[i], NULL);
    sleep(1);
  }  
  return(0);
}