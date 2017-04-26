#include <iostream>
using namespace std;
void ham();
int main() {

	for (;;) {
		ham();
		system("pause");
	}

}

void ham() {

	int number = rand() & 100 + 1;
	if (number <= 25) {
		cout << "blue" << endl;
		system("color 1F");
	}
	if (number >= 50 && number <= 75) {
		cout << "green" << endl;
		system("color 2F");
	}
	else {
		cout << "red" << endl;
		system("color 4F");

	}
}