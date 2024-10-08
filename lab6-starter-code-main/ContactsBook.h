#pragma once
#include "Address.h"
#include "Contact.h"

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB


class ContactsBook {
private:
	Contact *contacts_list; // array of contacts
	int size_of_contacts;   // storage limit
	int contacts_count;     // total contacts currently stored, next contact will be 
						    // stored at this count plus 1 index

public:
	void add_contact(const Contact& contact);
	int total_contacts();

	Contact* search_contact(std::string first_name, std::string last_name);
	Contact* search_contact(std::string phone);
	Contact* search_contact(const Address& address);

	ContactsBook(int size_of_list);

	void print_contacts_sorted(std::string choice); // Only two choices first_name or last_name
	void merge_duplicates(); // Implement this function that finds and merges all the duplicates
							 // Duplicate means exact equal, this means if
	
	/* 
	*  This function loads contacts from the given file (see details in ContactsBook.cpp)
	*/
	void load_from_file(std::string file_name);
	void save_to_file(std::string file_name);

private:
	bool full();
	void resize_list();
	void sort_contacts_list(Contact *contacts_list, std::string choice);
};
