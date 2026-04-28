/*
 * Key idea:
 *
 *   Supporting to pass rvalue containers to this function means we need to
 *   revise the declaration for c to accept both lvalues and rvalues, and that
 *   means that c needs to be a universal reference.
 *
 */

/*
 * 核心思想：
 *
 *   为了支持向该函数传递右值容器，需要修改 c 的声明，使它同时接受左值和右值；这意味着
 *   c 需要是一个万能引用。
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
