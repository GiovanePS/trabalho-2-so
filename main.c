#include "system/system.h"
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time((NULL)));

  init_system();

  return 0;
}
