#include "../memory/memory.h"
#include "../process/process.h"
#include "../utils/utils.h"
#include <stdbool.h>
#include <stdio.h>

#include "system.h"

void init_system() {
  int invalid_values = true;
  while (invalid_values) {
    printf("Define a physical memory size: ");
    scanf("%d", &PHYSICAL_MEMORY_SIZE);
    printf("Define a max logical memory size: ");
    scanf("%d", &MAX_LOGICAL_MEMORY_SIZE);
    printf("Define a frame/page size: ");
    scanf("%d", &FRAME_SIZE);
    PAGE_SIZE = FRAME_SIZE;

    if (!is_power_of_two(PHYSICAL_MEMORY_SIZE) ||
        !is_power_of_two(MAX_LOGICAL_MEMORY_SIZE) ||
        !is_power_of_two(FRAME_SIZE)) {
      printf("The values must be power of two.\n");
      continue;
    }

    if (PHYSICAL_MEMORY_SIZE % 2 != 0 || MAX_LOGICAL_MEMORY_SIZE % 2 != 0 ||
        FRAME_SIZE % 2 != 0) {
      continue;
    }

    if (FRAME_SIZE > PHYSICAL_MEMORY_SIZE) {
      printf("Frame/Page size can't have a size larger than physical memory "
             "size\n");
      continue;
    }
    if (FRAME_SIZE > MAX_LOGICAL_MEMORY_SIZE) {
      printf("Frame/Page size can't have a size larger than max logical memory "
             "size\n");
      continue;
    }

    invalid_values = false;
  }

  init_physical_memory();

  while (1) {
    printf("\n[1] Show memory.\n");
    printf("[2] Create process.\n");
    printf("[3] Show page table.\n");
    printf("[0] Exit.\n");

    int option;
    printf("Option: ");
    scanf("%d", &option);

    int pid;
    int process_size;
    switch (option) {
    case 1: // Show memory
      printf("Free frames: %.2f%%\n", (double)free_frames / total_frames * 100);
      show_memory();
      break;
    case 2: // Create process
      printf("Enter a PID number: ");
      scanf("%d", &pid);
      printf("Enter a size to the process: ");
      scanf("%d", &process_size);

      if (!is_power_of_two(process_size)) {
        printf("The process size must be a power of two.\n");
        break;
      }

      if (process_size > MAX_LOGICAL_MEMORY_SIZE) {
        printf(
            "The process size entered exceed memory limit! Enter a size lower "
            "than %d bytes.\n",
            MAX_LOGICAL_MEMORY_SIZE);
        break;
      }

      if (process_size < FRAME_SIZE) {
        printf("The process size can't be lower than Frame/Page size.\n");
        break;
      }

      if (free_frames < process_size / FRAME_SIZE) {
        printf("There is not enough memory to allocate a process with that "
               "size.\n");
        break;
      }

      int process_created = create_process(pid, process_size);
      if (process_created) {
        printf("Process created!\n");
      }
      break;
    case 3: // Show page table
      printf("Enter a PID: ");
      scanf("%d", &pid);
      show_table_page(pid);
      break;
    case 0:
      return;
    default:
      printf("Invalid choice!\n");
      break;
    }
  }
}
