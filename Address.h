#pragma once
#include <iostream>
#include <string>

class Address {
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;

public:
	bool equals(const Address& address);
	void print_address();
	Address copy_address();

	Address(std::string house, std::string street, std::string city, std::string country);
	Address();
	Address(const Address& other);

	// Getters
	std::string get_house() const;
	std::string get_street() const;
	std::string get_city() const;
	std::string get_country() const;
	// Setters
	void set_house(std::string house);
	void set_street(std::string street);
	void set_city(std::string city);
	void set_country(std::string country);
	// Overload cin for Address
	friend std::istream& operator>>(std::istream& in, Address& address);
	// Overload cout for Address
	friend std::ostream& operator<<(std::ostream& out, const Address& address);
};