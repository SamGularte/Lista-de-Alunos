#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "lista.h"

typedef struct t_nodo
{
	struct aluno *content;
    struct a_nodo *next;
}T_Nodo;

T_Nodo *inicio = NULL;

void Inserir(int matricula, char nome[40], float nota)
{
	T_Nodo* nodo = (T_Nodo*)malloc(sizeof(T_Nodo));
    if(nodo == NULL)
    {
        printf("memoria insuficiente!");
    }
    else
    {
        nodo->content =  CriarAluno(matricula, nome, nota);
		nodo->next = NULL;
    }
	
	if(inicio == NULL)
	{
		inicio = nodo;		
	}
	else
	{
		T_Nodo *aux = NULL;
		T_Nodo *help = NULL;
		aux = inicio;
		if(ChacarAlfa(inicio->content, nodo->content)>0)
		{
			inicio = nodo;
			nodo = aux;
			inicio->next = nodo;
			return;	
		}
		help = inicio;
		while(aux->content != NULL)
		{
			if(ChacarAlfa(aux->content, nodo->content)>0)
			{
				help->next = nodo;
				nodo->next = aux;
				return;	
			}
			help = aux;
			aux = aux->next;
			if(aux == NULL)
			{
				help->next = nodo;
				return;		
			}
		}
	}
}

void Retirar(char nome_procurado[40])
{
	if(inicio->content == NULL)
	{
		printf("Nao tem alunos na lista!\n");		
	}
	else
	{
		T_Nodo *aux = NULL;
		T_Nodo *help = NULL;
		aux = inicio;
		int verificador = 0;
		verificador = ChacarAlfa2(inicio->content, nome_procurado);
		if(verificador == 0)
		{
			inicio = inicio->next;
			printf("\n");
			printf("Aluno retirado com sucesso\n");
			return;	
		}
		help = inicio;
		while(aux->content != NULL)
		{
			verificador = ChacarAlfa2(aux->content, nome_procurado);
			if(verificador == 0)
			{
				help->next = aux->next;
				printf("\n");
				printf("Aluno retirado com sucesso\n");
				return;	
			}
			help = aux;
			aux = aux->next;
			if(aux == NULL)
			{
				printf("Aluno inexistente!\n");
				return;		
			}
		}
	}
}

void Consultar(char nome_procurado[40])
{
	if(inicio->content == NULL)
	{
		printf("Nao tem alunos na lista!\n");		
	}
	else
	{
		T_Nodo *aux = NULL;
		aux = inicio;
		int verificador = 0;
		verificador = ChacarAlfa2(inicio->content, nome_procurado);
		if(verificador == 0)
		{
			printf("\n");
			MostrarAluno(inicio->content);
			return;	
		}
		while(aux->content != NULL)
		{
			verificador = ChacarAlfa2(aux->content, nome_procurado);
			if(verificador == 0)
			{
				printf("\n");
				MostrarAluno(aux->content);
				return;	
			}
			aux = aux->next;
			if(aux == NULL)
			{
				printf("Aluno inexistente!\n");
				return;		
			}
		}
	}
}

void MostrarTudo()
{
	if(inicio == NULL)
	{
		printf("Nao tem alunos na lista!\n");
	}
	else
	{
		T_Nodo *aux = NULL;
		aux = inicio;
		while(aux != NULL)
		{
			MostrarAluno(aux->content);
			aux = aux->next;
		}
	}
}
