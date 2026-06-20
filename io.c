#include "io.h"
#include "stdio.h"
#include "stdlib.h"

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

//..
_Bool parseAndCompress(char *inputName, Parsed count)
{
   FILE *input = fopen(inputName, "r");
   if (input == NULL)
   {
       printf("Error occured while opening the input file: %s\n", inputName);
       printf("Please, check the path and file availability\n");
       return 1;
   }
   if (fseek(input, 0, SEEK_END) < 0) {
        printf("Error occured while getting the file input size: %s\n", inputName);
        printf("Please, check the path and file availability\n");
        fclose(input);
        return 1;
   }
   long int seekRes = ftell(input);
   printf("%ld\n", seekRes);
   if (seekRes < MIN_FILE_SIZE_BYTES) {
       printf("File already pretty small\n");
       fclose(input);
       return 0;
    }
    fseek(input, 0, SEEK_SET);

   int c;
   while ((c = fgetc(input)))
   {
     if (c == EOF)
         break;
     ++count[c];
   }
   fclose(input);

   // ..

   return 0;
}

// ..
void printHelp()
{
    printf("Usage: origami [OPTION] [FILE]\n");
    printf("VERSION: %.2f\n", VERSION);
    printf("Compress the file using Huffman algorithm, or analyze the file\n\n");
    printf("With no FILE show this message\n");
    printf("   -h\tShow this help message\n");
    printf("   -f\tCompress the given file\n");
    printf("   -a\tCount the occurrences of each character in a file\n");
}

// ..
_Bool outCodes(Treenode *root, const char *inputName, const char *outputName)
{

    return 0;
}
