/*
 * Key idea:
 *
 *   Calls to std::type_info::name are not guaranteed to return anything
 *   sensible, but implementations try to be helpful.  The level of helpfullnes
 *   varies.
 *
 */

/*
 * 核心思想：
 *
 *   调用 std::type_info::name 并不保证会返回任何有意义的内容，但实现通常会尽量提供
 *   帮助。帮助程度因实现而异。
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
