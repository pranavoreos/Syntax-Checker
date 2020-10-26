/*
Pranav Saravanan
Student id: 2341335
Email: saravanan@chapman.edu
CPSC 350-01
Assignment 3 Syntax Checker
*/

//header file GenStack.h

#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

template <class temp>
class GenStack {
  public:
    GenStack(); //default
    GenStack(int maxSize); //overloaded constructor
    ~GenStack(); //destructor

    void push(temp data);
    temp pop();
    temp peek();

    bool isFull();
    bool isEmpty();
    int getSize();
    void increaseSize();

    int top;
    int mSize;

    temp *myArray;
    temp *newArray;

};

// default constructor
template <class temp>
GenStack<temp>::GenStack(){
  myArray = new temp[128];
  newArray = new temp[128];
  mSize = 128;
  top = -1;
}

//overloaded constructor
template <class temp>
GenStack<temp>::GenStack(int maxSize){
  myArray = new temp[maxSize];
  newArray = new temp[maxSize];
  mSize = maxSize;
  top = -1;
}

//destructor
template <class temp>
GenStack<temp>::~GenStack(){
  delete myArray;
  delete newArray;
}

template <class temp>
void GenStack<temp>::push(temp data){
  myArray[++top] = data;
}

template <class temp>
temp GenStack<temp>::pop(){
  if(isEmpty()){
    cout << "stack is empty" << endl;
    return '\0';
  }
  return myArray[top--];
}

template <class temp>
temp GenStack<temp>::peek(){
  return myArray[top];
}

template <class temp>
bool GenStack<temp>::isFull(){
  if(isFull()){
    cout << "stack is full" << endl;
    return '\0';
  }
  return (top = mSize-1);
}

template <class temp>
bool GenStack<temp>::isEmpty(){
  return(top == -1);
}

template <class temp>
int GenStack<temp>::getSize(){
  return top + 1;
}

template <class temp>
void GenStack<temp>::increaseSize(){
  newArray = new temp[mSize];

  for (int i = top; i > -1; --i){
    newArray[i] = myArray[i];
  }

  mSize += 1;
  myArray = new temp[mSize];

  for (int i = top; i > -1; --i) {
      myArray[i] = newArray[i];
  }
}
