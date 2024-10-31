#include "sorting.h"
#include <time.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: %s controlfile.txt\n", argv[0]);
        return 1;
    }

    // Seed random number generator
    srand(time(NULL));

    const char *control_file_name = argv[1];

    if(processControlFile(control_file_name) != 0) 
    {
        fprintf(stderr, "Error processing control file %s\n", control_file_name);
        return 1;
    }

    return 0;
}