#include "custom_heap.h"
#include <stdio.h>

int
main(void)
{
  BinaryTree tree;
  tree.arr[0].priority = 6;
  tree.arr[1].priority = 4;
  tree.arr[2].priority = 1;
  tree.n = 3;
  print_tree(&tree);

  Node new = { NULL, 3 };
  // add_node(&tree, new);
  iter_add_node(&tree, new);

  print_tree(&tree);

  // Node ret_node = pop_top(&tree);
  Node ret_node = iter_pop_top(&tree);

  print_tree(&tree);

  printf("ret_node.prio: %d\n", ret_node.priority);

  return 0;
}
