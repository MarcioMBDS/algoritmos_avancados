# 🕵️ Detective Quest — Data Structures in C

A project developed in C focused on practical learning of **data structures**, showcasing the evolution from a simple system to a more complete application integrating multiple structures.

---

## 🎯 Purpose

Simulate an investigative game where the user explores a mansion searching for clues, using different data structures to handle:

* Navigation between rooms
* Storage of clues
* Efficient data organization and search
* Decision-making based on collected evidence

---

## 📁 Project Structure

```
📦 algoritmos_avancados
┣ 📄 detetive1.c   → Binary tree navigation
┣ 📄 detetive2.c   → Trees + BST (sorted clues)
┣ 📄 detetive3.c   → Full system (Tree + BST + Hash + logic)
┣ 📄 pratica1.c    → Tree traversals (pre, in, post-order)
┣ 📄 pratica2.c    → Trie + BST + data normalization
┣ 📄 pratica3.c    → Hash table with chaining
┣ 📄 pratica4.c    → Hash table with open addressing
```

---

## 🧠 Concepts Applied

### 🌳 Binary Trees

* Representation of the mansion (rooms and paths)
* Interactive navigation

### 🌲 Binary Search Trees (BST)

* Sorted storage of clues
* Automatic ordered output

### 🧩 Hash Tables

* Mapping clues to suspects
* Fast lookup (near O(1))

### 🔤 Trie (Prefix Tree)

* Storage of normalized words
* Efficient text lookup

---

## 🚀 Project Evolution

### 🔹 detetive1.c

* Basic binary tree implementation
* Room navigation

### 🔹 detetive2.c

* Introduction of clues
* Use of BST for sorting

### 🔹 detetive3.c

* Full system featuring:

  * BST (clues)
  * Hash table (clue → suspect)
  * Duplicate prevention
  * Final decision logic

---

## 🕹️ How to Run

Compile any file with:

```bash
gcc filename.c -o program
```

Run with:

```bash
./program
```

---

## 💡 Example (detetive3.c)

* The user navigates through the mansion
* Collects unique clues
* Clues are automatically sorted
* At the end, selects a suspect
* The system determines if they are guilty or innocent

---

## 📌 Technical Highlights

* Combination of multiple data structures
* Clear separation of responsibilities
* Duplicate data handling
* Hash collision handling
* Modular and reusable code

---

## 📈 Learning Outcomes

During development, the following concepts were practiced:

* Dynamic memory allocation (`malloc`, `free`)
* String manipulation (`string.h`)
* Recursion
* Core data structures
* Code organization in C

---

## 👨‍💻 Author

Marcio Moraes

---