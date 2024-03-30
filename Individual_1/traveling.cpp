#include "traveling.h"
#include <fstream>
#include <string>
using namespace std;

// TRAVEL CLASS

Travel::Travel()
	:mean(nullptr), 
	travel_destination(" ")
{}

Travel::Travel(Transport* T, string country)
	:mean(T), 
	travel_destination(country)
{}

Travel::Travel(const Travel& C)
	:mean(C.mean->clone()),
	travel_destination(C.travel_destination)
{}

Travel::~Travel() {
	delete mean;
}

void Travel::printTravel() const {
	cout << "Destination: " << travel_destination << ". Price of travel: " << getTravelPrice() << endl;
}

Transport& Travel::getTransport() const {
	return *mean;
}

void Travel::readFrom(std::istream& in) {
	mean->readFrom(in);
}

std::istream& operator>>(istream& in, Travel& T) {
	T.readFrom(in);
	return in;
}

bool Travel::operator<(const Travel& T) const {
	return getTravelPrice() < T.getTravelPrice();
}

// CAR TRAVEL CLASS

CarTravel::CarTravel()
	:Travel(new Car, " "),
	travel_distance(0.)
{}

CarTravel::CarTravel(Car* C, string country, double distance)
	:Travel(C, country),
	travel_distance(distance)
{}

CarTravel::CarTravel(const CarTravel& C)
	:Travel(C),
	travel_distance(C.travel_distance)
{}

CarTravel::~CarTravel() {}


double CarTravel::getTravelPrice() const {
	return (mean->getPrice() * travel_distance) / 100;
}

void CarTravel::printTravel() const {
	cout << "Travel by car. Car brand: " << mean->getBrand() << ". ";
	Travel::printTravel();
}

void CarTravel::readFrom(istream& in) {
	Travel::readFrom(in);
	in >> travel_destination >> travel_distance;
}

// FAMILY TRAVEL CLASS

FamilyTravel::FamilyTravel()
	:Travel(new Airplane, " "),
	membersQuantity(0)
{}

FamilyTravel::FamilyTravel(Airplane* A, string country, int family)
	:Travel(A, country),
	membersQuantity(family)
{}

FamilyTravel::FamilyTravel(const FamilyTravel& C)
	:Travel(C),
	membersQuantity(C.membersQuantity)
{}

FamilyTravel::~FamilyTravel() {}

double FamilyTravel::getTravelPrice() const {
	return (mean->getPrice() + 4000) * membersQuantity;
}

void FamilyTravel::printTravel() const {
	cout << "Family travel to the sea. Airline: " << mean->getBrand() << ". ";
	Travel::printTravel();
}

void FamilyTravel::readFrom(istream& in) {
	Travel::readFrom(in);
	in >> travel_destination >> membersQuantity;
}

// GENERAL 

Travel** createContainer(const string& fileName, size_t& n) {
	fstream fin(fileName);
	fin >> n;
	size_t count = 0;

	Travel** arr = new Travel * [n];
	for (size_t i = 0; i < n; ++i) {
		char type;
		fin >> type;
		if (type == Car::CAR_TYPE) {
			arr[count] = new CarTravel();
			fin >> *arr[count];
			++count;
		}
		else if (type == Airplane::AIRPLANE_TYPE) {
			arr[count] = new FamilyTravel();
			fin >> *arr[count];
			++count;
		}
		else {
			string line;
			getline(fin, line);
		}
	}

	fin.close();
	return arr;
}

void printContainer(Travel** arr, size_t n) {
	for (size_t i = 0; i < n; ++i) {
		arr[i]->printTravel();
	}
	cout << endl;
}

double getPriceOfAll(Travel** arr, size_t n) {
	double sum = 0;
	for (size_t i = 0; i < n; ++i) {
		sum += arr[i]->getTravelPrice();
	}

	return sum;
}

void findMaxAmongCarTravel(Travel** arr, size_t n) {
	int count = 0;
	for (size_t i = 0; i < n; ++i) {
		if (typeid(*arr[i]) == typeid(CarTravel)) {
			count = i;
			break;
		}
	}

	Travel* max = arr[count];
	for (size_t i = count + 1; i < n; ++i) {
		if (typeid(*arr[i]) == typeid(CarTravel)) {
			if (*max < *arr[i]) {
				max = arr[i];
			}
		}
	}

	cout << "The most expencive travel among car travels is: " << endl;
	max->printTravel();
}

void findMaxAmongSeaTravel(Travel** arr, size_t n) {
	int count = 0;
	for (size_t i = 0; i < n; ++i) {
		if (typeid(*arr[i]) == typeid(FamilyTravel)) {
			count = i;
			break;
		}
	}

	Travel* max = arr[count];
	for (size_t i = count + 1; i < n; ++i) {
		if (typeid(*arr[i]) == typeid(FamilyTravel)) {
			if (*max < *arr[i]) {
				max = arr[i];
			}
		}
	}

	cout << "The most expencive travel among family travels is: " << endl;
	max->printTravel();
}