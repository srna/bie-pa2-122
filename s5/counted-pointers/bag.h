#ifndef __BAG__
#define __BAG__
#include "wrapper.h"
#include <iostream>

class Bag
{
private:
  class Element
    {
  public:
    Wrapper *data;
    Element *next;
    Element (int a);
    Element (const Element & i);
    ~Element();
    operator int ();
    };
  Element *data;
  int count;

public:
  Bag();
  Bag(const Bag & b);
  ~Bag();

  void insert (int a);
  void remove (int a);
  bool isThere (int a);
  Bag& operator+=(int a);
  Bag& operator= (const Bag& b);


  friend std::ostream& operator<<(std::ostream& stream, const Bag& b);

};


#endif
