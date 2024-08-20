#include <stdio.h>
//Written by: Prashant Koirala
/*&& = and
|| = or
! = not*/
int main()
{
    int age = 18;
    int money = 450;

    int ageisLegal = age >= 18;;
    int moneyisEnough = money >= 500;
    int canBuyDrink = ageisLegal && moneyisEnough;
    printf("Can buy drink: %d", canBuyDrink);
    return 0;
}