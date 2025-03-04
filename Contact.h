#pragma once
#include <iostream>
#include <string>

#include "Address.h"
#include "List.h"
#include "Comparator.h"

class Contact : public Comparator<Contact> {
private:
	int contact_id;
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	Address* address;
	List<std::string> groups;
	int search_count;

public:
	bool equals(Contact contact);
	Contact& copy_contact();
	void print_contact();

	Contact();
	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address);
	Contact(const Contact& other);
	// Setters
	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_mobile_number(std::string mobile_number);
	void set_email_address(std::string email_address);
	void set_address(Address* address);
	void set_contact_id(int id);
	void set_search_count(int count);

	// Getters
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_mobile_number() const;
	std::string get_email_address() const;
	Address* get_address() const;
	Address& get_address(int n) const;
	int get_contact_id() const;
	int get_search_count() const;
	List<std::string> get_groups() const;
	Contact& get_contact(int id);

	// Virtual method to compare two contacts
	bool compare(const Contact& curr, const Contact& other, bool (*fptr)(const Contact& a, const Contact& b)) const override;
	// Overload cin for Contact
	friend std::istream& operator>>(std::istream& in, Contact& contact);
	// Overload cout for Contact
	friend std::ostream& operator<<(std::ostream& out, const Contact& contact);
	// Overload comparison operator for Contact
	bool operator==(const Contact& other);
	// Overload assignment operator for Contact
	Contact& operator=(const Contact& other);

	void add_to_group(std::string group);
	void remove_from_group(std::string group);
	void add_search_count();

	// Comparison functions
	static bool fn_less_than(const Contact& a, const Contact& b);
	static bool fn_greater_than(const Contact& a, const Contact& b);
	static bool ln_less_than(const Contact& a, const Contact& b);
	static bool ln_greater_than(const Contact& a, const Contact& b);

};