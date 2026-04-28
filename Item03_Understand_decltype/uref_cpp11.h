/*
 * Key idea:
 *
 *   The C++11 version is almost the same as its C++14 counterpart, except that
 *   you have to specify the return type yourself.
 *
 */

/*
 * 核心思想：
 *
 *   C++11 版本几乎与对应的 C++14 版本相同，区别只是必须自己显式指定返回类型。
 */

#include <utility>

void authenticateUser() {}

template<typename Container, typename Index>            // final
auto                                                    // C++11
authAndAccess(Container&& c, Index i)                   // version 
-> decltype(std::forward<Container>(c)[i])
{
  authenticateUser();
  return std::forward<Container>(c)[i];
}
