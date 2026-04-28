/*
 * Key idea:
 *
 *   If the original object is an rvalue, its value should be moved into the
 *   return value (thus avoiding the expense of making a copy), but if the
 *   original value is an lvalue, an actual copy must be created.
 *
 *   If the call to std::forward were omitted, frac would be unconditionally
 *   copied into reduceAndCopy's return value.
 *
 */

/*
 * 核心思想：
 *
 *   如果原对象是右值，它的值应该被移动到返回值中（从而避免拷贝开销）；但如果原值是左值，
 *   就必须创建真正的副本。
 *
 *   如果省略对 std::forward 的调用，frac 会被无条件拷贝到 reduceAndCopy 的返回值中。
 */

#include <utility>

struct Fraction {
  void reduce() {};
};

template<typename T>
Fraction                          // by value return
reduceAndCopy(T&& frac)           // universal reference param
{
  frac.reduce();
  return std::forward<T>(frac);   // move rvalue into return
}                                 // value, copy lvalue
