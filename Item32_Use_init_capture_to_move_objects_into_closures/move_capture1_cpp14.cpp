/**
 * Key idea:
 *
 *   C++14 example showing how you can create a local std::vector, put an
 *   appropriate set of values into it, and then move it into a closure.
 *
 */

/*
 * 核心思想：
 *
 *   C++14 示例，展示如何创建一个局部 std::vector，放入适当的一组值，然后把它移动到闭包中。
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
