#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Definindo a estrutura do produto
typedef struct {
    char nome[50];
    char categoria[50];
    int quantidade;
    float preco;
    char localizacao[50];
} Produto;

// Função para cadastrar um novo produto
void cadastrarProduto(Produto *produtos, int *quantidadeProdutos) {
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", produtos[*quantidadeProdutos].nome);
    printf("Digite a categoria do produto: ");
    scanf(" %[^\n]", produtos[*quantidadeProdutos].categoria);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &produtos[*quantidadeProdutos].quantidade);
    printf("Digite o preco do produto: ");
    scanf("%f", &produtos[*quantidadeProdutos].preco);
    printf("Digite a localizacao do produto: ");
    scanf(" %[^\n]", produtos[*quantidadeProdutos].localizacao);
    (*quantidadeProdutos)++;
}

// Função para atualizar o estoque de um produto

void atualizarEstoque(Produto *produtos, int quantidadeProdutos) {
    char nomeProduto[50];
    int quantidade;
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nomeProduto);
    for (int i = 0; i < quantidadeProdutos; i++) {
        if (strcmp(produtos[i].nome, nomeProduto) == 0) {
            printf("Digite a quantidade de produtos a ser adicionada ou removida (quantidade negativa): ");
            scanf("%d", &quantidade);
            produtos[i].quantidade += quantidade;
            return;
        }
    }
    printf("Produto nao encontrado\n");
}

// Função para rastrear a localização de um produto
void rastrearLocalizacao(Produto *produtos, int quantidadeProdutos) {
    char nomeProduto[50];
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nomeProduto);
    for (int i = 0; i < quantidadeProdutos; i++) {
        if (strcmp(produtos[i].nome, nomeProduto) == 0) {
            printf("Localizacao do produto: %s\n", produtos[i].localizacao);
            return;
        }
    }
    printf("Produto nao encontrado\n");
}

// Função para gerar relatórios sobre o estoque
void gerarRelatorios(Produto *produtos, int quantidadeProdutos) {
    int produtosBaixoEstoque = 0;
    int produtosExcessoEstoque = 0;
    int movimentacaoProdutos = 0;
    for (int i = 0; i < quantidadeProdutos; i++) {
        if (produtos[i].quantidade < 10) {
            produtosBaixoEstoque++;
        }
        if (produtos[i].quantidade > 20) {
            produtosExcessoEstoque++;
        }
        if (produtos[i].quantidade != 0) {
            movimentacaoProdutos++;
        }
    }
    printf("Produtos com estoque baixo: %d\n", produtosBaixoEstoque);
    printf("Produtos com excesso de estoque: %d\n", produtosExcessoEstoque);
    printf("Movimentacao de produtos: %d\n", movimentacaoProdutos);
}


int main() {
    Produto produtos[100];
    int quantidadeProdutos = 0;
    int opcao;
    do {
        printf("1 - Cadastrar produto\n");
        printf("2 - Atualizar estoque\n");
        printf("3 - Rastrear localizacao\n");
        printf("4 - Gerar relatorios\n");
        printf("5 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &quantidadeProdutos);
                break;
            case 2:
                atualizarEstoque(produtos, quantidadeProdutos);
                break;
            case 3:
                rastrearLocalizacao(produtos, quantidadeProdutos);
                break;
            case 4:
                gerarRelatorios(produtos, quantidadeProdutos);
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (opcao != 5);
    return 0;
}
