#include "Group.h"

// Constructor
Group::Group() : name(""), max_contacts(100), no_of_contacts(0) {}
Group::Group(std::string n, int max) : name(n), max_contacts(max), no_of_contacts(0) {}
// Copy constructor
Group::Group(const Group& other) : name(other.name), max_contacts(other.max_contacts), no_of_contacts(other.no_of_contacts) {
    this->members = other.members;
}
// Assignment operator
Group& Group::operator=(const Group& other) {
    if (this == &other)
        return *this;
    name = other.name;
    no_of_contacts = other.no_of_contacts;
    max_contacts = other.max_contacts;
    members = other.members;
    return *this;
}

// Destructor
Group::~Group() {}

// Method to add a contact to the group
void Group::add_contact(int contact_ID, ContactsBook& contactsBook)
{
    if (no_of_contacts == max_contacts)
    {
        return; // Max limit reached
    }
    members.append(contact_ID);
    contactsBook.get_contact(contact_ID).add_to_group(name);
    no_of_contacts++;
}

// Method to remove a contact from the group
void Group::remove_contact(int contact_ID, ContactsBook& contactsBook)
{
    members.remove(contact_ID);
    no_of_contacts--;
    contactsBook.get_contact(contact_ID).remove_from_group(name);
}

void Group::resize(int new_size)
{
    if (new_size > no_of_contacts)
        max_contacts = new_size;
}

// Get the name of the group
std::string Group::get_name() const
{
    return name;
}

// Get the size of the group
int Group::get_group_size() const
{
    return no_of_contacts;
}

// Get the list of members in the group
List<int>& Group::get_members()
{
    return members;
}

// operator == overloading
bool Group::operator==(const Group& other) const
{
    if (name == other.name && no_of_contacts == other.no_of_contacts && max_contacts == other.max_contacts && members == other.members)
        return true;
    return false;
}

// return the group
Group& Group::display()
{
    return *this;
}

// Less than
bool Group::less_than(const Group& a, const Group& b)
{
    return a.name < b.name;
}

// Greater than
bool Group::greater_than(const Group& a, const Group& b)
{
    return a.name > b.name;
}

// Compare two groups
bool Group::compare(const Group& a, const Group& b, bool (*fptr)(const Group& a, const Group& b)) const
{
    return fptr(a, b);
}