#include <iostream>
#include <conio.h>
#include <vector>
#include <ctime>
#include <algorithm>

void task1() {

	long double dices[2000];
	long double diceCounter = 0;

	long double dice1 = 0;
	long double dice2 = 0;
	long double dice3 = 0;
	long double dice4 = 0;
	long double dice5 = 0;
	long double dice6 = 0;


	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	for (int d = 0; d <= 1999; d++) {
		dices[d] = rand() % 6 + 1;
		diceCounter++;

		if (dices[d] == 1) {
			dice1++;
		}
		if (dices[d] == 2) {
			dice2++;
		}
		if (dices[d] == 3) {
			dice3++;
		}
		if (dices[d] == 4) {
			dice4++;
		}
		if (dices[d] == 5) {
			dice5++;
		}
		if (dices[d] == 6) {
			dice6++;
		}
	}

	std::cout << "You rolled 2000 dices\n\n";

	std::cout << "1: " << dice1 << " times\n";
	std::cout << "2: " << dice2 << " times\n";
	std::cout << "3: " << dice3 << " times\n";
	std::cout << "4: " << dice4 << " times\n";
	std::cout << "5: " << dice5 << " times\n";
	std::cout << "6: " << dice6 << " times\n\n";

	system("pause");
	system("cls");

}

struct person {
	int no;
	char name;
	int value;
	std::string health;
};

void printperson(person p) {
	std::cout << p.no << "\t" << p.name << "\t" << p.value << "\t" << p.health << "\n";
}

void task2() {
	std::vector <person> people(7);

	people.at(0).name = 'H';
	people.at(0).value = 5;

	people.at(1).name = 'S';
	people.at(1).value = 19;

	people.at(2).name = 'F';
	people.at(2).value = 8;

	people.at(3).name = 'Q';
	people.at(3).value = 13;

	people.at(4).name = 'B';
	people.at(4).value = 1;

	people.at(5).name = 'N';
	people.at(5).value = 4;

	people.at(6).name = 'I';
	people.at(6).value = 14;


	std::cout << "No\t" << "Name\t" << "Value\t" << "Health bar\n";

	for (int p = 0; p <= people.size() - 1; p++) {

		people.at(p).no = p;

		for (int s = 0; s <= people.at(p).value - 1; s++) {
			people.at(p).health.push_back('*');
		}

		printperson(people.at(p));
	}

	std::cout << "\nPeople sorted:\n";

	int lasthigh = 20;
	
	for (int t = 0; t <= people.size() - 1; t++) {
		int high = 0;
		person highp;

		for (int q = 0; q <= people.size()-1; q++) {
			if (high <= people.at(q).value && people.at(q).value < lasthigh) {
				high = people.at(q).value;
				highp = people.at(q);
			}
		}
		printperson(highp);
		lasthigh = high;

	}

	std::cout << "\n";
	system("pause");
	system("cls");
}

void task3() {
	int pX = 8;
	int pY = 7;

	bool done = false;

	do {

		char grid[10][10] = {
 {'+','#','#','#','#','#','#','#','#','|'},
 {'|','X',' ',' ',' ',' ',' ',' ',' ','|'},
 {'|','#','#',' ','#','#','#','#','#','|'},
 {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
 {'|',' ','|',' ','|','#','#','#','|','|'},
 {'|',' ','|',' ','|',' ',' ',' ','|','|'},
 {'|',' ','|',' ',' ',' ',' ',' ',' ','|'},
 {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
 {'|',' ',' ','#','#','#','#','#',' ','|'},
 {'|','_','_','_','_','_','_','_','_','|'},
		};

		grid[pY][pX] = 'E';

		for (int i = 0; i < 10; i++) {

			for (int j = 0; j < 10; j++) {
				std::cout << grid[i][j];
			}
			std::cout << "\n";
		}

		std::cout << "\nReach the X to end this task\n";

		std::cout << "Use W/A/S/D to move\n";
		char move = _getch();


		switch (move) {
		case('w'):
			pY -= 1;
			if (grid[pY][pX] == '#' || grid[pY][pX] == '|') {
				pY += 1;
			}
			break;
		case('s'):
			pY += 1;
			if (grid[pY][pX] == '#' || grid[pY][pX] == '|') {
				pY -= 1;
			}
			break;
		case('a'):
			pX -= 1;
			if (grid[pY][pX] == '#' || grid[pY][pX] == '|') {
				pX += 1;
			}
			break;
		case('d'):
			pX += 1;
			if (grid[pY][pX] == '#' || grid[pY][pX] == '|') {
				pX -= 1;
			}
			break;
		default:
			std::cout << "Not valid";
		}

		if (pY >= 10) {
			pY = 9;
		}


		if (grid[pY][pX] == 'X') {
			done = true;
		}

		system("cls");
	} while (done == false);



}



void task4() {
	int pX = 8;
	int pY = 7;

	bool done = false;

	int points = 0;

	bool dot1 = false;
	bool dot2 = false;
	bool dot3 = false;
	bool dot4 = false;
	bool dot5 = false;


	do {
		std::cout << "\t\t" << points << "\n";
		char grid[10][10] = {
 {'+','#','#','#','#','#','#','#','#','|'},
 {'|','X',' ',' ',' ',' ',' ',' ',' ','|'},
 {'|','#','#',' ','#','#','#','#','#','|'},
 {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
 {'|',' ','|',' ','|','#','#','#','|','|'},
 {'|',' ','|',' ','|',' ',' ',' ','|','|'},
 {'|',' ','|',' ',' ',' ',' ',' ',' ','|'},
 {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
 {'|',' ',' ','#','#','#','#','#',' ','|'},
 {'|','_','_','_','_','_','_','_','_','|'},
};


		int dotsX[5] = {7,1,7,8,4};
		int dotsY[5] = { 1,4,5,3,9 };

		for (int o = 0; o <= 4; o++) {
			grid[dotsY[o]][dotsX[o]] = '.';
		}

		if (dot1 == true) {
			grid[dotsY[0]][dotsX[0]] = ' ';
		}
		if (dot2 == true) {
			grid[dotsY[1]][dotsX[1]] = ' ';
		}
		if (dot3 == true) {
			grid[dotsY[2]][dotsX[2]] = ' ';
		}
		if (dot4 == true) {
			grid[dotsY[3]][dotsX[3]] = ' ';
		}
		if (dot5 == true) {
			grid[dotsY[4]][dotsX[4]] = '_';
		}


		grid[pY][pX] = 'E';
		

		for (int i = 0; i < 10; i++) {

			for (int j = 0; j < 10; j++) {
				std::cout << grid[i][j];
			}
			std::cout << "\n";
		}

		std::cout << "\nCollect all the dots(.) to win the game\n";


		std::cout << "Use W/A/S/D to move\n";
		char move = _getch();

		switch (move) {
		case('w'):
			pY -= 1;
			if (grid[pY][pX] == '#' || grid[pY][pX] == '|') {
				pY += 1;
			}
			break;
		case('s'):
			pY += 1;
			if (grid[pY][pX] == '#' || grid[pY][pX] == '|') {
				pY -= 1;
			}
			break;
		case('a'):
			pX -= 1;
			if (grid[pY][pX] == '#' || grid[pY][pX] == '|') {
				pX += 1;
			}
			break;
		case('d'):
			pX += 1;
			if (grid[pY][pX] == '#' || grid[pY][pX] == '|') {
				pX -= 1;
			}
			break;
		default:
			std::cout << "Not valid";
		}

		if (pY >= 10) {
			pY = 9;
		}


		if (pY == dotsY[0] && pX == dotsX[0]) {
			dot1 = true;
			points += 5;
		}
		if (pY == dotsY[1] && pX == dotsX[1]) {
			dot2 = true;
			points += 5;
		}
		if (pY == dotsY[2] && pX == dotsX[2]) {
			dot3 = true;
			points += 5;
		}
		if (pY == dotsY[3] && pX == dotsX[3]) {
			dot4 = true;
			points += 5;
		}
		if (pY == dotsY[4] && pX == dotsX[4]) {
			dot5 = true;
			points += 5;
		}

		if (points == 25) {
			done = true;
		}
		system("cls");
	} while (done == false);

	std::cout << "You finished the game";
}


int main() {

	bool move1 = false;
	bool move2 = false;
	bool move3 = false;
	bool move4 = false;

	
	bool login = false;
	int tries = 0;
	do{
		tries += 1;

		int moves = 0;
		int user = 0;
		do {

			char arr[9] = { '1','2','3','4','5','6','7','8','9' };
			arr[user] = '*';


			std::cout << "\n  |  " << arr[0] << "  ";
			std::cout << "|  " << arr[1] << "  ";
			std::cout << "|  " << arr[2] << "  |\n";
			std::cout << "  |  " << arr[3] << "  ";
			std::cout << "|  " << arr[4] << "  ";
			std::cout << "|  " << arr[5] << "  |\n";
			std::cout << "  |  " << arr[6] << "  ";
			std::cout << "|  " << arr[7] << "  ";
			std::cout << "|  " << arr[8] << "  |\n";
			std::endl(std::cout);

			std::cout << "\nUse 4 moves to enter the passcode\n";
			std::cout << "You have 3 tries\n";

			std::cout << "\nUse W/A/S/D to move around";
			char r = _getch();

			moves += 1;

			switch (r) {
			case('w'):
				user -= 3;
				if (user < 0) {
					user += 3;
					moves--;
				}
				break;
			case('s'):
				user += 3;
				if (user > 8) {
					user -= 3;
					moves--;
				}
				break;
			case('a'):
				user -= 1;
				if (user < 0) {
					user += 1;
					moves--;
				}
				break;
			case('d'):
				user += 1;
				if (user > 8) {
					user -= 1;
					moves--;
				}
				break;
			default:
				std::cout << "Not valid";
				moves --;
			}

			if (moves == 1 && user == 3) {
				move1 = true;
			}
			if (moves == 2 && user == 4) {
				move2 = true;
			}
			if (moves == 3 && user == 1) {
				move3 = true;
			}
			if (moves == 4 && user == 2) {
				move4 = true;
			}

			if (move1 == true && move2 == true && move3 == true && move4 == true) {
				login = true;
			}

			system("cls");

		} while (moves != 4 && login == false);


		if (moves == 1 && user == 3) {
			login = true;
		}
		if (tries == 4) {
			std::exit(0);
		}
	} while (login == false);
	
	char answer;
	bool exitprogram = false;
	do {
		int number;

		std::cout << "1. Task 1\n";
		std::cout << "2. Task 2\n";
		std::cout << "3. Task 3\n";
		std::cout << "4. Task 4\n";
		std::cout << "5. Quit the program\n";

		std::cout << "\nEnter a number from 1 to 5: ";
		std::cin >> number;


		system("cls");

		switch (number) {
		case(1):
			task1();
			break;
		case(2):
			task2();
			break;
		case(3):
			task3();
			break;
		case(4):
			task4();
			break;
		case(5):
			exitprogram = true;
			break;
		default:
			std::cout << "Wrong input... Do you want to try again: (y/n)";
			std::cin >> answer;

			if (answer == 'y') {
				exitprogram = false;
			}
			else if (answer == 'n') {
				exitprogram = true;
			}
		}
		
	} while (exitprogram == false);

}
