/*
 * Key idea:
 *
 * This code attempts to assign 10 to an rvalue int, which is forbidden in C++,
 * so the code won't compile.
 *
 */

/*
 * 核心思想：
 *
 *   这段代码试图把 10 赋给一个右值 int，这在 C++ 中是禁止的，因此代码无法编译。
 */

#include <deque>

//#include "compute_function_return_type_cpp14.h"
#include "compute_function_return_type_cpp11.h"

int main()
{
  std::deque<int> d;
  
  authAndAccess(d, 5) = 10;  // authenticate user, return d[5],
                             // then assign 10 to it;
                             // this won't compile!
}
