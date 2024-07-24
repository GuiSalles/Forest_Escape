#include "fila_de_prioridade.hpp"
#include <utility>

template <typename Item>
fila_de_prioridade<Item>::fila_de_prioridade(int capacidade) 
    : tamanho(0), capacidade(capacidade) {
    dados = new Item[capacidade];
}

template <typename Item>
fila_de_prioridade<Item>::~fila_de_prioridade() {
    delete[] dados;
}

template <typename Item>
void fila_de_prioridade<Item>::inserir(const Item& value) {
    dados[tamanho] = value;
    subir(tamanho++);
}

template <typename Item>
Item fila_de_prioridade<Item>::remover() {
    Item raiz = dados[0];
    dados[0] = dados[--tamanho];
    descer(0);
    return raiz;
}

template <typename Item>
bool fila_de_prioridade<Item>::vazia() const {
    return tamanho == 0;
}

template <typename Item>
void fila_de_prioridade<Item>::subir(int index) {
    while (index > 0) {
        int pai = (index - 1) / 2;
        if (dados[index] >= dados[pai]) break;
        trocar(index, pai);
        index = pai;
    }
}

template <typename Item>
void fila_de_prioridade<Item>::descer(int index) {
    while (true) {
        int filhoEsq = 2 * index + 1;
        int filhoDir = 2 * index + 2;
        int menor = index;

        if (filhoEsq < tamanho && dados[filhoEsq] < dados[menor]) {
            menor = filhoEsq;
        }
        if (filhoDir < tamanho && dados[filhoDir] < dados[menor]) {
            menor = filhoDir;
        }
        if (menor == index) break;
        trocar(index, menor);
        index = menor;
    }
}

template <typename Item>
void fila_de_prioridade<Item>::trocar(int i, int j) {
    Item temp = dados[i];
    dados[i] = dados[j];
    dados[j] = temp;
}

template class fila_de_prioridade<std::pair<double, std::pair<int, int>>>;
