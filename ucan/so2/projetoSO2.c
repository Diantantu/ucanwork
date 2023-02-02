/*Projeto de Sistema Operativo 2 'Sistema de Multiprogramacao'*/
//importacao das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//sistema linux
#include <pthread.h>//para threads
#include <sys/wait.h>//para processos
#include <sys/types.h>//para processos

//Diretivas
#define QTD_MEDIAS 2
#define QTD_ESTUDANTES 6
#define DISCIPLINAS_QTD_MAX 100



//Prototipos de funcoes
void* calcular_media_aluno();	//deve receber as duas notas de dois outros processos e calcular a media
void* criar_quadro_de_honra();
void* controlo_de_notas();
void* lancamento_de_notas();
void* consultar_media();
void* atualizar_media();
void inicializar_mutexes();
void terminar_mutexes();


//Variaveis globais
int qtd_disciplinas = 6;
float media_estudantes[QTD_ESTUDANTES];		
float nota_estudantes[QTD_ESTUDANTES][DISCIPLINAS_QTD_MAX];	//vai armazenar as notas dos alunos;
char nomes[3] = {"Carlos","Marley", "Jay","Rafael"};

//ultimo professor fica bloqueado por 5 mins
pthread_mutex_t varNotas;
pthread_mutex_t varMedia;
pthread_mutex_t varQtd_disciplinas;


int main(int argc, char* argv[])
{
	//threads
	inicializar_mutexes();
	//pthread_mutex_lock(&mutex);
	//pthread_mutex_unlock(&mutex);
	printf("\t\t\tSistema de Controlo de Notas\n");
	printf("=====Inicializando o sistema...\n");
	pthread_t t1;
	if(pthread_create(&t1, NULL, &lancamento_de_notas, NULL) != 0)
	{
		printf("Erro na criacao da thread");
	}
	if(pthread_join(t1, NULL))
	{
		return 2;
	}
	//processos
	int pid=fork();
	if(pid == -1)
	{
		return 1;
	}
	printf("Processo id:%d\n", getpid());
	if(pid != 0)
	{
		wait(NULL);
	}
	terminar_mutexes();
	return 0;
}
//Threads
void* calcular_media_aluno()
{//deve receber as duas notas de dois outros processos e calcular a media
	
}
void* criar_quadro_de_honra()
{//Criar o ranking dos melhores alunos e imprime
}
void* controlo_de_notas()
{//
	printf("Controlando as notas do sistema");

}
void* lancamento_de_notas()
{
	for(int i =0; i<QTD_ESTUDANTES; i++)
	{
		printf("----Lancamento de notas de %s; inserindo %.2f valores",nomes[i],);
	
	}


}
void* consultar_media()
{
}
void* atualizar_media()
{
}
void inicializar_mutexes()
{//inicializa os mutexes do programa
	pthread_mutex_init(&varNotas, NULL);//inicializando o mutex para as notas
	pthread_mutex_init(&varMedia, NULL);//inicializando o mutex para as medias
	pthread_mutex_init(&varQtd_disciplinas, NULL);//inicializando mutex para qtd de disciplinas
}
float gerarNota(float min)
{
		float num = rand() / (float) RAND_MAX;
		float conv = (float)min;
		return (conv + num*(20.0-conv));
}
void terminar_mutexes()
{
	pthread_mutex_destroy(&varNotas);
	pthread_mutex_destroy(&varMedia);
	pthread_mutex_destroy(&varQtd_disciplinas);
}
