/*
 * Key idea:
 *
 *   Sometimes, one needs decltype type deduction rules in cases where types are
 *   inferred.  C++14 makes this possible through the decltype(auto) specifier:
 *   auto specifies that the type is to be deduced, and decltype says that
 *   decltype rules should be used during the deduction.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

void authenticateUser() {}

template<typename Container, typename Index>  // C++14 only;
decltype(auto)                                // works, but
authAndAccess(Container& c, Index i)          // still requires
{                                             // refinement
  authenticateUser();
  return c[i];
}
