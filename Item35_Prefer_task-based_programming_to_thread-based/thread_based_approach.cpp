/**
 * Key ideas:
 *
 *   - The task-based approach is typically superior to its thread-based counterpart.
 *
 *   - With the thread-based invocation, there's no straightforward way to get access
 *     to the return value of doAsyncWork.
 *
 *   - With the thread-based approach, if doAsyncWork throws, the program dies (via a call
 *     to std::terminate).
 *
 */

/*
 * 核心思想：
 *
 *   - 基于任务的方法通常优于对应的基于线程的方法。
 *
 *   - 使用基于线程的调用时，没有直接的方法访问 doAsyncWork 的返回值。
 *
 *   - 使用基于线程的方法时，如果 doAsyncWork 抛出异常，程序会死亡（通过调用 std::terminate）。
 */

#include <iostream>
#include <thread>

int doAsyncWork()
{
    std::cout << "doAsyncWork()" << std::endl;

    //throw;

    return 1;

}


int main()
{
    std::thread t(doAsyncWork);

    t.join();

    return 0;
}
