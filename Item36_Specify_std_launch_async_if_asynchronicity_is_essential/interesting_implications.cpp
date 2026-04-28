/**
 * Key idea:
 *
 *   Using std::async with the default launch policy has some interesting implications.
 *
 * TODO: improve this example.
 *
 */

/*
 * 核心思想：
 *
 *   使用默认启动策略调用 std::async 会带来一些有趣的影响。
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
    auto fut = std::async(f);  // run f using default launch policy
}
