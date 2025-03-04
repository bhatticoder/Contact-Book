#ifndef SEARCHHISTORY_H
#define SEARCHHISTORY_H
#include <string>
#include <fstream>
#include "Contact.h"
#include "HistoryObject.h"
#include "List.h"
#include "sort.h"

using namespace std;

class AdvanceSearch;

class SearchHistory {
private:
    List<HistoryObject> frequentSearch;
    List<HistoryObject> history; // Stores search history in reverse (oldest first)
    List<Contact> searchedContacts;
    int historySize; // Track current size of history
    friend class AdvanceSearch;

public:
    SearchHistory(); // Constructor to initialize the lists
    SearchHistory(const SearchHistory& other); // Copy constructor
    bool check_frequent_search(Contact& contact);
    void update_frequent_search(HistoryObject& h);
    void add_search_item(HistoryObject& historyObject);
    List<HistoryObject> get_search_history();
    List<Contact> get_searched_contacts();
    List<HistoryObject> get_top5();
    //void save_to_file(string historyFile, string top5File);
    void save_history(string historyFile);
    void save_top5(string top5File);
};
#endif