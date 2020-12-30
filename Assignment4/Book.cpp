//Book Class for pa4

#include "Book.h"

Book::Book() {
	title = "";
	author = "";
	publisher = "";
	pubDate = "";
	category = "";
}

Book::Book(string t, string a, string p, string pd, string c)
{
	setBook(t, a, p, pd, c);
}

void Book::setBook(string t, string a, string p, string pd, string c) {
	title = t;
	author = a;
	publisher = p;
	pubDate = pd;
	category = c;
}

string Book::getTitle() {
	return title;
}

string Book::getAuthor() {
	return author;
}

string Book::getPublisher() {
	return publisher;
}

string Book::getPubDate() {
	return pubDate;
}

string Book::getCategory() {
	return category;
}