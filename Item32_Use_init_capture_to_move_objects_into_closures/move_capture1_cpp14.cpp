/**
 * Key idea:
 *
 *   C++14 example showing how you can create a local std::vector, put an
 *   appropriate set of values into it, and then move it into a closure.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <utility>
#include <vector>

int main()
{
  std::vector<double> data;             // object to be moved
                                        // into closure
  
  // ...                                // populate data
  
  auto func = [data = std::move(data)]  // C++14 init capture
              { /* uses of data */ };
}
