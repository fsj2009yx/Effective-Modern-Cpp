/** Key idea:
 *
 *   - The default launch policy's scheduling flexibility also affects
 *     wait-based for loops using timeouts, because calling wait_for or
 *     wait_until on a task (see Item 35) that's deferred yields the value
 *     std::launch::deferred.
 *
 */

/*
 * 核心思想：
 *
 *   - 默认启动策略的调度灵活性也会影响使用超时的基于 wait 的循环，因为对一个被延迟执行的
 *     任务（见 Item 35）调用 wait_for 或 wait_until，会得到 std::launch::deferred。
 */

#include <future>

using namespace std::literals;         // for C++14 duration
                                       // suffixes; see Item 34

void f()                               // f sleeps for 1 second,
{                                      // then returns
    std::this_thread::sleep_for(1s);
}


int main()
{
    auto fut = std::async(f);          // run f asynchronously
                                       // (conceptually)
    
    while (fut.wait_for(100ms) !=      // loop until f has
           std::future_status::ready)  // finished running...
    {                                  // which may never happen!
      // ...
    }
}
