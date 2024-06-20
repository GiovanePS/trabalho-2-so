#pragma once

#define MAX_LOGICAL_MEMORY_SIZE 128 // MAX PROCESS LENGTH
#define FRAMEPAGE_SIZE 4            // FRAME SIZE

typedef struct {
  short int is_free;
  int pointed_frame;
} Page_table_t;

typedef struct {
  int pid;
  int size;
  Page_table_t *page_table;
  char *logical_memory;
} Process_t;

/*
 * @param pid The arbitrary process id for the new process
 * @param size The size in bytes of the process
 * @return The process created
 */
Process_t *create_process(int pid, int size);
