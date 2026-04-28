/*
 * Key idea:
 *
 *   Member function reference qualifiers are one of C++11's less-publicized
 *   features and make it possible to limit use of a member function to lvalues
 *   only or to rvalues only.
 *
 */

/*
 * 核心思想：
 *
 *   成员函数引用限定符是 C++11 中不太被宣传的特性之一，它可以把成员函数的使用限制为
 *   只能用于左值或只能用于右值。
 */

#include <iostream>

class Widget {
public:

  void doWork() & {                          // this version of doWork applies only
    std::cout << "doWork() &" << std::endl;  // when *this is an lvalue
  }

  void doWork() && {                         // this version of doWork applies only
    std::cout << "doWork() &&" << std::endl; // when *this is an rvalue
  }

};

Widget makeWidget()      // factory function (returns rvalue)
{
  Widget w;
  return w;
}

int main()
{
  Widget w;               // normal object (an lvalue)

  w.doWork();             // calls Widget::doWork for lvalues
                          // (i.e., Widget::doWork &)

  makeWidget().doWork();  // calls Widget::doWork for rvalues
                          // (i.e., Widget::doWork &&)
}
