// io.h
// Contains function for I/O interaction
// TODO: provide a documentation
// TODO: BITWRITER to actually compress files

#ifndef IO_H_
#define IO_H_

#define COUNTBUF 256
#define MIN_FILE_SIZE_BYTES 200
#define VERSION 0.01

#include <stdio.h>
#include "stdbool.h"
#include "trex.h"

typedef int Parsed[COUNTBUF];

typedef struct {
  FILE *file;

} Writer;

// ..
_Bool parse(char *inputName, Parsed count);
// ..
void printHelp();
// ..
_Bool parseAndCompress(char *inputName, Parsed count);
// ..
_Bool outCodes(Treenode* root, const char* inputName, const char* outputName);

#endif // IO_H_
