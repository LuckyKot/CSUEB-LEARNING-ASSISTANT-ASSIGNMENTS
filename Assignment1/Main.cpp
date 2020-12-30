// LA Reference project
// No stealing allowed

#include <iostream>

using namespace std;

int main() {
	int nickel = 25; //5 cents
	int dime = 25; //10 cents
	int quarter = 25; //25 cents
	int dollar = 0;
	int dollarZ = 0;
	double price;
	int check = 0;
	int paid = 0;
	char menu = 0;

	int extraNickel = 0; //5 cents
	int extraDime = 0; //10 cents
	int extraQuarter = 0; //25 cents
	int extraDollar = 0;
	int extraDollarZ = 0;

	cout << "Welcome to the vending machine prompt\n";
	cout << "Change available:\n";
	cout << "nickels: " << nickel << '\n';
	cout << "dimes: " << dime << '\n';
	cout << "quarters: " << quarter << '\n';
	cout << "dollars: " << dollar << '\n';
	cout << "5 dollars: " << dollarZ << '\n';

	for (;;) {
		cout << "Enter price:\n" ;
		cout << "Note: IT MUST BE IN THIS FORMAT XX.XX\n";
		cin >> price;
		cout << "Price entered: " << price << '\n';
		price = price + 0.0000005;
		check = price * 100;
		paid = check;
		check = check % 5;
		if (price < 0) {
			cout << "invalid price\n";
		}
		else if (check == 0) {
			while (paid > 0) {
				price = paid;
				price = price / 100;
				cout << price << " left to pay\n";
				cout << "Choose an option:\n";
				cout << "'n' for nickel\n";
				cout << "'d' for dime\n";
				cout << "'q' for quarter\n";
				cout << "'o' for dollar\n";
				cout << "'f' for five dollars\n";
				cout << "'c' for cancel\n";
				cin >> menu;
				if (menu == 'n') {
					paid = paid - 5;
					extraNickel++;
				}
				else if (menu == 'd') {
					paid = paid - 10;
					extraDime++;
				}
				else if (menu == 'q') {
					paid = paid - 25;
					extraQuarter++;
				}
				else if (menu == 'o') {
					paid = paid - 100;
					extraDollar++;
				}
				else if (menu == 'f') {
					paid = paid - 500;
					extraDollarZ++;
				}
				else if (menu == 'c') {
					extraNickel = 0;
					extraDime = 0;
					extraQuarter = 0;
					extraDollar = 0;
					extraDollarZ = 0;
					break;
				}
				else {
					cout << "invalid input\n";
				}
			}

			nickel = nickel + extraNickel;
			dime = dime + extraDime;
			quarter = quarter + extraQuarter;
			dollar = dollar + extraDollar;
			dollarZ = dollarZ + extraDollarZ;

			extraNickel = 0;
			extraDime = 0;
			extraQuarter = 0;
			extraDollar = 0;
			extraDollarZ = 0;

			if (paid == 0) {
				cout << "no change needed\n";
			}
			else {
				while (paid < 0) {
					if (paid <= -500 && dollarZ > 0) {
						paid = paid + 500;
						dollarZ--;
						extraDollarZ++;
					}
					else if (paid <= -100 && dollar > 0) {
						paid = paid + 100;
						dollar--;
						extraDollar++;
					}
					else if (paid <= -25 && quarter > 0) {
						paid = paid + 25;
						quarter--;
						extraQuarter++;
					}
					else if (paid <= -10 && dime > 0) {
						paid = paid + 10;
						dime--;
						extraDime++;
					}
					else if (paid <= -5 && nickel > 0) {
						paid = paid + 5;
						nickel--;
						extraNickel++;
					}
					else {
						price = paid;
						price = price / 100;
						price = price * -1;
						cout << "unable to pay: " << price << ". Please, contact the store manager for the rest of the change\n";
						break;
					}
				}
				cout << "Dispensing:\n";
				cout << "nickels: " << extraNickel << '\n';
				cout << "dimes: " << extraDime << '\n';
				cout << "quarters: " << extraQuarter << '\n';
				cout << "dollars: " << extraDollar << '\n';
				cout << "5 dollars: " << extraDollarZ << '\n';
				extraNickel = 0;
				extraDime = 0;
				extraQuarter = 0;
				extraDollar = 0;
				extraDollarZ = 0;
			}
			cout << "Change available:\n";
			cout << "nickels: " << nickel << '\n';
			cout << "dimes: " << dime << '\n';
			cout << "quarters: " << quarter << '\n';
			cout << "dollars: " << dollar << '\n';
			cout << "5 dollars: " << dollarZ << '\n';
		}
		else {
			cout << "invalid price\n";
		}

	}

	return 0;
}
