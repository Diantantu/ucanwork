/*Projeto Lagoas em Luanda desenvolvido 
como trabalho para a disciplina de Matematica Discreta
curso de Engenharia Informatica, Universidade Catolica de 
Angola
*/
//Importacao de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Constantes
#define NUMCOL 10
#define NUMROW 12
#define NITENS 1
#define FILEIN "files/leituraCampo.txt"
#define FILEOUT "files/escritaCampoMapeado.txt"


//Prototipo de Funcoes
void marcarTerras(int U[][NUMCOL]);
void marcarVizinhos(int U[][NUMCOL],int M[][NUMCOL], int linha, int coluna, int numArea);
void imprimirCampo(int U[][NUMCOL]);
void zerarMatriz(int U[][NUMCOL]);
FILE* abrirFicheiro(char *caminho, char *modo);
void fecharFicheiro(FILE *fp, char nome[]);

//Declaracao de funcoes
int main()
{//Funcao Principal e inicio do programa

//Declaracao de variaveis;
	int controle, terminar = 0;
	FILE *campoEntrada, *campoMapeado;
	campoEntrada = abrirFicheiro(FILEIN, "r");
	int matriz_dados_superficies[NUMROW][NUMCOL];
	
	int nlinha=0, ncoluna=0,a;
	int NLidos = fscanf(campoEntrada, "%d ", &matriz_dados_superficies[nlinha][ncoluna]);
	while(!feof(campoEntrada))
	{
		ncoluna++;
		if(ncoluna==10)
		{
			nlinha++;
			ncoluna = 0;
		}
		
		if(NLidos!=NITENS)
		{
			printf("\nleitura suspensa devido a linha desformatada \n");
			break;
		}
		fscanf(campoEntrada, "%d ", &matriz_dados_superficies[nlinha][ncoluna]);
		fflush(campoEntrada);
		

	}
	fflush(campoEntrada);
	fecharFicheiro(campoEntrada, FILEIN);
	
	imprimirCampo(matriz_dados_superficies);
	
	do
	{
		printf("\n\nProjeto Lagoas em Luanda\n\n");
		printf("Menu:\n\n");
		printf("1-Imprimir Matriz original;\n");
		printf("2-Achar areas alagadas;\n");
		printf("0-Sair do programa;\n");
		printf("Digite o numero da opcao que pretende selecionar\n");
		scanf("%d", &controle);
		switch(controle)
		{
			case 1:
				imprimirCampo(matriz_dados_superficies);
				break;
			case 2:
				marcarTerras(matriz_dados_superficies);
				break;
			case 0:
				terminar=1;
				printf("\nPrograma Terminando...");
			default:
				printf("--------------------------------------------------------");
				printf("                       Opcao invalida                    ");
				printf("---------------------------------------------------------");
				break;
		}
		
	}while(terminar == 0);
	printf("Terminando o programa");

}
void imprimirCampo(int U[][NUMCOL])
{//Funcao para imprimir a matriz
	for(int linha = 0; linha < NUMROW; linha++)
	{	printf("\n");
		for( int coluna = 0; coluna < NUMCOL; coluna++)
			printf("%d  ", U[linha][coluna]);
	} 
}
void marcarVizinhos(int U[][NUMCOL],int M[][NUMCOL], int linha, int coluna, int numArea)
{//Funcao para marcar todos os vizinhos de uma area solida

	if(linha >= 0 && linha < NUMROW)
		if(coluna >= 0 && coluna < NUMCOL)
			if(U[linha][coluna] == 1 && M[linha][coluna] == 0)
			{
				M[linha][coluna] = numArea;
				marcarVizinhos(U,M,linha+1, coluna, numArea);
				marcarVizinhos(U,M,linha-1, coluna, numArea);
				marcarVizinhos(U,M,linha, coluna-1, numArea);
				marcarVizinhos(U,M, linha, coluna+1, numArea);
				
		
			}
}
void marcarTerras(int U[][NUMCOL])
{//Funcao para marcar todas as areas solidas da matriz

	//Criando uma nova matriz que ira armazenar as areas mapeadas
	int M[NUMROW][NUMCOL], contAreas =1;
	zerarMatriz(M);	
	for(int coluna = 0; coluna < NUMCOL; coluna++)
		for(int linha = 0; linha < NUMROW; linha++)
			if(U[linha][coluna] == 1 && M[linha][coluna] == 0 )
			{
				marcarVizinhos(U, M, linha, coluna, contAreas);
				contAreas++;
			}
	imprimirCampo(M);			
}
void zerarMatriz(int U[][NUMCOL])
{//Funcao para preencher todos os elementos da matriz com zeros(0)
	for(int linha = 0; linha < NUMROW; linha++)
		for(int coluna = 0; coluna < NUMCOL; coluna++)
			U[linha][coluna] = 0;

}

FILE* abrirFicheiro(char caminho[], char modo[])
{
	return fopen(caminho, modo);
}

void fecharFicheiro(FILE *fp, char nome[])
{
	while(1)
	{
		if( (fclose(fp)) == 0 ) break;
		printf("\nErro no encerramento do ficheiro %s", nome);
		
	}
}
