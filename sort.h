#pragma once
#include "Comparator.h"
#include "List.h"

// For ContactsBook
template <typename C>
void sort_list(C* arr, int n, Comparator<C>* comp, bool (*fptr)(const C& a, const C& b))
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (comp->compare(arr[j + 1], arr[j], fptr))
            {
                C temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// For other lists: SearchHistory, frequentlySearched, etc.
template <typename C>
void sort_list(List<C>& arr, Comparator<C>* comp, bool (*fptr)(const C& a, const C& b))
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (comp->compare(arr[j + 1], arr[j], fptr))
            {
                C temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
