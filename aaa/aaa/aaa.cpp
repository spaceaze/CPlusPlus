//* Program2.cpp
 //*
 //*  Created on: Jan 25, 2023
 //*      Author: william sonna
 //*/

#include<iostream>
#include<string>
#include<regex>
using namespace std;

// isLeapYear() below is mine
static bool isLeapYear(int year) {

	// year is a century if modulo 100 ==0
	if (year % 100 == 0)
		// centuries are leap years if modulo 400 == 0
		return (year % 400 == 0) ? true : false;
	// year is not a century, so leap year if modulo 4 == 0
	else
		return (year % 4 == 0) ? true : false;
}

// This handles the data string
void processDataString(string& dataString) {

	// no try/except needed, regex check guarantees only digits in dataString
	int value = stoi(dataString);
	string isIsNot = isLeapYear(value) ? " is " : " is not ";
	cout << dataString << isIsNot << "a leap year" << endl << endl;

}

// The 3 below are poached (with minor modifications) from stackoverflow

// trim from end of string (right)
string& rtrim(string& s, string ws) {
	s.erase(s.find_last_not_of(ws) + 1);
	return s;
}

// trim from beginning of string (left)
string& ltrim(string& s, string ws) {
	s.erase(0, s.find_first_not_of(ws));
	return s;
}

// trim whitespace from both ends of string
string& trim(string& s) {
	string ws = " \t\n\r\f\v";
	return ltrim(rtrim(s, ws), ws);
}

// acceptable means regex matches
bool dataStringAcceptable(string& dataString, regex& acceptable) {
	return (regex_match(dataString, acceptable));
}


// The regex below is used to identify valid input.
// Matches either a single 0 -or-_a single instance of [1-9] followed
// by zero or more instances of [0-9]. In other words: "0", "1984", and "11" all
// match, but "007", "00", "+2021", "1984.5", and "apachepoi" do not.
//
// stoi() can only parse characters [0-9], so any string that contains only those
// is guaranteed to parse without throwing an exception.  I, however, detest
// leading zeros and superfluous leading '+' signs, even if they parse, so I am not
// allowing them here, other than a single zero which is a valid year.  Note that I
// am allowing leading and trailing whitespace for superstitious reasons.
regex acceptableFormat("\\s*0|[1-9][0-9]*\\s*");

// the prompts for the data string and bad formatting
string prompt{ "Please enter a year (enter 'exit' to end): " };
string badFormat{ "Only positive integer values without a '+' sign or leading zeroes allowed" };

// An infinite loop, prompts for a data string.  Ends when user types
// "exit", otherwise checks the data string and if acceptable processes
// it, or if not, declares it unacceptable.  Then prompts again.
int main() {

	do {
		// prompt and get the data string
		cout << prompt;
		// read dataString
		string dataString;
		getline(cin, dataString);
		// and trim any leading or trailing whitespace;
		dataString = trim(dataString);
		// move cout to next line
		cout << endl;

		// loop ends on data string "exit"
		if (dataString == "exit")
			break;

		// Runtime check:  acceptable dataString. If acceptable, process
		if (dataStringAcceptable(dataString, acceptableFormat)) {
			processDataString(dataString);
		}
		// otherwise, declare unacceptable and continue with loop.
		else
			cout << badFormat << endl << endl;

	} while (true);

	return 0;
}
