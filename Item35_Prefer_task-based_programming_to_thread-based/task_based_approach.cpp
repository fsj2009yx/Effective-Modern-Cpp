/**
 * Key ideas:
 *
 *   - The task-based approach is typically superior to its thread-based counterpart.
 *
 *   - With the task-based approach, it is easy to get access to the return value of doAsyncWork,
 *     because the future returned from std::async offers the get function.
 *
 *   - The get function also provides access to the exception if doAsyncWork throws an exception.
 *
 */

/*
 * 核心思想：
 *
 *   - 基于任务的方法通常优于对应的基于线程的方法。
 *
 *   - 使用基于任务的方法时，很容易访问 doAsyncWork 的返回值，因为 std::async 返回的 future
 *     提供了 get 函数。
 *
 *   - 如果 doAsyncWork 抛出异常，get 函数也会提供对该异常的访问。
 */

#include <future>
#include <iostream>

int doAsyncWork()
{
    std::cout << "doAsyncWork()" << std::endl;

    //throw;

    return 1;
}


int main()
{
    auto fut = std::async(doAsyncWork);  // onus of thread mgmt is
                                         // on implementer of
					 // the Standard Library

    int ret = fut.get();
    std::cout << "doAsyncWork() returned " << ret << std::endl;

    return 0;
}
