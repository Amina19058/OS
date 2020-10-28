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
  int bfd = open("ex1.txt", O_RDWR);
  struct stat st;
  stat("ex1.txt", &st);
  int size = st.st_size;
  void* file_memory;
  file_memory = mmap (0, size, PROT_WRITE, MAP_SHARED, bfd, 0);
		close (bfd);
  sprintf((char*) file_memory, "%s\n", "This is a nice day");
  return 0;
}
