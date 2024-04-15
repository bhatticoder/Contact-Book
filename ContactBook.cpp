#include "ContactsBook.h"
#include <fstream>
// Constructor
ContactsBook::ContactsBook(int size_of_list)
{
	// Initialize the contacts_list array, also initialize the size and count members accordingly
	contacts_list = new Contact[size_of_list];
	size_of_contacts = size_of_list;
	contacts_count = 0;
}
// Destructor
ContactsBook::~ContactsBook()
{
	// Delete the contacts_list array
	delete[] contacts_list;
}
void ContactsBook::add_contact(const Contact& contact)
{
	// Check if the list is full, if it is full call the resize function
	if (full())
	{
		resize_list();
	}
	// If list is not full add the contact to the end of the array
	contacts_list[contacts_count] = contact;
	// Increment the count
	contacts_count++;
}
int ContactsBook::total_contacts() const
{
	// Return the total contacts currently stored
	return contacts_count;
}
bool ContactsBook::full() const
{
	// Return true if list is full, false otherwise
	return size_of_contacts == contacts_count;

}
void ContactsBook::resize_list()
{
	// Allocate a temporary new array of double the current size
	int new_size = size_of_contacts * 2;
	Contact* temp_contacts_list = new Contact[new_size];
	// Copy the contacts_list array to the new array
	for (int i = 0; i < contacts_count; ++i) {
		temp_contacts_list[i] = *(contacts_list[i].copy_contact());
	}
	// Delete the old array
	delete[] contacts_list;
	// Update the contacts_list pointer to point to the new array
	contacts_list = temp_contacts_list;
	size_of_contacts = new_size;
}
Contact* ContactsBook::search_contact(string first_name, string last_name)
{
	// Search the contact in the list according to the given first name and last name
	for (size_t i = 0; i < contacts_count; i++)
	{
		// If found return a copy of the contact using copy func
		if (contacts_list[i].get_first_name() == first_name || contacts_list[i].get_last_name() == last_name)
		{
			return contacts_list[i].copy_contact();
		}
	}
	// If not found return nullptr
	return nullptr;
}
Contact* ContactsBook::search_contact(string phone)
{
	// Search the contact in the list according to the given phone number
	for (size_t i = 0; i < contacts_count; i++)
	{
		// If found return a copy of the contact using copy func
		if (contacts_list[i].get_mobile_number() == phone)
		{
			return contacts_list[i].copy_contact();
		}
	}
	// If not found return nullptr
	return nullptr;
}
Contact* ContactsBook::search_contact(const Address& address)
{
	// Search the contact in the list according to the given address
	for (size_t i = 0; i < contacts_count; i++)
	{
		// If found return a copy of the contact using copy func
		if (contacts_list[i].get_address()->equals(address))
		{
			return contacts_list[i].copy_contact();
		}
	}
	// If not found return nullptr
	return nullptr;
}
Contact* ContactsBook::copy_list(Contact *contacts_list)
{
	// Implement this function to return a copy of the contacts_list array
	// This function is used to create a copy of the contacts_list array before sorting
	// So that the original insertion order is not changed
	Contact *temp = new Contact[contacts_count];
	for (size_t i = 0; i < contacts_count; i++)
	{
		temp[i] = *(contacts_list[i].copy_contact());
	}
	return temp;

}
bool compare_contacts(Contact& contact1, Contact& contact2, string choice) {
	if (choice == "first_name") {
		return contact1.get_first_name() > contact2.get_first_name();
	}
	else if (choice == "last_name") {
		return contact1.get_last_name() > contact2.get_last_name();
	}
	else {
		return contact1.get_first_name() > contact2.get_first_name();
	}
}
void ContactsBook::print_contacts_sorted(string choice)
{
	// Create a copy of this->contacts_list array
	Contact *copy = copy_list(this->contacts_list);
	// Call the sort function sort_contacts_list to sort the newly created copy
	sort_contacts_list(copy, choice);
	// Print the contacts in following format:
	// [First Name] [Last Name] [Mobile] [Email]
	for (size_t i = 0; i < contacts_count; i++)
	{
		cout << left << setw(10) << copy[i].get_first_name() << setw(10) << copy[i].get_last_name() << setw(14)
			<< copy[i].get_mobile_number() << copy[i].get_email_address() << endl;
		// Call the address print function to print address on next line
		copy[i].get_address()->print_address();
		cout << endl;
	}
	delete[] copy;
}
void ContactsBook::sort_contacts_list(Contact *contacts_list, std::string choice)
{
	// Bubble Sort
	for (int i = 0; i < contacts_count - 1; ++i) {
		for (int j = 0; j < contacts_count - i - 1; ++j) {
			if (compare_contacts(contacts_list[j], contacts_list[j + 1], choice)) {
				Contact temp = contacts_list[j];
				contacts_list[j] = contacts_list[j + 1];
				contacts_list[j + 1] = temp;
			}
		}
	}

}
void ContactsBook::print_contacts() const {
	// Print the contacts in the order they were added
	for (size_t i = 0; i < contacts_count; i++) {
		cout << left << setw(10) << contacts_list[i].get_first_name() << setw(10) << contacts_list[i].get_last_name()
			<< setw(14) << contacts_list[i].get_mobile_number() << contacts_list[i].get_email_address() << endl;
		// Call the address print function to print address on next line
		contacts_list[i].get_address()->print_address();
		std::cout << std::endl;
	}
}
void ContactsBook::merge_duplicates() {
	// Iterate through the contacts list to look for duplicates
	for (size_t i = 0; i < contacts_count; i++) {
		for (size_t j = i + 1; j < contacts_count; j++) {
			// If found a duplicate
			if (contacts_list[i].equals(contacts_list[j])) {
				// Shift the subsequent contacts to fill the gap
				for (size_t k = j; k < contacts_count - 1; ++k) {
					contacts_list[k] = contacts_list[k + 1];
				}
				// Decrement the count to remove the duplicate
				--contacts_count;
				--j;
			}
		}
	}
}
void ContactsBook::load_from_file(string file_name)
{
	// Follows strict format: first_name,last_name,mobile_number,email_address
	// 						  house,street,city,country
	ifstream file(file_name);
	if (!file.is_open())
	{
		cout << "Error opening file" << endl;
		return;
	}
	int count;
	file >> count;
	file.ignore();
	for (size_t i = 0; i < count; i++)
	{
		string first_name, last_name, mobile_number, email_address;
		// Read the contact attributes
		getline(file, first_name, ',');
		getline(file, last_name, ',');
		getline(file, mobile_number, ',');
		getline(file, email_address);
		// Read the address attributes
		string house, street, city, country;
		getline(file, house, ',');
		getline(file, street, ',');
		getline(file, city, ',');
		getline(file, country);
		// Skip any blank lines
		while (file.peek() == '\n') {
			file.ignore();
			if (file.eof()) break;  // Break the loop if the end of the file has been reached
		}
		// Create a new address object
		Address* address = new Address(house, street, city, country);
		// Create a new contact object
		Contact contact(first_name, last_name, mobile_number, email_address, address);
		// Add the contact to the contact book
		add_contact(contact);
	}
	file.close();
}
void ContactsBook::save_to_file(string file_name)
{
	ofstream file(file_name);
	if (!file.is_open())
	{
		cout << "Error opening file" << endl;
		return;
	}
	// Write the contacts count to the file
	file << contacts_count << endl;
	for (size_t i = 0; i < contacts_count; i++)
	{
		// Write the contact attributes to the file
		file << contacts_list[i].get_first_name() << "," << contacts_list[i].get_last_name() << "," << contacts_list[i].get_mobile_number()
			<< "," << contacts_list[i].get_email_address() << endl;
		// Write the address attributes to the file
		file << contacts_list[i].get_address()->get_house() << "," << contacts_list[i].get_address()->get_street() 
			<< "," << contacts_list[i].get_address()->get_city() << "," << contacts_list[i].get_address()->get_country() << endl;
		file << endl;
	}
	file.close();
}
