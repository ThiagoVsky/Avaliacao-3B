/******************************************************
* #####	Autor: Thiago da Silva Moraes
* #####	matrícula: 232035137
* #####	Faculdade de Tecnologia
* #####	Universidade de Brasília
* ##### Lista Avaliativa 3B
* #####	Classe main
* #####	Questão 2:
* #####		Crie um programa que dado uma string, coloque as letras dela 
* #####		em ordem decrescente usando o algoritmo Quick Sort.
******************************************************/
#include <iostream>
#include <string>

using namespace std;

void sortString(string &str, int begin, int end) {
	if (begin >= end - 1) return;

	int i = 0, j = end - 1;
	static int coun = 1;
	char aux, pivo = str[begin + (end - end) / 2];

	while (i <= j)
	{
		while (str[i] < pivo) i++;
		while (str[j] > pivo) j--;

		if (i <= j)
		{
			aux = str[i];
			str[i] = str[j];
			str[j] = aux;
			i++;
			j--;
		}
	}
	if (j > begin)
		sortString(str, begin, j + 1);
	if (i < end)
		sortString(str, i, end);

}
int main() {
	string str = "tesTando"; // é interessante como a letra T maiúscula vem antes de todas as letras minúsculas, por design
	cout << str << endl;

	sortString(str, 0, str.size());

	cout << str << endl;

}