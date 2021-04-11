/*
----------------------------------------------------------------Leia-me-------------------------------------------------------------
*Sistema feito no ano de 2021 por alunos da Universidade Federal Rural da Amazônia(UFRA): 

João Vitor Santa Brigida Dantas     Matrícula: 2020016360

Marcos Quadros Andrade              Matrí­cula: 2020015882

Mateus dos Santos Ribeiro           Matrí­cula: 2020016389

Thiago Tavares Gonzalez             Matrí­cula: 2020016146

--------------------------------------------------------------Requisitos------------------------------------------------------------
												#SISTEMA DE GERENCIAMENTO DE RECURSOS HUMANOS#


*Menu onde o usuário pode escolher as opções de cadastrar, listar, excluir, alterar ou sair.

1-Cadastrar: opção que habilita ao usuário do sistema cadastrar todos os atributos acima listados, porém antes de cadastrar (registrar no arquivo) deve ser feito uma consulta se o novo usuário já está cadastrado no arquivo.

2-Listar: listar todos os atributos cadastrados no arquivo.

3-Excluir: Excluir um usuário do arquivo com base no atributo chave (matrícula)

4-Alterar: Alterar dados de um determinado usuário escolhido pelo atributo chave, porém o sistema não deve permitir a alteração do atributo matrícula.

5-Sobre: função extra que exibe infos. da equipe de desenvolvimento 

6-Sair: opção de sair do sistema.

Sempre que o usuário escolher uma opção deve ter a possibilidade de voltar para a tela de menu, exceto quando escolher por sair do sistema.
------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

//struct funcionario: define a estrutura com as informações do funcionário.
typedef struct emp EMPLOYEE;

struct emp
{
	int mat;
	char nome[30];
	char email[50];
	char dataAdmisao[10];
	float salario;
};

//declaração de funções
void menu();
void cadastro();
void listar();
void excluir();
void alterar();
void sobre_nos();
void sair();
void cabecalho();
void voltarMenu();

//função cabeçalho:limpa o console e exibe um cabeçalho com o nome do sistema.
void cabecalho()
{
	system("cls");
	printf("-------------------------------\n");
	printf("PROGRAMA RECURSOS HUMANOS");
	printf("\n-------------------------------\n\n");
}

//função cadastrar: cadastra e grava em um arquivo as informações do funcionário(matrícula, nome, email, data de admissao e salário)
void cadastro()
{
	FILE *arquivo, *ler;
	EMPLOYEE emp;
	int mat;
	arquivo = fopen("arquivo.txt", "ab");

	if (arquivo == NULL)
	{
		printf("Problemas na abertura do arquivo\n");
	}
	else
	{

		do
		{

			cabecalho();

			fflush(stdin);
			printf("Digite a matricula: ");
			scanf("%d", &mat);

			ler = fopen("arquivo.txt", "r");
			while (fread(&emp, sizeof(EMPLOYEE), 1, ler) == 1)
			{
				if (mat == emp.mat)
				{
					printf("\nNao é possivel cadastrar. Numero de matricula ja cadastrado.\n");
					fclose(ler);
					printf("\n");
					printf("Digite uma tecla para voltar ao menu:");
					getch();
					system("cls");
					menu();
				}
			}
			fclose(ler);
			emp.mat = mat;
			fflush(stdin);
			printf("Digite o nome: ");
			gets(emp.nome);

			fflush(stdin);
			printf("Digite o email: ");
			gets(emp.email);

			fflush(stdin);
			printf("Digite a data de admissao: ");
			gets(emp.dataAdmisao);

			fflush(stdin);
			printf("Digite o Salario: ");
			scanf("%f", &emp.salario);
			fwrite(&emp, sizeof(EMPLOYEE), 1, arquivo);
			printf("\nFuncionario cadastrado com sucesso!");
			printf("\n ");
			printf("\nDeseja continuar(s/n) ?");

		} while (getche() == 's');

		fclose(arquivo);
		system("cls");
		menu();
	}
}

//função listar: lê o arquivo de cadastro e exibe todos os funcionário cadastrados na tela.
void listar()
{
	FILE *arquivo;
	EMPLOYEE emp;

	arquivo = fopen("arquivo.txt", "rb");
	cabecalho();
	if (arquivo == NULL)
	{
		printf("Problemas na abertura do arquivo\n");
	}

	else
	{
		while (fread(&emp, sizeof(EMPLOYEE), 1, arquivo) == 1)
		{
			printf("Matricula:%d \n", emp.mat);
			printf("Nome:%s \n", emp.nome);
			printf("Email:%s \n", emp.email);
			printf("Data de admissao:%s \n", emp.dataAdmisao);
			printf("Salario:%.2f \n", emp.salario);
			printf("-------------------------------\n\n");
		}
	}
	fclose(arquivo);
	printf("Digite uma tecla para voltar ao menu:");
	getch();
	system("cls");
	menu();
}

//função excluir: exclui um funcionário baseado na matrícula.
void excluir()
{

	FILE *arquivo, *temporario;
	EMPLOYEE emp;

	arquivo = fopen("arquivo.txt", "r+");
	temporario = fopen("temp.txt", "w");
	int mat;
	cabecalho();
	if (arquivo == NULL)
	{
		printf("Problemas na abertura do arquivo\n");
	}

	else
	{
		printf("Digite a matricula q deseja exlcuir: ");
		scanf("%d", &mat);

		while (fread(&emp, sizeof(EMPLOYEE), 1, arquivo) == 1)
		{
			if (mat != emp.mat)
			{
				fwrite(&emp, sizeof(EMPLOYEE), 1, temporario);
			}
		}
		printf("\nFuncionario excluido com sucesso!\n");
	}
	fclose(temporario);
	fclose(arquivo);
	remove("arquivo.txt");
	rename("temp.txt", "arquivo.txt");
	printf("\n");
	printf("Digite uma tecla para voltar ao menu:");
	getche();
	system("cls");
	menu();
}

//função alterar:altera as informações de um funcionario, exceto o numero de matrícula.
void alterar()
{
	FILE *arquivo, *temporario;
	EMPLOYEE emp;

	arquivo = fopen("arquivo.txt", "r+");
	temporario = fopen("temp.txt", "w");
	int mat;
	cabecalho();
	if (arquivo == NULL)
	{
		printf("Problemas na abertura do arquivo\n");
	}

	else
	{
		printf("Digite o numero de matricula que deseja Alterar: ");
		scanf("%d", &mat);
		printf("\n");

		while (fread(&emp, sizeof(EMPLOYEE), 1, arquivo) == 1)
		{

			if (mat == emp.mat)
			{

				printf("Matricula:%d \n", emp.mat);
				printf("Nome:%s \n", emp.nome);
				printf("Email:%s \n", emp.email);
				printf("Data de admissao:%s \n", emp.dataAdmisao);
				printf("Salario:%.2f \n", emp.salario);
				printf("-------------------------------\n\n");

				fflush(stdin);
				printf("Digite o nome: ");
				gets(emp.nome);

				fflush(stdin);
				printf("Digite o email: ");
				gets(emp.email);

				fflush(stdin);
				printf("Digite a data de admissao: ");
				gets(emp.dataAdmisao);

				fflush(stdin);
				printf("Digite o Salario: ");
				scanf("%f", &emp.salario);

				fwrite(&emp, sizeof(EMPLOYEE), 1, temporario);
			}
			if (mat != emp.mat)
			{
				fwrite(&emp, sizeof(EMPLOYEE), 1, temporario);
			}
		}
	}
	printf("Dados alterados com sucesso!\n");
	fclose(temporario);
	fclose(arquivo);
	remove("arquivo.txt");
	rename("temp.txt", "arquivo.txt");
	printf("\n Digite uma tecla para voltar ao menu:");
	getche();
	system("cls");
	menu();
}

//função sobre nós: exibe a equipe de desenvolvimento do sistema.
void sobre_nos()
{

	printf(" /$$      /$$                     /$$                       /$$                                         ',            \n| $$$    /$$$                    | $$                      |__/                                      .-`-,\\__            \n| $$$$  /$$$$  /$$$$$$  /$$$$$$$ | $$   /$$ /$$   /$$       /$$ /$$$$$$$   /$$$$$$$                    .\"`   `,            \n| $$ $$/$$ $$ /$$__  $$| $$__  $$| $$  /$$/| $$  | $$      | $$| $$__  $$ /$$_____/                  .'_.  ._  `;.        \n| $$  $$$| $$| $$  \\ $$| $$  \\ $$| $$$$$$/ | $$  | $$      | $$| $$  \\ $$| $$                    __ / `      `  `.\\ .--.    \n| $$\\  $ | $$| $$  | $$| $$  | $$| $$_  $$ | $$  | $$      | $$| $$  | $$| $$                   /--,| 0)   0)     )`_.-,)    \n| $$ \\/  | $$|  $$$$$$/| $$  | $$| $$ \\  $$|  $$$$$$$      | $$| $$  | $$|  $$$$$$$            |    ;.-----.__ _-');   /    \n|__/     |__/ \\______/ |__/  |__/|__/  \\__/ \\____  $$      |__/|__/  |__/ \\_______/             '--./         `.`/  `\"`        \n                                            /$$  | $$                                              :   '`      |.              \n                                           |  $$$$$$/                                              | \\     /  //             \n                                            \\______/                                                \\ '---'  /'           \n                                                                                                     `------'              \n");
	printf("\n");
	printf("Sistema desenvolvido por :\n");
	printf("\n");
	printf("João Vitor Santa Brigida Dantas     Matrícula: 2020016360\n");
	printf("\n");
	printf("Marcos Quadros Andrade              Matrícula: 2020015882\n");
	printf("\n");
	printf("Mateus dos Santos Ribeiro           Matrícula: 2020016389\n");
	printf("\n");
	printf("Thiago Tavares Gonzalez             Matrícula: 2020016146\n");
	printf("\n");
}

//função menu
void menu()
{

	int user_select = 0;

	printf("\n");
	printf("-------------MENU PRINCIPAL-------------\n");
	printf("\n");
	printf("1- Cadastrar\n");
	printf("2- Listar\n");
	printf("3- Excluir\n");
	printf("4- Alterar\n");
	printf("5- Sobre nós\n");
	printf("6- Sair\n ");
	printf("\n");
	printf("Escolha uma opção: ");
	scanf("%d", &user_select);

	switch (user_select)
	{
	case 1:
		//função cadastrar
		cadastro();
		break;
	case 2:
		//função listar
		listar();
		break;
	case 3:
		excluir();
		break;
	case 4:
		//função alterar
		alterar();
		break;
	case 5:
		//função sobre_nós
		system("cls");
		sobre_nos();
		voltarMenu();
		break;
	case 6:
		//função sair
		sair();
		break;
	default:
		//caso o usuário digite uma opção inválida, o programa retornará ao menu.
		system("cls");
		printf("Opção inválida... Retornando ao menu principal.\n");
		return menu();
		break;
	}
}

//Função para retornar o menu
void voltarMenu()
{
	int returnMenu;
	printf("------------------------------------------------------------------------------------------------");
	printf("\nDigite 1 para retornar ao menu\n");
	printf("\nDigite 2 para sair do sistema\n");
	scanf("%d", &returnMenu);

	if (returnMenu == 1)
	{
		system("cls");
		return menu();
	}
	else if (returnMenu == 2)
	{
		sair();
	}
}

//função sair
void sair()
{
	system("cls");
	printf("Sistema encerrado.");
	exit(0);
}
//função principal
int main()
{
	setlocale(LC_ALL, "Portuguese");

	menu();

	return 0;
}
