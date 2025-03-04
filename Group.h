#pragma once
#include "ContactsBook.h"
#include "Comparator.h"
#include "List.h"
#include <iostream>
#include <string>

class Group : public Comparator<Group> {
private:
    std::string	name;
    int max_contacts;
    List<int> members;
    int no_of_contacts;
public:
    Group();
    Group(std::string n, int max = 100); // Name and maximum contacts
    Group(const Group& other);
    Group& operator=(const Group& other);
    ~Group();
    void add_contact(int contactId, ContactsBook& contactsBook);
    void remove_contact(int contactID, ContactsBook& contactsBook);
    void resize(int new_size);
    // Method to get the name of the group
    std::string get_name() const;
    // Method to get the number of contacts in the group
    int get_group_size() const;
    // Method to get the list of contact IDs in the group
    List<int>& get_members();
    // Method to compare two groups
    bool compare(const Group& a, const Group& b, bool (*fptr)(const Group& a, const Group& b)) const override;
    // Method to check if two groups are equal
    bool operator==(const Group& other) const;
    // Method to display the group
    Group& display();
    // comparison functions
    static bool less_than(const Group& a, const Group& b);
    static bool greater_than(const Group& a, const Group& b);
};