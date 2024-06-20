#pragma once

#define MAX_LOGICAL_MEMORY_SIZE 128 // MAX PROCESS LENGTH
#define FRAMEPAGE_SIZE 4            // FRAME SIZE

typedef struct {
  int page_position;
  int frame_position;
} Page_table_entry_t;

typedef struct {
  int pid;
  int size;
  char *logical_memory;
  Page_table_entry_t *page_table;
} Process_t;

/*
 * @param pid   The arbitrary process id for the new process
 * @param size  The size in bytes of the process
 * @return The  process created
 */
Process_t *create_process(int pid, int size);

/*
 * @param process  The process that memory will be initialized randomly
 */
void init_logical_memory(Process_t *process);
