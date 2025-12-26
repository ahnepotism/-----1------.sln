#include <iostream>
#include <clocale>
using namespace std;
#include "Laba1.h"
#include "Laba2.h"
#include "Laba3.h"
#include "Laba4.h"
int main() {
	setlocale(LC_ALL, "");
	int choicee;
	while (true) {
		cout << "Введите номер:\n";
		cin >> choicee;
		switch (choicee) {
		case 1:
			Laba1();
			break;
		case 2:
			Laba2();
			break;
		case 3:
			Laba3();
			break;
		case 4:
			Laba4();
			break;

		case 0:
			return 0;
			break;
		}
	}



}