#pragma once

#define PHYSICAL_MEMORY_SIZE 256
#define FRAME_SIZE 2

extern char *physical_memory;
extern int least_free_frame;

void init_physical_memory();

void allocate_frame(char page[FRAME_SIZE]);

/*
 * Free all memory allocated by memory.c
 */
void free_memory();
