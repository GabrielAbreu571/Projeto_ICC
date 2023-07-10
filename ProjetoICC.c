/*
Trabalho feito para a disciplina: Introdução a Ciência da Computação 1
Professor: Rudinei Goulart
Integrantes: Gabriel de Andrade Abreu NUMUSP: 14571362
             Guilherme Antonio Costa Bandeira NUMUSP: 14575620 
             Antônio Carlos de Almeida Micheli Neto NUMUSP: 14559013
*/

#include <stdio.h>
#include <stdlib.h>

struct prod{
    char nomeProd[100]; 
    unsigned long long int quantidade;
    double preco;
};

typedef struct prod produto;

// Protótipos das funções

void adicionaItens(produtos *a);
void aumentaEstoque(unsigned int codigo, unsigned int quantidade);
void modificaPreco();
void realizaVenda();
void consuntaEstoque();
void consultaSaldo();
void finalizaDia();

// usaremos arquivos

produto *adicionaItens(unsigned int estoque;){
    produto *a;
    if((a = (produto *) malloc(estoque * sizeof(produto))) == NULL){
        printf("Erro ao alocar memória");
        exit (1);
    } 

    for(int i = 0; i < estoque; i++){
        scanf("%s %llu %lf", a[i].nomeProd, &(a[i].quantidade), &(a[i].preco));  
    }

    return a;
}

void aumentaEstoque(produto *a, unsigned long long int total){            
    a.quantidade = a.quantidade + total;

}

int main(void){
    unsigned int estoque;
    long long int saldo;
    FILE *fp;
    char ip[3]; 
    // etapas:
    // 1
    // 2
    if(fp = fopen()){

    } else{
        scanf("%u %lld", &estoque, &saldo);
        adicionaItens(estoque);
    }
    
    // 3
    // 4

    while(scanf("%s", id)){

    }
    // 5
    // 6
    // 7
    if(fclose){
        exit(1);
    }
    return 0;
}