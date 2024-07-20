#ifndef FILA_PRIORIDADE_HPP
#define FILA_PRIORIDADE_HPP

class FilaPrioridade {
public:
    FilaPrioridade(int tamanho);
    ~FilaPrioridade();
    void inserir(int vertice, double prioridade);
    int extrairMin();
    bool vazia() const;
    void atualizarPrioridade(int vertice, double novaPrioridade);

private:
    double* prioridades;
    int* vertices;
    int* posicao;
    int tamanho;
    int tamanhoAtual;
    static const double INFINITO = 10000000;

    void heapifyUp(int index);
    void heapifyDown(int index);
};

#endif FILA_PRIORIDADE_HPP
