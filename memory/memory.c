#include "memory.h"
#include <malloc.h>

char *physical_memory;
int num_free_frames;

void init_physical_memory() {
  int total_frames = PHYSICAL_MEMORY_SIZE / FRAMEPAGE_SIZE;
  physical_memory = (char *)malloc(total_frames * sizeof(char));
  num_free_frames = total_frames;
}

void free_memory() { free(physical_memory); }
