#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 17

// ============================================================
// ======================= BST (PISTAS) ========================
// ============================================================

struct NoBST {
    char pista[100];
    struct NoBST* esquerda;
    struct NoBST* direita;
};

int existePista(struct NoBST* raiz, const char* pista) {
    if (raiz == NULL) return 0;

    int cmp = strcmp(pista, raiz->pista);

    if (cmp == 0) return 1;
    else if (cmp < 0) return existePista(raiz->esquerda, pista);
    else return existePista(raiz->direita, pista);
}

struct NoBST* inserirPista(struct NoBST* raiz, const char* pista) {
    if (raiz == NULL) {
        struct NoBST* novo = malloc(sizeof(struct NoBST));
        strcpy(novo->pista, pista);
        novo->esquerda = novo->direita = NULL;
        return novo;
    }

    int cmp = strcmp(pista, raiz->pista);

    if (cmp < 0)
        raiz->esquerda = inserirPista(raiz->esquerda, pista);
    else if (cmp > 0)
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
// ======================= HASH ================================
// ============================================================

typedef struct NodoHash {
    char pista[100];
    char suspeito[50];
    struct NodoHash* proximo;
} NodoHash;

NodoHash* tabela_hash[TAMANHO_TABELA];

int funcao_hash(const char* chave) {
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i] * (i + 1);
    }
    return hash % TAMANHO_TABELA;
}

int jaExisteHash(const char* pista) {
    int indice = funcao_hash(pista);
    NodoHash* atual = tabela_hash[indice];

    while (atual != NULL) {
        if (strcmp(atual->pista, pista) == 0)
            return 1;
        atual = atual->proximo;
    }
    return 0;
}

void inserirHash(const char* pista, const char* suspeito) {
    if (jaExisteHash(pista)) return;

    int indice = funcao_hash(pista);

    NodoHash* novo = malloc(sizeof(NodoHash));
    strcpy(novo->pista, pista);
    strcpy(novo->suspeito, suspeito);

    novo->proximo = tabela_hash[indice];
    tabela_hash[indice] = novo;
}

const char* buscarSuspeito(const char* pista) {
    int indice = funcao_hash(pista);
    NodoHash* atual = tabela_hash[indice]; // ✅ corrigido

    while (atual != NULL) {
        if (strcmp(atual->pista, pista) == 0)
            return atual->suspeito;
        atual = atual->proximo;
    }
    return NULL;
}

// ============================================================
// ======================= SALAS ===============================
// ============================================================

struct Sala {
    char nome[100];
    char pista[100];
    struct Sala* esquerda;
    struct Sala* direita;
};

struct Sala* criarSala(const char* nome, const char* pista) {
    struct Sala* nova = malloc(sizeof(struct Sala));
    strcpy(nova->nome, nome);
    strcpy(nova->pista, pista);
    nova->esquerda = nova->direita = NULL;
    return nova;
}

// ============================================================
// ======================= LÓGICA ==============================
// ============================================================

const char* descobrirSuspeito(const char* pista) {
    if (strcmp(pista, "Pegadas de Lama") == 0) return "Jardineiro";
    if (strcmp(pista, "Chave perdida") == 0) return "Mordomo";
    if (strcmp(pista, "Lencol manchado") == 0) return "Empregada";
    if (strcmp(pista, "Livro com pagina faltando") == 0) return "Professor";
    if (strcmp(pista, "Gaveta perdida") == 0) return "Mordomo";
    return "Desconhecido";
}

// ============================================================
// ======================= EXPLORAÇÃO ==========================
// ============================================================

void explorarSalas(struct Sala* atual, struct NoBST** pistas) {
    char opcao;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);

        if (strlen(atual->pista) > 0) {
            if (!existePista(*pistas, atual->pista)) {
                printf("Pista encontrada: %s\n", atual->pista);

                *pistas = inserirPista(*pistas, atual->pista);

                const char* suspeito = descobrirSuspeito(atual->pista);
                inserirHash(atual->pista, suspeito);
            } else {
                printf("Pista já coletada!\n");
            }
        }

        printf("(e) esquerda, (d) direita, (s) sair: ");
        scanf(" %c", &opcao);

        if (opcao == 'e') atual = atual->esquerda;
        else if (opcao == 'd') atual = atual->direita;
        else if (opcao == 's') break;
        else printf("Opção inválida!\n");
    }
}

// ============================================================
// ======================= CONTAGEM ============================
// ============================================================

int contarPistasSuspeito(struct NoBST* raiz, const char* suspeito) {
    if (raiz == NULL) return 0;

    int count = 0;

    const char* s = buscarSuspeito(raiz->pista);
    if (s != NULL && strcmp(s, suspeito) == 0)
        count = 1;

    return count +
           contarPistasSuspeito(raiz->esquerda, suspeito) +
           contarPistasSuspeito(raiz->direita, suspeito);
}

// ============================================================
// ========================= MAIN ==============================
// ============================================================

int main() {

    for (int i = 0; i < TAMANHO_TABELA; i++)
        tabela_hash[i] = NULL;

    struct Sala* hall = criarSala("Hall", "");
    struct Sala* sala = criarSala("Sala", "Pegadas de Lama");
    struct Sala* cozinha = criarSala("Cozinha", "Chave perdida");
    struct Sala* quarto = criarSala("Quarto", "Lencol manchado");
    struct Sala* escritorio = criarSala("Escritorio", "Livro com pagina faltando");
    struct Sala* porao = criarSala("Porao", "Gaveta perdida");

    hall->esquerda = sala;
    hall->direita = cozinha;
    sala->esquerda = quarto;
    sala->direita = escritorio;
    cozinha->direita = porao;

    struct NoBST* pistas = NULL;

    explorarSalas(hall, &pistas);

    printf("\n=== PISTAS COLETADAS ===\n");
    exibirPistas(pistas);

    char suspeito[50];
    printf("\nDigite o suspeito: ");
    scanf(" %[^\n]", suspeito);

    int total = contarPistasSuspeito(pistas, suspeito);

    if (total >= 2)
        printf("CULPADO (%d pistas)\n", total);
    else
        printf("INOCENTE (%d pistas)\n", total);

    return 0;
}
