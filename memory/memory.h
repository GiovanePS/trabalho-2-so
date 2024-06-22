#pragma once

extern int PHYSICAL_MEMORY_SIZE;
extern int FRAME_SIZE;

extern char *physical_memory;
extern int last_free_frame;
extern int total_frames;
extern int free_frames;

/*
 * Allocates all memory necessary for program.
 */
void init_physical_memory();

/*
 * Allocates one frame from logical memory to physical memory
 *
 * @param page  An array with FRAME_SIZE length
 * @return      An integer that indicates a frame allocated
 */
int allocate_frame(char page[FRAME_SIZE]);

/*
 * Show all memory physcal memory allocated
 */
void show_memory();
