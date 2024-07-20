#include "fila_prioridade.hpp"
#include <cmath>

const double FilaPrioridade::INFINITO = 1e+30;

FilaPrioridade::FilaPrioridade(int tamanho) : tamanho(tamanho), tamanhoAtual(0) {
    prioridades = new double[tamanho];
    vertices = new int[tamanho];
    posicao = new int[tamanho];
    for (int i = 0; i < tamanho; i++) {
        posicao[i] = -1;
        prioridades[i] = INFINITO;
    }
}

FilaPrioridade::~FilaPrioridade() {
    delete[] prioridades;
    delete[] vertices;
    delete[] posicao;
}

void FilaPrioridade::inserir(int vertice, double prioridade) {
    if (posicao[vertice] != -1) {
        atualizarPrioridade(vertice, prioridade);
        return;
    }

    prioridades[tamanhoAtual] = prioridade;
    vertices[tamanhoAtual] = vertice;
    posicao[vertice] = tamanhoAtual;
    heapifyUp(tamanhoAtual);
    tamanhoAtual++;
}

int FilaPrioridade::extrairMin() {
    if (vazia()) return -1;

    int minVertice = vertices[0];
    posicao[minVertice] = -1;

    tamanhoAtual--;
    if (!vazia()) {
        vertices[0] = vertices[tamanhoAtual];
        prioridades[0] = prioridades[tamanhoAtual];
        posicao[vertices[0]] = 0;
        heapifyDown(0);
    }
    return minVertice;
}

bool FilaPrioridade::vazia() const {
    return tamanhoAtual == 0;
}

void FilaPrioridade::atualizarPrioridade(int vertice, double novaPrioridade) {
    int index = posicao[vertice];
    if (index == -1) return;

    double prioridadeAntiga = prioridades[index];
    prioridades[index] = novaPrioridade;

    if (novaPrioridade < prioridadeAntiga) {
        heapifyUp(index);
    } else {
        heapifyDown(index);
    }
}

void FilaPrioridade::heapifyUp(int index) {
    while (index > 0) {
        int pai = (index - 1) / 2;
        if (prioridades[index] < prioridades[pai]) {
            std::swap(prioridades[index], prioridades[pai]);
            std::swap(vertices[index], vertices[pai]);
            posicao[vertices[index]] = index;
            posicao[vertices[pai]] = pai;
            index = pai;
        } else {
            break;
        }
    }
}

void FilaPrioridade::heapifyDown(int index) {
    while (true) {
        int esquerda = 2 * index + 1;
        int direita = 2 * index + 2;
        int menor = index;

        if (esquerda < tamanhoAtual && prioridades[esquerda] < prioridades[menor]) {
            menor = esquerda;
        }

        if (direita < tamanhoAtual && prioridades[direita] < prioridades[menor]) {
            menor = direita;
        }

        if (menor != index) {
            std::swap(prioridades[index], prioridades[menor]);
            std::swap(vertices[index], vertices[menor]);
            posicao[vertices[index]] = index;
            posicao[vertices[menor]] = menor;
            index = menor;
        } else {
            break;
        }
    }
}
