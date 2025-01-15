/*
 * impressora.cpp
 *
 *  Created on: 28 de set de 2017
 *      Author: ramide
 */
#include <stdlib.h> // rand()
#include <iostream> // cout

#include <thread>
#include <chrono>
#define PAUSA(tempo) std::this_thread::sleep_for(std::chrono::milliseconds(tempo * 1000));
//#define PAUSA(tempo) for(long l = 0; l < 10000000; l++) rand();

#include "fila_array.h"
#include "fila_ligada.h"

using namespace std;

template <typename FilaTipo>
void simularImpressora() {
	FilaTipo impressora(10);
	int i = 0;
	while (true) {
		// 70% de chance do usuário mandar imprimir um documento
		if ((rand() % 100) < 70) {
			if (!impressora.cheia()) {
				cout << "Adicionado documento " << ++i << endl;
				impressora.enfileira(i);
			} else {
				cout << "Fila cheia, não foi possível adicionar o documento " << (i + 1) << endl;
			}
		}

		cout << "Status: " << impressora.tamanho() << " item(s) na fila" << endl;

		// 30% de chance da impressora imprimir um documento
		if ((rand() % 100) < 30) {
			if (!impressora.vazia()) {
				cout << "Imprimindo documento " << impressora.desenfileira() << endl;
			} else {
				cout << "Fila vazia, nada para imprimir." << endl;
			}
		}

		PAUSA(1);
	}
}

int mainImp() {
	cerr << "Simulacao com Fila baseada em array:" << endl;
	simularImpressora<Fila<int>>();

	cerr << "\nSimulação com Fila baseada em ponteiros:" << endl;
	simularImpressora<FilaLigada<int>>();

	return 0;
}




