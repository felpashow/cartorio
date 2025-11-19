#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h>	//biblioteca de alocações de texto por região
#include <string.h> //biblioteca das strings
int registro() //cadastrar os usuarios do sistema
	{
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		printf("Digite o CPF a ser cadastrado: ");
		scanf("%s", cpf);
		
		
		strcpy(arquivo, cpf); //copiar os valores das strings
		
		FILE *file;
		file = fopen(arquivo, "w");
		fprintf(file,cpf);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite um nome a ser cadastrado: ");
		scanf("%s",nome);
		
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file," ");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
		
		
	}

int consulta()
	{
		
		system("cls");
			setlocale (LC_ALL, "Portuguese"); //Definido a linguagem
		
		
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
	
		
		
		if(file == NULL)
		{
			printf("CPF Não foi localizado! \n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas sao as informaçoes do usuario: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		fclose(file);
		
		system("pause");
		
		
	}

int deletar()
	{
		char cpf[40];	
			printf("Digite o CPF que deseja deletar: ");
			scanf("%s",cpf);
			
			remove(cpf);
			
			FILE *file;
			file = fopen(cpf,"r");
			
			
			
			if(file == NULL ){
			printf("O usuário não se sencontra no sistema!.\n");
			system("pause");
			}
		
		
	}	

int main()
	{
		int opcao=0; //definido variáveis
		int x=1;
		
		for(x=1;x=1;)
		{
			system("cls");
			setlocale (LC_ALL, "Portuguese"); //Definido a linguagem
		
		printf("### Cartório do Felipe ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Opção: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //limpar texto
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
				printf("Essa opção não está disponivel\n");
			system("pause");
			break;
			}
			
		}	
	}
