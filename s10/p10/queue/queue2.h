// queue2.h 
// queue implementation using an array
// with a dynamic number of elements

#include <cstring>

template <class T>
class Queue {
public:
  Queue(int = 40);
  ~Queue();
  void add(const T&);
  T front() const;
  void remove();
  bool empty() const;
private:
  int head, available, count;
  int M;
  T* array;
  void copy(const Queue&);
  void del();
public:
  Queue(const Queue&);              // copy constructor forbidden
  Queue& operator=(const Queue&);   // assignment operator forbidden - main2b
};

template <class T>
void Queue<T>::copy(const Queue& q)
{
  head = q.head;
  available = q.available;
  count = q.count;
  M = q.M;
  array = new T[M];
  for(int i = 0; i < count; i++)
    array[(i+head)%M] = q.array[(i+head)%M];
}

template <class T>
void Queue<T>::del()
{
  delete [] array;
  array = 0;
}

template <class T>
Queue& Queue<T>::operator=(const Queue& q)
{
  if(this != &q)
  {
    del();
    copy(q);
  }
  return *this;
}

template <class T>
Queue<T>::Queue(const Queue& q)
{
  copy(q);
}

template <class T>
Queue<T>::Queue(int m) {
  head = available = count = 0;
  M = m;
  array = new T[M];
}

template <class T>
Queue<T>::~Queue() {
  del();
}

template <class T>
void Queue<T>::add(const T& x) {
  if (count==M) throw "queue full";
  array[available++] = x; count++;
  if (available>=M) available = 0;
}

template <class T>
T Queue<T>::front() const {
  if (empty()) throw "reading from an empty queue";
  return array[head];
}

template <class T>
void Queue<T>::remove() {
  if (empty()) return;
  head++; count--;
  if (head>=M) head = 0;
}

template <class T>
bool Queue<T>::empty() const {
  return count==0;
}
