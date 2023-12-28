#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;
using std::reverse;
using std::min_element;
using std::min;


int proverka(int a) {
	while (cin.fail() || a < 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка ввода данных, введите значение заново: ";
		cin >> a;
	}
	return a;
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int numThings, weightGram, numPerson;

	cout << "Сколько человек идут в поход?\n";
	cin >> numPerson;
	numPerson = proverka(numPerson);

	cout << "Укажите, сколько вещей вы хотите с собой взять: ";
	cin >> numThings;
	numThings = proverka(numThings);

	vector <int> weightThingsGram;

	for (int i = 0; i < numThings; i++) {
		cout << "Укажите размер " << i+1 << "-ой вещи: ";
		cin >> weightGram;
		weightGram = proverka(weightGram);
		weightThingsGram.push_back(weightGram);
	}

	sort(weightThingsGram.begin(), weightThingsGram.end());
	reverse(weightThingsGram.begin(), weightThingsGram.end());

	vector <int> backpacks;
	for (int i = 0; i < numPerson; i++) {
		backpacks.push_back(0);
	}

	if (numThings >= numPerson) {
		for (int i = 0; i < numPerson; i++) {
			backpacks[i] = weightThingsGram[i];
		}


		for (int i = numPerson; i < numThings; i++) {
			sort(backpacks.begin(), backpacks.end());
			backpacks[0] += weightThingsGram[i];
		}
	}
	else {
		for (int i = 0; i < numThings; i++) {
			backpacks[i] = weightThingsGram[i];
		}
	}



	for (int i = 0; i < numPerson; i++) {
		cout << "Вес " << i+1 << " рюкзака: " << backpacks[i] << " грамм\n";
	}


	


	system("pause");
	return 0;
}