/******************************************************
* #####	Autor: Thiago da Silva Moraes
* #####	matrícula: 232035137
* #####	Faculdade de Tecnologia
* #####	Universidade de Brasília
* ##### Lista Avaliativa 3B
* #####	Classe main
* #####	Questão 4 descrita em https://github.com/ThiagoVsky/Avaliacao-3B/issues/4
******************************************************/
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

using namespace std;
// Algoritmo baseado no encontrado em https://pt.wikipedia.org/wiki/Bubble_sort

void swap(float *a, float *b) {
	float temp = *a;
	*a = *b;
	*b = temp;
}
void sort(float *alt, int tam) {
	if (tam < 1) return;

	for (int i = 0; i < tam; i++)
		if (alt[i] > alt[i + 1])
			swap(&alt[i], &alt[i + 1]);
	sort(alt, tam - 1);
}

int main() {
	srand(time(NULL));
	float alturas[100];
	cout << setprecision(2) << fixed;

	for (int i = 0; i < 100; i++) 
	{
		alturas[i] = 100 + rand() % 200;
		alturas[i] = alturas[i] / 100;
	}

	for (int i = 0; i < 100; i++) cout << "Altura " << i + 1 << ": " << alturas[i] << endl;
	sort(alturas, 99);
	cout << "\n\nOrdenado:\n\n";
	for (int i = 0; i < 100; i++) cout << "Altura " << i + 1 << ": " << alturas[i] << endl;

}