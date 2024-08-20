#include <stdio.h>
//Written by: Prashant Koirala
int main()
{
    float percentage;
    printf("Hello, Welcome to NEB Website!You can check your results here:\n");
    printf("Enter your grade in percentage: ");
    scanf("%f", &percentage);
    if (percentage > 100 || percentage < 0)
    {
        printf("Invalid grade");
        return 1;
    }
    else if (percentage >= 80)
    {
        printf("You got Distinction");
    }
    else if (percentage >= 65)
    {
        printf("You got 1st Division");
    }
    else if (percentage >= 55)
    {
        printf("You got 2nd Division");
    }
    else if (percentage >= 40)
    {
        printf("You got 3rd Division");
    }
    else if (percentage <= 40)
    {
        printf("You failed! Congrulations! Arko Barsa Feri Try Gara Babu!");
    }

    return 0;
}
