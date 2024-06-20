#pragma once

#define MAX_PROCESS_MEMORY_SIZE 128 // MAX PROCESS LENGTH
#define FRAMEPAGE_SIZE 4 // FRAME SIZE

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

int pid_count = 0;

Process_t *create_process();
