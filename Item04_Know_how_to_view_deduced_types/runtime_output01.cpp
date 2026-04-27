/*
 * Key idea:
 *
 *   Calls to std::type_info::name are not guaranteed to return anything
 *   sensible, but implementations try to be helpful.  The level of helpfullnes
 *   varies.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <iostream>
#include <typeinfo>

const int theAnswer = 42;

auto x = theAnswer;
auto y = &theAnswer;

int main()
{
    std::cout << typeid(x).name() << '\n';   // display types for
    std::cout << typeid(y).name() << '\n';   // x and y
}
