// queue3.h
// queue implementation using an extensible array

#include "array.h"

template <class T>
class Queue {
public:
    Queue();
    ~Queue() {cout<<"queue destroyed"<<endl;}
    bool empty() const {return count==0;}
    void add(const T&);
    T front() const;
    void remove();
private:
    Array<T> array;
    int head;
    int available;
    int count;
};

template <class T>        
Queue<T>::Queue() {count=0; head=0; available=0;}

template <class T>        
void Queue<T>::add(const T& x) {
    if (count==array.length()) {
       array.extend(2*count);
       for (int i=0; i<head; i++)
          array[count+i] = array[i];
       available += count;
    } 
    array[available] = x;
    count++;
    available = (available+1) % array.length();
}

template <class T>        
T Queue<T>::front() const {
    if (empty()) throw "reading from an empty queue";
    return array[head];
}

template <class T>        
void Queue<T>::remove() {
    if (empty()) return;
    head = (head+1) % array.length();
    count--;
}
 
        
