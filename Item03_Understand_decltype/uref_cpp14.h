/*
 * Key idea:
 *
 *   Supporting to pass rvalue containers to this function means we need to
 *   revise the declaration for c to accept both lvalues and rvalues, and that
 *   means that c needs to be a universal reference.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <utility>

void authenticateUser() {}

template<typename Container, typename Index>            // final
decltype(auto)                                          // C++14
authAndAccess(Container&& c, Index i)                   // version 
{
  authenticateUser();
  return std::forward<Container>(c)[i];
}
