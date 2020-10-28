  
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main ()
{
int bfd = open("ex1.txt",O_RDWR);
int bfd2 = open("ex1.memcpy.txt",O_RDWR);

struct stat st = {};
fstat(bfd, &st);
off_t size = st.st_size;  

char* addr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, bfd, 0);
ftruncate(bfd2, size);
char* addr2 = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, bfd2, 0);

memcpy (addr2, addr, size);

close(bfd);
close(bfd2);
return 0;
}

