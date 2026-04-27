/**
 * Key idea:
 *
 *   The way to guarantee that std::async will schedule the task for truly
 *   asynchronous execution is to pass std::launch::async as the first argument
 *   when you make the call to std::async.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <future>
#include <iostream>

void f()
{
    std::cout << "f()" << std::endl;
}


int main()
{
    auto fut = std::async(std::launch::async, f);  // launch f
                                                   // asynchronously

    fut.get();

    return 0;
}
