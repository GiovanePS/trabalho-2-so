#include <stdio.h>
#include <malloc.h>
#include "memory.h"

char physical_memory[PHYSICAL_MEMORY_SIZE / FRAMEPAGE_SIZE];

void init_physical_memory() {
  for (int i = 0; i < PHYSICAL_MEMORY_SIZE / FRAMEPAGE_SIZE; i++) {
    physical_memory[i]
  }
}

void memory_allocate() {

}

void init_logical_memory(int size) {

}
