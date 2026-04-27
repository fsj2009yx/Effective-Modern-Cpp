/*
 * Key idea:
 *
 *   Example that shows how to use decltype to compute the return type.
 *   Needs refinement though!
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

void authenticateUser() {}

template<typename Container, typename Index>  // works, but
auto authAndAccess(Container& c, Index i)     // requires
  -> decltype(c[i])                           // refinement
{
  authenticateUser();
  return c[i];
}
