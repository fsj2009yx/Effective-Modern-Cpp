/*
 * Key idea:
 *
 *   auto universal references crop up quite a lot in C++14, because C++14
 *   lambda expressions may declare auto&& parameters.
 *
 */

/*
 * 核心思想：
 *
 *   auto 万能引用在 C++14 中相当常见，因为 C++14 的 lambda 表达式可以声明 auto&& 形参。
 */

#include <utility>

auto timeFuncInvocation =
  [](auto&& func, auto&&... params)               // C++14
  {
    // start timer;
    std::forward<decltype(func)>(func)(           // invoke func
      std::forward<decltype(params)>(params)...   // on params
      );
    // stop timer and record elapsed time;
  };
