#include "Genstackkk.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <ctype.h>
#include "syntaxChecker.h"

using namespace std;

int lineCount;
string cppFile=" ";

 int main(int argc, char const *argv[])
  {
   //created file error checker object

  cout<<"What file would you like to check for syntax errors?"<<endl;
  cin>> cppFile;
  syntaxError errorCheck;
  errorCheck.openDelimiters(cppFile);
return 0;
}
