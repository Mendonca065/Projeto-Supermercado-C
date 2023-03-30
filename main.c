//M539
#include <stdio.h> //padrao
#include <stdlib.h> //padrao 
#define STRTAM 40 //constante de tamanho
#include <conio.h> //reconhecer a tecla digitada
#include <string.h> //biblioteca de strings 
#include <windows.h> //biblioteca de delay


void interface_header(){// Cabeçalho da interface
	int i;
	printf("%c", 201);
	for(i = 0; i < STRTAM; i++)
		printf("%c", 205);
	printf("%c \n", 187);
}

void interface_blank(){// Cabeçalho da interface
	int i;
	printf("%c", 186);
	for(i = 0; i < STRTAM; i++)
		printf("%c", 32);
	printf("%c \n", 186);
}

void interface_item(int tamX, char str[]){//Linha para adicionar item na interface
	int conta_letras=0;
	int i;

	for (i=0;i<tamX;i++){
		if(str[i]=='\0')
			break;
		else
			conta_letras++;
	}

	printf("%c", 186);	
//for(i=0;i<STRTAM; i++)
	printf("%s",str);
	while(conta_letras<tamX){
		printf("%c",32);
		conta_letras++;
	}
	printf("%c\n", 186);
}

void interface_lb(){//line break, ou quebra de linha da interface
	int i;
	printf("%c", 204);
	for (i = 0; i < STRTAM; i++)
		printf("%c", 205);
	printf("%c\n", 185);
}


void interface_footer(){//rodape da interface
	int i;
	printf("%c", 200);
	for (i = 0; i < STRTAM; i++)
		printf("%c", 205);
	printf("%c\n", 188);
}

void menu(int tam, char str0[], char str1[], char str2[], char str3[],
char str4[], char str5[], char str6[], char str7[], char str8[], char str9[],  char str10[]){//Chama o menu

	interface_header();//cabeçalho
	interface_item(tam, str0);//titulo da pagina
	interface_lb();//quebra de linha
	interface_item(tam, str1);//string 1
	interface_item(tam, str2);//string 2
	interface_item(tam, str3);//string 3
	interface_item(tam, str4);//string 4
	interface_item(tam, str5);//string 5
	interface_item(tam, str6);//string 6
	interface_item(tam, str7);//string 7
	interface_item(tam, str8);//string 8
	interface_item(tam, str9);//string 9
	interface_blank();//quebra de linha em branco
	interface_item(tam, str10);//ultimo item - finalizar
	interface_footer();// o rodape da pagina
	
}

void carregar(char msg[]){
	
	for(int i=0; i<2;i++){
		printf("%s \n", msg);
		printf("o---------------");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("Oo--------------");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("oOo-------------");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("-oOo------------");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("--oOo-----------");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("---oOo----------");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("----oOo---------");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("-----oOo--------");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("------oOo-------");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("-------oOo------");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("--------oOo-----");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("---------oOo----");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("----------oOo---");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("-----------oOo--");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("------------oOo-");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("-------------oOo");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("--------------oO");
		Sleep(100);
		system("cls");
		printf("%s \n", msg);
		printf("---------------o");
		Sleep(100);
		system("cls");
	}
}

int pedir_qtd(){
	int qtd_produto;
	printf("\n");
	printf(" Digite a quantidade: ");// pede quantidade do produto
	scanf("%d", &qtd_produto);
	return qtd_produto;
}

char pedir_char(int x, char text[]){
	char carc[x];
	printf("\n");
	printf("   %s ", text);// pede uma char
	fgets(carc, x, stdin);
	return carc[x];
}

//struct's
typedef struct produto{
		int id;
		int qtd = 0;
		float preco;
		char nome[100];
	}t_produto;
	
float calcular_valor(int qtd, float preco){
	float total = 0;
	total = total + (qtd * preco);
	return total;
}


int main() {
	t_produto produto[60];
	//variavel para o mini cadastro
	char nome[30];
	char endereco[100];
	char telefone[15];
	//abre e ler um arquivo onde esta cadastrado todos os produtos
	FILE *file;
	file = fopen("produtos.txt", "r");
	                    
	int i = 0;
	while(i <= 59){
		fscanf(file, "%d%s%f", &produto[i].id, produto[i].nome, &produto[i].preco);
		i++;
	}
	fclose(file);
	
	char res = 0; //Resposta dos menu
	int runner = 0; // 0 CONTINUA / 1 PARA O PROGRAMA
	while(runner == 0){
		int qtd_produto = 0; //todo looping a quantidade zera para um novo item ser adicionado
		system("cls");// limpa a tela
		//printa menu principal
		menu(STRTAM,"Bem vindo! ao mercadinho do bom", "1 - Bebidas", "2 - Descartaveis","3 - Para os Pets","4 - Saudavel/Fitness",
		"5 - Limpeza","6 - Biscoitos e Salgadinhos","7 - Congelados"," "," ","0 - Finalizar Compra");
		//calcular valor em tempo real
		float total = 0;
		int j = 0;
		for(j = 0; j <= 60; j++){
			total = total + calcular_valor(produto[j].qtd, produto[j].preco);
		}
		printf(" Valor Total: R$%.2f", total);
		res = getch(); //Recebe a resposta
		switch(res){
			case '1'://Seção 01
				system("cls");// limpa a tela
				menu(STRTAM,"BEBIDAS", produto[0].nome, produto[1].nome, produto[2].nome, produto[3].nome,
				 produto[4].nome, produto[5].nome, produto[6].nome, produto[7].nome, produto[8].nome, "0 - voltar");
				printf(" Valor Total: R$%.2f", total);
				res = getch();
				switch(res){
					case '1':
						qtd_produto = pedir_qtd();
						produto[0].qtd = produto[0].qtd + qtd_produto;
						break;
					case '2':
						qtd_produto = pedir_qtd();
						produto[1].qtd = produto[1].qtd + qtd_produto;
						break;
					case '3':
						qtd_produto = pedir_qtd();
						produto[2].qtd = produto[2].qtd + qtd_produto;
						break;
					case '4':
						qtd_produto = pedir_qtd();
						produto[3].qtd = produto[3].qtd + qtd_produto;
						break;
					case '5':
						qtd_produto = pedir_qtd();
						produto[4].qtd = produto[4].qtd + qtd_produto;
						break;
					case '6':
						qtd_produto = pedir_qtd();
						produto[5].qtd = produto[5].qtd + qtd_produto;
						break;
					case '7':
						qtd_produto = pedir_qtd();
						produto[6].qtd = produto[6].qtd + qtd_produto;
						break;
					case '8':
						qtd_produto = pedir_qtd();
						produto[7].qtd = produto[7].qtd + qtd_produto;
						break;
					case '9':
						qtd_produto = pedir_qtd();
						produto[8].qtd = produto[8].qtd + qtd_produto;
						break;
					default:
						break;
				}
				break;//break 1
			case '2'://Seção 02
				system("cls");// limpa a tela
				menu(STRTAM,"DESCARTAVEIS", produto[9].nome, produto[10].nome, produto[11].nome, produto[12].nome,
				 produto[13].nome, produto[14].nome, "", "", "", "0 - voltar");
				printf(" Valor Total: R$%.2f", total);
				res = getch();
				switch(res){
					case '1':
						qtd_produto = pedir_qtd();
						produto[9].qtd = produto[9].qtd + qtd_produto;
						break;
					case '2':
						qtd_produto = pedir_qtd();
						produto[10].qtd = produto[10].qtd + qtd_produto;
						break;
					case '3':
						qtd_produto = pedir_qtd();
						produto[11].qtd = produto[11].qtd + qtd_produto;
						break;
					case '4':
						qtd_produto = pedir_qtd();
						produto[12].qtd = produto[12].qtd + qtd_produto;
						break;
					case '5':
						qtd_produto = pedir_qtd();
						produto[13].qtd = produto[13].qtd + qtd_produto;
						break;
					case '6':
						qtd_produto = pedir_qtd();
						produto[14].qtd = produto[14].qtd + qtd_produto;
						break;
					case '7':
						qtd_produto = pedir_qtd();
						produto[15].qtd = produto[15].qtd + qtd_produto;
						break;
					default:
						break;
				}
				break;//break 2
			case '3'://Seção 03
				system("cls");// limpa a tela
				menu(STRTAM,"Para Os Pets", produto[16].nome, produto[17].nome, produto[18].nome, produto[19].nome,
				 produto[20].nome, produto[21].nome, produto[22].nome, produto[23].nome, produto[24].nome, "0 - voltar");
				printf(" Valor Total: R$%.2f", total);
				res = getch();
				switch(res){
					case '1':
						qtd_produto = pedir_qtd();
						produto[16].qtd = produto[16].qtd + qtd_produto;
						break;
					case '2':
						qtd_produto = pedir_qtd();
						produto[17].qtd = produto[17].qtd + qtd_produto;
						break;
					case '3':
						qtd_produto = pedir_qtd();
						produto[18].qtd = produto[18].qtd + qtd_produto;
						break;
					case '4':
						qtd_produto = pedir_qtd();
						produto[19].qtd = produto[19].qtd + qtd_produto;
						break;
					case '5':
						qtd_produto = pedir_qtd();
						produto[20].qtd = produto[20].qtd + qtd_produto;
						break;
					case '6':
						qtd_produto = pedir_qtd();
						produto[21].qtd = produto[21].qtd + qtd_produto;
						break;
					case '7':
						qtd_produto = pedir_qtd();
						produto[22].qtd = produto[22].qtd + qtd_produto;
						break;
					case '8':
						qtd_produto = pedir_qtd();
						produto[23].qtd = produto[23].qtd + qtd_produto;
						break;
					case '9':
						qtd_produto = pedir_qtd();
						produto[24].qtd = produto[24].qtd + qtd_produto;
						break;
					default:
						break;
				}
				break;//break 3
			case '4'://Seção 04
				system("cls");// limpa a tela
				menu(STRTAM,"SAUDAVEL / FITNESS", produto[25].nome, produto[26].nome, produto[27].nome, produto[28].nome,
				 produto[29].nome, produto[30].nome, produto[31].nome, produto[32].nome, produto[33].nome, "0 - voltar");
				printf(" Valor Total: R$%.2f", total);
				res = getch();
				switch(res){
					case '1':
						qtd_produto = pedir_qtd();
						produto[25].qtd = produto[25].qtd + qtd_produto;
						break;
					case '2':
						qtd_produto = pedir_qtd();
						produto[26].qtd = produto[26].qtd + qtd_produto;
						break;
					case '3':
						qtd_produto = pedir_qtd();
						produto[27].qtd = produto[27].qtd + qtd_produto;
						break;
					case '4':
						qtd_produto = pedir_qtd();
						produto[28].qtd = produto[28].qtd + qtd_produto;
						break;
					case '5':
						qtd_produto = pedir_qtd();
						produto[29].qtd = produto[29].qtd + qtd_produto;
						break;
					case '6':
						qtd_produto = pedir_qtd();
						produto[30].qtd = produto[30].qtd + qtd_produto;
						break;
					case '7':
						qtd_produto = pedir_qtd();
						produto[31].qtd = produto[31].qtd + qtd_produto;
						break;
					case '8':
						qtd_produto = pedir_qtd();
						produto[32].qtd = produto[32].qtd + qtd_produto;
						break;
					case '9':
						qtd_produto = pedir_qtd();
						produto[33].qtd = produto[33].qtd + qtd_produto;
						break;
					default:
						break;
				}
				break;//break 4
			case '5'://Seção 05
				system("cls");// limpa a tela
				menu(STRTAM,"LIMPEZA", produto[34].nome, produto[35].nome, produto[36].nome, produto[37].nome,
				 produto[38].nome, produto[39].nome, produto[40].nome, "", "", "0 - voltar");
				printf(" Valor Total: R$%.2f", total);
				res = getch();
				switch(res){
					case '1':
						qtd_produto = pedir_qtd();
						produto[34].qtd = produto[34].qtd + qtd_produto;
						break;
					case '2':
						qtd_produto = pedir_qtd();
						produto[35].qtd = produto[35].qtd + qtd_produto;
						break;
					case '3':
						qtd_produto = pedir_qtd();
						produto[36].qtd = produto[36].qtd + qtd_produto;
						break;
					case '4':
						qtd_produto = pedir_qtd();
						produto[37].qtd = produto[37].qtd + qtd_produto;
						break;
					case '5':
						qtd_produto = pedir_qtd();
						produto[38].qtd = produto[38].qtd + qtd_produto;
						break;
					case '6':
						qtd_produto = pedir_qtd();
						produto[39].qtd = produto[39].qtd + qtd_produto;
						break;
					case '7':
						qtd_produto = pedir_qtd();
						produto[40].qtd = produto[40].qtd + qtd_produto;
						break;
					default:
						break;
				}
				break;//break 5	
			case '6'://Seção 06
				system("cls");// limpa a tela
				menu(STRTAM,"BISCOITOS E SALGADINHOS", produto[41].nome, produto[42].nome, produto[43].nome, produto[44].nome,
				 produto[45].nome, produto[46].nome, produto[47].nome, produto[48].nome, produto[49].nome, "0 - voltar");
				printf(" Valor Total: R$%.2f", total);
				res = getch();
				switch(res){
					case '1':
						qtd_produto = pedir_qtd();
						produto[41].qtd = produto[41].qtd + qtd_produto;
						break;
					case '2':
						qtd_produto = pedir_qtd();
						produto[42].qtd = produto[42].qtd + qtd_produto;
						break;
					case '3':
						qtd_produto = pedir_qtd();
						produto[43].qtd = produto[43].qtd + qtd_produto;
						break;
					case '4':
						qtd_produto = pedir_qtd();
						produto[44].qtd = produto[44].qtd + qtd_produto;
						break;
					case '5':
						qtd_produto = pedir_qtd();
						produto[45].qtd = produto[45].qtd + qtd_produto;
						break;
					case '6':
						qtd_produto = pedir_qtd();
						produto[46].qtd = produto[46].qtd + qtd_produto;
						break;
					case '7':
						qtd_produto = pedir_qtd();
						produto[47].qtd = produto[47].qtd + qtd_produto;
						break;
					case '8':
						qtd_produto = pedir_qtd();
						produto[48].qtd = produto[48].qtd + qtd_produto;
						break;
					case '9':
						qtd_produto = pedir_qtd();
						produto[49].qtd = produto[49].qtd + qtd_produto;
						break;
					default:
						break;
				}
				break;//break 6
			case '7'://Seção 07
				system("cls");// limpa a tela
				menu(STRTAM,"CONGELADOS", produto[50].nome, produto[51].nome, produto[52].nome, produto[53].nome,
				 produto[54].nome, produto[55].nome, produto[56].nome, produto[57].nome, produto[58].nome, "0 - voltar");
				printf(" Valor Total: R$%.2f", total);
				res = getch();
				switch(res){
					case '1':
						qtd_produto = pedir_qtd();
						produto[50].qtd = produto[50].qtd + qtd_produto;
						break;
					case '2':
						qtd_produto = pedir_qtd();
						produto[51].qtd = produto[51].qtd + qtd_produto;
						break;
					case '3':
						qtd_produto = pedir_qtd();
						produto[52].qtd = produto[52].qtd + qtd_produto;
						break;
					case '4':
						qtd_produto = pedir_qtd();
						produto[53].qtd = produto[53].qtd + qtd_produto;
						break;
					case '5':
						qtd_produto = pedir_qtd();
						produto[54].qtd = produto[54].qtd + qtd_produto;
						break;
					case '6':
						qtd_produto = pedir_qtd();
						produto[55].qtd = produto[55].qtd + qtd_produto;
						break;
					case '7':
						qtd_produto = pedir_qtd();
						produto[56].qtd = produto[56].qtd + qtd_produto;
						break;
					case '8':
						qtd_produto = pedir_qtd();
						produto[57].qtd = produto[57].qtd + qtd_produto;
						break;
					case '9':
						qtd_produto = pedir_qtd();
						produto[58].qtd = produto[58].qtd + qtd_produto;
						break;
					default:
						break;
				}
				break;//break 7
			case'0'://finalizando compra
				printf("\n");
				printf("\n");
				printf("Voce deseja finalizar a compra?[s/n]");
				res = getch();
				if(res == 's' or res == 'S'){//para evitar problemas de maiusculo e minusculo
					runner = 1;//quebra o while
				}
				else{
					runner = 0;
				}
					break;
		}
		//fim switch case
}	
	system("cls");// limpa a tela
	carregar("Finalizando Pedido, aguarde"); // tela de carregamento
	
	//calculador de valor total
	float total = 0;
	int j = 0;
		for(j = 0; j <= 60; j++){
		total = total + calcular_valor(produto[j].qtd, produto[j].preco);
		}
	if(total == 0){//se o total das compras for igual a 0 o programa finaliza aqui
		printf("Pedido Cancelado");
		exit(0);//finaliza o programa
	}
	
	//Mini cadastro de informações pessoais
	interface_header();
	interface_item(STRTAM,"Informacoes Pessoais");
	interface_footer();
	
	printf("\n");
	gets(nome);
	printf(" Digite seu nome e Sobrenome: ");
	gets(nome);
	printf(" Digite seu endereco: ");
	gets(endereco);
	printf(" Digite seu numero: ");
	gets(telefone);

	system("cls");//Clear Screen
	carregar("Cadastrando dados, aguarde"); // tela de carregamento
	
	char forma_de_pagamento[30];//seleciona a forma de pagamento
	menu(STRTAM,"SELECIONE A FORMA DE PAGAMENTO", "1-PIX", "2-CARTAO DE CREDITO", "3-CARTAO DE DEBITO", "4-DINHEIRO",
		"", "", "", "", "", "");
	printf(" Valor Total: R$%.2f \n", total);//valor total
	res = getch();
	if(res == '1'){//declara a variavel forma_de_pagamento, pela forma de pagamento selecionado
		strcpy(forma_de_pagamento, "PIX");
	}
	else if(res == '2'){
		strcpy(forma_de_pagamento, "CARTAO DE CREDITO");
	}
	else if(res == '3'){
		strcpy(forma_de_pagamento, "CARTAO DE DEBITO");
	}
	else if(res == '4'){
		strcpy(forma_de_pagamento, "DINHEIRO");
	}				 
	

	system("cls");// limpa a tela
	carregar("Gerando Pedido"); // tela de carregamento
	
	interface_header();
	interface_item(STRTAM,"Finalizar compra!");
	interface_footer();
	printf(" INFORMACOES DO COMPRADOR: \n");
	printf("   Nome: %s \n", nome);// mostra nome cadastrado
	printf("   Endereco: %s \n", endereco);//mostra endereço cadastrado
	printf("   Telefone: %s \n", telefone);//mostra telefone cadastrado
	printf("\n");
	printf(" INFORMACOES DO PEDIDO:: \n");
	srand(total);//ira alterar a seed de valor aleatorio
	int n_pedido = rand();//gera um numero aleatorio
	printf(" Numero do Pedido: #%d \n", n_pedido);//mostra o id do pedido
	printf("   FORMA DE PAGAMENTO: %s \n", forma_de_pagamento);//mostra a forma de pagamento escolhida
	printf("   Valor frete R$10,00 \n");//valor do frete
	printf("   Valor compras: R$%.2f \n", total);//valor das compras
	printf("   Valor final: R$%.2f \n", total + 10.00);//valor frete + compras
	printf("\n");
	printf(" CONFIRMAR PEDIDO: [s/n]");//pede confirmação do pedido
	res = getch();
	if(res == 's' or res == 'S'){
		system("cls");// limpa a tela
		carregar("Aguardando confirmacao da Loja"); // tela de carregamento
		system("cls");//Clear Screen
		printf("PEDIDO COMFIRMADO!");
	}
	else if(res == 'n' or res == 'N'){
		system("cls");// limpa a tela
		carregar("Cancelando Pedido"); // tela de carregamento
		system("cls");//Clear Screen
		printf("PEDIDO CANCELADO");
	}


	//system("cls");//Clear Screen
	//int i = 0;
	//for(i = 0; i <= 300; i++){
	//	printf("%d - %c \n", i, i);
	//}	
}
