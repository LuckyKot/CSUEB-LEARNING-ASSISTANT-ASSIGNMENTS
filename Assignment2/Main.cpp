/*
CS201 Assignment #2
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

int TOTAL_TYPES = 7;

void yearRange(string year[], int yLength, int* lowerR, int* upperR);

int main() {
	ifstream inFile;
	string line;
	string word;
	string typeChoice;
	int counter = 0;
	bool found = false;

	const char *keywords[7] = {"\"Severe Storm\"","\"Tropical Cyclone\"","\"Wildfire\"","\"Drought\"","\"Flooding\"","\"Winter Storm\"","\"Freeze\""};
//	const char *numbers[10] = {"0","1","2","3","4","5","6","7","8","9"};

	string name[100];
	int cLength = 0;
	string type[100];
	int tLength = 0;
	string year[100];
	int yLength = 0;
	string damage[100];
	int damLength = 0;
	string casualties[100];
	int casLength = 0;
	
	inFile.open("cataclysms.txt");
	if (!inFile) {
		cout << "The specified file does not exist or bugged out\n";
		cout << "Please, try again\n";
		cout << "\n";
		//error in case of wrong file name
	}
	else {
		while (!inFile.eof()) {
			getline(inFile, line);
//			line = inFile.Read
			word = "";
			for (auto x : line)
			{
				if (x == ',')
				{
//					cout << word << endl;
					if (counter == 0) {
						name[cLength] = word;
						cLength++;
						counter++;
					}
					else if (counter == 1) {
						type[tLength] = word;
						tLength++;
						counter++;
					}
					else if (counter == 2) {
						year[yLength] = word;
						yLength++;
						counter++;
					}
					else if (counter == 3) {
						damage[damLength] = word;
						damLength++;
						counter++;
					}

					word = "";
				}
				else
				{
					word = word + x;
				}
			}
			if (counter == 4) {
				casualties[casLength] = word;
				casLength++;
				counter = 0;
			}
//			cout << word << endl;
		}
		inFile.close();
	}
	for (int i = 0; i < cLength; i++) {
		cout << name[i] << ' ' << type[i] << ' ' << year[i] << ' ' << damage[i] << ' ' << casualties[i] << endl;		
	}

	cout << "-----------------------------------" << endl;
	cout << "list acquired" << endl;

	char yn = 0;
	int choice = 0;
	int upper = 0;
	int lower = 0;

	while (yn != 'y') {
		cout << "What would you like to do?" << endl;
		cout << "1.Look up a catastrophy from a year range\n";
		cout << "2.Look up a disaster by type\n";
		cout << "3.Get a summary of disasters\n";
		cout << "Your choice:";
		cin >> choice;
		if (choice == 1) {
			cout << "You chose the year range option, it is only from 2012 to 2019\n";
			cout << "please, enter the starting year:\n";
			cin >> lower;
			//can make a check here
			cout << "please, enter the ending year:\n";
			cin >> upper;
			//also a check there
			yearRange(year,yLength,&lower,&upper);
			for (int i = lower; i < upper; i++) {
				cout << name[i] << ' ' << type[i] << ' ' << year[i] << ' ' << damage[i] << ' ' << casualties[i] << endl;
			}
			cout << "--------------------------\n";
		}
		else if (choice == 2) {
			cout << "You chose the disaster type option\n";
			cout << "Please, specify the disaster:\n";
			cin.ignore();
			getline(cin,typeChoice);
			int iterator = 0;
			transform(typeChoice.begin(), typeChoice.end(), typeChoice.begin(), ::toupper);

			string helper;

			for (int i = 0; i < cLength;i++) {
				helper = type[i];
				
				transform(helper.begin(), helper.end(), helper.begin(), ::toupper);
				if (typeChoice.compare(helper) == 0) {
					iterator++;
					cout << name[i] << ' ' << type[i] << ' ' << year[i] << ' ' << damage[i] << ' ' << casualties[i] << endl;
				}

			}
			if (iterator == 0) {
				cout << "Nothing found for: " << typeChoice << endl;
				iterator = 0;
			}

		}
		else if (choice == 3) {
			cout << "You chose summary option\n";
			cout << "Generating summary...\n";
			int summaryVictims = 0;			
			string summaryType;

			int storm = 0;
			int cyclone = 0;
			int fire = 0;
			int drought = 0;
			int flooding = 0;
			int wStorm = 0;
			int freeze = 0;

			for (int i = 2012; i < 2019; i++) {
				for (int j = 0; j < cLength; j++) {
					string help;
					help = to_string(i);
					if (year[j]==help) {
						summaryVictims = summaryVictims + stoi(casualties[j]);
//						summaryType = summaryType + " " + type[j];
						for (int k = 0; k < TOTAL_TYPES; k++) {
							if (type[j].compare(keywords[k]) == 0) {
								if (k == 0) {
									storm++;
								}
								else if (k == 1) {
									cyclone++;
								}
								else if (k == 2) {
									fire++;
								}
								else if (k == 3) {
									drought++;
								}
								else if (k == 4) {
									flooding++;
								}
								else if (k == 5) {
									wStorm++;
								}
								else if (k == 6) {
									freeze++;
								}
							}
						}
					}
				}
				
				if (storm != 0) {
					summaryType = summaryType + " " + keywords[0];
					storm = 0;
				}
				if (cyclone != 0) {
					summaryType = summaryType + " " + keywords[1];
					cyclone = 0;
				}
				if (fire != 0) {
					summaryType = summaryType + " " + keywords[2];
					fire = 0;
				}
				if (drought != 0) {
					summaryType = summaryType + " " + keywords[3];
					drought = 0;
				}
				if (flooding != 0) {
					summaryType = summaryType + " " + keywords[4];
					flooding = 0;
				}
				if (wStorm != 0) {
					summaryType = summaryType + " " + keywords[5];
					wStorm = 0;
				}
				if (freeze != 0) {
					summaryType = summaryType + " " + keywords[6];
					freeze = 0;
				}

				cout << "In " << i << " total death is " << summaryVictims << endl;
				cout << "In " << i << " there were following cataclysms: " << summaryType << endl;
				summaryVictims = 0;
				summaryType = "";
			}
			
		}
		else {
			cout << "Invalid choice" << endl;
		}
		cout << "Would you like to exit?(y/n)\n";
		cin >> yn;
	}

	return 0;
}

void yearRange(string year[], int yLength, int* lowerR, int* upperR) {
	for (int i = 0; i < yLength; i++) {
		if (stoi(year[i]) != *lowerR) {
//			cout << "nope" << endl;
		}
		else {
//			cout << "yeah, this one: " << i << endl;
			*lowerR = i;
			break;
		}
	}

	int &upper = *upperR;
	upper += 1;

	for (int j = 0; j < yLength; j++) {
		if (stoi(year[j]) != upper) {
//			cout << "nope" << endl;
		}
		else {
//			j--;
//			cout << "yeah, this one: " << j << endl;
			*upperR = j;
			break;
		}
	}
}

//void disasterLookup() {
//
//}

//void summary() {
//
//}


/*

for (int i = 0; i < 7; i++) {
				helper = keywords[i];
				transform(helper.begin(), helper.end(), helper.begin(), ::toupper);
				if (helper == typeChoice) {
					cout << "Category found, conducting search\n";
					for (int j = 0; j < cLength; j++) {
						if (keywords[i] == type[j]) {
							cout << cataclysm[j] << ' ' << type[j] << ' ' << year[j] << ' ' << damage[j] << ' ' << casualties[j] << endl;
						}
					}
					break;
				}
			}


			/*
						string summaryList[100];
						for (int k = 0; k < j;k++) {
							if (type[j] == summaryList[k]) {
								k--;
								break;
							}
							else {
								summaryList[k] = type[j];
								cout << summaryList[k];

							}
						}

						dodelat summary*/