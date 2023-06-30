	//Bibli8otecas utilizadas.
#include <stdio.h>
#include <locale.h>

int main(void)
{
		//Resposavel pelas palavras proprias do portugues como "ç", "´; ~; ^".
	setlocale(LC_ALL, "Portuguese");
	/* ---------- 1° Parte Cadastro de nomes ------------ */

	
		//declaracao de variavel para saber tamanho de todos os vetores.
	int numero_produtos;
		//variavel responsavel por repetição que será utilizada em varios loop's For ao longo do codigo.
	int i;
		//variavel responsavel por repetição que será utilizada no armazenamento de nomes na matriz.
	int l;
		//1° Interação com o usuario de apresentação.
	printf("Ola!\nSeja bem vindo ao Sistema de almoxarifado Product X \n\n");
		//Solicitando o numero de produtos a serem cadastrados na Matriz.
	printf("Digite o numero de produtos a serem cadastrados: \n");
		//Scaneando e armazenando a quantidade na variavel numero_produtos.
	scanf("%d", &numero_produtos);
		//falsa leitura de informação para retirar ultima leitura (No caso o ENTER).
	scanf("%c");	
		//Declarando Matriz de armazenamento de nomes.
	char nome_produtos[numero_produtos][99];
	
		//iniciando loop para armazenamento do nome dos produtos.
	for ( l =0;l< numero_produtos;l++)
	{
		printf("Digite o nome do produto de codigo: 00%d \n", l);
			/*Armazenamento de matriz, que armazena o todos os dados digitados 
			inclusive espaçoes com limite de 99caracteres ate  digitar um ENTER
			*/
		scanf("%99[^\n]",nome_produtos[l]);
		//falsa leitura de informação para retirar ultima leitura (No caso o ENTER).
		scanf("%c");
	}
	printf("\n\n");	
		/* ---------- 1.1° Parte Alteração de nomes ------------ */	
		
		//declaracao de variavel para receber escolha do usuario pela alteracao ou nao.
	char alteracao ;
		//Declarando variavel de alteracao de material.
	int material_alterado;	
	
		// Interação com o usuario de Perguntando se deseja alterar material.
	printf("Deseja alterar o nome de algum Material? (s/n): \n");
	scanf("%c", &alteracao);
	
		//loop de condicao para alteracao de material.
	while (alteracao !='n')
	{	
			//condicao para execucao positiva do loop.
		if (alteracao == 's')
		{
				//interacao com usuario para solicitar material a ser alterado.		
			printf("Digite o codigo do material que deseja alterar: \n");
				//Scaneando e armazenando o codigo na variavel "Material alterado".
			scanf("%d", &material_alterado);
			scanf("%c");
				//interacao com usuario para solicitar novo nome do material.	
			printf("Digite o novo nome do Material de condigo 00%d:  \n", material_alterado);
				//Scaneando e armazenando o codigo na no devido local do vetor "nome_produtos[?]".
			scanf("%99[^\n]",nome_produtos[material_alterado]);
			scanf("%c");
		}
			//condicao para enceramento do loop.	
		else if (alteracao == 'n')
		{	
		printf("\n\n");		
		break;
		} //condicao de digitacao incorreta dando reinicio ao loop.
		 else 
		{
			printf("Opcao Digitada invalida! \nTente novamente. \n\n");		
		}
		// Interação com o usuario Perguntando se deseja continuar alerando nomes de materiais.
	printf("Deseja alterar o nome de mais algum Material? (s/n): \n");
	scanf("%c", &alteracao);	
			
	} 
	/* ---------- 1.2° Cadastro Definção de quantidades ------------ */
	
		//Declarando vetor de armazenamento da quantidade de cada produto. 
	int quantidade_materiais[numero_produtos];
		//iniciando loop para armazenamento da quantidade de cada produto
	for (i = 0; i < numero_produtos; i++)
    {
        printf("Digite a quantidade de unidades do produto de codigo: 00%d \n", i);
        scanf("%d", &quantidade_materiais[i]);
    }
	printf("\n\n");	
	/* ---------- 2° Parte Exibição de lista completa------------ */
	
		//Declarando variavel de exibicao de lkista completa de materiais.
	char exiba_completa= 's';	
		//loop de condicao para exibicao de lista completa de materiais.
	while (exiba_completa !='n')
	{
			//interacao com usuario para solicitar se deseja exibicao ou não da lista total de materiais.	
		printf("Deseja Exibir lista completa de produtos e quantidades? (s/n): \n");
			//Scaneando e armazenando o codigo na variavel "exiba_completa".
		scanf("%s", &exiba_completa);
			//condicao para execucao positiva do loop.
		if (exiba_completa == 's')
		{
			printf("Codigo--------------Nome---------------Quantidade\n");
			
			for (i=0; i<numero_produtos;i++)
			{	
				printf("00%d - Produto: %s Quantidade: %d  \n",i,nome_produtos[i], quantidade_materiais[i]);		
			}
			break;	
		}
			//condicao para enceramento do loop.	
		else if (exiba_completa == 'n')
		{
			printf("\n\n");	
			break;	
		}	//condicao de digitacao incorreta dando reinicio ao loop. 
		 else 
		{
			printf("Opcao Digitada invalida! \nTente novamente. \n\n");	
		}	
	}	
	printf("\n\n");	
	/* ---------- 2.1 Exibição de consulta detalhada de cada material------------ */
	
		//Declarando variavel exibicao informacoes detalhadas do produto"codigo_produto".
	int codigo_produto;
		//Declarando variavel que armazena a opcao para finalizar o programa".
	char pesquisa_detalhada;
		//loop de condicao para consulta de produtos.
		
		//interacao com usuario para solicitar se deseja consultar informacoes detalhadas de um certo produto.
	printf("Deseja consultar Informacoes detalhadas de algum produto especicifico? (s/n): \n");
		//Scaneando e armazenando o codigo na variavel "pesquisa_detalhada".
	scanf("%s", &pesquisa_detalhada);
		//loop de condicao para exibicao de consulta detalhada.
	while (pesquisa_detalhada !='n')
	{	
			//condicao para execucao positiva do loop.
		if (pesquisa_detalhada == 's')
		{
			printf("Digite o Codigo do produto que deseja consultar: \n");
			scanf("%d", &codigo_produto);
				//subconcição de execução somente em valores possiveis.
			if (codigo_produto < numero_produtos )
			{
				
			printf("00%d - O produto %s contem %d itens \n\n",codigo_produto,nome_produtos[codigo_produto],quantidade_materiais[codigo_produto]);		
				// Interação com o usuario Perguntando se deseja exibir outra culsulta detalhada.
			printf("Deseja consultar mais algum produto? (s/n): \n");
		 		//Scaneando e armazenando o codigo na variavel "pesquisa_detalhada".
			scanf("%s", &pesquisa_detalhada);
				//subconcição com erro de inserção de valores possiveis.
			}else if (codigo_produto > numero_produtos )
			
			printf("Codigo Digitado e maior do que armazenado no banco de dados! \nTente novamente. \n\n");	
			
			//condicao para enceramento do loop.
		} else if (pesquisa_detalhada == 'n')
			{
			printf("\n\n");
			break;		
			} //condicao de digitacao incorreta dando reinicio ao loop. 
			 else 
			{	
			printf("Opcao Digitada invalida! \nTente novamente. \n\n");	
			break;
			}				
	}	
	
	/* ---------- 3° Parte Retirada de algum quantitativo de material------------ */
	
		//Declarando variavel que armazena a opcao para retirada de qantitativo de itens".
	char retirada;
		//Declarando variavel que armazena a quantidade de itens retirados".
	int retirados;
		
	printf("Deseja Realizar Retirada de alguma quantidade de um produto? (s/n): \n");
	//Scaneando e armazenando o codigo na variavel "fim_execucao".
	scanf("%s", &retirada);
	
		//loop de condicao para exibicao de Reetirada de itens.
	while (retirada !='n')
	{
		
			//condicao para execucao positiva do loop de retirada de itens.
		if (retirada == 's')
		{
			printf("Digite o Codigo do produto: \n");
			scanf("%d", &codigo_produto);
				//subconcição de execução somente em valores possiveis.
			if (codigo_produto < numero_produtos )
			{
			
			printf("Digite a quantidade retirada do produto: \n");	
			scanf("%d", &retirados);
			
				//calculo de produtos retirados e armazenamento da nova quantidade no vetor.
			quantidade_materiais[codigo_produto] = (quantidade_materiais[codigo_produto] - retirados );
				//Exibição de novo quantitativo apos retirada.
			printf("Foram retirados %d Unidades do produto %s \n\n",retirados,nome_produtos[codigo_produto]);	
			printf("00%d - O produto %s Agora contem %d itens \n\n",codigo_produto,nome_produtos[codigo_produto],quantidade_materiais[codigo_produto]);		
				//subconcição com erro de inserção de valores possiveis.	
			}else if (codigo_produto > numero_produtos )
			
			printf("Codigo Digitado e maior do que armazenado no banco de dados! \nTente novamente. \n\n");	
			
			//condicao para enceramento do loop.
		} else if (retirada == 'n')
			{
			
			break;		
			} //condicao de digitacao incorreta dando reinicio ao loop. 
			
			 else 
			{	
			printf("Opcao Digitada invalida! \nTente novamente. \n\n");	
			}	
		// Interação com o usuario Perguntando se deseja realizar mais alguma retirada.		
	printf("Deseja Realizar mais alguma retirada de alguma quantidade de um produto? (s/n): \n");
		//Scaneando e armazenando o codigo na variavel "retirada".
	scanf("%s", &retirada);
	
			
	}	
	printf("\n\n");
	printf("Obrigado e ate a proxima!");
}

