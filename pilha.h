#ifndef PILHA_H
#define PILHA_H

template <typename T>
class Pilha {
protected:
    int capacidade;
    int tamanhoAtual;
public:
    virtual ~Pilha() = default;
    virtual void empilha(T item) = 0; //se tem zero, é virtual puro
    virtual T desempilha() = 0; //se é virtual puro, os filhos TEM QUE implementar o metodo
    virtual int tamanho() const = 0;

    bool estaVazia() const {
        return tamanhoAtual == 0;
    }

    bool estaCheia() const {
        return tamanhoAtual >= capacidade;
    }
};

#endif // PILHA_H
