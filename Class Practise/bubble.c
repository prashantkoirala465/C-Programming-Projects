#include <stdio.h>
//Written by: Prashant Koirala
int main()
{
  float heights[5] = {3.5,5.0,5,5,6.1,7.5};

  //Bubble sort data
  int len = 5;
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < len - i - 1; j++)
    {
      if (heights[j] > heights[j + 1])
      {
        //Swap
        float temp = heights[j];
        heights[j] = heights[j + 1];
        heights[j + 1] = temp;
      }
    }
  }
  for (int k = 0; k < len; k++)
  {
    printf("%.1f\n", heights[k]);
  }
}