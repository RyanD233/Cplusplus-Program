#include "GroceryTracker.h"
#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
using namespace std;

// Adds an item to the item map or increments an item count if the item is already in the map
void GroceryTracker::addItem(string itemName) {
	// Increments if the item is already in the map
	if (items.count(itemName) == 1) {
		items.at(itemName)++;
	}
	else {
		// Adds the item to the map
		items.emplace(itemName, 1);
	}
}

// Lets the user search for an item and prints the count of that item
void GroceryTracker::frequencyOneItem() {
	string itemName;
	cout << "Enter the item you are looking for: ";
	// Take user input for the item they are searching for
	cin >> itemName;
	cout << endl;

	// If it is found in the map, prints the name and count
	if (items.count(itemName) == 1) {
		cout << itemName << ": " << items.at(itemName) << endl;
	}
	else {
		// Or gives an error message
		cout << "Item not found." << endl;
	}
}

// Prints out the list of items and their counts
void GroceryTracker::frequencyAllItems() {
	cout << setw(15) << "Item Name" << setw(6) << "Count" << endl;
	cout << "-----------------------------------------------" << endl;

	// Runs through the items map printing each name and count
	for (auto i = items.begin(); i != items.end(); i++) {
		cout << right << setw(15) << i->first << ": " << i->second << endl;
	}
}

// Prints out a histogram visual for the user with the counts shown as asterisks
void GroceryTracker::histogram() {
	cout << setw(15) << "Item Name" << setw(6) << "Count" << endl;
	cout << "-----------------------------------------------" << endl;

	// Runs through the items map printing the item names
	for (auto i = items.begin(); i != items.end(); i++) {
		cout << right << setw(15) << i->first << ": ";
		// Prints asterisks equal to the count number of the item
		for (int j = 0; j < i->second; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

// Displays a menu of choices for the user that runs the other functions based on the choice
void GroceryTracker::displayMenu() {
	// Flag variable for the menu loop
	bool quit = false;
	int input;

	// Takes input from the user until they want to quit(entering 4)
	while (!quit) {
		cout << "To analyze data, enter the corresponding number: " << endl;
		cout << "1. Show the frequency of a single item." << endl;
		cout << "2. Show the frequency of all items." << endl;
		cout << "3. Show the frequency of all items in a histogram." << endl;
		cout << "4. Quit" << endl;

		try {
			cin >> input;
			// If the input is not an integer 1 through 4, gives an error message and resets the loop
			if (cin.fail() || input > 4 || input < 1) {
				cin.clear();
				cin.ignore();
				throw -1;
			}
			else if (input == 1) {
				frequencyOneItem();
			}
			else if (input == 2) {
				frequencyAllItems();
			}
			else if (input == 3) {
				histogram();
			}
			// The loop is exited if the input is 4 and the program closes
			else if (input == 4) {
				quit = true;
			}
		}
		catch (int error) {
			cout << "Bad input." << endl;
		}
	}
}

// Reads through the input file and adds items to the items map
void GroceryTracker::readInputFile() {
	// Sets up input stream
	ifstream itemsFS;
	string itemName;

	// Opens CS210_Project_Three_Input_File.txt
	itemsFS.open("CS210_Project_Three_Input_File.txt");
	// Checks that the file successefully opened
	if (itemsFS.is_open()) {
		// Runs through the whole file
		while (!itemsFS.fail()) {
			itemsFS >> itemName;
			addItem(itemName);

			// Breaks out of the loop if the input fails
			if (!itemsFS.good()) {
				break;
			}
		}
	}
	// Closes the input file
	itemsFS.close();
}

// Creates a .dat file of the map for a backup
void GroceryTracker::createDataFile() {
	// Creates an output stream
	ofstream itemsFS;
	// Opens a file to overwrite or makes a new file to write to
	itemsFS.open("frequency.dat");

	// Checks if the file is open
	if (itemsFS.is_open()) {
		// Runs through the items map and writes each item and count to the file
		for (auto i = items.begin(); i != items.end(); i++) {
			itemsFS << i->first << ": " << i->second << endl;
		}
	}
	// Closes the file
	itemsFS.close();
}

int main() {
	// Creates GroceryTracker object
	GroceryTracker tracker;

	tracker.readInputFile();
	tracker.createDataFile();
	tracker.displayMenu();

	return 0;
}
