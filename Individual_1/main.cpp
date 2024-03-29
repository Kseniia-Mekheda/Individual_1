#include "transport.h"
#include "traveling.h"
#include <iostream> 

using namespace std;

int main() {
	/*size_t n;
	Travel** container = createContainer("travel.txt", n);

	printContainer(container, n);*/

	Car C;
	cin >> C;
	C.print();

	CarTravel A;
	cin >> A;
	A.printTravel();
	return 0;
}