/*
 * Key idea:
 *
 *   Virtual function overriding is what makes it possible to invoke a derived
 *   class function through a base class interface.
 *
 */

/*
 * 核心思想：
 *
 *   虚函数重写使得通过基类接口调用派生类函数成为可能。
 */

#include <iostream>
#include <memory>

class Base {
public:
  virtual void doWork() {                        // base class virtual function
    std::cout << "Base::doWork()" << std::endl;
  }
};

class Derived : public Base {
public:
  virtual void doWork() {                           // overrides Base::doWork
    std::cout << "Derived::doWork()" << std::endl;  // ("virtual" is optional
  }                                                 // here")
};

int main()
{
  std::unique_ptr<Base> upb =     // create base class pointer
    std::make_unique<Derived>();  // to derived class object;
                                  // see Item 21 for info on
  // ...                          // std::make_unique

  upb->doWork();                  // call doWork through base
                                  // class ptr; derived class
                                  // function is invoked
}
