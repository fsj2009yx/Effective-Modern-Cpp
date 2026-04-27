/**
 * Key idea:
 *
 *   Using std::async with the default launch policy has some interesting implications.
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
    auto fut = std::async(f);  // run f using default launch policy
}
