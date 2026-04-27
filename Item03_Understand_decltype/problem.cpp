/*
 * Key idea:
 *
 * This code attempts to assign 10 to an rvalue int, which is forbidden in C++,
 * so the code won't compile.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

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
