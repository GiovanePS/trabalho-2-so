#include "process.h"
#include "../memory/memory.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES PHYSICAL_MEMORY_SIZE / MAX_LOGICAL_MEMORY_SIZE

Process_t *head_process = NULL;

static void include_process(Process_t *process);
static void search_process(int pid);

void create_process(int pid, int size) {
  int total_pages = size / PAGE_SIZE;
  Process_t *new_process = (Process_t *)malloc(sizeof(Process_t));
  new_process->pid = pid;
  new_process->size = size;
  new_process->next_process = NULL;
  init_logical_memory(new_process);
  init_table_page(new_process);
  include_process(new_process);
}

void init_logical_memory(Process_t *process) {
  process->logical_memory = (char *)malloc(process->size * sizeof(char));
  int n_teste = 0;
  for (int i = 0; i < process->size; i++) {
    process->logical_memory[i] = n_teste++ % 26 + 65;
    // printf("%c\n", process->logical_memory[i]);
    //  rand() % 95 + 33; // Randomly set only printable chars without space
  }
}

void init_table_page(Process_t *process) {
  int num_pages = process->size / PAGE_SIZE;
  Page_table_entry_t *new_page_table =
      (Page_table_entry_t *)malloc(num_pages * sizeof(Page_table_entry_t));

  char page_auxiliary[PAGE_SIZE];
  int frame_allocated;
  for (int i = 0; i < num_pages; i++) {
    for (int offset = 0; offset < PAGE_SIZE; offset++) {
      page_auxiliary[offset] = process->logical_memory[i + offset];
    }
    frame_allocated = allocate_frame(page_auxiliary);
    new_page_table->page_position = i;
    new_page_table->frame_position = frame_allocated;
    least_free_frame = least_free_frame + FRAME_SIZE;
  }

  process->page_table = new_page_table;
}

void show_table_page(int pid) {
  Process_t *cursor = head_process;
  while (cursor->next_process != NULL) {
    if (cursor->pid == pid) {
      break;
    }
  }

  // show table page here
}

static void include_process(Process_t *new_process) {
  if (head_process == NULL) {
    head_process = new_process;
    return;
  }

  Process_t *cursor = head_process;
  while (cursor->next_process != NULL) {
    cursor = cursor->next_process;
  }

  cursor->next_process = new_process;
}

static void search_process(int pid) {}
