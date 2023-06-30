#include <stdio.h>
int calculate_years(int n_current, int n_future);

int main(void)
{

    int n_current;
    int n_future;
    printf("Enter current number of Llamas: ");
    scanf("%d", &n_current);
    printf("Enter future number of Llamas: ");
    scanf("%d", &n_future);

    int years = calculate_years(n_current, n_future);
    printf("It will take %i years.", years);
}

int calculate_years(int n_current, int n_future)
{
    int n_years;
    while (n_current != n_future)
    {
        n_current += n_current/12;
        n_years = calculate_years(n_current, n_future);
    }
    
    return (n_years);
}