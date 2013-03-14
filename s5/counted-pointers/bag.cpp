#include "bag.h"
using namespace std;

Bag::Bag ()
  : count(0)
{
  data = NULL;
}

Bag::Bag (const Bag & b)
  : count (b.count)
{
  data = new Element (*b.data);
}

Bag::~Bag ()
{
  Element *tmp;
  for (Element *e = data; e; e = tmp)
    {
      tmp = e->next;
      delete e;
    }
}

void Bag::insert (int a)
{
  Element *c = new Element (a);
  c->next = data;
  data = c;
}

void Bag::remove (int a)
{
  if (data)
    {
      if (*data->data == a)
        {
          Element *c = data->next;
          delete data;
          data = c;
        }
      else
        {
          for (Element *c = data; c->next; c = c->next)
            {
              if (*c->next->data == a)
                {
                  Element *tmp = c->next;
                  c->next = c->next->next;
                  delete tmp;
                  break;
                }
            }
        }
    }
}

bool Bag::isThere (int a)
{
  for (Element *c = data; c; c = c->next)
    if (*c->data == a)
      return true;
  return false;
}

Bag & Bag::operator+= (int a)
{
  Bag *b = new Bag (*this);
  b->insert (a);
  Element *tmp;
  for (Element *e = data; e; e = tmp)
    {
      tmp = e->next;
      delete e;
    }
  return *b;
}

Bag & Bag::operator= (const Bag & b)
{
  if (this == &b)
    return *this;
  count = b.count;
  data = new Element (*b.data);
  return *this;
}

ostream & operator<< (ostream & stream, const Bag & b)
{
  for (Bag::Element *c = b.data; c; c = c->next)
    stream << *c << ' ';
  return stream;
}

Bag::Element::Element (int a)
{
  data = new Wrapper(a);
  next = NULL;
}

Bag::Element::Element (const Element & i)
{
  data = i.data;
  data->add_ref ();
  if (i.next)
    next = new Element (*i.next);
  else
    next = NULL;
}

Bag::Element::~Element ()
{
  data->release ();
}

Bag::Element::operator int ()
{
  return *data;
}
