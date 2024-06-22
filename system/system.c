#include "../memory/memory.h"
#include "../process/process.h"
#include <stdbool.h>
#include <stdio.h>

#include "system.h"

void init_system() {
  printf("Define a physical memory size: ");
  scanf("%d", &PHYSICAL_MEMORY_SIZE);
  printf("Define a max logical memory size: ");
  scanf("%d", &MAX_LOGICAL_MEMORY_SIZE);
  printf("Define a frame/page size: ");
  scanf("%d", &FRAME_SIZE);
  PAGE_SIZE = FRAME_SIZE;

  init_physical_memory();

  while (1) {
    printf("\n[1] Show memory.\n");
    printf("[2] Create process.\n");
    printf("[3] Show page table.\n");
    printf("[0] Exit.\n");

    // init_physical_memory();
    int option;
    printf("Option: ");
    scanf("%d", &option);

    int pid;
    int size;
    switch (option) {
    case 1: // Show memory
      printf("Free frames: %.2f%%\n", (double)free_frames / total_frames * 100);
      show_memory();
      break;
    case 2: // Create process
      printf("Enter a PID number: ");
      scanf("%d", &pid);
      while (1) {
        printf("Enter a size to the process: ");
        scanf("%d", &size);
        if (size > MAX_LOGICAL_MEMORY_SIZE) {
          printf("The size entered exceed memory limit! Enter a size lower "
                 "than %d bytes.\n",
                 MAX_LOGICAL_MEMORY_SIZE);
          break;
        }

        if (free_frames < size / FRAME_SIZE) {
          printf("There is not enough memory to allocate a process with that "
                 "size.\n");
          break;
        }

        int processo_criado = create_process(pid, size);
        if (processo_criado) {
          printf("Process created!\n");
        }
        break;
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
