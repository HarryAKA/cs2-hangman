/**   @file Hangman.cpp
      @author Harry Kran-Annexstein
      @date 10-15-2013
      
      Implementation for the Hangman class.
      */

#include <Hangman.h>

#include <string>
#include <iostream>

using namespace std;

Hangman::Hangman(string s) {
	word = s;
	guess = "";
	for(unsigned i = 0; i < word.size(); i++) {
		guess += '_';
	}
	missed = "";
	used = "";
	remaining = 6;
	win = false;
}

Hangman::Hangman(const Hangman &that) {
	word = that.word;
	guess = that.guess;
	missed = that.missed;
	used = that.used;
	remaining = that.remaining;
	win = that.win;
}

Hangman::~Hangman() {
}

void Hangman::nextTurn(const char c) {
	unsigned ucount = 0;
	unsigned mcount = 0;
	vector<unsigned> gpos;
	for (unsigned i = 0; i < used.size(); i++) {
		if (used[i] == c) {
			ucount++;
		}else {
			continue;
		 }
	}
	for (unsigned j = 0; j < missed.size(); j++) {
		if (missed[j] == c) {
			mcount++;
		}else {
			continue;
		 }
	}
	for (unsigned p = 0; p < word.size(); p++) {
		if (word[p] == c) {
			gpos.push_back(p);
		}else {
			continue;
		 }
	}
	if (ucount == 0 && gpos.size() > 0) {
		for (unsigned g = 0; g < gpos.size(); g++) {
			guess[gpos.at(g)] = c;
		}
		used += c;
	}else if(mcount == 0 && ucount == 0) {
		missed += c;
		remaining--;
	}
	if (guess == word) {
		win = true;
	}
}

int Hangman::getRemaining() {
	return remaining;
}

string Hangman::getWord() {
	return word;
}

string Hangman::getGuess() {
	return guess;
}

string Hangman::getMissed() {
	return missed;
}

string Hangman::getUsed() {
	return used;
}

bool Hangman::getWin() {
	return win;
}

void Hangman::reset(string s) {
	word = s;
	guess = "";
	for(unsigned i = 0; i < word.size(); i++) {
		guess += '_';
	}
	missed = "";
	used = "";
	remaining = 6;
	win = false;
}
