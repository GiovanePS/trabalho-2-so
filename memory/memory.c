#include "memory.h"
#include <malloc.h>
#include <stdio.h>

int PHYSICAL_MEMORY_SIZE;
int FRAME_SIZE;

char *physical_memory;
int last_free_frame = 0;
int total_frames;
int free_frames;

void init_physical_memory() {
  total_frames = PHYSICAL_MEMORY_SIZE / FRAME_SIZE;
  free_frames = total_frames;
  physical_memory = (char *)malloc(PHYSICAL_MEMORY_SIZE * sizeof(char));
}

int allocate_frame(char page[FRAME_SIZE]) {
  int frame_start = last_free_frame;

  for (int offset = 0; offset < FRAME_SIZE; offset++) {
    physical_memory[last_free_frame + offset] = page[offset];
  }

  last_free_frame += FRAME_SIZE;

  free_frames--;
  return frame_start / FRAME_SIZE;
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
