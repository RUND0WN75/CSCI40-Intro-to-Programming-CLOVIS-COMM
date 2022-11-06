#include <iostream>
#include <cmath>
using namespace std;

//Walkup & Heckathorn

//Vetting for bad input.
void die() {
	cout << "BAD INPUT!\n";
	exit(1);
}

bool complimentary_primes(int x, int y) {

	//Vetting for bad input. 
	if (!cin) die();
	if (x < 0 || y < 0) return false;

	//Checking for prime numbers.
	for (int i = 2; i <= x / 2; i++) {
		if (x % i ==0) {
			return false;
		}
	}

	for (int i = 2; i <= y / 2; i++) {
		if (y % i == 0) {
			return false;
		}
	}

	//Checking if the distance between the numbers is two apart.
	if (abs(x - y) == 2) {
		return true;
	}

	return false;

}

bool perfect_number(int x) {
	//Vetting for bad input. 
	if (!cin) die();
	
	int div, sum = 0;
	for (int i = 1; i < x; i++) {
		div = x % i;
		if (div == 0) sum = sum + i;
		if (sum == x) {
			return true;
		} 
	}
	return false;
}

int main() {
	cout << "Welcome to Coding World!\n";
	cout << "Input two numbers to see if they are twin primes:\n";
	int x = 0, y = 0;
	cin >> x >> y;
	cout << boolalpha << complimentary_primes(x, y) << endl;
	cout << "Input one number to see if it is perfect:\n";
	cin >> x;
	cout << boolalpha << perfect_number(x) << endl;
}
