/*
 * Key Idea:
 *
 *   Alias declarations may be templatized (typedefs cannot).
 *
 */

/*
 * 核心思想：
 *
 *   别名声明可以模板化（typedef 不可以）。
 */

#include <list>
#include <memory>

class Widget {};

template<typename T>
class MyAlloc : public std::allocator<T> {};

template<typename T>                           // MyAllocList<T>
using MyAllocList = std::list<T, MyAlloc<T>>;  // is synonym for
                                               // std::list<T,
                                               //   MyAlloc<T>>

MyAllocList<Widget> lw;                        // client code
