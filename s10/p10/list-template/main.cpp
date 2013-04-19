/* main.cpp */

#include <cstdlib>
using namespace std;

#include "list.h"

List<int> list;

int menu(void) {
  cout << "list of operations" << endl;
  cout << " 0. End the program\n";
  cout << " 1. insert\n";
  cout << " 2. remove\n";
  cout << " 3. removePrev\n";
  cout << " 4. toNext\n";
  cout << " 5. toPrev\n";
  cout << " 6. toBegin\n";
  cout << " 7. toEnd\n";
  cout << " 8. empty\n";
  cout << " 9. atBegin\n";
  cout << "10. atEnd\n";
  cout << "11. read\n";
  cout << "Input operation number" << endl;
  int op;
  do {
    cin >> op;
    if (op<0 || op>11) {
      cout << "wrong operation number, specify again" << endl;
      op = -1;
    }  
    cin.ignore(100, '\n');
  } while (op<0);
  return op;
}
    
int main() {
  int op;
  int x;
  do {
    cout << list << endl;
    op = menu();
    switch (op) {
      case 1: cin >> x; list.insert(x); break;
      case 2: list.remove(); break;
      case 3: list.removePrev(); break;
      case 4: list.toNext(); break;
      case 5: list.toPrev(); break;
      case 6: list.toBegin(); break;
      case 7: list.toEnd(); break;
      case 8: cout << list.empty() << endl; break;
      case 9: cout << list.atBegin() << endl; break;
      case 10: cout << list.atEnd() << endl; break;
      case 11: if (list.read(x)) cout << x << endl; break;
    }
  } while (op>0); 
  system("PAUSE");
  return 0;
}
