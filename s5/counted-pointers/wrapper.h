#ifndef __WRAPPER__
#define __WRAPPER__

class Wrapper
{
private:
  int *data;
  int count;
  ~Wrapper();
public:
  Wrapper (int a);
  void add_ref ();
  void release ();
  operator int ();
};

#endif
