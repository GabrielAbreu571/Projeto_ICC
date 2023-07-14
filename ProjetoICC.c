/*
Trabalho feito para a disciplina Introdução a Ciência da Computação 1
Professor: Rudinei Goulart
Integrantes: Gabriel de Andrade Abreu NUMUSP: 14571362
             Guilherme Antonio Costa Bandeira NUMUSP: 14575620 
             Antônio Carlos de Almeida Micheli Neto NUMUSP: 14559013
*/

#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 

struct Prod{
    char nomeProd[100];
    long long int qtd; 
    double preco;
};

typedef struct Prod produto;

// Protótipos das funções

void inserirProduto(produto **dados, int *tam);
void aumentaEstoque(produto *dados, unsigned int codigo, long long int quantidade);
void modificaPreco(produto *dados);
double realizaVenda(produto *dados, unsigned int codigo);
void consultaEstoque(produto *dados, int qtdEstoque);
void consultaSaldo(double saldo);
void finalizaDia(FILE **fp, int qtdEstoque, double saldo, produto *dados);

// explicar o que cada função faz
//adicionar comentários em cada função

void inserirProduto(produto **dados, int *tam){
    *dados = (produto *)realloc(*dados, ((*tam) + 1) * sizeof(produto));
 
    scanf("%s %lld %lf", (*dados)[*tam].nomeProd, &((*dados)[*tam]).qtd, &(*dados)[*tam].preco);
    (*tam)++;
}

void aumentaEstoque(produto *dados, unsigned int codigo, long long int quantidade){
    dados[codigo].qtd += quantidade;
}

void modificaPreco(produto *dados) {
    int codigo; double preco;
    scanf("%d %lf", &codigo, &preco);
    dados[codigo].preco = preco;
}

double realizaVenda(produto *dados, unsigned int codigo){
    if(!dados[codigo].qtd) return 0.00;
    dados[codigo].qtd--; 
    printf("%s %.2lf\n", dados[codigo].nomeProd, dados[codigo].preco);
    return dados[codigo].preco;
}

void consultaEstoque(produto *dados, int qtdEstoque){
    
    for (int i = 0; i < qtdEstoque; i++) {
        printf("%d %s %lld\n", i, dados[i].nomeProd, dados[i].qtd);
    }

    for(int i = 0; i < 50; i++){
        printf("-");
    }
    printf("\n");
}

void consultaSaldo(double saldo){
    printf("Saldo: %.2lf\n", saldo);
    for(int i = 0; i < 50; i++){
        printf("-");
    }
    printf("\n");
}

void finalizaDia(FILE **fp, int qtdEstoque, double saldo, produto *dados){
 
    if ((*fp = fopen("arquivo_estoque", "w")) == NULL) {
        printf("Erro na abertura do arquivo");
        exit(1);
    }
 
    fprintf(*fp, "%d\n", qtdEstoque);
    fprintf(*fp, "%.2lf\n", saldo);
 
    for (int i = 0; i < qtdEstoque; i++) {
        fprintf(*fp, "%s %lld %.2lf\n", dados[i].nomeProd,  dados[i].qtd, dados[i].preco);
    }
 
    fclose(*fp);
}

int main(void){

    FILE *fp; 
    int tam_estoque = 0;
    double saldo = 0.00;
    produto *dados; 

    dados = NULL;

    if((fp=fopen("arquivo_estoque", "rb")) == NULL){ 
        // Primeiro dia 
        scanf("%d %lf", &tam_estoque, &saldo);     
        tam_estoque = 0; 
    }

    else{
        
        fscanf(fp, "%d", &tam_estoque);
        fscanf(fp, "%lf", &saldo);
        dados = (produto *)calloc(tam_estoque, sizeof(produto));

        for(int i = 0 ; i < tam_estoque ; i++){
            fscanf(fp, " %s %lld %lf", dados[i].nomeProd, &(dados[i].qtd), &(dados[i].preco));
        }

        fclose(fp);
    }

    while (1) {
        
        char id[3]; 
        scanf("%s", id);
 
        if (strcmp(id, "IP") == 0) {
            inserirProduto(&dados, &tam_estoque);
        } else if (strcmp(id, "AE") == 0) {
            unsigned int codigo;
            long long int quantidade;
            scanf("%u %lld", &codigo, &quantidade);
            aumentaEstoque(dados, codigo, quantidade);
        } else if (strcmp(id, "MP") == 0) {
            modificaPreco(dados);
        } else if (strcmp(id, "VE") == 0) {
            int codigo; 
            double total = 0.00;               
 
            while (1) {
                scanf("%u", &codigo);
                if(codigo == -1){
                    break;
                }

                if(dados[codigo].qtd != 0){ 
                    saldo += dados[codigo].preco;
                    total += realizaVenda(dados, codigo);
                }
            }
 
            printf("Total: %.2lf\n", total);

            for(int i = 0; i < 50; i++){
                printf("-");
            }
            printf("\n");
        } else if (strcmp(id, "CE") == 0) {
            consultaEstoque(dados, tam_estoque);
        } else if (strcmp(id, "CS") == 0) {
            consultaSaldo(saldo);
        } else if (strcmp(id, "FE") == 0) {
            finalizaDia(&fp, tam_estoque, saldo, dados);
            break;
        }
    }

    if (dados != NULL) {
        free(dados);
        dados = NULL;
    }
 
    return 0;
}