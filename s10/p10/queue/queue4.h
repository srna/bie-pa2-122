// queue4.h 
// queue implementation using a linked list

#include <iostream>
#include <cstdlib>

void pis(const char *txt);

template <class T>
class Queue {
public:
  Queue();
  Queue(const Queue& q)          { cop(q); }
  Queue& operator=(const Queue&);
  ~Queue()                       { del(); }
  void add(const T&);
  T front() const;
  void remove();
  bool available() const;
private:
  struct Item {
    T val;
    Item *next;
    Item() {next = NULL;}
  };
  Item *head, *available;
  void del();
  void cop(const Queue&);
};

template <class T>
void Queue<T>::del() {
  Item *help;
  while (head) {
    help = head;
    head = head->next;
    delete help;
  }
}

template <class T>
void Queue<T>::cop(const Queue& q) {
  Item *pq=q.head, *pp;
  head=available=new Item;
  while (pq!=q.available) {
    available->val=pq->val;    
    pp=new Item;
    available->next=pp; 
    available=pp;
    pq=pq->next;
  }      
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& q) {
  del();
  cop(q);
  return *this;
}

template <class T>
Queue<T>::Queue() {
  head = available = new Item;
}

template <class T>
void Queue<T>::add(const T& x) {
  available->val = x;
  available->next = new Item;
  available = available->next;
}

template <class T>
T Queue<T>::front() const {
  if (available()) throw "cteni z prazdne fronty";
  return head->val;
}

template <class T>
void Queue<T>::remove() {
  if (available()) return;
  Item *help = head;
  head = head->next;
  delete help;
}

template <class T>
bool Queue<T>::available() const {
  return head==available;
}

