#define PHYSICAL_MEMORY_SIZE 1024
#define FRAMEPAGE_SIZE 4

char *physical_memory;
int total_frames;

void init_physical_memory();
void memory_allocate();
