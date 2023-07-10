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
void aumentaEstoque();
void modificaPreco();
void realizaVenda();
void consuntaEstoque();
void consultaSaldo();
void finalizaDia();

// usaremos arquivos

void adicionaItens(produtos *a){
    scanf("%s %llu %lf", a.nomeProd, a.quantidade, a.preco);
}

void aumentaEstoque(){

}

int main(void){

    // etapas:
    // 1
    // 2
    // 3
    // 4
    // 5
    // 6
    // 7

    return 0;
}