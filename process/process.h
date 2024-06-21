#pragma once

#define MAX_LOGICAL_MEMORY_SIZE 32 // MAX PROCESS SIZE
#define PAGE_SIZE 2

typedef struct Page_table_entry_t {
  int page_position;
  int frame_position;
} Page_table_entry_t;

typedef struct Process_t {
  int pid;
  int size;
  char *logical_memory;
  Page_table_entry_t *page_table;
  struct Process_t *next_process;
} Process_t;

/*
 * @param pid   The arbitrary process id for the new process
 * @param size  The size in bytes of the process
 */
int create_process(int pid, int size);

void show_table_page(int pid);
