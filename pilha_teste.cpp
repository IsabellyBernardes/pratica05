/*
 * pilha.cpp
 *
 *  Created on: 10 de mar de 2020
 *      Author: IFPE
 */

#include <iostream>

#include "pilha.h"

#define MAX 10

using namespace std;

int mainPilha() {
	Pilha<int> pilha(MAX);

	try {
		cerr << "Testando empilha() [normal]: ";
		for (int i = 0; i < MAX; i++) {
			pilha.empilha(2 * i);
		}
		cerr << "OK" << endl;
	} catch (...) {
		cerr << "FALHOU!" << endl;
		exit(1);
	}

	cerr << "Testando tamanho() [cheia]: ";
	if (pilha.tamanho() != MAX) {
		cerr << "FALHOU (tam = " << pilha.tamanho() << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;

	try {
		cerr << "Testando empilha() [overflow]: ";
		pilha.empilha(MAX + 1);
		cerr << "FALHOU!" << endl;
		exit(1);
	} catch (std::runtime_error &ex) {
		cerr << "OK (" << ex.what() << ")" << endl;
	}

	cerr << "Testando desempilha() [normal]: ";
	for (int i = (MAX - 1); i >= 0; i--) {
		if (pilha.desempilha() != 2 * i) {
			cerr << "FALHOU em " << i << endl;
			exit(1);
		}
	}
	cerr << "OK" << endl;

	cerr << "Testando tamanho() [vazia]: ";
	if (pilha.tamanho() != 0) {
		cerr << "FALHOU (tam = " << pilha.tamanho() << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;

	try {
		cerr << "Testando desempilha() [underflow]: ";
		pilha.desempilha();
		cerr << "FALHOU!" << endl;
		exit(1);
	} catch (std::runtime_error &ex) {
		cerr << "OK (" << ex.what() << ")" << endl;
	}

    cerr << "*** TODOS OS TESTES OK! *** " << endl;

	return 0;
}


