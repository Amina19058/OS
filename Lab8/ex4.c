#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main(void) {
  struct rusage usage;
    void *arr[10];
  for (int i = 0; i < 10; i++) {
    arr[i]  = malloc(10*1024*1024);
    memset(arr[i],0,10*1024*1024);
    getrusage(RUSAGE_SELF, &usage);
    printf("%ld\n", usage.ru_maxrss);
    sleep(1);
  }
  for (int i=0;i < 10; i++)
      free(arr[i]);
  return 0;
}
