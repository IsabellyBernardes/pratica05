#include <iostream>
#include "lista_array.h"
#include "lista_ligada.h"
#include "lista.h"

using namespace std;

const int MAX = 100;

template <typename ListaTipo>
ListaTipo criaLista(); 

template <>
ListaArray<int> criaLista<ListaArray<int>>() {
    return ListaArray<int>(MAX);
}

template <>
ListaLigada<int> criaLista<ListaLigada<int>>() {
    return ListaLigada<int>();
}

template <typename ListaTipo>
void testaTamanho(ListaTipo& lista, const char* subcaso, int tamanho) {
    cerr << "Testando tamanho() [" << subcaso << "]: ";
    if (lista.tamanho() != tamanho) {
        cerr << "FALHOU (tam = " << lista.tamanho() << ")" << endl;
        exit(1);
    }
    cerr << "OK" << endl;
}

template <typename ListaTipo>
void testarLista() {
    ListaTipo lista = criaLista<ListaTipo>();

    try {
        cerr << "Testando insere() [normal]: ";
        for (int i = 1; i <= MAX; i++) {
            lista.insere(i * 7);
        }
        cerr << "OK" << endl;
    } catch (...) {
        cerr << "FALHOU!" << endl;
        exit(1);
    }

    testaTamanho(lista, "cheia", MAX);

    try {
        cerr << "Testando insere() [overflow]: ";
        lista.insere(MAX + 1);  
        cerr << "FALHOU!" << endl;
        exit(1);
    } catch (std::runtime_error& ex) {
        cerr << "OK (" << ex.what() << ")" << endl;
    }

try {
    cerr << "Testando pega() [idx < 1]: ";
    lista.pega(0); 
    cerr << "FALHOU!" << endl;
    exit(1);
} catch (std::exception& ex) { 
    cerr << "OK (" << ex.what() << ")" << endl;
}

try {
    cerr << "Testando pega() [idx > tam]: ";
    lista.pega(MAX + 1);
    cerr << "FALHOU!" << endl;
    exit(1);
} catch (std::exception& ex) {  
    cerr << "OK (" << ex.what() << ")" << endl;
}
    cerr << "Testando pega() [todos]: ";
    for (int i = 1; i <= MAX; i++) {
        try {
            int valorEsperado = i * 7;
            int valorPegado = lista.pega(i);
            if (valorPegado != valorEsperado) {
                cerr << "FALHOU em " << i << " (valor = " << valorPegado << ")" << endl;
                exit(1);
            }
        } catch (...) {
            cerr << "FALHOU em " << i << " (exceção)" << endl;
            exit(1);
        }
    }
    cerr << "OK" << endl;

    cerr << "Testando remove() [pares]: ";
    try {
        for (int i = MAX / 2; i >= 1; i--) {
            lista.remove(2 * i);
        }
    } catch (...) {
        cerr << "FALHOU!" << endl;
        exit(1);
    }
    cerr << "OK" << endl;

    testaTamanho(lista, "metade", MAX / 2);

    cerr << "Testando pega() [impares]: ";
    for (int i = 1; i <= MAX / 2; i++) {
        if (lista.pega(i) != 7 * (((i - 1) * 2) + 1)) {
            cerr << "FALHOU em " << i << endl;
            exit(1);
        }
    }
    cerr << "OK" << endl;

    cerr << "Testando adiciona() [pares]: ";
    for (int i = 1; i <= (MAX / 2); i++) {
        lista.insere(2 * i * 7);
    }
    cerr << "OK" << endl;

    testaTamanho(lista, "cheia", MAX);

    cerr << "*** TODOS OS TESTES OK! ***" << endl;
}

int mainLista() {
    cerr << "Testando Lista com array:" << endl;
    testarLista<ListaArray<int>>();

    cerr << "\nTestando Lista com ponteiros:" << endl;
    testarLista<ListaLigada<int>>();

    return 0;
}
