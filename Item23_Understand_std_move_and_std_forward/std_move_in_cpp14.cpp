/*
 * Key idea:
 *
 *   std::move can be easily implemented in C++14 thanks to function return type
 *   deduction and to the Standard Library's alias template
 *   std::remove_reference_t.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <type_traits>
using std::remove_reference_t;

template<typename T>                          // C++14 only; still
auto move(T&& param)                          // in namespace std
{
  using ReturnType = remove_reference_t<T>&&;
  return static_cast<ReturnType>(param);
}
