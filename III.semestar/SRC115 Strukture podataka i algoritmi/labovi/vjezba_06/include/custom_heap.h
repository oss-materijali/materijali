#ifndef CUSTOM_HEAP
#define CUSTOM_HEAP

#define P(k) (((k) - 1) / 2)
#define L(k) (2 * (k) + 1)
#define R(k) (2 * (k) + 2)

#define N 10000

typedef struct
{
  void* data;
  int priority;
} Node;

typedef struct
{
  Node arr[N];
  int n;
} BinaryTree;

void
swap(Node* a, Node* b);

void
print_tree(BinaryTree* tree);

int
fix_bot_to_top(BinaryTree* tree, int k);

void
iter_fix_bot_to_top(BinaryTree* tree);

int
fix_top_to_bot(BinaryTree* tree, int k);

void
iter_fix_top_to_bot(BinaryTree* tree);

void
add_node(BinaryTree* tree, Node node);

void
iter_add_node(BinaryTree* tree, Node node);

Node
pop_top(BinaryTree* tree);

Node
iter_pop_top(BinaryTree* tree);

#endif
