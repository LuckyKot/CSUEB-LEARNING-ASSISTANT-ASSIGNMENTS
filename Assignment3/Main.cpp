/*
CS201 Assignment #3
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <locale>

using namespace std;

void Readfile(string words[9][30], int lengths[], int &counterL);
void find_matches(string words[9][30], int lengths[], int &counterL);

int main() {

	string words[9][30];
	int lengths[10];
	int counterL = 0;

	Readfile(words,lengths,counterL);
	find_matches(words,lengths,counterL);

	return 0;
}

void Readfile(string words[9][30], int lengths[],int &counterL) {

	ifstream inFile;
	string filename;	
	string line;
	string word;
	
	int counterW = 0;
	int counterS = 0;

	cout << "Enter a file name:\n";
	cin >> filename;
	filename += ".txt";

	inFile.open(filename);
	while (!inFile) {
		cout << "The specified file does not exist or bugged out\n";
		cout << "Please, try again\n";
		cout << "\n";
		//error in case of wrong file name
		cout << "Enter a file name:\n";
		cin >> filename;
		filename += ".txt";
		inFile.open(filename);
	}

	while (!inFile.eof()) {
		getline(inFile, line);
		word = "";
		for (auto x : line) {
			if (x == ' ') {				
				if (word == "") {
					word = "";
				}
				else {
					reverse(word.begin(), word.end());
					transform(word.begin(), word.end(), word.begin(),tolower);
					words[counterL][counterW] = word;
					counterW++;
					word = "";
				}
			}
			else if (x == ':') {

			}
			else {
				word = word + x;
			}

		}
		reverse(word.begin(), word.end());
		transform(word.begin(), word.end(), word.begin(), tolower);
		words[counterL][counterW] = word;
		lengths[counterL] = counterW;
		counterW = 0;
		counterL++;
	}

	inFile.close();

	string temp[30];
	

	for (int i = 0; i < counterL; i++) {
		copy(begin(words[i]), end(words[i]), begin(temp));
		for (int j = 0, k = lengths[i]; k >= 0; j++,--k) {
			words[i][j] = temp[k];
		}
	}

	for (int i = 0; i < counterL; i++) {
		for (int j = 0; j <= lengths[i]; j++) {
			cout << words[i][j] << " ";
		}
		cout << endl;
	}

	
}

void find_matches(string words[9][30], int lengths[],int &counterL) {

	string command;
	string word;
	
	

	

	cin.ignore();

	while (command != "quit"){
		string search[10];
		int foundIn[10];
		int counter = 0;
		int matchCounter = 0;

		cout << "Enter space-separated words: ";
		getline(cin, command);
		word = "";
		for (auto x : command) {
			if (x == ' ') {
				search[counter] = word;
				counter++;
				word = "";
			}
			else {
				word = word + x;
			}
		}
		search[counter] = word;
		counter++;
		string temp;

		for (int i = 0; i < counterL; i++) {
			for (int j = 0; j <= lengths[i]; j++) {
				for (int k = 0; k < counter; k++) {
					temp = words[i][j];
					if (temp == search[k]) {
						matchCounter++;
						break;
					}
				}
			}
			if (matchCounter >= counter) {
				foundIn[i] = 1;
			}
			else {
				foundIn[i] = 0;
			}
			matchCounter = 0;
		}

		int checksum = 0;
		cout << "The co-occurance for: " + command<< endl;
		string summary = "Lines: ";
		int p = 0;

		for (int i = 0; i < counterL; i++) {
			checksum += foundIn[i];
			if (foundIn[i]!=0){
				p = i + 1;
				summary += to_string(p) + ' ';
			}
		}
		if (checksum == 0) {
			summary = "No matches";
		}
		cout << summary << endl;
		cout << endl;
		


		counter = 0;
	}

	if (command == "quit") {
		exit(0);
	}
}