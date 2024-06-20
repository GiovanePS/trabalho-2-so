#pragma once

#define PHYSICAL_MEMORY_SIZE 1024
#define FRAMEPAGE_SIZE 4

void init_physical_memory();

/*
 * Free all memory allocated by memory.c
 */
void free_memory();
