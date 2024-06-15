#define PHYSICAL_MEMORY_SIZE 1024
#define FRAMEPAGE_SIZE 16

extern char* physical_memory;

void init_physical_memory();
void memory_allocate();

void init_logical_memory(int size);