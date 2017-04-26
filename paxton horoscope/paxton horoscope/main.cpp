#include <iostream>
using namespace std;
bool Horo(int input);

int main() {
	int input;
	cout << "enter the nmumber of the month you were born my good friend" << endl;
	cin >> input;
	Horo(input);

	if (Horo(input) == true)
		cout << "ah dank af" << endl;

}
bool Horo(int input) {
	if (input == 1)
		cout << "Capricorn, be who you please boiiiiiiiiii" << endl;
	else if (input == 2)
		cout << "Aquarius, the water type pokemon"<< endl;
	else if (input == 3)
		cout << "Pisces, p stands for pasta" << endl;
	else if (input == 4)
		cout << "Aries, big horn big heart" << endl;
	else if (input == 5) {
		cout << "Tarus, this is BULL sh*t" << endl;
		return true;
	}
	else if (input == 6)
		cout << "Gemini, das pretty gucci" << endl;
	else if (input == 7)
		cout << "Cancer, kinda ironic" << endl;
	else if (input == 8)
		cout << "Leo, rawr XD" << endl;
	else if (input == 9)
		cout << "Virgo, ha looser you're a virgin" << endl;
	else if (input == 10)
		cout << "Libra, as in library because of edumaction" << endl;
	else if (input == 11)
		cout << "Scorpio, xbox scorpio now starting at $299.99 (not sponsored)" << endl;
	else if (input == 12)
		cout << "Sagittarius, she thicker than a centaur" << endl;
}