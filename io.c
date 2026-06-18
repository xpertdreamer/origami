#include "io.h"
#include "stdio.h"
#include "stdlib.h"
#include "trex.h"

//..
_Bool parse(char *inputName, Parsed count)
{
   FILE *input = fopen(inputName, "r");
   if (input == NULL)
   {
       printf("Error occured while opening the file: %s", inputName);
       printf("Please, check the path and file availability");
       return 1;
   }
   int c;
   while ((c = fgetc(input)))
   {
     if (c == EOF)
         break;
     ++count[c];
   }

   for (int i = 0; i < COUNTBUF; ++i)
       if (count[i] > 0)
           printf("%c: %d\n", i, count[i]);

   fclose(input);
   return 0;
}

// ..
_Bool parseAndCompress(char *inputName, Parsed count)
{
   FILE *input = fopen(inputName, "r");
   if (input == NULL)
   {
       printf("Error occured while opening the file: %s", inputName);
       printf("Please, check the path and file availability");
       return 1;
   }

   int c;
   while ((c = fgetc(input)))
   {
     if (c == EOF)
         break;
     ++count[c];
   }

   char *symbols = (char* )malloc(COUNTBUF * sizeof(char));
   int i = COUNTBUF - 1;
   while (i >= 0)
   {
       symbols[i] = i;
       --i;
   }
   code(symbols, count, COUNTBUF);

   fclose(input);
   return 0;
}

// ..
void printHelp()
{
    printf("VERSION: %.2f\n", VERSION);
    printf("Usage: origami [OPTION] [FILE]\n");
    printf("Compress the file using Huffman algorithm, or analyze the file\n\n");
    printf("With no FILE show this message\n");
    printf("   -h\tShow this help message\n");
    printf("   -f\tCompress the given file\n");
    printf("   -a\tCount the occurrences of each character in a file\n");
}
