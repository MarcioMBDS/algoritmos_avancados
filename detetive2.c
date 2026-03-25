#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================================
// ======================= BST (PISTAS) ========================
// ============================================================

struct NoBST {
    char pista[100];
    struct NoBST* esquerda;
    struct NoBST* direita;
};

struct NoBST* inserirPista(struct NoBST* raiz, const char* pista) {
    if (raiz == NULL) {
        struct NoBST* novo = (struct NoBST*) malloc(sizeof(struct NoBST));
        strcpy(novo->pista, pista);
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }

    if (strcmp(pista, raiz->pista) < 0)
        raiz->esquerda = inserirPista(raiz->esquerda, pista);
    else
        raiz->direita = inserirPista(raiz->direita, pista);

    return raiz;
}

void exibirPistas(struct NoBST* raiz) {
    if (raiz != NULL) {
        exibirPistas(raiz->esquerda);
        printf("- %s\n", raiz->pista);
        exibirPistas(raiz->direita);
    }
}

// ============================================================
// ======================= SALAS (ÁRVORE) ======================
// ============================================================

struct Sala {
    char nome[100];
    char pista[100];
    struct Sala* esquerda;
    struct Sala* direita;
};

struct Sala* criarSala(const char* nome, const char* pista) {
    struct Sala* nova = (struct Sala*) malloc(sizeof(struct Sala));
    strcpy(nova->nome, nome);
    strcpy(nova->pista, pista);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// ============================================================
// ======================= EXPLORAÇÃO ==========================
// ============================================================

void explorarSalasComPistas(struct Sala* atual, struct NoBST** arvorePistas) {
    char opcao;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);

        if (strlen(atual->pista) > 0) {
            printf("Pista encontrada: %s\n", atual->pista);
            *arvorePistas = inserirPista(*arvorePistas, atual->pista);
        }

        printf("Escolha: (e) esquerda, (d) direita, (s) sair: ");
        scanf(" %c", &opcao);

        if (opcao == 'e') {
            atual = atual->esquerda;
        } else if (opcao == 'd') {
            atual = atual->direita;
        } else if (opcao == 's') {
            break;
        } else {
            printf("Opção inválida!\n");
        }
    }
}

// ============================================================
// ========================= MAIN ==============================
// ============================================================

int main() {

    // ---------- Criando mapa da mansão ----------
    struct Sala* hall = criarSala("Hall de Entrada", "");
    struct Sala* salaEstar = criarSala("Sala de Estar", "Pegadas de Lama");
    struct Sala* cozinha = criarSala("Cozinha", "Chave perdida");
    struct Sala* quarto = criarSala("Quarto", "Lencol manchado");
    struct Sala* escritorio = criarSala("Escritorio", "Livro com pagina faltando");
    struct Sala* porao = criarSala("Porao", "Gaveta perdida");

    // Ligando salas (árvore binária)
    hall->esquerda = salaEstar;
    hall->direita = cozinha;

    salaEstar->esquerda = quarto;
    salaEstar->direita = escritorio;

    cozinha->direita = porao;

    // ---------- BST de pistas ----------
    struct NoBST* pistas = NULL;

    // ---------- Exploração ----------
    explorarSalasComPistas(hall, &pistas);

    // ---------- Resultado ----------
    printf("\n=== PISTAS COLETADAS (ORDENADAS) ===\n");
    exibirPistas(pistas);

    return 0;
}
