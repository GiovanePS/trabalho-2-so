#include "memory.h"
#include <malloc.h>

char *physical_memory;
int total_frames;

void init_physical_memory() {
  total_frames = PHYSICAL_MEMORY_SIZE / FRAMEPAGE_SIZE;
  physical_memory = (char *)malloc(total_frames * sizeof(char));
}
