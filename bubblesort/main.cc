//Bubble sort implementation
//Loop through the input array, find the maximum element and put it into the sorted_array
// and then clear the maximum element from the read_array
#include <iostream>
#include <climits>
using namespace std;

const int MAX_SIZE = 100;

//Array contains the array we're searching through
//arr_size is the size of the array
//We will write the index of the maximum number into index_no
//Call it in main like this: int max = max_element(sorted_array,numbers_read,index_no);
int max_element(int array[], int arr_size, int &index_no) {
	int indexBiggest = array[0];
	for (int i = 0; i < arr_size; i++) {
		if (array[i] > indexBiggest) {
			indexBiggest = array[i];
			index_no = i;
		}
	}
	return indexBiggest;
}
int main() {
	//First read in numbers until a 0 is read
	int numbers_read = 0; 
	int read_array[MAX_SIZE] = {};

	cout << "Please insert numbers to sort (0 to end)\n";
	while (cin) {
		int temp;
		cin >> temp; 
		if (!cin || temp == 0 || numbers_read >= MAX_SIZE) break;
		read_array[numbers_read++] = temp;
	}
	//Print out array
	cout << "You have entered the following array: " << endl;
	for (int i = 0; i < numbers_read; i++)
		cout << "Element " << i << ": " << read_array[i] << endl;

	//Now sort the array
	int sorted_array[MAX_SIZE] = {};
	for (int i = 0; i < numbers_read; i++) {
		int max_element = INT_MIN;
		int location;
		for (int j = 0; j < numbers_read; j++) {
			if (max_element < read_array[j]) {
				max_element = read_array[j];
				location = j;
			}
		}
		sorted_array[i] = max_element;
		read_array[location] = INT_MIN;

	}

	//Print out the sorted array
	cout << "Here is the sorted array: " << endl;
	for (int i = 0; i < numbers_read; i++) {
		cout << "Element " << i << ": " << sorted_array[i] << endl;
	}
}
