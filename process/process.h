#include "../memory/memory.h"

typedef struct {
  short int is_free;
  int value;
} Page_table_t;

typedef struct {
  int pid;
  int size;
  Page_table_t* page_table;
} Process_t;

int pid_count = 0;

Process_t* create_process();