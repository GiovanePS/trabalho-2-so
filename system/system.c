#include <stdbool.h>
#include <stdio.h>

#include "system.h"

void init_system() {
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

    switch (option) {
    case 1:
      printf("Memória sendo vizualizada.\n");
      break;
    case 2:
      int pid, size;
      printf("Enter a PID number: ");
      scanf("%d", &pid);
      while (1) {
        printf("Enter a size to the process: ");
        scanf("%d", &size);
        if (size > MAX_LOGICAL_MEMORY_SIZE) {
          printf("The size entered exceed memory limit! Enter a size lower "
                 "than %d bytes.\n",
                 MAX_LOGICAL_MEMORY_SIZE);
        } else {
          create_process(pid, size);
          printf("Process created!\n");
          printf("Least memory allocated: %d\n", least_free_frame);
          break;
        }
      }
      break;
    case 3:
      printf("Tabela sendo vizualizada.\n");
      break;
    case 0:
      return;
    default:
      printf("Invalid choice!\n");
      break;
    }
  }
}
