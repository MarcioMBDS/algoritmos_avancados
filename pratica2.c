#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAMANHO_ALFABETO 26

// ============================================================
// ======================= TRIE ================================
// ============================================================

struct NoTrie {
    struct NoTrie* filhos[TAMANHO_ALFABETO];
    bool ehFimDePalavra;
};

struct NoTrie* criarNoTrie() {
    struct NoTrie* novoNo = (struct NoTrie*) malloc(sizeof(struct NoTrie));

    if (novoNo == NULL) {
        printf("Erro de memória!\n");
        exit(1);
    }

    novoNo->ehFimDePalavra = false;

    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        novoNo->filhos[i] = NULL;
    }

    return novoNo;
}

void inserirTrie(struct NoTrie* raiz, const char* palavra) {
    struct NoTrie* atual = raiz;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';

        if (indice < 0 || indice >= TAMANHO_ALFABETO)
            continue;

        if (atual->filhos[indice] == NULL) {
            atual->filhos[indice] = criarNoTrie();
        }

        atual = atual->filhos[indice];
    }

    atual->ehFimDePalavra = true;
}

bool buscarTrie(struct NoTrie* raiz, const char* palavra) {
    struct NoTrie* atual = raiz;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';

        if (indice < 0 || indice >= TAMANHO_ALFABETO)
            return false;

        if (atual->filhos[indice] == NULL)
            return false;

        atual = atual->filhos[indice];
    }

    return atual != NULL && atual->ehFimDePalavra;
}

void listarTrie(struct NoTrie* no, char* buffer, int nivel) {
    if (no->ehFimDePalavra) {
        buffer[nivel] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (no->filhos[i] != NULL) {
            buffer[nivel] = 'a' + i;
            listarTrie(no->filhos[i], buffer, nivel + 1);
        }
    }
}

// ============================================================
// ======================= BST ================================
// ============================================================

struct NoBST {
    char valor[100];
    struct NoBST* esquerda;
    struct NoBST* direita;
};

struct NoBST* criarNoBST(const char* valor) {
    struct NoBST* novo = (struct NoBST*) malloc(sizeof(struct NoBST));

    if (novo == NULL) {
        printf("Erro de memória!\n");
        exit(1);
    }

    strcpy(novo->valor, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

struct NoBST* inserirBST(struct NoBST* raiz, const char* valor) {
    if (raiz == NULL) {
        return criarNoBST(valor);
    }

    if (strcmp(valor, raiz->valor) < 0) {
        raiz->esquerda = inserirBST(raiz->esquerda, valor);
    } else {
        raiz->direita = inserirBST(raiz->direita, valor);
    }

    return raiz;
}

bool buscarBST(struct NoBST* raiz, const char* valor) {
    if (raiz == NULL) return false;

    int cmp = strcmp(valor, raiz->valor);

    if (cmp == 0) return true;
    else if (cmp < 0) return buscarBST(raiz->esquerda, valor);
    else return buscarBST(raiz->direita, valor);
}

void emOrdem(struct NoBST* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%s\n", raiz->valor);
        emOrdem(raiz->direita);
    }
}

// ============================================================
// =================== NORMALIZAÇÃO ===========================
// ============================================================

void normalizar(const char* entrada, char* saida) {
    int j = 0;

    for (int i = 0; entrada[i] != '\0'; i++) {
        char c = entrada[i];

        if (c >= 'A' && c <= 'Z') c += 32;

        if (c >= 'a' && c <= 'z') {
            saida[j++] = c;
        }
    }

    saida[j] = '\0';
}

// ============================================================
// ========================= MAIN =============================
// ============================================================

int main() {

    // ---------- TRIE ----------
    struct NoTrie* trie = criarNoTrie();
    char normalizada[100];

    normalizar("Pegadas de Lama", normalizada);
    inserirTrie(trie, normalizada);

    normalizar("Chave perdida", normalizada);
    inserirTrie(trie, normalizada);

    normalizar("Livro com pagina faltando", normalizada);
    inserirTrie(trie, normalizada);

    normalizar("Lencol manchado", normalizada);
    inserirTrie(trie, normalizada);

    normalizar("Gaveta perdida", normalizada);
    inserirTrie(trie, normalizada);

    printf("=== TRIE (ordenado) ===\n");
    char buffer[100];
    listarTrie(trie, buffer, 0);

    // ---------- BST ----------
    struct NoBST* bst = NULL;

    bst = inserirBST(bst, "Pegadas de Lama");
    bst = inserirBST(bst, "Chave perdida");
    bst = inserirBST(bst, "Livro com pagina faltando");
    bst = inserirBST(bst, "Lencol manchado");
    bst = inserirBST(bst, "Gaveta perdida");

    printf("\n=== BST (em ordem) ===\n");
    emOrdem(bst);

    // ---------- BUSCA ----------
    printf("\nBusca BST:\n");
    printf("Lencol manchado: %s\n",
           buscarBST(bst, "Lencol manchado") ? "Encontrado" : "Não encontrado");

    printf("Oculos: %s\n",
           buscarBST(bst, "Oculos") ? "Encontrado" : "Não encontrado");

    return 0;
}