#include "Address.h"
#include<iostream>
#include<string>
using namespace std;
// Constructors
Address::Address() {
	house = "";
	street = "";
	city = "";
	country = "";
}
Address::Address(std::string house, std::string street, std::string city, std::string country) {
	this->house = house;
	this->street = street;
	this->city = city;
	this->country = country;
}
// Getters
string Address::get_house() const { return house; }
string Address::get_street() const { return street; }
string Address::get_city() const { return city; }
string Address::get_country() const { return country; }
// Setters
void Address::set_house(std::string house) {
	this->house = house;
}
void Address::set_street(std::string street) {
	this->street = street;
}
void Address::set_city(std::string city) {
	this->city = city;
}
void Address::set_country(std::string country) {
	this->country = country;
}
// equals() method to check if passed address is equal to *this
bool Address::equals(const Address& address)
{
	if (this == &address) {
		return true;
	}
	if (this->house != address.house ||
		this->street != address.street ||
		this->city != address.city ||
		this->country != address.country)
	{
		return false;
	}
	return true;
}
// print the address in one line in this format: House, Street, City, Country
void Address::print_address()
{
	cout << house << ", " << street << ", " << city << ", " << country << endl;
}
// Return a copy of current object
Address Address::copy_address()
{
	return Address(house, street, city, country);
}
// Overload cin for Address
std::istream& operator >> (std::istream& in, Address& address)
{
	string newHouse;
	string newStreet;
	string newCity;
	string newCountry;
	in.ignore();
	cout << "Enter house: ";
	getline(in, newHouse);
	cout << "Enter street: ";
	getline(in, newStreet);
	cout << "Enter city: ";
	getline(in, newCity);
	cout << "Enter country: ";
	getline(in, newCountry);
	address.set_house(newHouse);
	address.set_street(newStreet);
	address.set_city(newCity);
	address.set_country(newCountry);
	return in;
}
