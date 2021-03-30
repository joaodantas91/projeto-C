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
#include <locale.h>

void menu()
{

	int user_select = 0;

	printf("1- Cadastrar\n");
	printf("2- Listar\n");
	printf("3- Excluir\n");
	printf("4- Alterar\n");
	printf("5- Sobre nós\n");
	printf("6- Sair\n ");

	scanf("%d",&user_select);

	switch (user_select)
	{
	case 1:
		//função cadastrar
		printf("Teste cad.");
		//1- Cadastrar o usuário
		//2- Retornar para o menu
		break;
	case 2:
		printf("Teste list.");
		//função listar
		break;
	case 3:
		//função excluir
		break;

	case 4:
		//função alterar
		break;
	case 5:
		//função sair
		break;

	case 6:
		//função sobre_nos
		break;

	default:
		break;
	}
}

int main()
{
	menu();
	return 0;
}
