// main1b.cpp

#include "queue1.h"
#include <iostream>
using namespace std;

int main() {
  try {
    Queue<int> q;
    cout << sizeof(q)<<endl;
    q.add(1); q.add(2); q.add(3); q.remove(); q.remove();

    Queue<int> q1=q;
    
    for (int i=10; i<=35; i++)
      q.add(i);
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.remove();
    }
    cout << endl;
    while (!q1.empty()) {
        cout << q1.front() << ' ';
        q1.remove();
    }
    cout << endl;
  }
  catch (const char* s) {
    cerr << "error: " << s << endl;
  }
  return 0;
}
        

