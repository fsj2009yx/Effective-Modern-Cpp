/**
 * Key idea:
 *
 *   The default launch policy's scheduling flexibility often mixes poorly with the use
 *   of thread_local variables, because it means that if f reads or writes such thread-local
 *   storage (TLS), it's not possible to predict which thread's variables will be accessed.
 *
 * TODO: improve this example.
 *
 */

/*
 * 核心思想：
 *
 *   默认启动策略的调度灵活性常常与 thread_local 变量的使用配合不佳，因为这意味着如果 f
 *   读写这种线程局部存储（TLS），就无法预测会访问哪个线程的变量。
 *
 *   TODO：改进这个示例。
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
