#include "process.h"
#include <stdlib.h>

int pid_count = 0;

Process_t *create_process(int pid, int size) {
  int total_pages = size / FRAMEPAGE_SIZE;
  Process_t *new_process = (Process_t *)malloc(sizeof(Process_t));

  new_process->pid = pid;
  new_process->size = size;
  new_process->logical_memory = (char *)malloc(size * sizeof(char));
  new_process->page_table = (Page_table_entry_t *)malloc(sizeof(Page_table_entry_t));

  return new_process;
}
