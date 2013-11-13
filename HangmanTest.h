/**   @file HangmanTest.h
      @author Harry Kran-Annexstein
      @date 10-15-2013
      
      Unit tests for the Hangman class.
      */

#ifndef HANGMAN_TEST_H
#define HANGMAN_TEST_H

#include <Hangman.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class HangmanTest : public CxxTest::TestSuite {
public:
	void testConstructorWord() {
		string s = "Word";
		Hangman h(s);
		TS_ASSERT_EQUALS(h.getWord(),s);
	}
	void testConstructorGuess() {
		string s = "Word";
		Hangman h(s);
		TS_ASSERT_EQUALS(h.getGuess(),"____");
	}
	void testConstructorMissed() {
		string s = "Word";
		Hangman h(s);
		TS_ASSERT_EQUALS(h.getMissed(),"");
	}
	void testConstructorUsed() {
		string s = "Word";
		Hangman h(s);
		TS_ASSERT_EQUALS(h.getUsed(),"");
	}
	void testConstructorRemaining() {
		string s = "Word";
		Hangman h(s);
		TS_ASSERT_EQUALS(h.getRemaining(),6);
	}
	void testConstructorWin() {
		string s = "Word";
		Hangman h(s);
		TS_ASSERT_EQUALS(h.getWin(),false);
	}
	void testNextTurn() {
		string s = "Word";
		Hangman h(s);
		h.nextTurn('x');
		TS_ASSERT(!h.getWin());
	}
	void testReset() {
		string s = "Word";
		Hangman h(s);
		h.reset(s);
		TS_ASSERT_EQUALS(h.getWord(),s);
	}
};

#endif
