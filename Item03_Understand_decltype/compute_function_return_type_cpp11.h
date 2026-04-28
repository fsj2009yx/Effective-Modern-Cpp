/*
 * Key idea:
 *
 *   Example that shows how to use decltype to compute the return type.
 *   Needs refinement though!
 *
 */

/*
 * 核心思想：
 *
 *   这个示例展示如何使用 decltype 计算返回类型。不过它仍需要进一步完善。
 */

void authenticateUser() {}

template<typename Container, typename Index>  // works, but
auto authAndAccess(Container& c, Index i)     // requires
  -> decltype(c[i])                           // refinement
{
  authenticateUser();
  return c[i];
}
