#include<iostream>
#include <stack>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <ctype.h>

using namespace std;

class syntaxError{
  private:
    string cppFile;
public:
  int lineCount;
  int openDelimCount;
  int closedDelimCount;
  int totalElements;
  syntaxError();//default
  syntaxError(string fileName); //overloadedconstructor
  ~syntaxError();//deconstructor
  void openDelimiters(string fileName);
  int noErrorDetected();
};
