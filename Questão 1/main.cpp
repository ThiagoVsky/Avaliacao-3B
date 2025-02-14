/******************************************************
* #####	Autor: Thiago da Silva Moraes
* #####	matrícula: 232035137
* #####	Faculdade de Tecnologia
* #####	Universidade de Brasília
* ##### Lista Avaliativa 3B
* #####	Classe main
* #####	Questão 1: 
* #####		Faça um programa que leia n nomes de um arquivo inserindo-os em uma lista de 
* #####		forma ordenada utilizando a ideia do algoritmo Insertion Sort. No final, o 
* #####		programa deve mostrar todos os nomes ordenados alfabeticamente. 
******************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> sortNames(vector<string> str) {
	for (int i = 1; i < (str.size() - 1); i++) { // i = 1 pois a posição 0 não precisa rodar
		string select = str[i];
		int j = i - 1;
		while (j >= 0 && str[j] > select) {
			str[j + 1] = str[j];
			j--;
		}
		str[j + 1] = select;
	}
	return str;
}

vector<string> getNames(string name) {
	ifstream file(name);
	vector<string> data;
	if (file.is_open()) {
		bool a = false;
		do {
			if (file.eof()) a = true;
			char c[20U];
			file.getline(c, 20U);
			string s(c);
			data.push_back(s);
		} while (!a);
	}
	file.close();
	return data;
}

int main() {
	setlocale(LC_ALL, "portuguese");

	stringstream ss1;
	vector<string> data = getNames("nomes.txt");
	for (int i = 0; i < data.size() - 1; i++) ss1 << data[i] << endl;

	cout << "Nomes desordenados:\n" << ss1.str() << endl << endl;
	
	vector<string> sorted = sortNames(data);
	stringstream ss2;
	for (int i = 0; i < sorted.size() - 1; i++) ss2 << sorted[i] << endl;
	cout << "\n\Nomes ordenados:\n" << ss2.str() << endl;

}
