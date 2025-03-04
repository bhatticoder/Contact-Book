#ifndef ADVANCEDSEARCH_H
#define ADVANCEDSEARCH_H
#include "HistoryObject.h"
#include "ContactsBook.h"
#include "SearchHistory.h"
#include "List.h"
#include <string>
#include <ctime>

class AdvanceSearch {
private:
    int maxSize;
    List<Contact> searchResults;
    int item_count;
public:
    // Constructor
    AdvanceSearch();
    //Destructor
    ~AdvanceSearch();
    // Method to perform the search
    void perform_search(std::string query, ContactsBook& book);
    List<Contact> get_results();
    void update_history(HistoryObject& h, SearchHistory& sh);
    bool is_query_in_string(const std::string& query, const std::string& str);
    HistoryObject search_history(Contact& c);
};
#endif
