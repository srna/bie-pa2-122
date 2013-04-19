// main2a.cpp
// skonci chybou

#include "queue2.h"
#include <iostream>
using namespace std;

int main2a() {
  try {
    Queue<int> q(10);
    q.add(1); q.add(2); q.add(3); 
    q.remove(); q.remove(); q.remove();
    for (int i=10; i<=20; i++)
      q.add(i);
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.remove();
    }
    cout << endl;
  }
  catch (const char* s) {
    cerr << "error: " << s << endl;
  }
  system("PAUSE");
  return 0;
}
        

