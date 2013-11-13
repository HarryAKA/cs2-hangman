/**   @file DictionaryTest.h
      @author Harry Kran-Annexstein
      @date 10-15-2013
      
      Unit tests for the Dictionary class.
      */

#ifndef DICTIONARY_TEST_H
#define DICTIONARY_TEST_H

#include <Dictionary.h>

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class DictionaryTest : public CxxTest::TestSuite {
public:
	void constructorSizeTest() {
		const unsigned EXPECTEDSIZE = 168037;
		Dictionary d;
		TS_ASSERT_EQUALS(EXPECTEDSIZE,d.getSize());
	}
	void constructorMINLENTest() {
		const unsigned MINLEN = 4;
		Dictionary d;
		int ecount = 0;
		for (unsigned i = 0; i < 1000000; i++) {
			string word = d.getWord();
			if (word.size() <= MINLEN) {
				ecount++;
			}
		}
		TS_ASSERT_EQUALS(0, ecount);
	}
	void testGetWord() {
		const unsigned MINLEN = 4;
		Dictionary d;
		string word = d.getWord();
		TS_ASSERT_LESS_THAN(MINLEN,word.size());
	}
	void testGetSize() {
		Dictionary d;
		TS_ASSERT_LESS_THAN(0,d.getSize());
	}
};
  
#endif
