// tree.h
// In this file there are some basic defenitions of structures
// which needed to build a Huffman tree (to encode basicly),
// but in same level it`s 'trex.h' file (stands for 'tree extended').
// This another file provide functions which are useful and also vital for our goals
// I don`t really know if it`s a proper way to organize fs for this 'toy-project',
// but i kinda like it and think that this is pretty comfortable to know that
// i have all functions in the separate file


#ifndef TREE_H_
#define TREE_H_

// A simple node of Huffman tree
typedef struct tnode
{
  // One node store just one character.
  // For now it will be a character, but is suppose it better to replace with \
  // \ some number type to properly use memory
  char data;
  // Each character in the file has some frequency of occurrence.
  // We will represent this frequency as unsigned int for now.
  // Why unsigned? Simply because the character 'a', for example, can not appear in the text '-1' time.
  unsigned int freq;
  // Each node in a Huffman tree, as an every tree, has children.
  // We will store it here, exactly in the parent node to avoid creating
  // separate array of children.
  // Keep in mind that coding idea is to build a binary tree from input
  // characters where each leaf node represents a character and the path from
  // the root to the leaf node determines the code for that character and then
  // traverse it to find optimal codes.
  //
  // For example, we have an alphabet A = { a/15, b/25, c/1}.
  // Let`s take 'a' and 'c' and create a new subtree with some abstract root r1
  // (note that the node name is the frequency of the symbol):
  //      r1
  //  0 /   \ 1
  //   /     \
  // (15)   (1)
  // Now we will simply take 'r1/16' node and 'merge' it with character 'b':
  //        (r2/41)
  //     0 /       \ 1
  //      /         \
  //   (25)         r1
  //             0 /  \ 1
  //              /    \
  //            (15)   (1)
  // Here it is. Based on pathes:
  // A = { a, b, c} = { 10, 0, 11 }
  // Its optimal coding, Huffman proved it.
  tnode *left, *right;
} Treenode;

// Collection of Huffman tree nodes also often called min-heap
struct Tree {
    // TODO: provide a documentation
    unsigned int size;
    unsigned int capacity;
    Treenode **heap;
};

#endif // TREE_H_
