#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

int get_bits(int message_code, int counter);
void print_bulb(int bit);

int main(void)
{
    char message[130];
    printf("Message: ");
    fgets(message, sizeof(message), stdin);
    
    for (int i = 0, bits_counter = 0; i < strlen(message) - 1; ++i)
    {
        int message_code = (int) message[i];
        get_bits(message_code, bits_counter);
        printf("\n");
    }
}

int get_bits(int message_code, int counter)
{
    if (message_code == 0 && counter == BITS_IN_BYTE) {
        return 0;
    }
    
    get_bits(message_code / 2, ++counter);

    if (message_code % 2 == 1)
    {
        print_bulb(1);
        return 0;
    }
    else
    {
        print_bulb(0);
        return 0;
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
