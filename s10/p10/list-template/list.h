/* list.h */

#ifndef _LIST_
#define _LIST_

#include <iostream>
using namespace std;

template <class T>
class List {
public:
  List();
  ~List();
  void insert(T);       // insert before the mark
  void remove();        // remove element on the mark
  void removePrev();    // remove element preceding the mark
  void toNext();        // mark to the next element
  void toPrev();        // mark to the previous element
  void toBegin();       // mark to the beginning
  void toEnd();         // mark to the end
  bool empty()   const; // is the list empty?
  bool atBegin() const; // is the mark at the beginning?
  bool atEnd()   const; // is the mark at the end?
  bool read(T&)  const; // reading from the mark position
  ostream& print(ostream&) const;  // print mehtod

private:
  struct Node {
    T val;
    Node *next, *prev;
    Node(T x, Node *n) {
      // n cannot be NULL
      val = x; next = n; prev = n->prev;
    }
    Node() {next = NULL; prev = NULL;}
  };
  Node *begin;
  Node *tail;
  Node *mark;
  List(const List &);
  List& operator=(const List&);
};


template <class T>
List<T>::List() {
  begin = tail = mark = new Node;
} 

template <class T>
List<T>::~List() {
  Node *p;
  while (begin) {
    p  = begin;
    begin = begin->next;
    delete p;
  }
}

template <class T>
bool List<T>::empty() const {
  return begin == tail;
}

template <class T>
bool List<T>::atBegin() const {
  return mark==begin;
}

template <class T>
bool List<T>::atEnd() const {
  return mark==tail;
}

template <class T>
void List<T>::toBegin() {
  mark = begin;
}

template <class T>
void List<T>::toEnd() {
  mark = tail;
}

template <class T>
void List<T>::toNext() {
  if (atEnd()) return;
  mark = mark->next;
}

template <class T>
void List<T>::toPrev() {
  if (atBegin()) return;
  mark = mark->prev;
}

template <class T>
void List<T>::insert(T x) {
  Node *p = new Node(x, mark);
  mark->prev = p;
  if (atBegin()) 
    begin = p;
  else
    p->prev->next = p;
}

template <class T>
void List<T>::remove() {
  if (atEnd()) return;
  Node *p = mark;
  mark->next->prev = mark->prev;
  if (atBegin())
    begin = mark->next;
  else
    mark->prev->next = mark->next;
  mark = mark->next;
  delete p;
}
    
template <class T>
void List<T>::removePrev() {
  if (atBegin()) return;
  toPrev();
  remove();
}

template <class T>
bool List<T>::read(T &x) const {
  if (atEnd()) return false;
  x = mark->val;
  return true;
}
  
template <class T>
ostream& List<T>::print(ostream& s) const {
  s << '[';
  Node *p = begin;
  while (p) {
    if (p==mark) s << '|';
    if (p!=tail) s << p->val << ' ';
    p = p->next;
  }
  s << ']';
  return s;
}
   
template <class T>
ostream& operator<<(ostream& s, const List<T>& lst) {
  return lst.print(s);
}


#endif

