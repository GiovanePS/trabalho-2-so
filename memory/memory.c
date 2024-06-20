#include "memory.h"
#include <malloc.h>

char *physical_memory;
int least_free_frame = 0;

void init_physical_memory() {
  physical_memory = (char *)malloc(PHYSICAL_MEMORY_SIZE * sizeof(char));
}

void allocate_frame(char page[FRAME_SIZE]) {
  for (int offset = 0; offset < FRAME_SIZE; offset++) {
    physical_memory[least_free_frame + offset] = page[offset];
  }
}

void free_memory() { free(physical_memory); }
