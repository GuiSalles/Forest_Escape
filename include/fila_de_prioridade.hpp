#ifndef FILA_DE_PRIORIDADE_HPP
#define FILA_DE_PRIORIDADE_HPP

template <typename Item>

class fila_de_prioridade
{
public:
    fila_de_prioridade(int tamanho);
    ~fila_de_prioridade();
    void inserir(const Item& value);
    Item remover();
    bool vazia() const;

private:
    void subir(int index);
    void descer(int index);
    void trocar(int i, int j);
    int tamanho;
    int capacidade;
    Item *dados;
};

#endif // FILA_DE_PRIORIDADE_HPP
