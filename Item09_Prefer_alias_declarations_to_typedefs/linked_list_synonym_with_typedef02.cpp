/*
 * Key Idea:
 *
 *   Typedefs cannot be templatized, and therefore need to be wrapped
 *   in a metafunction or container. In addition, dependent types
 *   must be preceded by typename.
 *
 */

/*
 * 核心思想：
 *
 *   typedef 不能模板化，因此需要包装在元函数或容器中。此外，依赖类型必须前置 typename。
 */

#include <list>
#include <memory>

template<typename T>
class MyAlloc : public std::allocator<T> {};

template<typename T>                      // MyAllocList<T>::type
struct MyAllocList {                      // is synonym for
  typedef std::list<T, MyAlloc<T>> type;  // std::list<T,
};                                        //   MyAlloc<T>>

template<typename T>
class Widget {                            // Widget<T> contains
private:                                  // a MyAllocList<T>
  typename MyAllocList<T>::type list;     // as a data member
  // ...
};
