/*
Para conseguir acessar o tamanho da lista com complexidade O(1) basta colocar um atributo na struct list que vai ficar sendo atualizado de acordo com o aumento e o decremento da lista de acordo com o uso da lista e das funções.
*/

#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

int main() {
  
  list *l = createList();
  printList(l);
  printf("%d\n", size(l));
  add(l, 20);
  printList(l);
  printf("%d\n", size(l));
  add(l, 40);
  printList(l);
  printf("%d\n", size(l));
  removeBack(l);
  printList(l);
  printf("%d\n", size(l));
  removeBack(l);
  printList(l);
  printf("%d\n", size(l));
  add(l, 20);
  add(l, 60);
  add(l, 100);
  insertPosition(l, 30, 1);
  printList(l);
  printf("%d\n", size(l));
  removePosition(l, 1);
  printList(l);
  printf("%d\n", size(l));
  removeElement(l, 100);
  printList(l);
  printf("%d\n", size(l));
  return 0;
}

