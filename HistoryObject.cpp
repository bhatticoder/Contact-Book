#include"HistoryObject.h"
#include<iostream>
using namespace std;

// Default constructor
HistoryObject::HistoryObject() : time(), date(), contact() {}
// Constructor with separate hour, minute, second, day, month, year parameters
HistoryObject::HistoryObject(int hour, int minute, int second, int day, int month, int year, Contact c) :
    time(hour, minute, second), date(day, month, year), contact(c) {}
// Constructor with Time and Date objects
HistoryObject::HistoryObject(const Time& time, const Date& date, Contact c) : time(time), date(date), contact(c) {}

HistoryObject& HistoryObject::display() {
    return *this;
}

Time& HistoryObject::get_time() {
    return time;
}

void HistoryObject::set_time(int hour, int minute, int second) {
    time.set_time(hour, minute, second);
}

Date& HistoryObject::get_date() {
    return date;
}

void HistoryObject::set_date(int day, int month, int year) {
    date.set_date(day, month, year);
}

Contact& HistoryObject::get_contact() {
    return contact;
}
// Copy constructor
HistoryObject::HistoryObject(const HistoryObject& other) : time(other.time), date(other.date), contact(other.contact) {}
// Assignment operator
HistoryObject& HistoryObject::operator=(const HistoryObject& other) {
    time = other.time;
    date = other.date;
    contact = other.contact;
    return *this;
}

bool HistoryObject::less_than(const HistoryObject& h1, const HistoryObject& h2) {
    // Returns true if h1 is less than h2, else false
    // Assuming the history object is compared based on date, then time
    if (h1.date.compare(h1.date, h2.date, Date::less_than))
        return true;
    else if (h1 == h2 && h1.time.compare(h1.time, h2.time, Time::less_than))
        return true;
    else
        return false;
}

bool HistoryObject::greater_than(const HistoryObject& h1, const HistoryObject& h2) {
    // Returns true if h1 is greater than h2, else false
    // Assuming the history object is compared based on date, then time
    if (h1.date.compare(h1.date, h2.date, Date::greater_than))
        return true;
    else if (h1.date == h2.date && h1.time.compare(h1.time, h2.time, Time::greater_than))
        return true;
    else
        return false;
}

bool HistoryObject::by_search_count(const HistoryObject& a, const HistoryObject& b) {
    return a.contact.get_search_count() > b.contact.get_search_count();
}

bool HistoryObject::compare(const HistoryObject& a, const HistoryObject& b, bool (*fptr)(const HistoryObject& h1, const HistoryObject& h2)) const {
    return fptr(a, b);
}

bool HistoryObject::operator==(const HistoryObject& other) const {
    return (time == other.time && date == other.date);
}

// cout overload
ostream& operator<<(ostream& os, const HistoryObject& history_object) {
    os << history_object.contact << endl;
    os << history_object.time.get_hours() << ":" << history_object.time.get_minutes() << ":" << history_object.time.get_seconds() << endl;
    os << history_object.date.get_day() << "/" << history_object.date.get_month() << "/" << history_object.date.get_year() << endl;
    return os;
}