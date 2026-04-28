/*
 * Key Idea:
 *
 *   With alias declaration, dependent types no longer require
 *   to be preceded by typename (as does the cumbersome "::type" suffix).
 *
 */

/*
 * 核心思想：
 *
 *   使用别名声明时，依赖类型不再需要前置 typename，也不再需要笨重的 ::type 后缀。
 */

#include <list>
#include <memory>

template<typename T>
class MyAlloc : public std::allocator<T> {};

template<typename T>
using MyAllocList = std::list<T, MyAlloc<T>>;  // as before

template<typename T>
class Widget {
private:
  MyAllocList<T> list;                         // no "typename",
  // ...                                       // no "::type"
};
