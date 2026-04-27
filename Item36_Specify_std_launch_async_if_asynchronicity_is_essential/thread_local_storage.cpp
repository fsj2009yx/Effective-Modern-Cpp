/**
 * Key idea:
 *
 *   The default launch policy's scheduling flexibility often mixes poorly with the use
 *   of thread_local variables, because it means that if f reads or writes such thread-local
 *   storage (TLS), it's not possible to predict which thread's variables will be accessed.
 *
 * TODO: improve this example.
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
    auto fut = std::async(f);  // TLS for f possibly for
                               // independent thread, but
			       // possibly for thread
			       // invoking get or wait on fut
}
