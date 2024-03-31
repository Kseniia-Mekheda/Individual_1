#pragma once
#include <iostream>
#include "transport.h"

class Travel {
protected: 
	Transport* mean;
	std::string travel_destination; 

public:
	Travel();
	Travel(Transport* T, std::string country);
	Travel(const Travel& C);
	virtual ~Travel();

	virtual double getTravelPrice() const abstract;
	virtual void printTravel() const;
	Transport& getTransport() const;
	virtual void readFrom(std::istream& in);
	bool operator<(const Travel& T) const;
};

std::istream& operator>>(std::istream& in, Travel& T);

class CarTravel : public Travel {
private:
	double travel_distance;

public:
	CarTravel();
	CarTravel(Car* C, std::string country, double distance);
	CarTravel(const CarTravel& C);
	virtual ~CarTravel();


	virtual double getTravelPrice() const override;
	virtual void printTravel() const override;
	virtual void readFrom(std::istream& in) override;
};

class FamilyTravel :public Travel {
private:
	int membersQuantity;

public:
	FamilyTravel();
	FamilyTravel(Airplane* A, std::string country, int family);
	FamilyTravel(const FamilyTravel& C);
	virtual ~FamilyTravel();

	virtual double getTravelPrice() const override;
	virtual void printTravel() const override;
	virtual void readFrom(std::istream& in) override;
};

Travel** createContainer(const std::string& fileName, size_t& n); 
void printContainer(Travel** arr, size_t n);
double getPriceOfAll(Travel** arr, size_t n);

void findMaxAmongCarTravel(Travel** arr, size_t n);
void findMaxAmongSeaTravel(Travel** arr, size_t n);

Travel** onlyCarTravelContainer(Travel** arr, size_t n, size_t& carN);
Travel** onlySeaTravelContainer(Travel** arr, size_t n, size_t& carN);

void mostExpensiveRide(Travel** arr, size_t n);
int membersOfACheapestFlight(Travel** arr, size_t n);

void deleteArr(Travel** arr, size_t n);