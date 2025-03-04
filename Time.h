#ifndef TIME_H
#define TIME_H
#include "Comparator.h"
class Time : public Comparator<Time> {
private:
    int hours;
    int minutes;
    int seconds;
public:
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int hours, int minutes, int seconds);
    Time(const Time& other);
    Time& operator=(const Time& other);
    bool operator==(const Time& other) const;
    bool compare(const Time& a, const Time& b, bool (*fptr)(const Time& t1, const Time& t2)) const override;
    Time& get_time();
    void set_time(int hours, int minutes, int seconds);
    // Getters
    int get_hours() const;
    int get_minutes() const;
    int get_seconds() const;
    static bool less_than(const Time& t1, const Time& t2);
    static bool greater_than(const Time& t1, const Time& t2);
};
#endif