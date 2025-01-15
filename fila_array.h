#ifndef FILA_H
#define FILA_H
using namespace std;
//deixa mais livre o atendimento para novas funções como se fosse um atendimento de restaurante

template <class T>
class Fila { //usa o padrão FIFO
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
        //caso dê zero o resto da divisão, faz o fim voltar para zero, para ser o final da capacidade
        items[fim] = item;
        tamanhoAtual++;
    }

    T desenfileira() {
        if (vazia()) { throw runtime_error("Fila vazia");
        }
        T item = items[inicio];
        //ele utiliza a ideia de resto da divisão
        //o resto deve ser zero para funcionar
        inicio = (inicio + 1) % capacidade; // Incrementa inicio de forma circular
        tamanhoAtual--;
        return item;
    }

    int cheia() {
        return tamanhoAtual == capacidade;//para fazer o teste de fila cheia, meio que força o erro
    }

    int vazia() {
        return tamanhoAtual == 0;
    }

    int tamanho() {
        return tamanhoAtual;
    }
};

#endif //FILA_H