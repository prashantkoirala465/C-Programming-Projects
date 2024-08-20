// #include <stdio.h>

// float getPercentage(int obtainedMarks, int fullMarks){
//   float percentage = (obtainedMarks/ (fullMarks * 1.0)) * 100;
//   return percentage;
// }
// int main()
// {
//   int obtainedMarks, fullMarks;
//   printf("Enter the obtained marks: ");
//   scanf("%d", &obtainedMarks);
//   printf("Enter the full marks: ");
//   scanf("%d", &fullMarks);


//   float result = getPercentage(obtainedMarks, fullMarks);
//   printf("The percentage is: %.2f", result);
//   return 0;
// }

#include <stdio.h>
void introducingMyself(){
  printf("Hello, I am Prashant Koirala, I am a student of BSCS, I am from Nepal, I am 20 years old, I am a programmer and this is my program using functions\n");
}
void sayGoodbye(){
  printf("Goodbye, I am Prashant Koirala, last but not least, I am a programmer and this is my program using functions\n");
}
int main()
{
  introducingMyself();
  sayGoodbye();
  return 0;
}