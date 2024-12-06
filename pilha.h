#ifndef PILHA_H
#define PILHA_H

template <class T>
class Pilha {
private:
    T* items;
    int capacidade;
    int topo;
public:
    Pilha(int capacidade) {
        this->capacidade = capacidade; this->items = new T[capacidade]; this->topo = -1; //
    }
    ~Pilha() {
        delete[] items;
    }
    void empilha(T item) {
        if (topo >= capacidade - 1) {
            throw std::runtime_error("Estouro da pilha");
        }
        items[++topo] = item;
    }
    T desempilha() {
        if (topo < 0) {
            throw std::runtime_error("Pilha vazia");
        }
        return items[topo--];
    }
    int tamanho() {
        return topo + 1;
    }
};

#endif //PILHA_H
