#include <iostream>

#ifndef _ACLASS_H
#define _ACLASS_H

class A { // base class
private: 
  int a;

protected:
  double d;

public: 
  A(int val = 0, double num = 0): a(val), d(num) { };
  ~A() { std::cout << "A obj killed" << std::endl; } ;
  void seta(int val) { a = val; };
  void setd(double dval) { d = dval; } ;
  void display() { std::cout << "non-virtual display A " <<  std::endl; show(); };
  void test() { std::cout << "test A" << std::endl ; };
  virtual void show() { std::cout << "A is " << a << std::endl; test(); };
  // virtual = aptr = bptr; aptr->show(). show is virtual. show function 
  // from the b object is called because aptr is pointing to a b object

};

#endif
