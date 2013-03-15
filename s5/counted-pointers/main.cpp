#include "bag.h"
#include <iostream>
using namespace std;

int main() {
    Bag b1;
    b1. insert (1);
    b1. insert (3);
    b1. insert (1);
    b1. insert (2);
    cout << "b1 = " << b1 << endl;
    Bag b2 = b1;
    b1. remove (1);
    cout << "b1 = " << b1 << endl;
    cout << "b2 = " << b2 << endl;
    Bag b3;
    b3 = b1;
    b1. remove (1);
    cout << "b1 = " << b1 << endl;
    cout << "b3 = " << b3 << endl;
    return 0;
}

