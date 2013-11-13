/**   @file Dictionary.h
      @author Harry Kran-Annexstein
      @date 10-15-2013
      
      Interface for the Dictionary class.
      */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>

using namespace std;

class Dictionary {
public:
  Dictionary();

  Dictionary(const Dictionary &that);

  virtual ~Dictionary();
  
  string getWord();

  int getSize();

private:
  vector<string> words;
};

#endif
