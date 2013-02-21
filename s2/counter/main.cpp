#include <iostream>
#include "ccounter.h" // our counter class
using namespace std;
const int OP_QUIT = 0;
const int OP_INC = 1; // counter operations
const int OP_DEC = 2;
const int OP_RESET = 3;

/* user interaction - return the choice */
int menu() {
  char choice;
  cout << endl;
  while ( true ) {
    cout << "0. Quit\n"
         << "1. Inc\n"
         << "2. Dec\n"
         << "3. Reset\n"
         << "Your choice:" << endl;
    cin >> choice;
    cin . ignore(INT_MAX, '\n');
    if (choice >= '0' && choice <= '3')
      return choice - '0';
    cout << "Invalid choice" << endl;
} }
int main()
{
  int     choice;
  CCounter  val(0); // the value is not a global variable
  do {
    cout << "Value = " << val . Value () << endl;
    choice = menu();
    switch (choice) {
      case OP_INC: val . Increment(); break;
      case OP_DEC: val . Decrement(); break;
      case OP_RESET: val . Reset(); break;
    }
  } while (choice != OP_QUIT );
  cout << "Bye" << endl;
  return 0;
}