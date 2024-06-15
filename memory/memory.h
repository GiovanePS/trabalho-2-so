#define LENGHT_PHYSICAL_MEMORY 1024
#define LENGHT_LOGICAL_MEMORY 128

extern char* physical_memory;

void init_physical_memory();
void memory_allocate();
//char* get_physical_memory();

void init_logical_memory();