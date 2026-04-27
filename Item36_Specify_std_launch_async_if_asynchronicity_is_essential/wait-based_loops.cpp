/** Key idea:
 *
 *   - The default launch policy's scheduling flexibility also affects
 *     wait-based for loops using timeouts, because calling wait_for or
 *     wait_until on a task (see Item 35) that's deferred yields the value
 *     std::launch::deferred.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

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
