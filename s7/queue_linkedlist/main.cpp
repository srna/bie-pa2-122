/* main.cpp */
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "queue.h"
#include "../complex/complex.h"

int main() {
/*{
 Queue<int> positive, negative;
 int num;
 cout << "write a zero-terminated sequence of integers" <<
endl;
 cin >> num;
 while (num) {
   if (num>0) positive.push(num);
   else negative.push(num);
   cin >> num;
 }
 cout << "positive numbers:" << endl;
 while (!positive.isEmpty()) {
    num = positive.pop();
    cout << num << ' ';
 }
 cout << "\nnegative numbers:" << endl;
 while (!negative.isEmpty()) {
    num = negative.pop();
    cout << num << ' ';
 }
 cout << endl;
}
{
 Queue<float> positive, negative;
 float num;
 cout << "write a zero-terminated sequence of integers" <<
endl;
 cin >> num;
 while (num) {
   if (num>0) positive.push(num);
   else negative.push(num);
   cin >> num;
 }
 cout << "positive numbers:" << endl;
 while (!positive.isEmpty()) {
    num = positive.pop();
    cout << num << ' ';
 }
 cout << "\nnegative numbers:" << endl;
 while (!negative.isEmpty()) {
    num = negative.pop();
    cout << num << ' ';
 }
 cout << endl;
}*/
{
 Queue<Complex> positive, negative;
 Complex num;
 cout << "write a zero-terminated sequence of complex numbers" <<
endl;
 cin >> num;
 while (num.abs()) {
   if (num.getRe()>=0) positive.push(num);
   else negative.push(num);
   cin >> num;
 }
 cout << "positive numbers:" << endl;
 while (!positive.isEmpty()) {
    num = positive.pop();
    cout << num << ' ';
 }
 cout << "\nnegative numbers:" << endl;
 while (!negative.isEmpty()) {
    num = negative.pop();
    cout << num << ' ';
 }
 cout << endl;
}
 return 0;
}