#pragma once
#include <iostream>

class Transport {
public:
	virtual ~Transport();

	virtual void print() const;
	virtual double getPrice() const abstract;
	virtual Transport* clone() const abstract;
	virtual void readFrom(std::istream& in) abstract;
	virtual std::string getBrand() const abstract;
};

std::istream& operator>>(std::istream& in, Transport& T); 

class Car : public Transport {
private:
	std::string car_brand;
	double car_fuel; // liters per 100 km

public:
	static const char CAR_TYPE = 'C';
	Car();
	Car(std::string brand, double fuel);
	Car(const Car& C);
	virtual ~Car();

	virtual void print() const override;
	virtual double getPrice() const override;
	virtual Transport* clone() const override;
	virtual void readFrom(std::istream& in) override;

	virtual std::string getBrand() const override;
};

class Airplane : public Transport {
private:
	std::string airplane_company;
	double airplane_ticket_price;

public:
	static const char AIRPLANE_TYPE = 'A';
	Airplane();
	Airplane(std::string comp, double price);
	Airplane(const Airplane& C);
	virtual ~Airplane(); 

	virtual void print() const override;
	virtual double getPrice() const override;
	virtual Transport* clone() const override;
	virtual void readFrom(std::istream& in) override;
	
	virtual std::string getBrand() const override;
};