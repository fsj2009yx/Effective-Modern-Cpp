/**
 * Key idea:
 *
 *   This is a C++14 version of a function that acts like std::async, but that
 *   automatically uses std::launch::async as the launch policy.
 *
 */

/*
 * 核心思想：
 *
 *   这是一个 C++14 版本的函数，行为类似 std::async，但会自动使用 std::launch::async 作为
 *   启动策略。
 */

#include <future>
#include <iostream>

template<typename F, typename... Ts>
inline
auto                                     // C++14
reallyAsync(F&& f, Ts&&... params)
{
  return std::async(std::launch::async,
                    std::forward<F>(f),
                    std::forward<Ts>(params)...);
}

void f()
{
    std::cout << "f()" << std::endl;
}

int main()
{
    auto fut = reallyAsync(f);  // run f asynchronously;
                                // throw if std::async
                                // would throw
}
