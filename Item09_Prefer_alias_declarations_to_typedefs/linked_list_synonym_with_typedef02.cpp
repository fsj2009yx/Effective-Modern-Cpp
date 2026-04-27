/*
 * Key Idea:
 *
 *   Typedefs cannot be templatized, and therefore need to be wrapped
 *   in a metafunction or container. In addition, dependent types
 *   must be preceded by typename.
 *
 *   中文解释：
 *   typedef 不能直接模板化，所以需要用模板结构体包一层并暴露 type。
 *   当这个 type 依赖模板参数时，编译器需要 typename 来确认它表示类型。
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
