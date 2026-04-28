/**
 * Key idea:
 *
 *   The way to guarantee that std::async will schedule the task for truly
 *   asynchronous execution is to pass std::launch::async as the first argument
 *   when you make the call to std::async.
 *
 */

/*
 * 核心思想：
 *
 *   要保证 std::async 会以真正异步的方式调度任务，做法是在调用 std::async 时把
 *   std::launch::async 作为第一个实参传入。
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
