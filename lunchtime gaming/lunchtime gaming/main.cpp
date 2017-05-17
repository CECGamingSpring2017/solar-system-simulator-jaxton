#include <iostream>
using namespace std;
int main() {
	char input;
	cout << "what game should you play at lunch?!" << endl;


	int Smash = 0;
	int Craft = 0;
	int Halo = 0;
	int Fallout = 0;

	cout << "what is your weapon of choice (photoncanon=C battlerifle=H myfists=S VATS=F)" << endl;
	cin >> input;

	if (input == 'C')
		Craft = Craft + 1;
	else if (input == 'H')
		Halo = Halo + 1;
	else if (input == 'S')
		Smash = Smash + 1;
	else
		Fallout = Fallout + 1;


	cout << "Where do you like to live? (BaseOfOperations=C Nowhere=H NintendoHQ=S Sanctuary=F)" << endl;
	cin >> input;

	if (input == 'C')
		Craft = Craft + 1;
	else if (input == 'H')
		Halo = Halo + 1;
	else if (input == 'S')
		Smash = Smash + 1;
	else
		Fallout = Fallout + 1;


	cout << "What enemy would you rather fight? (Protossucks=C Elites=H YourFriends=S RadRoach=F)" << endl;
	cin >> input;

	if (input == 'C')
		Craft = Craft + 1;
	else if (input == 'H')
		Halo = Halo + 1;
	else if (input == 'S')
		Smash = Smash + 1;
	else
		Fallout = Fallout + 1;

	cout << "who is your companion of choice? (YourHomies=C TheArbider=H Nobody=S Piper=F)" << endl;
	cin >> input;

	if (input == 'C')
		Craft = Craft + 1;
	else if (input == 'H')
		Halo = Halo + 1;
	else if (input == 'S')
		Smash = Smash + 1;
	else
		Fallout = Fallout + 1;


	cout << "your low on resources and amo what do you do? (BuildAnSCV=C UseThirtyGrenades=H IDontNeedGuns=S ScrapGreyGarden=F)" << endl;
	cin >> input;

	if (input == 'C')
		Craft = Craft + 1;
	else if (input == 'H')
		Halo = Halo + 1;
	else if (input == 'S')
		Smash = Smash + 1;
	else
		Fallout = Fallout + 1;

	cout << "you level up what do you do? (StayANoob=C ImBadAssWithoutLevelUps=H WhatAreLevels=S PickAPerk=F)" << endl;
	cin >> input;

	if (input == 'C')
		Craft = Craft + 1;
	else if (input == 'H')
		Halo = Halo + 1;
	else if (input == 'S')
		Smash = Smash + 1;
	else
		Fallout = Fallout + 1;

	cout << "you come across a group of enemies what do you do? (ZergRush=C TakeEmAllOn=H BeatThemUp=S TagEmAllInVats=F)" << endl;
	cin >> input;

	if (input == 'C')
		Craft = Craft + 1;
	else if (input == 'H')
		Halo = Halo + 1;
	else if (input == 'S')
		Smash = Smash + 1;
	else
		Fallout = Fallout + 1;

	cout << "You are winning the game what do you do? (AllowYourOpponentToSurender=C MercEmEvenMore=H BeatEmUp=S TakeTheirCaps=F)" << endl;
	cin >> input;

	if (input == 'C')
		Craft = Craft + 1;
	else if (input == 'H')
		Halo = Halo + 1;
	else if (input == 'S')
		Smash = Smash + 1;
	else
		Fallout = Fallout + 1;

	cout << "what gamer are you? (Competetive=C ADouche=H Recriational=S ANerd=F)" << endl;
	cin >> input;

	if (input == 'C')
		Craft = Craft + 1;
	else if (input == 'H')
		Halo = Halo + 1;
	else if (input == 'S')
		Smash = Smash + 1;
	else
		Fallout = Fallout + 1;

	cout << "What is your enviorment of choice? (ABattlefield=C ACovenantShip=H FinalDestination=S TheWasteland=F)" << endl;
	cin >> input;

	if (input == 'C')
		Craft = Craft + 1;
	else if (input == 'H')
		Halo = Halo + 1;
	else if (input == 'S')
		Smash = Smash + 1;
	else
		Fallout = Fallout + 1;

	if ((Craft > Halo) && (Craft > Smash) && (Craft > Fallout))
		cout << "you should play starcraft" << endl;
	else if ((Halo > Craft) && (Halo > Smash) && (Halo > Fallout))
		cout << "you should play halo" << endl;
	else if ((Smash > Halo) && (Smash > Craft) && (Smash > Fallout))
		cout << "you should play smash" << endl;
	else if ((Fallout > Halo) && (Fallout > Smash) && (Fallout > Craft))
		cout << "you should play fallout shelter cus we can't afford fallout 3-4 PC edition" << endl;

}