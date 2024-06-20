#include "memory/memory.h"
#include "system/system.h"
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time((NULL)));

  init_system();
  free_memory();

  return 0;
}
