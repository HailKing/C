#include <stdio.h>
#include "duplamenteencadeada.h"

int main(){
  list *l1 = create_liked_list();
  add_ending(l1, 20);
  print_linked_list(l1);
  add_beginning(l1, 10);
  print_linked_list(l1);
  add_ending(l1, 30);
  add_ending(l1, 40);
  print_linked_list(l1);
  printf("Posição do valor 10 = %d\n", search_value(l1, 10));
  printf("Posição do valor 15(inexistente) = %d\n", search_value(l1, 15));

  printf("\n\n");
  print_linked_list(l1);
  printf("%d\n", remove_value(l1, 20));
  printf("%d\n", remove_value(l1, 40));
  print_linked_list(l1);
  

  printf("\n\n");
  list *l2 = create_liked_list();
  list *l3 = create_liked_list();
  add_beginning(l3, 10);
  becomeCircular(l3);
  print_linked_list(l2);
  add_beginning(l2, 40);
  add_ending(l2, 60);
  add_ending(l2, 80);
  print_linked_list(l2);
  becomeCircular(l2);
  printf("Provando-se que a lista está circular, ao tentar acessar o valor do pŕoximo elemento a partir do último, resultado = %d\n", l2 -> end -> next -> data);
  printCircular(l2);
  insertCircular(l2, 100);
  printCircular(l2);
  printf("%d\n", l2 -> end -> next -> data);
  insertCircular(l3, 20);
  insertCircular(l3, 30);
  insertCircular(l3, 40);
  printCircular(l3);
  removeElementCircular(l3, 20);
  printCircular(l3);

  return 0;
}
