/**   @file Dictionary.h
      @author Harry Kran-Annexstein
      @date 10-15-2013
      
      Implementation for the Dictionary class.
      */

#include <Dictionary.h>

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
// Needed for random
#include <time.h>
#include <cstdlib>

using namespace std;

const unsigned MINLEN = 4;

Dictionary::Dictionary() {
	srand(time(0));
	ifstream dict;
	dict.open("wordswithfriends.txt");
	string word;
	while(dict >> word) {
		if (word.length() <= MINLEN) {
			continue;
		}else {
		   words.push_back(word);
		 }
	}
}

Dictionary::Dictionary(const Dictionary &that) {
	vector<string> words(that.words);
}

Dictionary::~Dictionary() {
}

string Dictionary::getWord() {
	int i = rand() % getSize();
	return words.at(i);
}

int Dictionary::getSize() {
	return words.size();
}
