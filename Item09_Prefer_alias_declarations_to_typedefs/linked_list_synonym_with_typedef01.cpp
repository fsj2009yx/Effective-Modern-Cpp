/*
 * Key Idea:
 *
 *   Typedefs cannot be templatized, and therefore need to be wrapped
 *   in a metafunction or container.
 *
 *   中文解释：
 *   typedef 不能直接写成模板别名，因此只能把它包在一个模板结构体里，
 *   再通过内部的 type 成员间接取得真正的类型。
 */

#include <list>
#include <memory>

class Widget {};

template<typename T>
class MyAlloc : public std::allocator<T> {};

template<typename T>                      // MyAllocList<T>::type
struct MyAllocList {                      // is synonym for
  typedef std::list<T, MyAlloc<T>> type;  // std::list<T,
};                                        //   MyAlloc<T>>

MyAllocList<Widget>::type lw;             // client code
