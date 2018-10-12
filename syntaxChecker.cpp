#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <ctype.h>
#include "syntaxChecker.h"
#include <string>
#include "Genstackkk.h"
using namespace std;


syntaxError::syntaxError(){//default constructor
}
syntaxError::~syntaxError(){ //destructor
}


void syntaxError::openDelimiters(string syntaxFile){
GenStack<char> syntaxStack(300);//declaring stack talk to daniel about it
ifstream cppFileName (syntaxFile);//reader file
string line;

if (cppFileName.is_open()){
 while(getline(cppFileName,line)){
   lineCount++;//counts number of lines in file

    //continues to read through everyline of file
   for(int i=1; i<line.size(); i++){
     totalElements++; //counts how many characters there are total for location for user.
 if((line[i] == '{' )|| (line[i] == '[')||(line[i]=='('))//pushes only the opening delimiters
   {
     syntaxStack.Push(line[i]);
     openDelimCount++;
   }


else  if(line[i]=='}' || line[i]==']'|| line[i]==')')//condition is used for validing closing bracket with the char that was pushed.
     {

      if(syntaxStack.Peek()=='[' && line[i]==']'){
       syntaxStack.Pop();
     }
      if(syntaxStack.Peek()=='{' && line[i]=='}'){
       syntaxStack.Pop();
     }
      if(syntaxStack.Peek()=='(' && line[i]==')'){
       syntaxStack.Pop();
     }
     if(syntaxStack.isEmpty()){
       cout<<"You have a syntax error of closing demiliter w/o any opening delimiters : @ "<< lineCount<< " character: "<< totalElements<<endl;
       exit(0);
     }


     }

  }
  }
  }
  cppFileName.close();

}



int syntaxError::noErrorDetected()
{
  cout<<"No errors were detected"<<endl;
  return 0;
}
