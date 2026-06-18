// trex.h
// Please, read the comments inside the 'tree.h'.
// TODO: provide documentation

#ifndef TREX_H_
#define TREX_H_

#define INITIAL_SIZE 0

#include "tree.h"
#include "stdbool.h"

// Small function allocating a new node of tree with given character and
// frequency.
Treenode *createNode(char data, unsigned int frequency);
// Only leaves contains the characters and it`s code.
// Because of that we need to be able to determine which node is a leaf.
_Bool isLeaf(Treenode *rootNode);
// Before we actually can start to insert nodes in our tree by set of rules
// which I`ll declare in the 'trex.h' file we need to initialize the tree in
// memory. This function accepts capacity of tree.
// VERSION 0.01 NOTE: for now capacity is fixed value, but I think later it will
// be dinamically allocatable
struct Tree* initTree(unsigned int capacity);
// ..
#endif // TREX_H_
