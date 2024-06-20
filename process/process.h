#pragma once

#define MAX_LOGICAL_MEMORY_SIZE 32 // MAX PROCESS SIZE
#define PAGE_SIZE 2

typedef struct {
  int page_position;
  int frame_position;
} Page_table_entry_t;

typedef struct {
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
void create_process(int pid, int size);

/*
 * @param process  The process that memory will be initialized randomly
 */
void init_logical_memory(Process_t *process);

void init_table_page(Process_t *process);

void show_table_page(int pid);

void include_process(Process_t *process);
