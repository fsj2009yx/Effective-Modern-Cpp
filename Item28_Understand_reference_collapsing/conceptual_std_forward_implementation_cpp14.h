/*
 * Key idea:
 *
 *   A conceptual (not Standards-conformant) implementation of std::forward in
 *   C++14 can be implemented more concisely than in C++11 and could look like
 *   this.
 *
 * TODO: add this to CMakeLists.txt so that it gets checked somehow.
 *
 */

/*
 * 核心思想：
 *
 *   C++14 中 std::forward 的一个概念性实现（不符合标准）可以比 C++11 更简洁，可能如下所示。
 *
 *   TODO：把它加入 CMakeLists.txt，使其能以某种方式被检查。
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
