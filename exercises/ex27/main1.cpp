// 601.220 - example of inheritance, virtual functions, dynamic binding

#include "Aclass.h"
#include "Bclass.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main (void) {
  A aobj(1);
  A* aptr;
  B bobj(2);
  B* bptr;

  aptr = &aobj;
  aptr->show();
  aptr->display(); 
  cout << endl;
  // aobj.d = 17.5;  
  // a::d is protected and this is not a memeber function

  bptr = &bobj;
  aptr = bptr;   
  // aptr->setb(15); 
  // A does not have a member function setb
  aptr->seta(3);
  aptr->show();     
  cout << endl;
  aptr->display();  

  cout << endl;
  aobj = A(10);
  aobj.show();
  aobj = bobj;
  aobj.show();
  A a5(5);
  // B does not define an assignment that takes an operator of type a
  // bobj = a5;  

}


