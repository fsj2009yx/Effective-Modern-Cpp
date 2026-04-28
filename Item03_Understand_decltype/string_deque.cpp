/*
 * Key idea:
 *
 *   Supporting such use means we need to revise the declaration for c to accept
 *   both lvalues and rvalues, and that means that c needs to be a universal
 *   reference.
 *
 */

/*
 * 核心思想：
 *
 *   要支持这种用法，需要修改 c 的声明，使它同时接受左值和右值；这意味着 c 需要是一个
 *   万能引用。
 */

#include <string>
#include <deque>

#include "uref_cpp11.h"

std::deque<std::string> makeStringDeque()   // factory function
{
  std::deque<std::string> ds;
  return ds;
}

int main()
{
  
  // make copy of 5th element of deque returned
  // from makeStringDeque
  auto s = authAndAccess(makeStringDeque(), 5);
}
