/*
 * Key idea:
 *
 *   A conceptual (not Standards-conformant) implementation of std::forward in
 *   C++14 can be implemented more concisely than in C++11 and could look like
 *   this.
 *
 * TODO: add this to CMakeLists.txt so that it gets checked somehow.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <type_traits>
#include <utility>

using std::move;
using std::remove_reference;

template<typename T>                                 // C++14; still in
T&& forward(typename remove_reference_t<T>& param)   // namespace std
{
  return static_cast<T&&>(param);
}
