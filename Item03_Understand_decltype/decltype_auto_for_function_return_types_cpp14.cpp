/*
 * Key idea:
 *
 *   Sometimes, one needs decltype type deduction rules in cases where types are
 *   inferred.  C++14 makes this possible through the decltype(auto) specifier:
 *   auto specifies that the type is to be deduced, and decltype says that
 *   decltype rules should be used during the deduction.
 *
 */

/*
 * 核心思想：
 *
 *   有时在类型被推断的场景中，需要使用 decltype 的类型推导规则。C++14 通过
 *   decltype(auto) 说明符支持这一点：auto 表示类型需要被推导，decltype 表示推导时
 *   应使用 decltype 规则。
 */

void authenticateUser() {}

template<typename Container, typename Index>  // C++14 only;
decltype(auto)                                // works, but
authAndAccess(Container& c, Index i)          // still requires
{                                             // refinement
  authenticateUser();
  return c[i];
}
