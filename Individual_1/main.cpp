#include "transport.h"
#include "traveling.h"
#include <iostream> 

using namespace std;

int main() {
	size_t n;
	Travel** container = createContainer("travel.txt", n);
	
	cout << "Your container: " << endl;
	printContainer(container, n);

	cout << "Sum of the prices of all travellings: " << getPriceOfAll(container, n) << " usd" << endl;

	cout << endl;
	findMaxAmongCarTravel(container, n);

	cout << endl;
	findMaxAmongSeaTravel(container, n);


	return 0;
}