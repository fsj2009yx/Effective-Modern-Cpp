/*
 * Key idea:
 *
 *   The C++11 version is almost the same as its C++14 counterpart, except that
 *   you have to specify the return type yourself.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

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
