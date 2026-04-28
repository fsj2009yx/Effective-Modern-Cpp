/*
 * Key idea:
 *
 *   A conceptual (not Standards-conformant) implementation of std::forward
 *   could look like this.
 *
 * TODO: add this to CMakeLists.txt so that it gets checked somehow.
 *
 */

/*
 * 核心思想：
 *
 *   std::forward 的一个概念性实现（不符合标准）可能如下所示。
 *
 *   TODO：把它加入 CMakeLists.txt，使其能以某种方式被检查。
 */

#include <type_traits>
#include <utility>

using std::move;
using std::remove_reference;

template<typename T>                              // in
T&& forward(typename                              // namespace
              remove_reference<T>::type& param)   // std
{
  return static_cast<T&&>(param);
}
