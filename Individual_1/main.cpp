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

	cout << endl;
	size_t carSize;
	Travel** carContainer = onlyCarTravelContainer(container, n, carSize);
	cout << "Container with car travels only: " << endl;
	printContainer(carContainer, carSize);

	cout << endl;

	size_t seaSize;
	Travel** seaContainer = onlySeaTravelContainer(container, n, seaSize);
	cout << "Container with sea travels only: " << endl;
	printContainer(seaContainer, seaSize);

	cout << "Car Travel with the most expensive car ride: " << endl;
	mostExpensiveRide(carContainer, carSize);

	cout << endl;
	cout << "Family members quantity of a cheapest ride: " << membersOfACheapestFlight(seaContainer, seaSize) << endl;
	
	for (size_t i = 0; i < n; ++i) {
		delete container[i];
	}
	delete[] container;

	delete[] carContainer;
	delete[] seaContainer;
	return 0;
}