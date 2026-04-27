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
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

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
