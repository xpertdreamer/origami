#include "trex.h"
#include "stdlib.h"

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
    tempTree->heap = (Treenode **)malloc(capacity * sizeof(struct Treenode *));
    return tempTree;
}
