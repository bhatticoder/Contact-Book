#include "Contact.h"

// Constructors
Contact::Contact()
{
	first_name = "";
	last_name = "";
	mobile_number = "";
	email_address = "";
	address = nullptr;
	search_count = 0;
	set_contact_id(0);
}

Contact::Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address)
{
	set_first_name(first_name);
	set_last_name(last_name);
	set_mobile_number(mobile_number);
	set_email_address(email_address);
	set_address(address);
	search_count = 0;
	set_contact_id(0);
}

Contact::Contact(const Contact& other)
{
		this->contact_id = other.contact_id;
		this->first_name = other.first_name;
		this->last_name = other.last_name;
		this->mobile_number = other.mobile_number;
		this->email_address = other.email_address;
		if (other.address != nullptr) {
			this->address = new Address(other.address->get_house(), other.address->get_street(), other.address->get_city(), other.address->get_country());
		}
		else {
			this->address = nullptr;
		}
		this->search_count = other.search_count;
}

//Contact::~Contact()
//{
//	delete address;
//}

// Setters
void Contact::set_first_name(std::string first_name)
{
	if (first_name.size() != 0)
		this->first_name = first_name;
}
void Contact::set_last_name(std::string last_name)
{
	if (last_name.size() != 0)
		this->last_name = last_name;
}
void Contact::set_mobile_number(std::string mobile_number)
{
	if (mobile_number.size() != 0 && mobile_number.size() == 11)
		this->mobile_number = mobile_number;
}
void Contact::set_email_address(std::string email_address)
{
	if (email_address.size() != 0)
		this->email_address = email_address;
}
void Contact::set_address(Address* address)
{
	if (address != nullptr) {
		this->address = new Address(address->get_house(), address->get_street(), address->get_city(), address->get_country());
	}
}

void Contact::set_contact_id(int id)
{
	this->contact_id = id;
}

void Contact::set_search_count(int count)
{
	this->search_count = count;
}

// Getters
std::string Contact::get_first_name() const { return first_name; }
std::string Contact::get_last_name() const { return last_name; }
std::string Contact::get_mobile_number() const { return mobile_number; }
std::string Contact::get_email_address() const { return email_address; }
Address* Contact::get_address() const { return address; }
Address& Contact::get_address(int n) const { return *address; }
int Contact::get_contact_id() const { return contact_id; }
int Contact::get_search_count() const { return search_count; }
List<std::string> Contact::get_groups() const { return groups; }
Contact& Contact::get_contact(int id) { return *this; }

// equals() method to test if passed contact is equal to *this
bool Contact::equals(Contact contact)
{
	if (this->first_name == contact.first_name && this->last_name == contact.last_name && this->mobile_number == contact.mobile_number && this->email_address == contact.email_address && this->address->equals(*contact.address))
	{
		return true;
	}
	return false;
}



void Contact::print_contact()
{
	std::cout << "\nName: " << first_name << " " << last_name << std::endl;
	std::cout << "Mobile Number: " << mobile_number << std::endl;
	std::cout << "Email Address: " << email_address << std::endl;
	std::cout << "Address: " << address->get_house() << ", " << address->get_street() << ", " << address->get_city() << ", " << address->get_country() << std::endl;
}

// Return a deep copy of *this
Contact& Contact::copy_contact()
{
	Contact copiedContact;
	copiedContact.first_name = this->first_name;
	copiedContact.last_name = this->last_name;
	copiedContact.mobile_number = this->mobile_number;
	copiedContact.email_address = this->email_address;
	copiedContact.contact_id = this->contact_id;
	copiedContact.address = new Address(this->address->get_house(),
		this->address->get_street(),
		this->address->get_city(),
		this->address->get_country());
	return copiedContact;
}

// Overload cin for Contact
std::istream& operator>>(std::istream& in, Contact& contact)
{
	std::cout << "\nEnter first name: ";
	in >> contact.first_name;
	std::cout << "Enter last name: ";
	in >> contact.last_name;
	std::cout << "Enter mobile number: ";
	in >> contact.mobile_number;
	std::cout << "Enter email address: ";
	in >> contact.email_address;
	std::cout << "\nEnter address: " << std::endl;
	if (contact.address == nullptr) {
		contact.address = new Address();
	}
	// Will use overloaded cin for Address
	in >> *(contact.address);
	return in;
}

// Overload cout for Contact
std::ostream& operator<<(std::ostream& out, const Contact& contact)
{
	out << contact.first_name << " " << contact.last_name << " " << contact.mobile_number << " " << contact.email_address << "\n" << *contact.address;
	return out;
}

// Overload comparison operator for Contact
bool Contact::operator==(const Contact& other)
{
	if (this->first_name == other.first_name && this->last_name == other.last_name && this->mobile_number == other.mobile_number && this->email_address == other.email_address && this->address->equals(*other.address))
	{
		return true;
	}
	return false;
}

// Overload assignment operator for Contact
Contact& Contact::operator=(const Contact& other)
{
	if (this != &other)
	{
		this->contact_id = other.contact_id;
		this->first_name = other.first_name;
		this->last_name = other.last_name;
		this->mobile_number = other.mobile_number;
		this->email_address = other.email_address;
		if (this->address != nullptr) {
			delete this->address;
			this->address = nullptr;
		}	
		if (other.address != nullptr) {
			this->address = new Address(*other.address);
		}
		this->search_count = other.search_count;
	}
	return *this;
}

// Add a group to the list of groups
void Contact::add_to_group(std::string group)
{
	groups.append(group);
}

// Remove a group from the list of groups
void Contact::remove_from_group(std::string group)
{
	groups.remove(group);
}

// Increment the search count
void Contact::add_search_count()
{
	search_count++;
}

// Method to compare two contacts
bool Contact::compare(const Contact& curr, const Contact& other, bool (*fptr)(const Contact& a, const Contact& b)) const
{
	return fptr(curr, other);
}

// Comparison functions
bool Contact::fn_less_than(const Contact& a, const Contact& b)
{
	return a.first_name < b.first_name;
}

bool Contact::fn_greater_than(const Contact& a, const Contact& b)
{
	return a.first_name > b.first_name;
}

bool Contact::ln_less_than(const Contact& a, const Contact& b)
{
	return a.last_name < b.last_name;
}

bool Contact::ln_greater_than(const Contact& a, const Contact& b)
{
	return a.last_name > b.last_name;
}

