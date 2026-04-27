/*
 * Key Idea:
 *
 *   With alias declaration, dependent types no longer require
 *   to be preceded by typename (as does the cumbersome "::type" suffix).
 *
 *   中文解释：
 *   使用 using 别名模板后，客户端代码可以直接写别名类型，
 *   不需要再写 typename，也不需要通过繁琐的 ::type 取出嵌套类型。
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
