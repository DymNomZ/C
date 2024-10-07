#include <iostream>
#include "linkedlist.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	LinkedList* list = new LinkedList();
	Person* p;
	string name, name2;
	int units;
	char op;
	while (true) {
		cout << "Op: ";
		cin >> op;
		switch (op) {
			case 'a':
				p = new Person();
				cout << "Name: ";
				cin >> p->firstName >> p->lastName;
				cout << "Age: ";
				cin >> p->age;
				cout << "Requests (B,M,C,D): ";
				cin >> p->requests[0] >> p->requests[1] >> p->requests[2] >> p->requests[3];
				list->add(p);
				break;
			case '+':
				cout << "Who to advance? ";
				cin >> name;
				cout << "By how many units? ";
				cin >> units;
				list->advance(name, units);
				break;
			case '-':
				cout << "Who to delay? ";
				cin >> name;
				cout << "By how many units? ";
				cin >> units;
				list->delay(name, units);
				break;
			case '=':
				cout << "Who to trade? ";
				cin >> name >> name2;
				list->trade(name, name2);
				break;
			case 'p':
				list->print();
				break;
			case 'x':
				cout << "Exiting...";
				return 0;
		}
	}
	return 0;
}