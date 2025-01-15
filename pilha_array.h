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
    ~Pilha() { // Destrutor: libera o espaço usado pela pilha
        delete[] items;
    }
    void empilha(T item) { // Adiciona um item no topo da pilha
        if (topo >= capacidade - 1) {
            throw runtime_error("Estouro da pilha");
        }
        items[++topo] = item; // Coloca o item no topo e atualiza o índice
    }
    T desempilha() {
        if (topo < 0) {
            throw runtime_error("Pilha vazia");
        }
        return items[topo--]; // Remove o item do topo e atualiza o índice
    }
    int tamanho() { // Retorna quantos itens estão atualmente na pilha
        return topo + 1; // O topo começa em -1, então soma-se 1 para obter o total
    }
};

#endif //PILHA_H