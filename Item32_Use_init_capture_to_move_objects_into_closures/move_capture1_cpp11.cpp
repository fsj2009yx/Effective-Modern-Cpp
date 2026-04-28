/**
 * Key idea:
 *
 *   C++11 example showing how you can emulate move capture in C++11 by
 *
 *   1. moving the object to be captured into a function object produced by
 *      std::bind and
 *   2. giving the lambda a reference to the "captured" object.
 *
 */

/*
 * 核心思想：
 *
 *   C++11 示例，展示如何在 C++11 中模拟移动捕获：
 *
 *   1. 把要捕获的对象移动到 std::bind 生成的函数对象中；
 *   2. 让 lambda 持有对这个“被捕获”对象的引用。
 */

#include <functional>
#include <utility>
#include <vector>

int main()
{
  std::vector<double> data;                    // object to be moved
                                               // into closure
  
  // ...                                       // populate data
  
  {
    auto func =
      std::bind(                               // C++11 emulation
        [](const std::vector<double>& data)    // of init capture
        { /* uses of data */ },
        std::move(data)
      );
  }

  {
    auto func =
      std::bind(                               // C++11 emulation
        [](std::vector<double>& data) mutable  // of init capture
        { /* uses of data */ },                // for mutable lambda
        std::move(data)
      );
  }
}
