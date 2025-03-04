#include "Time.h"
#include <iostream>
using namespace std;
//Parametraized Constructor 
Time::Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) {}
Time::Time(const Time& other)
{
    this->hours = other.hours;
    this->minutes = other.minutes;
    this->seconds = other.seconds;
}
//Time& Time::get_time() {
//    return *this;
//}
void Time::set_time(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

int Time::get_hours() const { return hours; }
int Time::get_minutes() const { return minutes; }
int Time::get_seconds() const { return seconds; }

bool Time::operator==(const Time& other) const {
    return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
}

Time& Time::operator=(const Time& other) {
    this->hours = other.hours;
    this->minutes = other.minutes;
    this->seconds = other.seconds;
    return *this;
}

bool Time::less_than(const Time& t1, const Time& t2) {
    // Returns true if t1 is less than t2, else false
    // Assuming the time is compared based on hours, then minutes, then seconds
    if (t1.hours < t2.hours)
        return true;
    else if (t1.hours == t2.hours && t1.minutes < t2.minutes)
        return true;
    else if (t1.hours == t2.hours && t1.minutes == t2.minutes && t1.seconds < t2.seconds)
        return true;
    else
        return false;
}

bool Time::greater_than(const Time& t1, const Time& t2) {
    // Returns true if t1 is greater than t2, else false
    // Assuming the time is compared based on hours, then minutes, then seconds
    if (t1.hours > t2.hours)
        return true;
    else if (t1.hours == t2.hours && t1.minutes > t2.minutes)
        return true;
    else if (t1.hours == t2.hours && t1.minutes == t2.minutes && t1.seconds > t2.seconds)
        return true;
    else
        return false;
}

bool Time::compare(const Time& a, const Time& b, bool (*fptr)(const Time& t1, const Time& t2)) const {
    return fptr(a, b);
}