#include <iostream>
#include <string>
using namespace std;

void die() {
	cout << "Bad input\n";
	exit(1);
}

string mandarin(int i) {
		if (i == 0) return "ling";								
		if (i == 1) return "yi";
		if (i == 2) return "er";
		if (i == 3) return "san";
		if (i == 4) return "si";
		if (i == 5) return "wu";
		if (i == 6) return "liu";
		if (i == 7) return "qi";
		if (i == 8) return "ba";
		if (i == 9) return "jiu";
		if (i == 10) return "shi";	
}

int main() {
	int min = 0, max = 0, stepSize = 0;
	//User inputs the maximum, minimum, and step values. 
	cout << "Please enter a number that you want to count up to in Mandarin. ";
	cin >> max;
//	if (!cin || max < 0 || max > 100) die();
	cout << "Please enter what number to start with: "; 
	cin >> min;
//	if (!cin || min < 0 || min > 100) die();
	cout << "What step size do you want to use?\n";
	cin >> stepSize;
//	if (!cin || stepSize < 0 || stepSize > 100) die();

	//Outputting numbers above 10. 	
	for (int i = min; i <= max; i += stepSize) {
		cout << i << " "; 	
			if (i == 99990) cout << mandarin(i) << " jiu wan jiu qian jiu bai jiu shi" << endl;
			else if (i > 99990 && i <= 99999) cout << mandarin(i) << " jiu wan jiu qian jiu bai jiu shi " << mandarin(i % 10) << endl;
			else if ((i > 20 && i < 30) || (i > 30 && i < 40) || (i > 40 && i < 50) || (i > 50 && i < 60) || (i > 60 && i < 70) || (i > 70 && i < 80) || (i > 80 && i < 90) || (i > 90 && i < 100)) cout << mandarin(i / 10) << " shi " << mandarin(i % 10) << endl;
			else if (i == 20 || i == 30 || i == 40 || i == 50 || i == 60 || i == 70 || i == 80 || i == 90) cout << mandarin(i / 10) << " shi" << endl;
			else if (i >= 11 && i <= 19) cout << "shi " << mandarin(i % 10) << endl;
			else if (i >=0 && i <= 10) cout << mandarin(i) << endl;
			//else die();
	}
}					


