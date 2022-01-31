#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "lista.h"

int main()
{	
	int x, y, bandaSelecionada, opcao;
	x = y = opcao = 0;
	
	int matricula = 0;
    char nome[40];
    float nota = 0;
    
	do
    {
        printf("**********OPCOES************\n");
        printf("1 - Criar aluno\n");
        printf("2 - Remover Aluno da lista\n");
        printf("3 - Consultar Aluno da lista\n");
        printf("4 - Imprimir alunos na tela\n");
        printf("5 - sair\n");
        printf("digite sua escolha: ");
        scanf("%i", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            printf("Digite o numero da matricula do aluno: ");
            scanf("%i", &matricula);
            fflush(stdin);
            printf("Digite o nome do aluno: ");
            fgets(nome, 40, stdin);
        	fflush(stdin);
        	printf("Digite a nota do aluno: ");
            scanf("%f", &nota);
        	fflush(stdin);
        	Inserir(matricula, nome, nota);
        	printf("\n");
        	printf("Aluno adicionado com sucesso\n");
        	printf("\n");
            break;

        case 2:
        	printf("Digite o nome do aluno que deseja remover: ");
            fgets(nome, 40, stdin);
        	fflush(stdin);
        	Retirar(nome);
        	printf("\n");
            break;
            
        case 3:
        	printf("Digite o nome do aluno que deseja consultar: ");
            fgets(nome, 40, stdin);
        	fflush(stdin);
        	Consultar(nome);
        	printf("\n");
            break;

        case 4:
        	MostrarTudo();
            break;

        case 5:
        	printf("\n");
            printf("Programa encerrado!!");
            break;
        
        default:
        	printf("\n");
            printf("Opcao invalida!!");
            printf("\n");
            break;
        }
    } while (opcao != 5);
    
    return 0;
}
