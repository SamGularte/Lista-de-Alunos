#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct aluno
{
    int matricula;
    char nome[40];
    float nota;
}Aluno;

Aluno* CriarAluno(int matricula, char nome[40], float nota)
{
    Aluno* a = (Aluno*)malloc(sizeof(Aluno));
    if(a == NULL)
    {
        printf("memoria insuficiente!");
    }
    else
    {
        a->matricula = matricula;
        strcpy(a->nome,nome);
        a->nota = nota;
        return a;
    }
}

void MostrarAluno(Aluno *aux)
{
	printf("******************************\n");
	printf("matricula: %i\n", aux->matricula);
	printf("nome: %s\n", aux->nome);
	printf("nome: %.1f\n", aux->nota);
	printf("\n");	
}

int ChacarAlfa(Aluno *pessoa1, Aluno *pessoa2)
{
	return (int)strcmp(pessoa1->nome,pessoa2->nome);
}

int ChacarAlfa2(Aluno *pessoa1, char nome[40])
{
	return (int)strcmp(pessoa1->nome,nome);
}
