#include "custom_heap.h"
#include <stdio.h>

void
swap(Node* a, Node* b)
{
  Node tmp = *a;
  *a = *b;
  *b = tmp;
}

void
print_tree(BinaryTree* tree)
{
  for (int i = 0; i < tree->n; i++)
    printf("%d, ", tree->arr[i].priority);
  printf("\n");
}

int
fix_bot_to_top(BinaryTree* tree, int k)
{
  if (k == 0)
    return 0;

  if (tree->arr[k].priority > tree->arr[P(k)].priority) {
    swap(&tree->arr[k], &tree->arr[P(k)]);
    return fix_bot_to_top(tree, P(k));
  }

  return 0;
}

void
iter_fix_bot_to_top(BinaryTree* tree)
{
  int k = tree->n - 1;
  while (k != 0 && tree->arr[k].priority > tree->arr[P(k)].priority) {
    swap(&tree->arr[k], &tree->arr[P(k)]);
    k = P(k);
  }
}

int
fix_top_to_bot(BinaryTree* tree, int k)
{
  if (k >= tree->n)
    return 0;

  if (tree->arr[k].priority < tree->arr[L(k)].priority) {
    swap(&tree->arr[k], &tree->arr[L(k)]);
    return fix_top_to_bot(tree, L(k));
  } else if (tree->arr[k].priority < tree->arr[R(k)].priority) {
    swap(&tree->arr[k], &tree->arr[R(k)]);
    return fix_top_to_bot(tree, R(k));
  }

  return 0;
}

void
iter_fix_top_to_bot(BinaryTree* tree)
{
  int k = 0;
  while (k < tree->n) {
    if (tree->arr[k].priority < tree->arr[L(k)].priority) {
      swap(&tree->arr[k], &tree->arr[L(k)]);
      k = L(k);
    } else if (tree->arr[k].priority < tree->arr[R(k)].priority) {
      swap(&tree->arr[k], &tree->arr[R(k)]);
      k = R(k);
    }
  }
}

void
add_node(BinaryTree* tree, Node node)
{
  tree->arr[tree->n].priority = node.priority;
  tree->n++;
  fix_bot_to_top(tree, tree->n - 1);
}

void
iter_add_node(BinaryTree* tree, Node node)
{
  tree->arr[tree->n].priority = node.priority;
  tree->n++;
  iter_fix_bot_to_top(tree);
}

Node
pop_top(BinaryTree* tree)
{
  swap(&tree->arr[0], &tree->arr[tree->n]);
  tree->n--;
  fix_top_to_bot(tree, 0);
  return tree->arr[tree->n + 1];
}

Node
iter_pop_top(BinaryTree* tree)
{
  swap(&tree->arr[0], &tree->arr[tree->n]);
  tree->n--;
  iter_fix_top_to_bot(tree);
  return tree->arr[tree->n + 1];
}
