#include "process.h"
#include "../memory/memory.h"
#include <stdio.h>
#include <stdlib.h>

int MAX_LOGICAL_MEMORY_SIZE; // MAX PROCESS SIZE
int PAGE_SIZE;

Process *head_process = NULL;

static void init_logical_memory(Process *process);
static void init_table_page(Process *process);
static void include_process(Process *process);
static Process *find_process(int pid);

int create_process(int pid, int size) {
  if (find_process(pid) != NULL) {
    printf("Process with PID %d already created.\n", pid);
    return 0;
  }

  int total_pages = size / PAGE_SIZE;
  Process *new_process = (Process *)malloc(sizeof(Process));
  new_process->pid = pid;
  new_process->size = size;
  new_process->next_process = NULL;
  init_logical_memory(new_process);
  init_table_page(new_process);
  include_process(new_process);

  return 1;
}

/*
 * @param process  The process that memory will be initialized randomly
 */
static void init_logical_memory(Process *process) {
  process->logical_memory = (char *)malloc(process->size * sizeof(char));
  for (int i = 0; i < process->size; i++) {
    process->logical_memory[i] =
        rand() % 25 + 65; // Randomly set only printable chars without space
  }
}

static void init_table_page(Process *process) {
  int num_pages = process->size / PAGE_SIZE;
  PageTableEntry *new_page_table =
      (PageTableEntry *)malloc(num_pages * sizeof(PageTableEntry));

  char page_auxiliary[PAGE_SIZE];
  int frame_allocated;

  // Memory allocation
  for (int i = 0; i < num_pages; i++) {
    for (int offset = 0; offset < PAGE_SIZE; offset++) {
      page_auxiliary[offset] = process->logical_memory[i * PAGE_SIZE + offset];
    }
    frame_allocated = allocate_frame(page_auxiliary);
    PageTableEntry *entry = (PageTableEntry *)malloc(sizeof(PageTableEntry));
    entry->page_position = i;
    entry->frame_position = frame_allocated;
    new_page_table[i] = *entry;
  }

  // Table page included
  process->page_table = new_page_table;
}

void show_table_page(int pid) {
  Process *process = find_process(pid);
  if (process == NULL) {
    printf("Process with PID %d not found.\n", pid);
    return;
  }

  printf("Process size: %d\n", process->size);

  int num_pages = process->size / PAGE_SIZE;
  int page, frame;
  printf("Page <=> Frame\n");
  for (int i = 0; i < num_pages; i++) {
    page = process->page_table[i].page_position;
    frame = process->page_table[i].frame_position;
    printf("%d    <=> %d\n", page, frame);
  }
}

static void include_process(Process *new_process) {
  if (head_process == NULL) {
    head_process = new_process;
    return;
  }

  Process *cursor = head_process;
  while (cursor->next_process != NULL) {
    cursor = cursor->next_process;
  }

  cursor->next_process = new_process;
}

static Process *find_process(int pid) {
  if (head_process == NULL) {
    printf("None process created.\n");
    return NULL;
  }

  Process *cursor = head_process;
  while (cursor->next_process != NULL) {
    if (cursor->pid == pid) {
      break;
    }
    cursor = cursor->next_process;
  }

  if (cursor->next_process == NULL && cursor->pid != pid) {
    return NULL;
  }

  return cursor;
}
