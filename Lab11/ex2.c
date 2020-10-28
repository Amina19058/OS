#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>

int main(void) {
   FILE *ptrFile = fopen("file.txt", "w");
  setvbuf( ptrFile, NULL, _IOLBF, 1024 );
  printf("H");
  sleep(1);
  printf("e");
  sleep(1);
  printf("l");
  sleep(1);
  printf("l");
  sleep(1);
  printf("o");
  fflush(stdout);
  return 0;
}
