// main1.cpp

#include "queue1.h"
#include <iostream>
using namespace std;

int main() {
  try {
    Queue<int> q;
    q.add(1); q.add(2); q.add(3); q.remove(); q.remove();
    for (int i=10; i<=35; i++)
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
        

