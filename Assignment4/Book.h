#ifndef BOOK_H
#define BOOK_H

#include <new>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <locale>

using namespace std;

class Book
{
public:
	// Constructors
	Book();
	Book(string title, string author, string publisher, string pubDate, string category);
	// copy constructor
   // Destructor

   // accessors
	string getTitle();
	string getAuthor();
	string getPublisher();
	string getPubDate();
	string getCategory();

	// mutators
	void setBook(string title, string author, string publisher, string pubDate, string category);
	// overloaded operators member functions go here


private:
	// member variables
	string title;
	string author;
	string publisher;
	string pubDate;
	string category;

};

#endif