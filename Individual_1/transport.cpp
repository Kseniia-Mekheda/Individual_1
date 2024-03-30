#include "transport.h"
using namespace std;

// TRANSPORT CLASS

Transport::~Transport() {}

void Transport::print() const {
	cout << "Price of a ride: " << getPrice() << endl;
}

std::istream& operator>>(istream& in, Transport& T) {
	T.readFrom(in);
	return in;
}

// CAR CLASS

Car::Car()
	:car_brand(" "),
	car_fuel(0.)
{}

Car::Car(std::string brand, double fuel)
	:car_brand(brand),
	car_fuel(fuel)
{}

Car::Car(const Car& C)
	:car_brand(C.car_brand),
	car_fuel(C.car_fuel)
{}

Car::~Car() {}

void Car::print() const {
	cout << "Car: " << car_brand << ". ";
	Transport::print();
}

double Car::getPrice() const {
	return car_fuel * 55.;
}

Transport* Car::clone() const {
	return new Car(*this);
}

void Car::readFrom(istream& in) {
	in >> car_brand >> car_fuel;
}

string Car::getBrand() const {
	return car_brand;
}

// AIRPLANE CLASS

Airplane::Airplane()
	:airplane_company(" "),
	airplane_ticket_price(0.)
{}

Airplane::Airplane(string comp, double price)
	:airplane_company(comp),
	airplane_ticket_price(price)
{}

Airplane::Airplane(const Airplane& C)
	:airplane_company(C.airplane_company),
	airplane_ticket_price(C.airplane_ticket_price)
{}

Airplane::~Airplane() {}

void Airplane::print() const {
	cout << "Airline: " << airplane_company << ". ";
	Transport::print();
}

double Airplane::getPrice() const {
	return airplane_ticket_price;
}

Transport* Airplane::clone() const {
	return new Airplane(*this);
}

void Airplane::readFrom(std::istream& in) {
	in >> airplane_company >> airplane_ticket_price;
}

string Airplane::getBrand() const {
	return airplane_company;
}