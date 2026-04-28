/*
 * Key idea:
 *
 *   std::move can be easily implemented in C++14 thanks to function return type
 *   deduction and to the Standard Library's alias template
 *   std::remove_reference_t.
 *
 */

/*
 * 核心思想：
 *
 *   得益于函数返回类型推导以及标准库别名模板 std::remove_reference_t，std::move 可以在
 *   C++14 中很容易地实现。
 */

#include <type_traits>
using std::remove_reference_t;

template<typename T>                          // C++14 only; still
auto move(T&& param)                          // in namespace std
{
  using ReturnType = remove_reference_t<T>&&;
  return static_cast<ReturnType>(param);
}
