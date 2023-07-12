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
void inserirProduto(produto** dados);//char *nome, unsigned int quantidade, double preco
void aumentaEstoque(produto *a, unsigned long long int quantidade);
void modificaPreco(produto *a, double valor);
void realizaVenda();
void consuntaEstoque();
void consultaSaldo();
void finalizaDia();

// usaremos arquivos (binários)

produto *alocaProduto(unsigned int estoque){
    produto *prod;

    if((prod = (produto *) malloc(estoque * sizeof(produto))) == NULL){
        printf("Erro ao alocar memória");
        exit (1);
    }
//precisa tambem realocar dinâmicamente o vetor de produtos
    return prod; 
}

void inserirProduto(produto** dados,unsigned int qtd/char *nome, unsigned int quantidade, double preco/){ 
    //tem que passar o ponteiro do produto
    int t=qtd;
    (dados)=(produto)realloc(*dados,(t+1)*sizeof(produto));
    scanf("%s %llu %lf", (*dados)[t].nomeProd, &((*dados)[t].quantidade), &((*dados)[t].preco));    
}   

void aumentaEstoque(produto *a, unsigned long long int quantidade){            
    *a.quantidade = *a.quantidade + quantidade;//derreferenciar
}

void modificaPreco(produto *a, double valor){
    *a.preco = valor;//derreferenciae?
}

void realizaVenda(int codigo){
    dados[codigo].quantidade--;
}

void realizaVenda(int codigo){

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
   
    fp = fopen("ArquivoEstoque.txt","r");  

    if(fp!=NULL){
        fscanf(fp,"%u",&qtdEstoque);
        fscanf(fp,"%lld",&saldo);

        for(int i=0;i<qtdEstoque;i++){
             fscanf(fp," %s",dados[i].nomeProd);
             fscanf(fp," %llu",&dados[i].quantidade); 
             fscanf(fp," %lf",&dados[i].preco);
        }
       fclose(fp);
      fp= fopen("ArquivoEstoque.txt","w");
         if(fp==NULL){
           printf("erro na abertura do arquivo");
           exit(1);
         }
            
    } else{
        fp=fopen("ArquivoEstoque.txt","w");
        scanf("%u %lld", &qtdEstoque, &saldo);
    }
     
    inserirProduto(&dados,qtdEstoque);
// falta adicionar os codigos dos produtos
    while(1){
        scanf("%s", id);

        if(id == "IP"){
            dados = alocaProduto(qtdEstoque);
            qtdEstoque++;
            if(qtdEstoque > 0){
                for(int i = 0; i < qtdEstoque; i++){
                    
                    dados[i] = inserirProduto(dados[i].nomeProd, dados[i].);
                }
            } else{
                scanf("%s %u %lf", );
            }

        } else if(id == "AE"){
            

        } else if(id == "MP"){
            


        } else if(id == "VE"){
            int codigo;

            while(scanf("%d", codigo) != -1){
                double total = 0;
                realizaVenda(codigo);
                printf("%s %.2lf\n", dados[codigo].nomeProd, dados[codigo].preco)
                total += dados[codigo].preco.
            }
            saldo += total;
            printf("%.2lf", total);
            printf("\n--------------------------------------------------");
        } else if(id == "CE"){
            for(int i = 0; i < qtdEstoque; i++){
                printf("%d %s %llu\n", /*codigo*/, dados[i].nomeProd, dados[i].quantidade);
            }
            printf("\n--------------------------------------------------");
        } else if(id == "CS"){
            printf("Saldo: %.2lf", saldo);
            printf("\n--------------------------------------------------");
        } else if(id == "FE"){
            // usar arquivos
            finalizaDia();
        }
    }

    fprintf(fp,"%u\n",qtdEstoque);
    fprintf(fp,"%lld\n",saldo);
    
    fclose(fp);
    return 0;
}