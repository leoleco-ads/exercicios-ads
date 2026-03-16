#include <stdio.h>

#define TAMANHO_ACERVO 20  //Definição de quantidade máxima de livros para cadastro.

struct Livro { //Aqui criaremos a estrutura do livro e colocaremos a quantidade máxima de caracteres permitido para o título, o autor, a área, a editora e definiremos "codigo" e "ano" como números inteiros.
    int codigo;
    char titulo[50];
    char autor[30];
    char area[30];
    int ano;
    char editora[30];
};

//Aqui criaremos as assinaturas das funções que utilizaremos mais tarde//
void cadastrarLivros(struct Livro acervo[], int *quantidade); //Cadastro
void imprimirLivros(struct Livro acervo[], int quantidade); //Impressão
void pesquisarLivro(struct Livro acervo[], int quantidade); //Pesquisa
void ordenarLivros(struct Livro acervo[], int quantidade); //Ordenação

int main() { 
    struct Livro acervo[TAMANHO_ACERVO];
    int opcao;
    int quantidade = 0;

    do {
        printf("\nBem vindo ao menu principal!\n");
        printf("1 - Cadastrar livros\n");
        printf("2 - Imprimir todos os livros\n");
        printf("3 - Pesquisar livro por codigo\n");
        printf("4 - Ordenar livros por ano de publicacao\n");
        printf("5 - Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin); 

        switch(opcao) {
            case 1: 
            cadastrarLivros(acervo, &quantidade); 
            break;
            
            case 2: 
            imprimirLivros(acervo, quantidade); 
            break;
            
            case 3: 
            pesquisarLivro(acervo, quantidade); 
            break;

            case 4: 
            ordenarLivros(acervo, quantidade); 
            break;
            
            case 5: 
            printf("Encerrando o programa...\n"); 
            break;
            
            default: printf("Opcao invalida!\n");
        }

    } while(opcao != 5);

    return 0;
}
//Função de cadastrar os livros//
void cadastrarLivros(struct Livro acervo[], int *quantidade) {
    int qtdCadastrar;

    if (*quantidade == TAMANHO_ACERVO) {
        printf("\nAcervo cheio! Nao e possivel cadastrar mais livros.\n");
        return;
    }

    printf("\nQuantos livros deseja cadastrar? ");
    scanf("%d", &qtdCadastrar);

    if (*quantidade + qtdCadastrar > TAMANHO_ACERVO) {
        printf("Erro! O acervo suporta no maximo %d livros.\n", TAMANHO_ACERVO);
        return;
    }

    for (int i = 0; i < qtdCadastrar; i++) {
        printf("\nLivro %d:\n", *quantidade + 1);

        printf("Codigo: ");
        scanf("%d", &acervo[*quantidade].codigo);

        printf("Titulo: ");
        scanf(" %[^\n]", acervo[*quantidade].titulo);

        printf("Autor: ");
        scanf(" %[^\n]", acervo[*quantidade].autor);

        printf("Area: ");
        scanf(" %[^\n]", acervo[*quantidade].area);

        printf("Ano: ");
        scanf("%d", &acervo[*quantidade].ano);

        printf("Editora: ");
        scanf(" %[^\n]", acervo[*quantidade].editora);

        (*quantidade)++;
    }
}

// Função de impressão
void imprimirLivros(struct Livro acervo[], int quantidade) {
    if (quantidade == 0) {
        printf("\nNenhum livro cadastrado.\n");
        return;
    }

    printf("\n---- LISTA DE LIVROS ----\n");

    for (int i = 0; i < quantidade; i++) {
        printf("\nLivro %d\n", i + 1);
        printf("Codigo: %d\n", acervo[i].codigo);
        printf("Titulo: %s\n", acervo[i].titulo);
        printf("Autor: %s\n", acervo[i].autor);
        printf("Area: %s\n", acervo[i].area);
        printf("Ano: %d\n", acervo[i].ano);
        printf("Editora: %s\n", acervo[i].editora);
    }
}

// Função de pesquisa
void pesquisarLivro(struct Livro acervo[], int quantidade) {
    int codigoBusca;
    int encontrado = 0;

    if (quantidade == 0) {
        printf("\nNenhum livro cadastrado.\n");
        return;
    }

    printf("\nDigite o codigo do livro: ");
    scanf("%d", &codigoBusca);

    for (int i = 0; i < quantidade; i++) {
        if (acervo[i].codigo == codigoBusca) {
            printf("\n---- LIVRO ENCONTRADO ----\n");
            printf("Codigo: %d\n", acervo[i].codigo);
            printf("Titulo: %s\n", acervo[i].titulo);
            printf("Autor: %s\n", acervo[i].autor);
            printf("Area: %s\n", acervo[i].area);
            printf("Ano: %d\n", acervo[i].ano);
            printf("Editora: %s\n", acervo[i].editora);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nLivro NAO encontrado!\n");
    }
}

// Função de ordenação
void ordenarLivros(struct Livro acervo[], int quantidade) {
    struct Livro temp;

    if (quantidade < 2) {
        printf("\nNao ha livros suficientes para ordenar.\n");
        return;
    }

    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - 1 - i; j++) {
            if (acervo[j].ano > acervo[j + 1].ano) {
                temp = acervo[j];
                acervo[j] = acervo[j + 1];
                acervo[j + 1] = temp;
            }
        }
    }

    printf("\nLivros ordenados por ano com sucesso!\n");
}
