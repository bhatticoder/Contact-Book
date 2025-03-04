#pragma once

template <typename T>
class Comparator
{
public:
    virtual bool compare(const T& a, const T& b, bool (*fptr)(const T& a, const T& b)) const = 0;
    virtual ~Comparator() {};
};

// Use cases:
// 1. Compare contact's names (first name, last name)
// 2. Compare contact's search_count
// 3. Compare two time objects
// 4. Compare two date objects
// 5. Compare two History objects