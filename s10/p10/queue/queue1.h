// queue1.h 
// queue implementation using an array
// with a static number of elements

template <class T>
class Queue {
public:
  //enum {M = 40};
  static const int M=40; // can be done like this
  Queue();
  void add(const T&);
  T front() const;
  void remove();
  bool empty() const;
private:
  int head, available, count;
  T array[M];
};

template <class T>
Queue<T>::Queue() {
  head = available = count = 0;
}

template <class T>
void Queue<T>::add(const T& x) {
  if (count==M) throw "queue full";
  array[available++] = x; count++;
  if (available>=M) available = 0;
}

template <class T>
T Queue<T>::front() const {
  if (count==0) throw "reading from an empty queue";
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
