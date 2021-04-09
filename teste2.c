#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int arr[1] = {0};
  int numero;


  printf("numero \n");
  scanf("%d", &numero);

  for (size_t j = 1; j < numero; j++)
  {
    arr[j] = j;
    printf("%d \n" , arr[j]);
  }

  
  system("pause");
  return(0);
}