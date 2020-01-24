#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

//===| Estrutura de Dados |========================================================================
typedef struct tipoDisc
{
	char Nome[TAM];
	int Freq;
	int Nota;
	struct tipoDisc *prox;
} TDisc;
typedef struct tipoAluno
{
	char Nome[TAM];
	char Sexo[TAM];
	TDisc *historico;
	struct tipoAluno *ante;
	struct  tipoAluno *prox;
} TAluno;
typedef struct tipoCurso
{
	char Nome[TAM];
	char Cood[TAM];
	TAluno *alunos;
	struct tipoCurso *prox;
} TCurso;
typedef struct tipoLista
{
	TCurso *inicio;
	TCurso *fim;
} TLista;
//==================================================
//VARIAVEL GLOBAL ==================================
TLista lista;
//==================================================
//================      INICIALIZA  ===================================================================================
void inicializa(TLista *L);
//======================================================================================================================
//================      MENU        ====================================================================================
void menu();
//=====================================================================================================================
//================      CURSO       ====================================================================================
void insereCurso(TLista *L);
void listarCurso(TLista L);
void consultarCurso(TLista L);//, char * Nome);
void excluirCurso(TLista *L);//, char * Nome);
//======================================================================================================================
//================      ALUNO       ====================================================================================
//======================================================================================================================
void insereAluno(TLista *L); // char * Nome, char * Sexo);
void listarAluno(TLista L);
void consultarAluno(TLista  L);
void excluirAluno(TLista * L);
//======================================================================================================================
//================    DISCIPLINA    ====================================================================================
//===================================================================================================================
void insereDisciplina(TLista *L);//, char * Nome, int freq, int nota);
void listarDisciplina(TLista L);
void consultarDisciplina(TLista L);
void excluirDisciplina(TLista *L);//, char * existeDisciplina);
//=====================================================================================================================
//==============     EXIBIR NOTAS E FREQUENCIA DE ALUNOS EM DISCIPLINA ESPECIFICA ======================================
void exibirNotasFreqDisciplina(TLista * L);
// ============================================================================================================
void exibirTudo(TLista *L);

int main()
{
	inicializa(&lista);
	menu();
	return 0;
}
//===================================================================================================================
//=======================    INICIALIZA    =============================================================================
void inicializa(TLista *L)
{
	L->inicio = NULL;
	L->fim = NULL;
}
//==================================================================================================================
//=======================       MENU         ===========================================================================
void menu()
{

	int escolha = -1;

	while (escolha != 0)
	{
		printf("\n MENU\n");
		printf("\n ============================================");
		printf("\n 0 - SAIR (ENCERRAR APLICATIVO)          \n");
		printf("\n ============================================");
		printf("\n     (0)  - SAIR				               \n");
		printf("\n     (1)  - INSERIR CURSO                    \n");
		printf("\n     (2)  - LISTAR CURSOS                    \n");
		printf("\n     (3)  - EXCLUIR CURSO ESPECIFICO         \n");
		printf("\n     (4)  - CONSULTAR CURSO ESPECIFICO       \n");
		printf("\n     (5)  - INSERIR ALUNO(EM CURSO)          \n");
		printf("\n     (6)  - LISTAR ALUNOS         		   \n");
		printf("\n     (7)  - EXCLUIR ALUNO ESPECIFICO    	   \n");
		printf("\n     (8)  - CONSULTAR ALUNO ESPECIFICO       \n");
		printf("\n     (9)  - INSERIR DISCIPLINA PARA ALUNO    \n");
		printf("\n     (10) - LISTAR DISCIPLINAS               \n");
		printf("\n     (11) - EXCLUIR DISCIPLINA ESPECIFICA    \n");
		printf("\n     (12) - CONSULTAR DISCIPLINA ESPECIFICA  \n");
		printf("\n     (13) - EXIBIR NOTAS E FREQ DE ALUNOS EM DISCIPLINA ESPECIFICA       \n");
		printf("\n	   (14) - EXEMPLO						   \n");
		printf("\n ============================================");
		printf("\n (escolha): ");
		scanf("%d", &escolha);

		switch (escolha)
		{
		case 0:
			break;
		case 1:
			insereCurso(&lista);
			break;
		case 2:
			listarCurso(lista);
			break;
		case 3:
			excluirCurso(&lista);
			break;
		case 4:
			consultarCurso(lista);
			break;
		case 5:
			insereAluno(&lista);
			break;
		case 6:
			listarAluno(lista);
			break;
		case 7:
			excluirAluno(&lista);
			break;
		case 8:
			consultarAluno(lista);
			break;
		case 9:
			insereDisciplina(&lista);
			break;
		case 10:
			listarDisciplina(lista);
			break;
		case 11:
			excluirDisciplina(&lista);
			break;
		case 12:
			consultarDisciplina(lista);
			break;
		case 13:
			exibirNotasFreqDisciplina(&lista);
			break;
		case 14:
			exibirTudo(&lista);
			break;
		default:
			printf("\nOPCAO INVALIDA\n");
		}
	}
	system("PAUSE");
}

//===================================================================================================================
//=======================    LISTA VAZIA    ==============================================================================
int listaVazia(TLista *L)
{
	if(L->inicio == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//===============================================================================================================
//======================       INSERIR       =============================================================================
void insereCurso(TLista *L)
{
	TCurso *novo = (TCurso *)malloc(sizeof(TCurso));
	TCurso *atualC = L->inicio;
	TCurso *anterior = NULL;

	int inseriu = 0;

	printf("\n\n\n\t\t=====| INSERIR CURSO |====\n\n");
	printf("\t Nome do Curso: ");
	fflush(stdin);
	gets(novo->Nome);

	printf("\t Coordenador: ");
	fflush(stdin);
	gets(novo->Cood);

	novo->alunos = NULL;
	novo->prox = NULL;

	if(listaVazia(L))
	{
		L->inicio = novo;
		L->fim = novo;
		printf("\n\n\t CURSO CADASTRADO COM SUCESSO !!! \n");
	}
	else
	{
		while(atualC != NULL)
		{
			if(strcmp(novo->Nome, atualC->Nome) == -1)
			{
				if(atualC == L->inicio)
				{
					//Inserindo NOVO no inicio da Lista ...
					L->inicio = novo;
				}//if

				novo->prox = atualC;

				if(anterior != NULL)
				{
					anterior->prox = novo;
				}//if
				inseriu = 1;
				printf("\n\n\t CURSO CADASTRADO COM SUCESSO !!! \n");
				break;
			}//if

			anterior = atualC;
			atualC = atualC->prox;
		}//while

		if(!inseriu)
		{
			//inserindo NOVO no final da LISTA ...
			L->fim->prox = novo;
			L->fim = novo;
			printf("\n\n\t CURSO CADASTRADO COM SUCESSO !!! \n");

		}//if
	}

}//insereFilme()
//=========================================================================
void insereAluno(TLista *L)
{
	TAluno *novo = (TAluno *)malloc(sizeof(TAluno));
	char *resposta = (char *)malloc(sizeof(char));

	listarCurso(lista);

	printf("\n\tInforme o curso que voce deseja inserir no aluno: ");
	fflush(stdin);
	gets(resposta);

	TCurso *atualC = L->inicio;
	TAluno *atualA = NULL;

	while(atualC != NULL)
	{
		if(strcmp(atualC->Nome, resposta) == 0)
		{
			printf("\n\n\n\t\t=====| INSERIR ALUNO |====\n\n");
			printf("\t Nome do ALUNO: ");
			fflush(stdin);
			gets(novo->Nome);

			printf("\t Sexo: ");
			fflush(stdin);
			gets(novo->Sexo);

			novo->historico = NULL;
			novo->ante = NULL;
			novo->prox = NULL;

			if(atualC->alunos == NULL)
			{
				atualC->alunos = novo;
				printf("\n\n\t ALUNO CADASTRADO COM SUCESSO \n");
				break;
			}
			else
			{
				atualA = atualC->alunos;
				//alterado
				while (atualA->prox != NULL)
				{
					atualA = atualA->prox;
					//atualA = atualA->ante;
				}//while
				atualA->prox = novo;
				novo->ante = atualA;
				//atualA->ante = novo;
				break;
			}//if
		}//if
		atualC = atualC->prox;
	}//while
}//insereAluno()
//=============================================================================================================
void insereDisciplina(TLista *L)
{

	TDisc *novo = (TDisc *)malloc(sizeof(TDisc));
	char *respostaC = (char *)malloc(sizeof(char));
	char *respostaA = (char *)malloc(sizeof(char));

	TCurso * atualC = L->inicio;
	TAluno * atualA = NULL;
	TDisc * atualD = NULL;
	TDisc * anterior = NULL;

	printf("\n\n\n\t\t=====| VERIFICAR CURSO E ALUNO CADASTRADO |====\n\n");
	//printf("Nomes dos Cursos:")
	printf("\t Informe o NOME do curso CADASTRADO: ");
	fflush(stdin);
	gets(respostaC);

	//nomes dos alunos
	printf("\t Informe o NOME do aluno CADASTRADO no curso: ");
	fflush(stdin);
	gets(respostaA);

	while(atualC != NULL)
	{

		if (strcmp(atualC->Nome, respostaC) == 0)
		{
			atualA = atualC->alunos;
			while(atualA != NULL)
			{
				if(strcmp(atualA->Nome, respostaA) == 0)
				{
					printf("\n\n\n\t\t=====| INSERIR DISCIPLINA |====\n\n");
					printf("\t Nome da Disciplina: ");
					fflush(stdin);
					gets(novo->Nome);

					printf("\t Frequencia: ");
					fflush(stdin);
					scanf("%d", &novo->Freq);

					printf("\t Nota: ");
					fflush(stdin);
					scanf("%d", &novo->Nota);

					novo->prox = NULL;

					if(atualA->historico == NULL)
					{
						atualA->historico = novo;
						printf("\n\n\t DISCIPLINA CADASTRADA COM SUCESSO \n");
						break;
					}
					else
					{
						atualD = atualA->historico;
						//alterado
						while (atualD->prox != NULL)
						{
							atualD = atualD->prox;

						}//while
						//anterior = atualD;
						atualD->prox = novo;
						anterior = atualD;
						printf("\n\n\t DISCIPLINA CADASTRADA COM SUCESSO \n");
						break;
					}//if
				}//if
				atualA = atualA->prox;
			}//while
		}//if
		else
		{
			printf("\n\t NAO EXISTE O CURSO DIGITADO \n");
		}
		atualC = atualC->prox;
	}//while
}//insereDisciplina()
//============================================================================================================
//======================        LISTAR       ======================================================================
void listarCurso(TLista L)
{
	TCurso *atualC = L.inicio;

	printf("\n\n\n\t\t=====| LISTA DE CURSOS |=====\n\n");
	//printf("\tTotal de Elementos: %d\n\n",L.total);

	while(atualC != NULL)
	{
		printf("\t\t CURSOS: (%s)\n", atualC->Nome);
		atualC = atualC->prox;
	}//while
	printf("\n\n");
}
//===========================================================================================================
void listarAluno(TLista  L)
{
	TCurso *atualC = L.inicio;
	TAluno *atualA = atualC->alunos;
	char * respostaC = (char*)malloc(sizeof(char));

	printf("\n\n\n\t\t=====| LISTAR ALUNOS |=====\n\n");
	//printf("\tTotal de Elementos: %d\n\n",L.total);

	printf("\n\tInforme o curso em que deseja listar os alunos: ");
	fflush(stdin);
	gets(respostaC);

	while(atualC != NULL)
	{

		if(strcmp(atualC->Nome, respostaC) == 0)
		{
			atualA = atualC->alunos;
			while(atualA != NULL)
			{
				printf("\t\t ALUNO: (%s)\n", atualA->Nome);
				atualA = atualA->prox;
			}
		}
		atualC = atualC->prox;
	}//while
	printf("\n\n");
	system("PAUSE");
}
//===========================================================================================================
void listarDisciplina(TLista  L)
{
	TCurso *atualC = L.inicio;
	TAluno *atualA = atualC->alunos;
	TDisc * atualD;
	char * respostaC = (char*)malloc(sizeof(char));

	printf("\n\n\t\t=====| LISTAR DISCIPLINAS |=====\n\n");
	//printf("\tTotal de Elementos: %d\n\n",L.total);

	printf("\n\tInforme o curso em que deseja listar as disciplinas: ");
	fflush(stdin);
	gets(respostaC);

	while(atualC != NULL)
	{

		if(strcmp(atualC->Nome, respostaC) == 0)
		{

			while(atualA != NULL)
			{
				atualD = atualA->historico;
				while(atualD != NULL)
				{
					printf("\t\t DISCIPLINA: (%s)\n", atualD->Nome);
					atualD = atualD->prox;
				}
				atualA = atualA->prox;
			}
		}
		atualC = atualC->prox;
	}//while
	printf("\n\n");
	system("PAUSE");
}
//============================================================================================================
//======================        CONSULTAR     ======================================================================
void consultarCurso(TLista L)
{
	int cont = 0;
	TCurso *atualC = L.inicio;
	char * nome = (char *)malloc(sizeof(char));

	printf("\n\n\n\t\t=====| CONSULTAR CURSO |====\n\n");
	printf("\t Informe o curso a ser consultado: ");
	fflush(stdin);
	gets(nome);


	while (atualC != NULL)
	{
		cont++;
		if(strcmp(atualC->Nome, nome) == 0)
		{
			printf("\n\n\n\t Curso: %s \n\n\t Coordenador: %s \n\n\n", atualC->Nome, atualC->Cood);
			system("PAUSE");
			break;
		}//if
		else
		{
			printf("CURSO INEXISTENTE");
		}
		atualC = atualC->prox;
	}//while

}
//===========================================================================================================
void consultarAluno(TLista  L)
{
	int cont = 0, contA = 0;
	TCurso * atualC = L.inicio;
	TAluno * atualA;
	TDisc * atualD;

	char * respostaC = (char*)malloc(sizeof(char));
	char * respostaA = (char*)malloc(sizeof(char));

	printf("\n\n\t\t CONSULTAR ALUNO ESPECIFICO \n\n");

	printf("\n\tInforme o curso em que o aluno esta matriculado: ");
	gets(respostaC);

	printf("\n\tInforme o nome do aluno que deseja pesquisar:");
	gets(respostaA);


	while(atualC != NULL)
	{
		cont++;
		if(strcmp(atualC->Nome, respostaC) == 0)
		{
			printf("\n\n\t Nome do CURSO: %s", atualC->Nome);
			atualA = atualC->alunos;

			while (atualA != NULL)
			{
				contA++;

				if(strcmp(atualA->Nome, respostaA) == 0)
				{
					printf("\n\t\t- Aluno: %s \t Sexo: %s\n", atualA->Nome, atualA->Sexo);
					atualD = atualA->historico;
					while(atualD != NULL)
					{
						printf("\n\t\t- Disciplina: %s\n", atualD->Nome);
						atualD = atualD->prox;
					}//while
				}//if
				atualA = atualA->prox;
			}//while
		}//if
		printf("\n");
		atualC = atualC->prox;
	}//while
	printf("\n");
	system("PAUSE");

}//exibiralunoss()
//===========================================================================================================
void consultarDisciplina(TLista L)
{
	int cont = 0;
	TCurso * atualC = L.inicio;
	TAluno * atualA;
	TDisc *atualD;

	char * nomeCurso = (char*)malloc(sizeof(char));
	char * nomeAluno = (char*)malloc(sizeof(char));
	char * nome = (char*)malloc(sizeof(char));

	printf("\n\n\t\t CONSULTAR DISCIPLINA ESPECIFICO\n");



	printf("\n\tInforme o nome do curso que a DISCIPLINA esta: ");
	fflush(stdin);
	gets(nomeCurso);

	printf("\n\tInforme o nome do aluno que a DISCIPLINA esta: ");
	fflush(stdin);
	gets(nomeAluno);

	printf("\n\tInforme o nome da disciplina que deseja pesquisar: ");
	fflush(stdin);
	gets(nome);

	while(atualC != NULL)
	{
		if(strcmp(atualC->Nome, nomeCurso) == 0)
		{
			atualA = atualC->alunos;
			while (atualA != NULL)
			{
				if(strcmp(atualA->Nome, nomeAluno) == 0)
				{
					printf("\n\n\n\t Nome do ALUNO: %s \n\n", atualD->Nome);
					atualD = atualA->historico;
					while (atualD != NULL)
					{
						cont++;
						if(strcmp(atualD->Nome, nome) == 0)
						{
							printf("\n\n\n\t Nome da DISCIPLINA: %s \n\n", atualD->Nome);
							system("PAUSE");
							break;
						}//if
						atualD = atualD->prox;
					}//while
				}
				atualA = atualA->prox;
			}
		}//while
		atualC = atualC->prox;
	}
}//while
//============================================================================================================
//======================        EXCLUIR        ======================================================================
void excluirCurso(TLista *L)
{
	TCurso *atualC = L->inicio;
	TAluno *auxA = NULL, *atualA;
	TDisc *auxD = NULL, *atualD;
	TCurso *anterior = NULL;

	char * nome = (char*)malloc(sizeof(char));

	printf("\n\n\n\t\t=====| INFORME CURSO A SER EXCLUIDO |====\n\n");
	printf("\t Nome do Curso: ");
	fflush(stdin);
	gets(nome);


	while(atualC != NULL)
	{
		if(strcmp(atualC->Nome, nome) == 0)
		{
			atualA = atualC->alunos;
			while(atualA != NULL)
			{
				//Excluindo DISCIPLINAS
				atualD = atualA->historico;
				while(atualD != NULL)
				{
					auxD = atualD->prox;
					free(atualD);
					atualD = auxD;
				}
				//Excluindo ALUNOS
				auxA = atualA->prox;
				free(atualA);
				atualA = auxA;
			}
			//Excluindo elemento no INICIO da LISTA ...
			if(atualC == L->inicio)
			{
				L->inicio = atualC->prox;
				if(L->inicio == NULL)
				{
					L->fim = NULL;
				}

			}
			//Excluindo elemento no FIM da LISTA ...
			else if (atualC == L->fim)
			{
				L->fim = anterior;
				anterior->prox = NULL;

			}
			else
			{
				//Excluindo elemento no MEIO da LISTA ...
				anterior->prox = atualC->prox;

			}//if
			printf("\n\n\t CURSO EXCLUIDO COM SUCESSO");
			free(atualC);
			break;
		}//if
		anterior = atualC;
		atualC = atualC->prox;
	}//while
	printf("\n\n");
	system("PAUSE");
}
//============================================================================================================
void excluirDisciplina(TLista *L)
{

	TCurso *atualC = L->inicio;
	TAluno *auxA = NULL, *atualA;
	TDisc *auxD = NULL, *atualD;
	TCurso *anterior = NULL;
	char * existeCurso = (char*)malloc(sizeof(char));
	char * existeDisciplina = (char*)malloc(sizeof(char));
	char * existeAluno = (char*)malloc(sizeof(char));


	printf("\n\n Informe o nome do CURSO em que a DISCIPLINA estar: ");
	fflush(stdin);
	gets(existeCurso);

	printf("\n\n Informe o nome do ALUNO em que a DISCIPLINA estar: ");
	fflush(stdin);
	gets(existeAluno);


	printf("\n\n Informe o nome da DISCIPLINA a ser excluida: ");
	fflush(stdin);
	gets(existeDisciplina);

	while(atualC != NULL)
	{
		if(strcmp(atualC->Nome, existeCurso) == 0)
		{
			atualA = atualC->alunos;
			while(atualA != NULL)
			{
				if(strcmp(atualA->Nome, existeAluno) == 0)
				{
					atualD = atualA->historico;
					while(atualD != NULL)
					{
						if(strcmp(atualD->Nome, existeDisciplina) == 0)
						{
							//Excluindo elemento no INICIO da LISTA ...
							if(atualA->historico->prox == atualD->prox)
							{

								if(atualA->historico->prox == NULL)
								{
									atualA->historico->prox = atualD->prox;
								}
								atualA->historico = atualD->prox;

							}
							else if (atualA->historico->prox != atualD->prox)
							{
								atualD->prox = anterior;
								anterior->prox = NULL;
							}
							else
							{
								//Excluindo elemento no MEIO da LISTA ...
								anterior->prox = atualA->historico->prox;
							}//if

							free(atualD);
							break;
						}
						anterior = atualD;
						atualD = atualD->prox;
					}
				}
				atualA = atualA->prox;
			}
		}
		atualC = atualC->prox;
	}

	printf("\n\n");
	system("PAUSE");
}
//===========================================================================================================
void excluirAluno(TLista * L)
{

	TCurso *atualC = L->inicio;
	TAluno *atualA;
	TAluno *anterior, *posterior;
	TDisc *atualD, *auxD;
	int total = 0;

	char * nomeAluno = (char*)malloc(sizeof(char));
	char * nomeCurso = (char*)malloc(sizeof(char));

	printf("\n\n\n\t\t EXCLUIR ALUNO \n\n");


	printf("\n INSIRA o curso que o aluno esta: ");
	fflush(stdin);
	gets(nomeCurso);

	printf("\n INSIRA o nome do aluno: ");
	fflush(stdin);
	gets(nomeAluno);

	while(atualC != NULL)
	{
		if(strcmp(atualC->Nome, nomeCurso) == 0)
		{
			atualA = atualC->alunos;
			while (atualA != NULL)
			{
				if(strcmp(nomeAluno, atualA->Nome) == 0)
				{
					atualD = atualA->historico;
					while(atualD != NULL)
					{
						auxD = atualD->prox;
						free(atualD);
						atualD = auxD;
					}//while

					if(atualA->ante == NULL)
					{
						printf("\n\n\t CURSO EXCLUIDO COM SUCESSO INICIO");
						if (atualA->prox != NULL)atualA->prox->ante = NULL;
						atualC->alunos = atualA->prox;
						free(atualA);
						break;
					}
					if(atualA->prox == NULL)
					{
						printf("\n\n\t CURSO EXCLUIDO COM SUCESSO FIM");
						atualA->ante->prox = NULL;
						free(atualA);
						break;
					}
					else
					{

						atualA->ante->prox = atualA->prox;
						atualA->prox->ante = atualA->ante;
						printf("\n\n\t CURSO EXCLUIDO COM SUCESSO MEIO");
						free(atualA);
						break;
					}
				}
				anterior = atualA;
				atualA = atualA->prox;
			}//while
		}//if
		printf("\n");
		atualC = atualC->prox;
	}//while
	printf("\n");
	system("PAUSE");

}//exibiralunoss()
//============================================================================================================
//================== EXIBIR NOTAS & FREQUENCIA DE ALUNOS EM DISCIPLINA ESPECIFICA ============================
void exibirNotasFreqDisciplina(TLista *L)
{

	TCurso *atualC = L->inicio;
	TAluno *atualA;
	TDisc *atualD;
	int contador = 0;
	char nomeDisciplina[40];

	printf("\n\n\n\t\t EXIBIR NOTAS E FREQUENCIAS DE ALUNOS \n\n");
	printf("\n\n\t insira o nome da disciplina que voce deseja exibir \n\n");
	gets(nomeDisciplina);
	while(atualC != NULL)
	{
		atualA = atualC->alunos;

		while (atualA != NULL)
		{
			atualD = atualA->historico;
			while(atualD != NULL)
			{
				if (strcmp(nomeDisciplina, atualD->Nome) == 0)
				{
					printf("\n\t\t- Aluno: %s \t Sexo: %s\n", atualA->Nome, atualA->Sexo);
					printf("\n\t\t- Frequencia: %d \t nota: %d\n", atualD->Freq, atualD->Nota);
				}
				atualD = atualD->prox;

			}//while
			atualA = atualA->prox;
		}//while

		printf("\n");
		atualC = atualC->prox;
	}//while
	printf("\n");
	system("PAUSE");

}//exibiralunoss()
//============================================================================================================

void exibirTudo(TLista * L)
{
	TCurso *atualC = L->inicio;
	TAluno *atualA;
	TDisc *atualD;
	int contador = 0;

	printf("\n\n\n\t\t Cursos & Alunos & Disciplinas \n\n");

	while(atualC != NULL)
	{
		printf("\t(%d) - Nome:%s Coordenador:[%s]", contador, atualC->Nome, atualC->Cood);
		atualA = atualC->alunos;

		while (atualA != NULL)
		{
			printf("\n\t\t- Aluno: %s \t Sexo: %s\n", atualA->Nome, atualA->Sexo);
			atualD = atualA->historico;
			while(atualD != NULL)
			{
				printf("\n\t\t- Disciplina: %s\n", atualD->Nome);
				atualD = atualD->prox;

			}//while
			atualA = atualA->prox;
		}//while

		printf("\n");
		atualC = atualC->prox;
	}//while
	printf("\n");
	system("PAUSE");

}//exibiralunoss()
