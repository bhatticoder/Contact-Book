#ifndef BASIC_LIB
#define BASIC_LIB
#include "Address.h"
#include <iostream>
#include <string>
using namespace std;
class Contact {
private:
	string first_name;
	string last_name;
	string mobile_number;
	string email_address;
	Address *address;

public:
	bool equals(Contact contact);
	Contact* copy_contact();
	void print_contact();
	Contact();
	Contact(string first_name, string last_name, string mobile_number, string email_address, Address *address);
	// Setters
	void set_first_name(string first_name);
	void set_last_name(string last_name);
	void set_mobile_number(string mobile_number);
	void set_email_address(string email_address);
	void set_address(Address *address);
	// Getters
	string get_first_name() const;
	string get_last_name() const;
	string get_mobile_number() const;
	string get_email_address() const;
	Address* get_address() const;
	// Overload cin for Contact
	friend istream& operator >> (istream& in, Contact& contact);
};
#endif // !BASIC_LIB
