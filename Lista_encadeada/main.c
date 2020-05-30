#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

int main() {
  
  list *l = createList();
  printList(l);
  if(isEmpty(l)) printf("%d: lista vazia\n", isEmpty(l));
  removeBack(l);
  add(l, 10);
  removeBack(l);
  printList(l);
  if(!isEmpty(l)) printf("%d: lista preenchida\n", isEmpty(l));
  add(l, 20);
  add(l, 30);
  add(l, 40);
  printList(l);
  printf("Quantidade de elementos = %d\n", size(l));
  removeBack(l);
  printList(l);
  
  printf("\n\n");

  list *l1 = createList();
  printf("Resultado da inserção numa lista vazia = %d\n", insertPosition(l1, 10, 0));
  add(l1, 5);
  add(l1, 15);
  insertPosition(l1, 10, 0);
  printList(l1);
  insertPosition(l1, 85, 2);
  printList(l1);

  printf("\n\n");

  list *l2 = createList();
  add(l2, 5);
  add(l2, 10);
  add(l2, 60);
  add(l2, 40);
  add(l2, 140);
  add(l2, 2000);
  add(l2, 30);
  printf("Lista completa\n");
  printList(l2);
  removePosition(l2, 0);
  printf("Removendo o elemento na posição 0\n");
  printList(l2);
  removePosition(l2, 1);
  printf("Removendo o elemento na posição 1\n");
  printList(l2);
  printf("Retirando o elemento 10, resultado = %d\n", removeElement(l2, 10));
  printList(l2);
  printf("Retirando o elemento 2000, resultado = %d\n",removeElement(l2, 2000));
  printList(l2);
  printf("Retirando o elemento 30, resultado = %d\n",removeElement(l2, 30));
  printList(l2);
  printf("Retirando o elemento 150(inexistente), resultado = %d\n", removeElement(l2, 150));
  printf("\n\n");

  add(l2, 50);
  add(l2, 60);
  add(l2, 70);
  add(l2, 80);
  removeElement(l2, 140);
  int searched;
  get(l2, 4, &searched);
  printList(l2);
  printf("Atribuindo o valor da posição 4 a variável searched, searched = %d\n", searched);
  printf("Atribuindo o valor de uma posição inexistente a variável searched, resultado = %d\n", get(l2, 6, &searched));
  return 0;
}
