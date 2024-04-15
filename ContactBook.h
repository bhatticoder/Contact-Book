#ifndef BASIC_LIB
#include "Contact.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#define BASIC_LIB
class ContactsBook {
private:
	Contact *contacts_list; // array of contacts
	int size_of_contacts;   // storage limit
	int contacts_count;     // total contacts currently stored, next contact will be 
							// stored at this count plus 1 index
public:
	void add_contact(const Contact& contact);
	int total_contacts() const;
	Contact* search_contact(string first_name, string last_name);
	Contact* search_contact(string phone);
	Contact* search_contact(const Address& address);
	ContactsBook(int size_of_list);
	~ContactsBook();
	void print_contacts_sorted(string choice); // Only two choices first_name or last_name
	void merge_duplicates(); // Merge duplicates
	void print_contacts() const;	// Print all contacts in the order they were added
	void load_from_file(string file_name);
	void save_to_file(string file_name);
	Contact *copy_list(Contact *contacts_list);
private:
	bool full() const;
	void resize_list();
	void sort_contacts_list(Contact *contacts_list, string choice);
};
#endif // !BASIC_LIB
