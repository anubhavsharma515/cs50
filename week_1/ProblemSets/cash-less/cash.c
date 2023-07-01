#include <stdio.h>

int main(void) 
{ 
   int coins = 0;
   int change;
   do { 
    printf("Change Owed: "); 
    scanf("%d", &change);
   } 
   while (change < 0);

   while (change != 0) 
   { 
    if (change >= 25) 
    { 
        coins+=1;
        change-=25;
    }
    else if (change >= 10) 
    { 
        coins+=1;
        change-=10;
    }
    else if (change >= 5) 
    { 
        coins+=1;
        change-=5;
    }
    else if (change >= 1) 
    { 
        coins+=1;
        change-=1;
    }
    }

    printf("%d", coins);
}