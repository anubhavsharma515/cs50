#include <stdio.h>

int main(void) 
{
   int split = 2;
   int height;
   do { 
    printf("Height: "); 
    scanf("%d", &height);
   } 
   while ((height< 1) || (height > 8));

   for (int i = 0; i < height; i++) {
    for (int j = 0; j <= height + split + i; ++j) {

        if (j < height) { 
            if (i + j < height - 1) { 
                printf(" "); 
                } 
            else { 
                printf("#"); 
                } 
            }
        else if (j >= height && j <= height + 1) { 
            printf(" "); 
            } 
        else { 
            printf("#"); 
            } 
        }
    printf("\n");    
    }
}