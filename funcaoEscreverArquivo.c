#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char funcMatriculaExiste(char);

// Define o nome do novo tipo criado
struct Funcionario // Cria uma STRUCT para armazenar os dados de uma pessoa
{
  char nome[60];         // define o campo Nome
  char matricula[60];         // define o campo Nome
};    



int main(void)
{
  char inputMatricula;

  FILE *pont_arq;

  struct Funcionario cadastro[1];

  pont_arq = fopen("arquivo.txt", "ab");

  printf("Digite a matricula do funcionario: ");
  fflush(stdin);
  gets(cadastro[0].matricula);
  printf("Digite o nome do funcionario: ");
  fflush(stdin);
  gets(cadastro[0].nome); 

  strcpy(inputMatricula, cadastro[0].matricula);

  fread (cadastro, sizeof(struct Funcionario), 10, pont_arq);
  
  for (size_t i = 0; i < 10; i++)
  {
    if (strcmp(cadastro[i].matricula, cadastro[0].matricula) == 0) {
      printf("existe");
    }
    printf("nao existe");
  };

  fwrite (cadastro, sizeof(struct Funcionario), 1, pont_arq);

  fclose (pont_arq);
  
  system("pause");
  return(0);
}

// char funcMatriculaExiste(char matricula, char cadastro, char pont_arq) {
//   // FILE *pont_arq;

//   // struct Funcionario cadastro[10];

//   // pont_arq = fopen("arquivo.txt", "rb");
    
//   fread (cadastro, sizeof(struct Funcionario), 10, pont_arq);
  
//   for (size_t i = 0; i < 2; i++)
//   {
    
//     if (strcmp(cadastro[i].matricula, matricula) == 0) {
//       return "true";
//     }
//     printf("teste");
//   };
  
//   fclose (pont_arq);
//   return "false";
// }
