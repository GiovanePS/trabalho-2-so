#include <stdio.h>
#include <malloc.h>
#include "memory.h"

char* physical_memory = NULL;

void init_physical_memory() {
  physical_memory = malloc(LENGHT_PHYSICAL_MEMORY);
}

void memory_allocate() {

}

void init_logical_memory() {

}
