#include "process.h"
#include <stdlib.h>

Process_t *create_process() {
  int size = rand() % MAX_PROCESS_MEMORY_SIZE + 1; // RANDOM PROCESS SIZE
  int total_pages = size / FRAMEPAGE_SIZE;
  Process_t *new_process = (Process_t *)malloc(sizeof(Process_t));
  
  new_process->pid = pid_count;
  new_process->size = size;
  new_process->logical_memory = (char *)malloc(size * sizeof(char));
  new_process->page_table = (Page_table_t *)malloc(sizeof(Page_table_t));

  return new_process;
}
