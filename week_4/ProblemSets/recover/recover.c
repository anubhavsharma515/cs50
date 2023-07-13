#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
const int BLOCK_SIZE = 512;
typedef uint8_t BYTE;

int main(int argc, char *argv[])

{
    if (argc != 2)
    {
        printf("Usage ./recover <file_name>.");
        return 1;
    }

    FILE *inptr = fopen(argv[1], "r");
    FILE *outptr = NULL;

    if (inptr == NULL)
    {
        printf("File not found.");
        return 1;
    }

    BYTE *buffer = malloc(sizeof(BYTE)*512);
    if (buffer == NULL)
    {
        printf("Memory Error");
        return 1;
    }

    int counter = 0;
    char *filename = malloc(sizeof(char)*8);

    while(fread(buffer, 512, 1, inptr)==1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }
            sprintf(filename, "%03i.jpg", counter);
            outptr = fopen(filename, "w"); 
            ++counter;
        }
        // the reason this is needed is because the next JPG might not be 512 Bytes away.
        // if putting in the previous block, only the first 512 bytes after the header are written,
        // and the rest get discarded.
        if (outptr != NULL)
        {
            fwrite(buffer, 512, 1, outptr);
        }
    }

    free(buffer);
    free(filename);
    fclose(inptr);
    fclose(outptr);

    return 0;
}

