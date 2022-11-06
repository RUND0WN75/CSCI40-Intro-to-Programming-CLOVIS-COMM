#include <iostream>
using namespace std;

void die() {
	cout << "BAD INPUT!" << endl;
	exit(1);
}

int main() {
	const int ADD = 1;
	const int MULTIPLY = 2;
	const int MAX_SIZE = 20; //At most a 20x20 table
	int choice = 0, min = 0, max = 0;
	cout << "Choose:\n";
	cout << "1. Addition Table\n";
	cout << "2. Times Table\n";
	//YOU: Input choice here, and vet it for correctness
	cin >> choice;
	if (!cin || choice <= 0 || choice >= 3) die(); //Prints "BAD INPUT!" and quits.

	cout << "Please enter the smallest number on the table:\n";
	cout << "Please enter the largest number on the table:\n";
	//YOU: Input min here, and make sure cin is not false
	cin >> min;
	if (!cin || min < 0) die();

	//YOU: Input max here, and make sure that cin is not false,
	// that min is not bigger than max, and that you will not
	// be outputting more than a 20x20 table
	cin >> max;
	if (!cin || max < min || (max - min) + 1 > MAX_SIZE) die(); 

	//YOU: Now output the table
	//Start by printing a + or X, then do the column headers
	//Then do each row, starting with a row header
	//Each entry should have a tab separating each one
	//cout << "\t"; //This is how you output a tab

	//Addition table
	if (choice == ADD) {
		cout << "+\t";
		for (int i = 0; i <= (max - min); i++) { //Outputs the row 
				cout << i + max << "\t"; 
			}
		cout << endl;
			for (int i = 0; i <= (max - min); i++) { //Outputs the column
				cout << i + min << "\t";
				for (int j = 0; j <= (max - min); j++) {
					cout << (i + j) + (min * 2) << "\t";
				}
				cout << endl;
			}
		}
	//Multiplication table. 
	if (choice == MULTIPLY) {
		cout << "X\t";
		for (int i = 0; i <= (max - min); i++) {
				cout << i + min << "\t"; 
			} cout << endl;
		for (int i = 0; i <= (max -  min); i++) {
			cout << i + min << "\t";
			for (int j = 0; j <= (max - min); j++) { 
				cout << (i + min) * (j + min) << "\t"; 
					
			} cout << endl;
		}
	}
	}
