#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage

    if (argc != 3)
    {
        printf("Usage ./reverse <filename>");
        return 1;
    }
    // Open input file for reading
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open file.");
        return 1;
    }

    // Read header

    WAVHEADER *bh = malloc(sizeof(WAVHEADER));
    fread(bh, sizeof(WAVHEADER), 1, inptr);

    // Use check_format to ensure WAV format
    if (check_format(*bh))
    {
        printf("Invalid WAV Format\n");
        return 1;
    }
    // Open output file for writing

    FILE *outptr = fopen("output.wav", "w");
    // Write header to file
    fwrite(bh, sizeof(WAVHEADER), 1, outptr);

    // Use get_block_size to calculate size of block
    int blockSize = get_block_size(*bh);

    BYTE samples[blockSize];

    fseek(inptr, 0, SEEK_END);

    // get the size of audio data
    long audioSize = ftell(inptr) - sizeof(WAVHEADER);
    // get the number of blocks we need to store
    int blockNum = audioSize / blockSize;

    // Beacuse we need to iterate a set number of times. a for loop makes more sense.
    for (int i = blockNum - 1; i >= 0; i--)
    {
        // Starting From End of the File
        fseek(inptr, sizeof(WAVHEADER) + i * blockSize, SEEK_SET);
        fread(samples, blockSize, 1, inptr);
        fwrite(samples, blockSize, 1, outptr);
    }

    free(bh);
    fclose(outptr);
    fclose(inptr);
}

int check_format(WAVHEADER header)
{
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
         return 0;
    }
    
    return 1;
}

int get_block_size(WAVHEADER header)
{
    int blockSize;

    blockSize = round(header.bitsPerSample / 8.0) * header.numChannels;
    return blockSize;
}