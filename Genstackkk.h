#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
 #include <fstream>
#include <cstring>
#include <ctype.h>
#include <string>
using namespace std;
template <class Type>
class GenStack
{
private:
  int size;
  int top=0;
  Type* stackPtr;
public:
  GenStack(int size);//overloaded constructor
  ~GenStack();//destructor
  void Push(Type data);
  Type Pop();
  Type Peek();
  bool isFull();
  bool isEmpty();
  int getSize();
  void increaseSize();
  //is a pointer-reference or adddress
};

template<typename Type>
GenStack<Type>::GenStack(int size){
  if(size>0){
    this-> size = size;
    stackPtr = new Type[size];
  }
  else{
  this->top=-1;
  stackPtr = new Type(this-> size);
}
}

template<typename Type>
Type GenStack<Type>::Peek()
{
if(this-> top <= this-> size-1 && this-> isEmpty()==false){
return stackPtr[this->top];
}
}

template<typename Type>
Type GenStack<Type>::Pop()
{
  if(top>0){
  return stackPtr[this->top--];
          }
}

template<typename Type>
int GenStack<Type>::getSize(){
  return this -> size;
}

template<typename Type>
GenStack<Type>::~GenStack(){ //deletes memory and array
  delete []stackPtr;
}

template<typename Type>
void GenStack<Type>::Push(Type data){

  if(this-> isFull()==false){
    stackPtr[++this -> top]=data;
  }

  else{
    cout<<"stack is full"<<endl;
  }
}

template<typename Type>
bool GenStack<Type>::isFull(){
  return (this->size ==this -> size-1);
}
template<typename Type>
bool GenStack<Type>::isEmpty(){
  return (this->top==1);
}
template<typename Type>
void GenStack<Type>::increaseSize(){
  size = size *5;
  Type resizedArray = new Type(size);
  for(int i = 0; i <size;i++){
    resizedArray[i]= stackPtr[i];
  }
  stackPtr = resizedArray;
  }
