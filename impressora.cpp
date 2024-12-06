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

#include "fila.h"

using namespace std;

int mainImp() {
	Fila<int> impressora(10);
	int i = 0;
	while (1) {
		// 70% de chance do usuário mandar imprimir um documento
		if ((rand() % 100) < 70) {
			if (!impressora.cheia()) {
				cout << "Adicionado documento " << ++i << endl;
				impressora.enfileira(i);
			}
		}

		cout << "Status: " << impressora.tamanho() << " item(s) na fila" << endl;

		// 30% de chance da impressora imprimir um documento
		if ((rand() % 100) < 30) {
			if (!impressora.vazia()) {
				cout << "Imprimindo documento " << impressora.desenfileira() << endl;
			}
		}

		PAUSA(1);
	}

	return 0;
}



