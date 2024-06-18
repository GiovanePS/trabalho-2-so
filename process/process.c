#include <stdlib.h>
#include "process.h"

#define MAX_PROCESS_MEMORY_SIZE 128 // MAX PROCESS LENGTH

Process_t* create_process() {
  int size = rand() % MAX_PROCESS_MEMORY_SIZE + 1; // RANDOM PROCESS SIZE
  Process_t new_process = {pid_count++, size};
  init_logical_memory(size);

  return &new_process;
}
