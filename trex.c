#include "trex.h"
#include "io.h"
#include "stdlib.h"
#include "stdio.h"
#include "proj.h"
#include "string.h"

// Small function allocating a new node of tree with given character and
// frequency
// Init node it`s just a dummy with empty children
Treenode *createNode(char data, unsigned int frequency)
{
   Treenode *init = (Treenode *)malloc(sizeof(Treenode));
   init->data = data;
   init->freq = frequency;
   init->left = NULL;
   init->right = NULL;
   return init;
}

// Only leaves contains the characters and it`s code.
// Because of that we need to be able to determine which node is a leaf.
// Keep in mind that left (0-relation) and right (1-relation) represents a
// connection of node with other nodes. To check if the leaf is a node or not we
// need to check if it have connection with one or two other nodes.
// If not - it is a leaf.
_Bool isLeaf(Treenode *rootNode)
{
   return rootNode->left == NULL && rootNode->right == NULL;
}

// Before we actually can start to insert nodes in our tree by set of rules
// which I`ll declare in the 'trex.h' file we need to initialize the tree in
// memory. This function accepts capacity of tree.
// VERSION 0.01 NOTE: for now capacity is fixed value, but I think later it will
// be dinamically allocatable
struct Tree *initTree(unsigned int capacity)
{
    struct Tree *tempTree  = (struct Tree *)malloc(sizeof(struct Tree));
    tempTree->capacity = capacity;
    tempTree->size = INITIAL_SIZE;
    tempTree->heap = (Treenode **)calloc(capacity, sizeof(Treenode *));
    return tempTree;
}

//..
void insertNode(struct Tree *tree, Treenode *node)
{
   tree->size++;
   int ptr = tree->size - 1;

   while (ptr != 0 && node->freq < tree->heap[(ptr - 1) / 2]->freq)
   {
     *(tree->heap + ptr) = tree->heap[(ptr - 1) / 2];
     ptr = (ptr - 1) / 2;
   }     

   *(tree->heap + ptr) = node;
}

//..
void heapify(struct Tree *tree, int index)
{
  int smallest = index;
  int leftChild = 2 * index + 1;
  int rightChild = 2 * index + 2;

  if (leftChild < tree->size &&
      tree->heap[leftChild]->freq < tree->heap[smallest]->freq)
    smallest = leftChild;
  if (rightChild < tree->size &&
      tree->heap[rightChild]->freq < tree->heap[smallest]->freq)
    smallest = rightChild;
  if (smallest != index)
  {
    Treenode *temp = tree->heap[smallest];
    tree->heap[smallest] = tree->heap[index];
    tree->heap[index] = temp;
    heapify(tree, smallest);
  }    
}

// ..
Treenode *extractMinimum(struct Tree *tree)
{
  Treenode *minimum = tree->heap[0];
  #ifdef DEBUG
      if (tree == NULL) {
        printf("Tree is NULL\n");
    }
    printf("Tree size: %d, capacity: %d\n", tree->size, tree->capacity);
    for (int i = 0; i < tree->size; i++) {
        if (tree->heap[i] != NULL) {
            printf("heap[%d]: char='%c', freq=%u\n", i, tree->heap[i]->data, tree->heap[i]->freq);
        } else {
            printf("heap[%d]: NULL\n", i);
        }
    }
  #endif
  tree->heap[0] = tree->heap[tree->size - 1];
  tree->size--;
  heapify(tree, 0);
  return minimum;
}

// ..
struct Tree *buildHeap(char *data, int *frequencys, int initialSize)
{
  struct Tree *tree = initTree(initialSize);
  int realSize = 0;

  for (int i = 0; i < initialSize; ++i)
  {
      if (frequencys[i] != 0) {
          *(tree->heap + realSize) = createNode(*(data + i), *(frequencys + i));
          ++realSize;
      }
  }

  tree->size = realSize;
  for (int i = (tree->size - 2) / 2; i >= 0; --i)
    heapify(tree, i);

  return tree;
}

// ..
Treenode *buildTree(char *data, int *frequencys, int initialSize)
{
  Treenode *left, *right, *top;
  struct Tree *tree = buildHeap(data, frequencys, initialSize);

  while (tree->size != 1)
  {
    left = extractMinimum(tree);
    right = extractMinimum(tree);
    top = createNode('\x00', left->freq + right->freq);
    top->left = left;
    top->right = right;
    insertNode(tree, top);
  }

  return extractMinimum(tree);
}

// ..
void code(char *data, int *frequencys, int initialSize)
{
  Treenode *root = buildTree(data, frequencys, initialSize);
  #ifdef DEBUG
  int array[getHeight(root)];
  int top = 0;
  printCodes(root, array, top);
  #endif
}

// ..
void printCodes(Treenode *root, int *array, int top)
{
  if (root->left != NULL)
  {
    array[top] = 0;
    printCodes(root->left, array, top + 1);
  }
  if (root->right != NULL)
  {
    array[top] = 1;
    printCodes(root->right, array, top + 1);
  }
  if (isLeaf(root))
  {
    printf("%c: ", root->data);
    for (int i = 0; i < top; ++i)
    {
        printf("%d", array[i]);
    }
    printf("\n");
  }
}

// ..
int getHeight(Treenode *root)
{
  if (root == NULL)
    return -1;
  int leftHeight = getHeight(root->left);
  int rightHeight = getHeight(root->right);
  return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
