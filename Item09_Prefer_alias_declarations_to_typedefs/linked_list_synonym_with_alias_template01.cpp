/*
 * Key Idea:
 *
 *   Alias declarations may be templatized (typedefs cannot).
 *
 *   中文解释：
 *   using 声明可以直接写成别名模板，
 *   而 typedef 不能直接模板化，所以 using 更适合表达模板类型别名。
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
