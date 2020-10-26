/*
Pranav Saravanan
Student id: 2341335
Email: saravanan@chapman.edu
CPSC 350-01
Assignment 3 Syntax Checker
*/

#include "GenStack.h"

using namespace std;

int main (int argc, char** argv){

  //Creates a stack of 10 chars
  GenStack <char> myStack(10);

  bool repeat = true;

  //A while loop for in case the user wants to keep going
  while(repeat){

    //File Input
    string fileName;
    cout << "Please enter in the file name: " << endl;
    cin >> fileName;
    ifstream infile;
    infile.open(fileName.c_str());
    if (!infile) {
      cerr << "Unable to open file";
      exit(1);
    }

    string str;
    int lineNum = 0;

    //While loop to check for the delimeters
    while (getline(infile, str)){
      lineNum++;
      for(int i = 0; i < str.size(); ++i){
        if ((str[i] == '(')||(str[i] == ')')||(str[i] == '{')||(str[i] == '}')||(str[i] == '[')||(str[i] == ']')){
          if ((myStack.peek() == '(')&&(str[i] == ')')){
              myStack.pop();
            }
          else if((myStack.peek() == '{')&&(str[i] == '}')){
            myStack.pop();
          }
          else if((myStack.peek() == '[')&&(str[i] == ']')){
            myStack.pop();
          }
          else if((myStack.peek() == '(')&&(str[i] == '}')){
            cout << "Line " << lineNum << ": ')' expected and found '}" << endl;
            return 0;
          }
          else if((myStack.peek() == '(')&&(str[i] == ']')){
            cout << "Line " << lineNum << ": ')' expected and found ']" << endl;
            return 0;
          }
          else if((myStack.peek() == '{')&&(str[i] == ')')){
            cout << "Line " << lineNum << ": '}' expected and found ')" << endl;
            return 0;
          }
          else if((myStack.peek() == '{')&&(str[i] == ']')){
            cout << "Line " << lineNum << ": '}' expected and found ']" << endl;
            return 0;
          }
          else if((myStack.peek() == '[')&&(str[i] == ')')){
            cout << "Line " << lineNum << ": ']' expected and found ')" << endl;
            return 0;
          }
          else if((myStack.peek() == '[')&&(str[i] == '}')){
            cout << "Line " << lineNum << ": ']' expected and found '}" << endl;
            return 0;
          }
          else if((str[i] == '(')||(str[i] == '{')||(str[i] == '[')){
            myStack.push(str[i]);
          }
        }
      }
    }

    //Throws Error if isEmpty is false
    if (myStack.isEmpty() == 0) {
            cout << "ERROR!" << myStack.peek() << endl;
            return 0;
        }

    //If the file has no errors asking the user if they want to go again
    char answer;
    cout << "There were no errors found in this file. Would you like to check another file for any errors?(Y/N)" << endl;
    cin >> answer;

    if(answer == 'Y' || answer == 'y'){
      repeat = true;
    }
    else{
      repeat = false;
    }
  }
  return 0;
}
