#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char number[7];
}
plate;

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char *buffer = malloc(7 * sizeof(char));
    if (buffer == NULL)
    {
        printf("Memory error.");
        return 1;
    }

    // Create array to store plate numbers
    plate *plates = malloc(sizeof(plate) * 8);
    if (plates == NULL)
    {
        printf("Memory error.");
        return 2;
    }

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        // strcpy copies the value of buffer to the address pointed by plates, 
        // instead of copying the address of the buffer to the plate. 
        strcpy(plates[idx].number, buffer);

        idx++;
    }
    fclose(infile);
    free(buffer);

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i].number);
    }
    free(plates);
}
