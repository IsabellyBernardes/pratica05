#ifndef FILA_H
#define FILA_H
using namespace std;

template <class T>
class Fila {
private:
    T* items; // Array de itens
    int capacidade; // Capacidade máxima da fila
    int tamanhoAtual; // Número de itens atualmente na fila
    int inicio; // Índice do início da fila
    int fim;
public:
    Fila(int cap) {
        capacidade = cap;
        items = new T[capacidade];
        tamanhoAtual = 0;
        inicio = 0;
        fim = -1;
    }

    ~Fila() {
        delete[] items;
    }

    void enfileira(const T & item) {
        if (cheia()) {
          throw runtime_error("Fila cheia"); // Lança exceção se a fila estiver cheia
        }
        fim = (fim + 1) % capacidade; // Incrementa fim de forma circular
        items[fim] = item;
        tamanhoAtual++;
    }

    T desenfileira() {
        if (vazia()) { throw runtime_error("Fila vazia");
        }
        T item = items[inicio];
        inicio = (inicio + 1) % capacidade; // Incrementa inicio de forma circular
        tamanhoAtual--;
        return item;
    }

    int cheia() {
        return tamanhoAtual == capacidade;
    }

    int vazia() {
        return tamanhoAtual == 0;
    }

    int tamanho() {
        return tamanhoAtual;
    }
};

#endif //FILA_H
