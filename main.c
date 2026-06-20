#include "io.h"
#include "unistd.h"

int main(int argc, char** argv) {
   Parsed count = { 0 };
   int opt;
       
   while ((opt = getopt(argc, argv, "hf:a:")) != -1)
   {
       switch(opt)
       {
           case 'f':
           {
               parseAndCompress(optarg, count);
               break;
           }
           case 'a':
           {
               return parse(optarg, count);
           }
           case 'h':
           default: {
               printHelp();
               break;
           }
       }
   }

   if (optind == 1) printHelp();

        /* char sym[] = {'a', 'b', 'c', 'd', 'e', 'v'}; */
        /* int freq[] = {60, 5, 30, 5, 45, 0}; */
        /* int size = sizeof(sym) / sizeof(sym[0]); */
        /* code(sym, freq, size); */
    return 0;
}
