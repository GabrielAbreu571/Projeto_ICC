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

produto *alocaProduto(unsigned int estoque);
void inserirProduto(char *nome, unsigned int quantidade, double preco);
void aumentaEstoque(produto *a, unsigned long long int quantidade);
void modificaPreco(produto *a, double valor);
void realizaVenda();
void consuntaEstoque();
void consultaSaldo();
void finalizaDia();

// usaremos arquivos

produto *alocaProduto(unsigned int estoque){
    produto *prod;

    if((prod = (produto *) malloc(estoque * sizeof(produto))) == NULL){
        printf("Erro ao alocar memória");
        exit (1);
    }

    return prod; 
}

void inserirProduto(char *nome, unsigned int quantidade, double preco){
    scanf("%s %llu %lf", a.nomeProd, &(a.quantidade), &(a.preco));    
}   

void aumentaEstoque(produto *a, unsigned long long int quantidade){            
    a.quantidade = a.quantidade + quantidade;
}

void modificaPreco(produto *a, double valor){
    a.preco = valor;
}

void finalizaDia(){
    // mexer com os arquivos
    exit(1);
}

int main(void){
    unsigned int qtdEstoque;
    long long int saldo;
    FILE *fp;
    char id[3]; 
    produto *dados;
 
    // etapas:
   
    if(fp = fopen()){

    } else if(!= NULL){
        scanf("%u %lld", &qtdEstoque, &saldo);
    } 

    while(1){
        scanf("%s", id);

        if(id == "IP"){
            dados = alocaProduto(qtdEstoque);

            if(qtdEstoque > 0){
                for(int i = 0; i < qtdEstoque; i++){
                    scanf("%s %u %lf", );
                    dados[i] = inserirProduto(dados[i].nomeProd, dados[i].)
                }
            } else{
                scanf("%s %u %lf", );
            }

        } else if(id == "AE"){
            scanf("%s %u %lf", );
        } else if(id == "MP"){
            scanf("%s %u %lf", );
        } else if(id == "VE"){
            int codigo;
            scanf("%s %u %lf", );

            while(scanf("%d", codigo) != -1){

            }

            printf("\n--------------------------------------------------");
        } else if(id == "CE"){
            
            printf("\n--------------------------------------------------");
        } else if(id == "CS"){
            
            printf("\n--------------------------------------------------");
        } else if(id == "FE"){
            // usar arquivos
            finalizaDia();
        }
    }
    
    // 3
    // 4
    // 5
    // 6
    // 7
    return 0;
}