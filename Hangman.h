/**   @file Hangman.h
      @author Harry Kran-Annexstein
      @date 10-15-2013
      
      Interface for the Hangman class.
      */

#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>
using namespace std;

class Hangman {
public:
	Hangman(string s);

	Hangman(const Hangman &that);

	virtual ~Hangman();

	void nextTurn(const char c);

	int getRemaining();

	string getWord();

	string getGuess();

	string getMissed();

	string getUsed();

	bool getWin();

	void reset(string s);
private:
  string word;
  string guess;
  string missed;
  string used;
  int remaining;
  bool win;
};

#endif
