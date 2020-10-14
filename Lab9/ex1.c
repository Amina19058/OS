#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  int page_num;
  uint8_t age;
} page_entry;
page_entry *pages = NULL;
int cache_size = 0;
int pages_read = 0;
int pages_alloced = 0;

int page_index(size_t page)
{
    for (int i=0;i<pages_read;i++)
      if (pages[i].page_num == page)
        return i;
    if (pages_read >= pages_alloced) 
      pages = (page_entry *)realloc(pages, (pages_alloced*=2)*sizeof(page_entry));
    pages[pages_read].page_num = page;
    pages[pages_read].age = 0;
    return pages_read++;
}

void update_ages(void)
{
  for (int i=0;i<pages_read && i<cache_size;i++)
    pages[i].age >>= 1;
  for (int i=cache_size;i < pages_read;i++)
    pages[i].age=0x80|(pages[i].age>>1); 
  /* 8 0 */
  /* 1000 0000 в 2*/
  /* age = 11101010 */
  /* age>>1 = 01110101 */
  /* 0x80|(age>>1)=11110101*/
}

int page_request(size_t page)
{
  int ret = 1;
  int idx = page_index(page);
  if (idx >= cache_size) {
    int idx_min = 0;
    for (int i=1;i<cache_size;i++)
      if (pages[i].age < pages[idx_min].age)
        idx_min = i;
    page_entry p = pages[idx_min];
    pages[idx_min] = pages[idx];
    pages[idx] = p;
    ret = 0;
  }
  update_ages();
  return ret;
}

int main(void) {
  
  int page, hits = 0,misses = 0;
  scanf("%d", &cache_size);
  pages_alloced = cache_size;
  pages = (page_entry *)malloc(pages_alloced*sizeof(page_entry));
  pages_read = 0;
  FILE *myfile = fopen("input.txt", "r");
  while (fscanf(myfile,"%d",&page) == 1) {
    if (page_request(page))
      hits++;
    else
      misses++;
  }
  printf("Hit:%d\tMisses:%d\n", hits, misses);
  return 0;
}
