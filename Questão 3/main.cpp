/******************************************************
* #####	Autor: Thiago da Silva Moraes
* #####	matrícula: 232035137
* #####	Faculdade de Tecnologia
* #####	Universidade de Brasília
* ##### Lista Avaliativa 3B
* #####	Classe main
* #####	Questão 3:
* #####		Considere a seguinte estrutura: 
* #####			struct pessoa { 
* #####				int matricula; 
* #####				char nome[30]; 
* #####				float nota; 
* #####			}; 
* #####		Faça uma função que dado um array de tamanho N dessa estrutura, ordene o 
* #####		array pelo campo escolhido pelo usuário. A ordenação deve utilizar o método 
* #####		Selection Sort. 
******************************************************/
#include <iostream>
#include <array>

using namespace std;

const int tam = 6;

struct pessoa {
	int matricula;
	char nome[30];
	float nota;
};

// algorítmo baseado no encontrado em https://pt.wikipedia.org/wiki/Selection_sort
// selector: 0 = matricula, 1 = nome, 2 = nota
array<pessoa, tam> pessoaSort(array<pessoa, tam> vetor, int tam, int selector) {
    if (selector == 0)
    {
        cout << "debug 1" << endl;
        for (int indice = 0; indice < tam; ++indice) {
            int indiceMenor = indice;
            for (int indiceSeguinte = indice + 1; indiceSeguinte < tam; ++indiceSeguinte) {
                if (vetor[indiceSeguinte].matricula < vetor[indiceMenor].matricula) {
                    indiceMenor = indiceSeguinte;
                }
            }
            pessoa aux = vetor[indice];
            vetor[indice] = vetor[indiceMenor];
            vetor[indiceMenor] = aux;
        }
    }
    else if (selector == 1) {
        cout << "debug 2" << endl;
        for (int indice = 0; indice < tam; ++indice) {
            int indiceMenor = indice;
            for (int indiceSeguinte = indice + 1; indiceSeguinte < tam; ++indiceSeguinte) {
                if (strcmp(vetor[indiceSeguinte].nome, vetor[indiceMenor].nome) < 0) {
                    indiceMenor = indiceSeguinte;
                }
            }
            pessoa aux = vetor[indice];
            vetor[indice] = vetor[indiceMenor];
            vetor[indiceMenor] = aux;
        }
    }
    else if (selector == 2) {
        cout << "debug 3" << endl;
        for (int indice = 0; indice < tam; ++indice) {
            int indiceMenor = indice;
            for (int indiceSeguinte = indice + 1; indiceSeguinte < tam; ++indiceSeguinte) {
                if (vetor[indiceSeguinte].nota < vetor[indiceMenor].nota) {
                    indiceMenor = indiceSeguinte;
                }
            }
            pessoa aux = vetor[indice];
            vetor[indice] = vetor[indiceMenor];
            vetor[indiceMenor] = aux;
        }
    }
    return vetor;
}

void printPessoa(array<pessoa, tam> p, int tam) {
    setlocale(LC_ALL, "portuguese");
    for (int i = 0; i < tam; i++) {
        cout << "Matrícula: " << p[i].matricula << ", nome: " << p[i].nome << ", nota " << p[i].nota << endl;
    }
    cout << "\n\n";
}

int main() {
    array<pessoa, tam> p = { {
        {56789, "Marcos", 8.59},
        {45678, "José", 9.12},
        {67890, "Emanoel", 3.89},
        {34567, "Kamille", 7.89},
        {23456, "Valério", 8.52},
        {12345, "Thiago", 10.0}
    } };

    array<pessoa, tam> p0 = pessoaSort(p, tam, 0);
    array<pessoa, tam> p1 = pessoaSort(p, tam, 1);
    array<pessoa, tam> p2 = pessoaSort(p, tam, 2);

    printPessoa(p0, tam);
    printPessoa(p1, tam);
    printPessoa(p2, tam);
}