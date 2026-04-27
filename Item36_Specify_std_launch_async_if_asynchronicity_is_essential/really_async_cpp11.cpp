/**
 * Key idea:
 *
 *   This is a C++11 version of a function that acts like std::async, but that
 *   automatically uses std::launch::async as the launch policy.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <future>
#include <iostream>

template<typename F, typename... Ts>
inline
std::future<typename std::result_of<F(Ts...)>::type>
reallyAsync(F&& f, Ts&&... params)       // return future
{                                        // for asynchronous
  return std::async(std::launch::async,  // call to f(params...)
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
