#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o 
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema 
{
	//inicio da cria��o de vari�veis 
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis 
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string 
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" signfica escrever 
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a"); //como o computador n�o entende separa��o, inserimos uma v�rgula e o "a" singfica atualiza��o de informa��o
	fprintf(file,",");
	fclose(file); //fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //salvando na vari�vel/string 
	
	file = fopen(arquivo, "a"); //salvando no arquivo 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //inserindo mais uma v�rgula 
	fprintf(file, ",");
	fclose(file); //fecha o arquivo 
	
	printf("Digite o sobrenome a ser casdastrado: "); //coletando informa��o do usu�rio 
	scanf("%s",sobrenome); //salvando na vari�vel/string 
	
	file = fopen(arquivo, "a"); //salvando no arquivo 
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //inserindo mais uma v�rgula 
	fprintf(file, ",");
	fclose(file); //fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio 
	scanf("%s",cargo); //salvando na vari�vel/string 
	
	file = fopen(arquivo, "a"); //salvando no arquivo 
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); 
		
}

int consulta() //fun��o respons�vel por consultar os usu�rios no sistema 
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	//inicio da cria��o de vari�veis
	char cpf[40];
	char conteudo[200]; //conte�do do arquivo 
	//final da cria��o de vari�veis 
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio 
	scanf("%s",cpf); //salvando na vari�vel/string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o "r" signfica ler
	
	if(file == NULL) //valida��o caso o computador n�o encontre o arquivo 
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n"); //informando o usu�rio 
    }
	
	while(fgets(conteudo, 200, file) != NULL) //caso o fgets n�o encontre o arquivo dentro dos 200 caracteres, ele para quando for NULL, ou seja, quando n�o encontrar
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //informando o usu�rio
		printf("%s", conteudo); //salvando na vari�vel/string 
		printf("\n\n");
	}
	
 	system("pause");
}

int deletar() //fun��o respons�vel por deletar os usu�rios no sistema 
{
	//inicio da cria��o de vari�veis
	char cpf[40];
	//final da cria��o de vari�veis 
	
	printf("Digite o CPF do usu�rio a ser deletado"); //coletando informa��es do usu�rio
	scanf("%s",cpf); //salvando na vari�vel/string
	
	remove(cpf); //acessa a pasta principal e deleta o n�mero ou nome do arquivo que o usu�rio digitou 
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o "r" signfica ler
	
	if(file == NULL) //valida��o caso n�o encontre o arquivo 
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause"); //pausa para o usu�rio ter tempo de ler a mensagem 
	}
	
	
	
}

int main() 
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	  system("cls");
	
	  setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	  printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	  printf("Escolha a op��o desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n");
	  printf("Op��o: "); //Fim do menu
	
	  scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	  system("cls"); //respons�vel por limpar a tela 
	  
	  
	  switch(opcao) //inicio da sele��o do menu
	  {
	  	 case 1:
	  	 registro(); //chamada de fun��es 
		 break;	
		 
		 case 2:
		 consulta(); //chamada de fun��es
		 break;
		 
		 case 3:
		 deletar(); //chamada de fun��es
		 break;
		 
		 default: //
		 printf("Essa op��o n�o est� dispon�vel!\n");
		 system("pause");
		 break;
		 	
	  }
	 
	}
}
