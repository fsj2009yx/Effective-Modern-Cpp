/*
 * Key idea:
 *
 *   In essence, std::move casts its argument to an rvalue, and that's all it
 *   does.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <type_traits>
using std::remove_reference;

template<typename T>                       // in namespace std
typename remove_reference<T>::type&&
move(T&& param)
{
  using ReturnType =                       // alias declaration;
    typename remove_reference<T>::type&&;  // see Item 9

  return static_cast<ReturnType>(param);
}
