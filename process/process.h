#pragma once

extern int MAX_LOGICAL_MEMORY_SIZE; // MAX PROCESS SIZE
extern int PAGE_SIZE;

typedef struct PageTableEntry {
  int page_position;
  int frame_position;
} PageTableEntry;

typedef struct Process {
  int pid;
  int size;
  char *logical_memory;
  PageTableEntry *page_table;
  struct Process *next_process;
} Process;

/*
 * @param pid   The arbitrary process id for the new process
 * @param size  The size in bytes of the process
 */
int create_process(int pid, int size);

void show_table_page(int pid);
