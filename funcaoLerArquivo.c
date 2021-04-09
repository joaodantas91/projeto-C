#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  // Define o nome do novo tipo criado
  struct Funcionario // Cria uma STRUCT para armazenar os dados de uma pessoa
  {
    char nome[60];         // define o campo Nome
    char matricula[60];         // define o campo Nome
  };    

int main(void)
{
  char inputMatricula[60];

  FILE *pont_arq;

  struct Funcionario cadastro[10];

  pont_arq = fopen("arquivo.txt", "rb");

  printf("Digite a matricula: ");
  gets(inputMatricula);

  fread (cadastro, sizeof(struct Funcionario), 10, pont_arq);
  for (size_t i = 0; i < 10; i++)
  {
    if (strcmp(cadastro[i].matricula, inputMatricula) == 0)
    { 
      printf("%s \n", cadastro[i].nome);
    }
  };

  fclose (pont_arq);
  
  system("pause");
  return(0);
}