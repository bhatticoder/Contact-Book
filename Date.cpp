#include "Date.h"
#include <iostream>
using namespace std;
Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}
Date& Date::get_date() {
    return *this;
}
void Date::set_date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(const Date& other)
{
    this->year = other.year;
    this->month = other.month;
    this->day = other.day;
}

Date& Date::operator=(const Date& other)
{
    this->year = other.year;
    this->month = other.month;
    this->day = other.day;
    return *this;
}

int Date::get_day() const { return day; }
int Date::get_month() const { return month; }
int Date::get_year() const { return year; }

bool Date::less_than(const Date& d1, const Date& d2) {
    // Returns true if d1 is less than d2, else false
    // Assuming the date is compared based on year, then month, then day
    if (d1.year < d2.year)
        return true;
    else if (d1.year == d2.year && d1.month < d2.month)
        return true;
    else if (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day)
        return true;
    else
        return false;
}

bool Date::greater_than(const Date& d1, const Date& d2) {
    // Returns true if d1 is greater than d2, else false
    // Assuming the date is compared based on year, then month, then day
    if (d1.year > d2.year)
        return true;
    else if (d1.year == d2.year && d1.month > d2.month)
        return true;
    else if (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day)
        return true;
    else
        return false;
}

bool Date::compare(const Date& a, const Date& b, bool (*fptr)(const Date& a, const Date& b)) const {
    return fptr(a, b);
}

bool Date::operator==(const Date& other) const {
    return (day == other.day && month == other.month && year == other.year);
}