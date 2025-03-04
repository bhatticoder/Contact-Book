#ifndef DATE_H
#define DATE_H
#include "Comparator.h"
class Date : Comparator<Date> {
private:
    int day;
    int month;
    int year;
public:
    Date() : day(0), month(0), year(0) {}
    Date(int day, int month, int year);
    Date(const Date& other);
    Date& operator=(const Date& other);
    bool compare(const Date& a, const Date& b, bool (*fptr)(const Date& a, const Date& b)) const override;
    Date& get_date();
    int get_day() const;
    int get_month() const;
    int get_year() const;
    void set_date(int day, int month, int year);
    static bool less_than(const Date& d1, const Date& d2);
    static bool greater_than(const Date& d1, const Date& d2);
    bool operator==(const Date& other) const;
};
#endif