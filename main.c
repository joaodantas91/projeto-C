/*
--------------------------------------------------------------Requisitos------------------------------------------------------------

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

void menu();
void voltarMenu();
void sair();
void sobre_nos();



//função menu
void menu()
{

	int user_select = 0;


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
		system("cls");
		printf("Teste cad.");
		break;
	case 2:
		//função listar
		system("cls");
		printf("Teste list.");
		break;
	case 3:
		//função excluir
		system("cls");
		break;
	case 4:
		//função alterar
		system("cls");
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

//função sobre nós 
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

int main()
{
	setlocale(LC_ALL, "Portuguese");

	menu();

	return 0;
}
