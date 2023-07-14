/*
Trabalho feito para a disciplina Introdução a Ciência da Computação 1
Professor: Rudinei Goulart
Integrantes: Antônio Carlos de Almeida Micheli Neto NUMUSP: 14559013
             Gabriel de Andrade Abreu NUMUSP: 14571362
             Guilherme Antonio Costa Bandeira NUMUSP: 14575620 
*/

#include <stdlib.h> //biblioteca incluida para fazer a alocação dinamica dos vetores
#include <stdio.h>// biblioteca básica de input e output do C
#include <string.h>// incluimos essa biblioteca para poder fazer a checagem do scanf com strcmp

struct Prod{
    char nomeProd[100];
    long long int qtd; 
    double preco;
};//struct feita para guardar as informnações dos produtos de forma eficiente, todas as interações com um produto envolverão essa struct

typedef struct Prod produto;// definimos produto como do tipo struct prod para poder usar essa struct deforma simples

// Protótipos das funções

void inserirProduto(produto **dados, int *tam);// função que insere um novo produto no sistema
void aumentaEstoque(produto *dados, unsigned int codigo, long long int quantidade);// função que aumenta a quantidade de um produto já existente no estoque
void modificaPreco(produto *dados);// função que modifica o preço de um produto já existente
double realizaVenda(produto *dados, unsigned int codigo);// função para quando se realiza uma venda
void consultaEstoque(produto *dados, int qtdEstoque);// função que realiza uma consulta as quantidades de cada produto existente
void consultaSaldo(double saldo);// função que consulta o saldo total
void finalizaDia(FILE **fp, int qtdEstoque, double saldo, produto *dados);// função que encerra o código e salva as informações


void inserirProduto(produto **dados, int *tam){// recebe o vetor dados para modificar e o numero de produtos novos que ja existem
    *dados = (produto *)realloc(*dados, ((*tam) + 1) * sizeof(produto));// realocação de memória para caber o novo produto que será inserido
 
    scanf("%s %lld %lf", (*dados)[*tam].nomeProd, &((*dados)[*tam]).qtd, &(*dados)[*tam].preco);// leitura do novo produto
    (*tam)++;// aumento da variavel tamanho com o novo produto incluido
}

void aumentaEstoque(produto *dados, unsigned int codigo, long long int quantidade){// recebe o vetor dados, o codigo do produto que é sua posição no vetor, e a quantidade a ser adicionada
    dados[codigo].qtd += quantidade;// a variavel quantidade da struct é alterada
}

void modificaPreco(produto *dados) {// recebe o vetor dados
    int codigo; 
    double preco;
    scanf("%d %lf", &codigo, &preco);// leitura do código do produto e o novo preço
    dados[codigo].preco = preco;// altera a variavel preço da struct do determinado produto
}

double realizaVenda(produto *dados, unsigned int codigo){// recebe o vetor dados e o codigo do produto a ser vendido
    if(!dados[codigo].qtd){// checagem da quantidade do produto para possibilitar a venda
        return 0.00;// saída imediata da função
    }
    dados[codigo].qtd--;// redução da quantidade do produto pois está sendo vendido 
    printf("%s %.2lf\n", dados[codigo].nomeProd, dados[codigo].preco);// print do produto, seu codigo e o preço da venda
    return dados[codigo].preco;// return da função, retorna o preço do produto
}

void consultaEstoque(produto *dados, int qtdEstoque){// recebe o vetor dados e a quantidade geral do estoque
    
    for (int i = 0; i < qtdEstoque; i++) {
        printf("%d %s %lld\n", i, dados[i].nomeProd, dados[i].qtd);
    }// loop que percorre o vetor e checa todos os produtos do estoque

    for(int i = 0; i < 50; i++){
        printf("-");// print padrão de encerramento da função
    }
    printf("\n");
}

void consultaSaldo(double saldo){// recebe apenas o saldo total
    printf("Saldo: %.2lf\n", saldo);// print do saldo
    for(int i = 0; i < 50; i++){
        printf("-");// print padrão de encerramento da função
    }
    printf("\n");
}

void finalizaDia(FILE **fp, int qtdEstoque, double saldo, produto *dados){// recebe o arquivo relacionado ao programa, o estoque, o saldo e o vetor dos produtos, todos atualizados
 
    if ((*fp = fopen("arquivo_estoque", "w")) == NULL) {// checagem de erro ao abrir o arquivo
        printf("Erro na abertura do arquivo");
        exit(1);// saída forçada do programa
    }
 
    fprintf(*fp, "%d\n", qtdEstoque);// escreve no arquivo a quantidade do estoque
    fprintf(*fp, "%.2lf\n", saldo);// escreve no arquivo o saldo atual
 
    for (int i = 0; i < qtdEstoque; i++) {
        fprintf(*fp, "%s %lld %.2lf\n", dados[i].nomeProd,  dados[i].qtd, dados[i].preco);// loop que escreve todos os produtos do estoque
    }
 
    fclose(*fp);// fechamento do arquivo
}

int main(void){

    FILE *fp; //arquivo que guardará as informações do sitema, o saldo e os produtos que temos
    int tam_estoque = 0;//variável que receberá a quantidade do estoque
    double saldo = 0.00;// variável que receberá o saldo
    produto *dados;// vetor de struct que receberá todos os produtos com suas respectivas informações 

    dados = NULL;

    if((fp=fopen("arquivo_estoque", "rb")) == NULL){ //conferindo se o arquivo já possui informções de dias anteriores
        // caso não tenha o usuário deverá informar o estoque e o saldo
        scanf("%d %lf", &tam_estoque, &saldo);// leitura do estoque e do saldo     
        tam_estoque = 0; 
    }

    else{//caso em que tenham informações uteis no arquivo
        
        fscanf(fp, "%d", &tam_estoque);//leitura no arquivo do estoque
        fscanf(fp, "%lf", &saldo);// leitura no arquivo do saldo
        dados = (produto *)calloc(tam_estoque, sizeof(produto));// alocação de memória no vetor dados para receber os produtos que estarão no arquivo

        for(int i = 0 ; i < tam_estoque ; i++){
            fscanf(fp, " %s %lld %lf", dados[i].nomeProd, &(dados[i].qtd), &(dados[i].preco));
        }// loop que percorre o arquivo lendo os produtos e armazenando no vetor dados

        fclose(fp);// fechamento do arquivo
    }
// abertura do programa para interação com o usuário, agora os comandos podem ser executados
    while (1) {
        
        char id[3];// variável que vai receber a string do nome do comando que o usario deseja executar, tamanho 3 pois todos os comandos são de 2 letras
        scanf("%s", id);// leitura do comando
 // checagens de todos os comandos
        if (strcmp(id, "IP") == 0) {// caso em que a função é para inserir um produto
            inserirProduto(&dados, &tam_estoque);
        } else if (strcmp(id, "AE") == 0) {// caso em que a função é para aumentar o estoque de um produto
            unsigned int codigo;
            long long int quantidade;
            scanf("%u %lld", &codigo, &quantidade);
            aumentaEstoque(dados, codigo, quantidade);
        } else if (strcmp(id, "MP") == 0) {// caso em que a função é para modificar o preço de um produto
            modificaPreco(dados);
        } else if (strcmp(id, "VE") == 0) {// caso em que a função é para realizar uma venda
            int codigo; 
            double total = 0.00;               
 
            while (1) {// loop necessário para se realizar sucessivas vendas
                scanf("%u", &codigo);// leitura do código do produto que está sendo vendido, com o código o sistema sabe o preço da venda e a quantidade em estoque para o produto
                if(codigo == -1){// o loop encerra quando se digita -1
                    break;// saída do loop
                }

                if(dados[codigo].qtd != 0){// checagem da quantidade em estoque
                    saldo += dados[codigo].preco;
                    total += realizaVenda(dados, codigo);
                }// se tiver o produto em estoque o valor da venda é adicionado no saldo e a função venda é executada, se não estiver disponivel a função de venda não é executada
            }
 
            printf("Total: %.2lf\n", total);// escrita do valor total da venda

            for(int i = 0; i < 50; i++){
                printf("-");// print padrão do fim da função
            }
            printf("\n");
        } else if (strcmp(id, "CE") == 0) {// caso em que a função é para consultar o estoque
            consultaEstoque(dados, tam_estoque);
        } else if (strcmp(id, "CS") == 0) {// caso em que a função é para consultar o saldo
            consultaSaldo(saldo);
        } else if (strcmp(id, "FE") == 0) {// caso em que a função é para finalizar o dia e encerrar o programa
            finalizaDia(&fp, tam_estoque, saldo, dados);
            break;
        }
    }

    if (dados != NULL) {//checagem se o vetor dados foi alterado
        free(dados);// liberando a memória que foi alocada
        dados = NULL;
    }
 
    return 0;// fim do programa
}