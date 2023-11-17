#include "Compiler.h"
#include <stdio.h>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

int main(int argc, char* argv[])
{

    printf("hello world");


	// Check if there are enough command line arguments
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1; // Exit with an error code
    }

    // Pass the input and output file names to the Compile function
	Compile(argv[1], argv[2]);
    printf("%d\n", _CrtDumpMemoryLeaks());
    return 0; // Exit successfully
}
