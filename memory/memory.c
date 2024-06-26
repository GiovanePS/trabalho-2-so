#include "memory.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int PHYSICAL_MEMORY_SIZE;
int FRAME_SIZE;

char *physical_memory = NULL;
Node *head_free_frames = NULL;
int last_free_frame = 0;
int total_frames;
int free_frames;

static Node *get_some_frame_to_allocate();

void init_physical_memory() {
  head_free_frames = (Node *)malloc(sizeof(Node));
  head_free_frames->id_serial = 0;
  total_frames = PHYSICAL_MEMORY_SIZE / FRAME_SIZE;
  free_frames = total_frames;
  physical_memory = (char *)malloc(PHYSICAL_MEMORY_SIZE * sizeof(char));

  Node *cursor = head_free_frames;
  for (int i = 1; i < total_frames; i++) {
    Node *next_node = (Node *)malloc(sizeof(Node));
    next_node->id_serial = i;
    cursor->next = next_node;
    cursor = cursor->next;
  }
}

int allocate_frame(char page[FRAME_SIZE]) {
  Node *anterior = get_some_frame_to_allocate();
  Node *cursor = anterior->next;
  int frame_start = cursor->id_serial;

  frame_start = frame_start * FRAME_SIZE;
  for (int offset = 0; offset < FRAME_SIZE; offset++) {
    physical_memory[frame_start + offset] = page[offset];
  }

  free_frames--;
  int frame_allocated = cursor->id_serial;
  if (cursor->next != NULL) {
    anterior->next = cursor->next;
    free(cursor);
  } else {
    anterior->next = NULL;
    free(cursor);
  }

  return frame_allocated;
}

static Node *get_some_frame_to_allocate() {
  int frame;
  if ((float)free_frames / total_frames >= 0.5) {

    Node *cursor;
    Node *anterior;
    while (1) {
      frame = rand() % free_frames;
      cursor = head_free_frames;
      while (1) {
        if (cursor->next->id_serial == frame) {
          return cursor;
        }

        if (frame < cursor->id_serial) {
          break;
        }
        anterior = cursor;
        cursor = cursor->next;
        if (cursor->next == NULL) {
          break;
        }
      }
    }
  } else {
  }
}

void show_memory() {
  printf("Position <=> Value\n");
  char frame_auxiliary[FRAME_SIZE + 1];
  for (int i = 0; i < PHYSICAL_MEMORY_SIZE / FRAME_SIZE; i++) {
    for (int offset = 0; offset < FRAME_SIZE; offset++) {
      frame_auxiliary[offset] = physical_memory[i * FRAME_SIZE + offset];
    }
    frame_auxiliary[FRAME_SIZE] = '\0';

    // Print single frame
    printf("%d <=> %s\n", i, frame_auxiliary);
  }
}
