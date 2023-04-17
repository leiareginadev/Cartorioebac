#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região 
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // função responsável por cadastrar os usuários no sistema 
{
	//inicio da criação de variáveis 
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis 
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string 
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" signfica escrever 
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a"); //como o computador não entende separação, inserimos uma vírgula e o "a" singfica atualização de informação
	fprintf(file,",");
	fclose(file); //fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); //salvando na variável/string 
	
	file = fopen(arquivo, "a"); //salvando no arquivo 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //inserindo mais uma vírgula 
	fprintf(file, ",");
	fclose(file); //fecha o arquivo 
	
	printf("Digite o sobrenome a ser casdastrado: "); //coletando informação do usuário 
	scanf("%s",sobrenome); //salvando na variável/string 
	
	file = fopen(arquivo, "a"); //salvando no arquivo 
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //inserindo mais uma vírgula 
	fprintf(file, ",");
	fclose(file); //fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário 
	scanf("%s",cargo); //salvando na variável/string 
	
	file = fopen(arquivo, "a"); //salvando no arquivo 
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); 
		
}

int consulta() //função responsável por consultar os usuários no sistema 
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	//inicio da criação de variáveis
	char cpf[40];
	char conteudo[200]; //conteúdo do arquivo 
	//final da criação de variáveis 
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário 
	scanf("%s",cpf); //salvando na variável/string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o "r" signfica ler
	
	if(file == NULL) //validação caso o computador não encontre o arquivo 
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n"); //informando o usuário 
    }
	
	while(fgets(conteudo, 200, file) != NULL) //caso o fgets não encontre o arquivo dentro dos 200 caracteres, ele para quando for NULL, ou seja, quando não encontrar
	{
		printf("\nEssas são as informações do usuário: "); //informando o usuário
		printf("%s", conteudo); //salvando na variável/string 
		printf("\n\n");
	}
	
 	system("pause");
}

int deletar() //função responsável por deletar os usuários no sistema 
{
	//inicio da criação de variáveis
	char cpf[40];
	//final da criação de variáveis 
	
	printf("Digite o CPF do usuário a ser deletado"); //coletando informações do usuário
	scanf("%s",cpf); //salvando na variável/string
	
	remove(cpf); //acessa a pasta principal e deleta o número ou nome do arquivo que o usuário digitou 
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o "r" signfica ler
	
	if(file == NULL) //validação caso não encontre o arquivo 
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause"); //pausa para o usuário ter tempo de ler a mensagem 
	}
	
	
	
}

int main() 
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	  system("cls");
	
	  setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	  printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	  printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n");
	  printf("Opção: "); //Fim do menu
	
	  scanf("%d", &opcao); //armazenando a escolha do usuário
	
	  system("cls"); //responsável por limpar a tela 
	  
	  
	  switch(opcao) //inicio da seleção do menu
	  {
	  	 case 1:
	  	 registro(); //chamada de funções 
		 break;	
		 
		 case 2:
		 consulta(); //chamada de funções
		 break;
		 
		 case 3:
		 deletar(); //chamada de funções
		 break;
		 
		 default: //
		 printf("Essa opção não está disponível!\n");
		 system("pause");
		 break;
		 	
	  }
	 
	}
}
