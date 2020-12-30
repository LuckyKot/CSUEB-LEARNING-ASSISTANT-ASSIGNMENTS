/*
CS201 Assignment #4
*/

#include "Book.h"
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

bool isAnagram(string s, string t) {
	vector<char> pool;
	int k = 0;
	bool found;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; i < pool.size(); i++) {
			if (pool[j] == s[i]) {
				found = 1;
				break;
			}
		}
		if (found == 0) {
			pool[k] = s[i];
			k++;
			found = 0;
		}
	}
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; i < pool.size(); i++) {
			if (t[i] == pool[j]) {
				found = 1;
				break;
			}
		}
		if (found == 0) {
			break;
		}
	}
	return found;
}

int main() {
	string p = "car";
	string l = "tar";
	
	cout<<isAnagram(p, l);


	return 0;
}






