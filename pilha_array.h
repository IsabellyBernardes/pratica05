#ifndef PILHA_H
#define PILHA_H
using namespace std;

template <class T>

class Pilha {//Usa a ideia de LIFO
private:
    T* items;
    int capacidade;
    int topo;
public:
    Pilha(int capacidade) {
        this->capacidade = capacidade;
        this->items = new T[capacidade];
        this->topo = -1; // Para a pilha começar vazia
    }
    ~Pilha() { 
        delete[] items;
    }
    void empilha(T item) { 
        if (topo >= capacidade - 1) {
            throw runtime_error("Estouro da pilha");
        }
        items[++topo] = item; 
    }
    T desempilha() {
        if (topo < 0) {
            throw runtime_error("Pilha vazia");
        }
        return items[topo--]; 
    }
    int tamanho() { 
        return topo + 1; 
    }
};

#endif //PILHA_H