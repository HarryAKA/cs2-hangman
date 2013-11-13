/**   @file main.cpp
      @author Harry Kran-Annexstein
      @date 10-15-2013
      
      Main function for hangman, plays as many games of hangman as the user wants, using the wordswithfriends.txt
      file as the dictionary of available words.
      */

#include <Hangman.h>
#include <Dictionary.h>
#include <iostream>

using namespace std;

int main() {
  Dictionary d;
  Hangman h(d.getWord());
  cout << "Welcome to Hangman (beta). I've loaded " << d.getSize()
			 << " words." << endl;
  bool play = true;
  while (play) {
  	for(int i = 1; i < 80; i++) {
  		cout << "-";
  	} cout << endl;
  	while(h.getRemaining() > 0 && !h.getWin()) {
  		cout << "Guess: " << h.getGuess();
  		cout << " misses remaining: " << h.getRemaining();
  		cout << " missed letters: " << h.getMissed() << endl;
  		char nextletter = '0';
  		while (nextletter < 'a' || nextletter > 'z') {
  			cout << "Please enter a lowercase letter: ";
  			cin >> nextletter;
  			cout << endl;
  		}
  		h.nextTurn(nextletter);
  	}
  	if(h.getWin()) {
  		cout << "You win! You guessed the word: " << h.getWord();
  		cout << " with " << h.getRemaining() << " misses remaining." << endl;

  	}else {
  		cout << "Sorry, you lose. The word was: " << h.getWord() << endl;
  	}
  	char ans = '0';
  	while (ans != 'y' && ans != 'n') {
  		cout << "Play again? (y/n) ";
  		cin >> ans;
  	}
  	if (ans == 'n') {
  		play = false;
  		cout << "Goodbye!" << endl;
  	}else {
  		play = true;
  	  h.reset(d.getWord());
  	}
  }
  return 0;  
}
