//GL;HF
#include <iostream>
using namespace std;

int main () {

	int choice = 0;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	cout << "1) addition 2) subtraction 3) multiplication 4) division: \n";
	cin >> choice;

//For bad input regarding the choice.  
	if (choice < 1 or choice > 5) {
		cout << "BAD INPUT!\n";
		exit(0);
	}
//User inputting two numbers. 
	cout << "Please enter two numbers: \n"; 
	cin >> num1;
	cin >> num2;

//For bad input. 
	if (!cin) {
		cout << "BAD INPUT!\n";
		exit(0);
	}

//For addition. 
	if (choice == 1) {
		num3 = num1 + num2;
		cout << num3 << endl;
		exit(0);
	}

//For subtraction. 
	if (choice == 2) {
		num3 = num1 - num2;
		cout << num3 << endl;
		exit(0);
	}

//For multiplication.
	if (choice == 3) {
		num3 = num1 * num2;
		cout << num3 << endl;
		exit(0);
	}

//For regular division. 
	if (choice == 4 && num2 > 0) {
		num3 = num1 / num2;
		cout << num3 << endl;
		exit(0);
	}

//For division by zero. 
	if (choice == 4 && num2 == 0) {
		cout << "BAD INPUT!\n";
		exit(0);
	}

//For modulus division. 	
	if (choice == 5 && num2 == 0) {
		cout << "BAD INPUT!\n";
		exit(0);
	}

	else {
		cout << num1 % num2 << endl;
		exit(0);
	}
}
