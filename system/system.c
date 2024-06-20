#include <stdbool.h>
#include <stdio.h>

#include "system.h"

void init_system() {
  while (1) {
    printf("[1] Visualizar memória.\n");
    printf("[2] Criar processo.\n");
    printf("[3] Visualizar tabela de páginas.\n");
    printf("[0] Sair.\n");

    // init_physical_memory();
    print_interface();
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
                 "than %d.\n",
                 MAX_LOGICAL_MEMORY_SIZE);
        } else {
          printf("Processo criado!");
          break;
        }
      }
      break;
    case 3:
      printf("Tabela sendo vizualizada.\n");
    case 0:
      return;
    default:
      break;
    }
  }
}

void print_interface() {}
