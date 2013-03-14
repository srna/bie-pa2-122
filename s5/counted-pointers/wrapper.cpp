#include "wrapper.h"

Wrapper::Wrapper (int a)
{
  count = 1;
  data = new int (a);
}

void Wrapper::add_ref ()
{
  count++;
}

void Wrapper::release ()
{
  count--;
  if (count == 0)
    delete this;
}

Wrapper::~Wrapper ()
{
  if (count != 0)
    throw "Wrapper destroyed while still referenced";
  delete data;
}

Wrapper::operator int ()
{
  return *data;
}
