#ifndef BASIC_LIB
#include "Contact.h"
#include <algorithm>
#include <iomanip>
#define BASIC_LIB
#include <iostream>
#include <string>
class ContactsBook {
private:
	Contact *contacts_list; // array of contacts
	int size_of_contacts;   // storage limit
	int contacts_count;     // total contacts currently stored, next contact will be 
							// stored at this count plus 1 index
public:
	void add_contact(const Contact& contact);
	int total_contacts() const;
	Contact* search_contact(std::string first_name, std::string last_name);
	Contact* search_contact(std::string phone);
	Contact* search_contact(const Address& address);
	ContactsBook(int size_of_list);
	~ContactsBook();
	ContactsBook(const ContactsBook& other);
	void print_contacts_sorted(std::string choice); // Only two choices first_name or last_name
	void merge_duplicates(); // Merge duplicates
	void print_contacts() const;	// Print all contacts in the order they were added
	void load_from_file(std::string file_name);
	void save_to_file(std::string file_name);
	Contact *copy_list(Contact *contacts_list);
	// Overload assignment operator
	ContactsBook& operator=(const ContactsBook& other);
private:
	bool full() const;
	void resize_list();
	void sort_contacts_list(Contact *contacts_list, std::string choice);

};
#endif // !BASIC_LIB
