#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------------------------------------------------------
// Estrutura da sala (nó da árvore binária)
// ------------------------------------------------------------
struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
};

// ------------------------------------------------------------
// Função: criarSala
// Cria uma nova sala dinamicamente
// ------------------------------------------------------------
struct Sala* criarSala(char* nome) {
    struct Sala* nova = (struct Sala*) malloc(sizeof(struct Sala));

    if (nova == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;

    return nova;
}

// ------------------------------------------------------------
// Função: explorarSalas
// Permite ao jogador navegar pela mansão
// ------------------------------------------------------------
void explorarSalas(struct Sala* atual) {
    char opcao;

    while (atual != NULL) {
        printf("\n📍 Você está em: %s\n", atual->nome);

        // Verifica se chegou a um nó folha
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("🏁 Você chegou a um cômodo final!\n");
            break;
        }

        printf("\nEscolha um caminho:\n");
        printf("[e] Esquerda\n");
        printf("[d] Direita\n");
        printf("[s] Sair\n");
        printf("Opção: ");

        scanf(" %c", &opcao);

        if (opcao == 'e') {
            if (atual->esquerda != NULL) {
                atual = atual->esquerda;
            } else {
                printf("❌ Não há caminho à esquerda!\n");
            }
        }
        else if (opcao == 'd') {
            if (atual->direita != NULL) {
                atual = atual->direita;
            } else {
                printf("❌ Não há caminho à direita!\n");
            }
        }
        else if (opcao == 's') {
            printf("🚪 Saindo da mansão...\n");
            break;
        }
        else {
            printf("⚠️ Opção inválida!\n");
        }
    }
}

// ------------------------------------------------------------
// Função: liberarMemoria
// Libera toda a árvore da memória
// ------------------------------------------------------------
void liberarMemoria(struct Sala* raiz) {
    if (raiz != NULL) {
        liberarMemoria(raiz->esquerda);
        liberarMemoria(raiz->direita);
        free(raiz);
    }
}

// ------------------------------------------------------------
// Função principal
// Monta o mapa da mansão e inicia exploração
// ------------------------------------------------------------
int main() {

    // Montagem manual da árvore (mapa da mansão)
    struct Sala* raiz = criarSala("Hall de Entrada");

    raiz->esquerda = criarSala("Sala de Estar");
    raiz->direita = criarSala("Biblioteca");

    raiz->esquerda->esquerda = criarSala("Quarto");
    raiz->esquerda->direita = criarSala("Cozinha");

    raiz->direita->esquerda = criarSala("Escritorio");
    raiz->direita->direita = criarSala("Jardim");

    // Início da exploração
    printf("🔎 Bem-vindo ao Detective Quest!\n");
    printf("Explore a mansão e encontre pistas...\n");

    explorarSalas(raiz);

    // Libera memória ao final
    liberarMemoria(raiz);

    return 0;
}