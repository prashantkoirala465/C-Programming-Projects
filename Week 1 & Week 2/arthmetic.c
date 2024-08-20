#include<stdio.h>
int main()
{
    float anupam,aananta,aaska,nivriti,bibechan;
    float averageheight;
    printf("Enter the height of anupam: ");
    scanf("%f",&anupam);
    printf("Enter the height of aananta: ");
    scanf("%f",&aananta);
    printf("Enter the height of aaska: ");
    scanf("%f",&aaska);
    printf("Enter the height of nivriti: ");
    scanf("%f",&nivriti);
    printf("Enter the height of bibechan: ");
    scanf("%f",&bibechan);
    averageheight = (anupam + aananta + aaska + nivriti + bibechan)/5;
    printf("Their average height is: %f",averageheight);
    return 0;
}