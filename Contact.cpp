#include "Contact.h"
#include<iostream>
#include<string>
using namespace std;
// Constructors
Contact::Contact()
{
	first_name = "";
	last_name = "";
	mobile_number = "";
	email_address = "";
	address = nullptr;
}
Contact::Contact(string first_name, string last_name, string mobile_number, string email_address, Address *address)
{
	set_first_name(first_name);
	set_last_name(last_name);
	set_mobile_number(mobile_number);
	set_email_address(email_address);
	set_address(address);
}
// Setters
void Contact::set_first_name(string first_name)
{
	if (first_name.size() != 0)
		this->first_name = first_name;
}
void Contact::set_last_name(string last_name)
{
	if (last_name.size() != 0)
		this->last_name = last_name;
}
void Contact::set_mobile_number(string mobile_number)
{
	if (mobile_number.size() != 0 && mobile_number.size() == 11)
		this->mobile_number = mobile_number;
}
void Contact::set_email_address(string email_address)
{
	if (email_address.size() != 0)
		this->email_address = email_address;
}
void Contact::set_address(Address *address)
{
	if (address != nullptr) {
		this->address = address;
	}
}
// Getters
string Contact::get_first_name() const { return first_name; }
string Contact::get_last_name() const { return last_name; }
string Contact::get_mobile_number() const { return mobile_number; }
string Contact::get_email_address() const { return email_address; }
Address* Contact::get_address() const { return address; }
// equals() method to test if passed contact is equal to *this
bool Contact::equals(Contact contact)
{
	if (this->first_name == contact.first_name && this->last_name == contact.last_name && this->mobile_number == contact.mobile_number &&
		this->email_address == contact.email_address && this->address->equals(*contact.address))
	{
		return true;
	}
	return false;
}
void Contact::print_contact()
{
	cout << "\nName: " << first_name << " " << last_name << endl;
	cout << "Mobile Number: " << mobile_number << endl;
	cout << "Email Address: " << email_address << endl;
	cout << "Address: " << address->get_house() << ", " << address->get_street() << ", " 
		<< address->get_city() << ", " << address->get_country() << endl;
}
// Return a deep copy of *this
Contact* Contact::copy_contact()
{
	Contact* copiedContact = new Contact();
	copiedContact->first_name = this->first_name;
	copiedContact->last_name = this->last_name;
	copiedContact->mobile_number = this->mobile_number;
	copiedContact->email_address = this->email_address;
	copiedContact->address = new Address(this->address->get_house(),
		this->address->get_street(),
		this->address->get_city(),
		this->address->get_country());
	return copiedContact;
}
// Overload cin for Contact
istream& operator >> (istream& in, Contact& contact)
{
	cout << "\nEnter first name: ";
	in >> contact.first_name;
	cout << "Enter last name: ";
	in >> contact.last_name;
	cout << "Enter mobile number: ";
	in >> contact.mobile_number;
	cout << "Enter email address: ";
	in >> contact.email_address;
	cout << "\nEnter address: " << endl;
	if (contact.address == nullptr) {
		contact.address = new Address();
	}
	// Will use overloaded cin for Address
	in >> *(contact.address);
	return in;
}
