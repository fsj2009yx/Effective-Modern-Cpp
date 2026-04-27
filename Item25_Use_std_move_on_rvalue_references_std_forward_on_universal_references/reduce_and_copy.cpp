/*
 * Key idea:
 *
 *   If the original object is an rvalue, its value should be moved into the
 *   return value (thus avoiding the expense of making a copy), but if the
 *   original value is an lvalue, an actual copy must be created.
 *
 *   If the call to std::forward were omitted, frac would be unconditionally
 *   copied into reduceAndCopy's return value.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

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
