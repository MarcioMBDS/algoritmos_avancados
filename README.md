# 🕵️ Detective Quest — Estruturas de Dados em C

Projeto desenvolvido em linguagem C com foco no aprendizado prático de **estruturas de dados**, explorando a evolução de um sistema simples até uma aplicação mais completa com múltiplas estruturas integradas.

---

## 🎯 Objetivo

Simular um jogo investigativo onde o usuário explora uma mansão em busca de pistas, utilizando diferentes estruturas de dados para:

* Navegação entre ambientes
* Armazenamento de pistas
* Organização e busca eficiente de informações
* Tomada de decisão com base nos dados coletados

---

## 📁 Estrutura do Projeto

```
📦 algoritmos_avancados
┣ 📄 detetive1.c   → Navegação em árvore binária
┣ 📄 detetive2.c   → Árvores + BST (pistas ordenadas)
┣ 📄 detetive3.c   → Sistema completo (Árvore + BST + Hash + lógica)
┣ 📄 pratica1.c    → Percursos em árvore (pré, em e pós-ordem)
┣ 📄 pratica2.c    → Trie + BST + normalização de dados
┣ 📄 pratica3.c    → Hash com encadeamento (listas ligadas)
┣ 📄 pratica4.c    → Hash com endereçamento aberto
```

---

## 🧠 Conceitos Aplicados

### 🌳 Árvores Binárias

* Representação da mansão (salas e caminhos)
* Navegação interativa pelo usuário

### 🌲 Árvores de Busca Binária (BST)

* Armazenamento ordenado das pistas
* Exibição automática em ordem alfabética

### 🧩 Tabelas Hash

* Associação entre pistas e suspeitos
* Busca eficiente em tempo próximo de O(1)

### 🔤 Trie (Árvore de Prefixos)

* Armazenamento de palavras normalizadas
* Busca eficiente por termos

---

## 🚀 Evolução do Projeto

### 🔹 detetive1.c

* Implementação básica de árvore binária
* Navegação entre salas

### 🔹 detetive2.c

* Introdução de pistas
* Uso de BST para ordenação

### 🔹 detetive3.c

* Sistema completo com:

  * BST (pistas)
  * Hash (pista → suspeito)
  * Evita duplicação de pistas
  * Lógica de julgamento final

---

## 🕹️ Como Executar

Compile qualquer arquivo com:

```bash
gcc nome_do_arquivo.c -o programa
```

Execute com:

```bash
./programa
```

> No Windows:

```bash
programa.exe
```

---

## 💡 Exemplo de Uso (detetive3.c)

* O usuário navega pela mansão
* Coleta pistas únicas
* As pistas são organizadas automaticamente
* No final, escolhe um suspeito
* O sistema determina se ele é culpado ou inocente

---

## 📌 Destaques Técnicos

* Uso combinado de múltiplas estruturas de dados
* Separação clara de responsabilidades
* Controle de duplicidade de dados
* Implementação de hash com tratamento de colisão
* Código modular e reutilizável

---

## 📈 Aprendizados

Durante o desenvolvimento, foram praticados:

* Alocação dinâmica de memória (`malloc`, `free`)
* Manipulação de strings (`string.h`)
* Recursão
* Estruturas de dados clássicas
* Organização de código em C

---

## 👨‍💻 Autor

Márcio Moraes