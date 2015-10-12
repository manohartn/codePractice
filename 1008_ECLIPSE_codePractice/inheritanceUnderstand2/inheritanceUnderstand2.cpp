#include <iostream>
#include <cstdio>

using namespace std;

class Base1
{
  public:

  virtual int virt1() { return 100; }

  int data1;
};

class Base2
{
  public:

  virtual int virt2() { return 200; }

  int data2;
};

class MultipleDerived : public Base1, public Base2
{
  public:

  virtual int virt1() { return 150; }
  virtual int virt2() { return 250; }

  int derivedData;
};
int Global1( Base1 * b1 )
{
  return b1->virt1();
}

int Global2( Base2 * b2 )
{
  return b2->virt2();
}

int main()
{
  MultipleDerived * md = new MultipleDerived;

  printf( "%d %d %d %d\n",
    md->virt1(), Global1( md ), md->virt2(), Global2( md ));
  return 0;
}
