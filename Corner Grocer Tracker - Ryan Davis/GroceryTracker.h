#include <map>
#include <string>
using namespace std;

class GroceryTracker {
public:
	void addItem(string itemName);
	void frequencyOneItem();
	void frequencyAllItems();
	void histogram();
	void displayMenu();
	void readInputFile();
	void createDataFile();
private:
	// A map with items as keys and their frequencies as values
	map<string, int> items;
};

