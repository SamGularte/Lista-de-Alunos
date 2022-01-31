typedef struct aluno Aluno;

Aluno* CriarAluno(int matricula, char nome[40], float nota);

void MostrarAluno(Aluno *aux);

int ChacarAlfa(Aluno *pessoa1, Aluno *pessoa2);

int ChacarAlfa2(Aluno *pessoa1, char nome[40]);
