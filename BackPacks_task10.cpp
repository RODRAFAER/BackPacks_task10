#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;
using std::reverse;

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

	int numThings, weightGram;

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

	int backpack1 = 0;
	int backpack2 = 0;

	for (int i = 0; i < numThings; i++) {
		if ((backpack1-backpack2) > weightThingsGram[numThings-1]) {
			backpack2 += weightThingsGram[i];
		}
		else {
			backpack1 += weightThingsGram[i];
		}
	}
	cout << "Вес первого рюкзака: " << backpack1 << " грамм" << endl;
	cout << "Вес второго рюкзака: " << backpack2 << " грамм" << endl;

	


	system("pause");
	return 0;
}