#include <iostream>
#include <string>
using namespace std;
class Address {
private:
	string house;
	string street;
	string city;
	string country;
public:
	bool equals(const Address& address);
	void print_address();
	Address copy_address();
	Address(string house, string street, string city, string country);
	Address();
	// Getters
	string get_house() const;
	string get_street() const;
	string get_city() const;
	string get_country() const;
	// Setters
	void set_house(string house);
	void set_street(string street);
	void set_city(string city);
	void set_country(string country);
	// Overload cin for Address
	friend istream& operator >> (istream& in, Address& address);
};
