/*
 * Key ideas:
 *
 *   1. A function with an auto return type that returns a braced initializer list
 *      won't compile.
 *
 *   2. When auto is used in a parameter type specification in a C++14 lambda
 *      expression, things won't compile.
 *
 */

/*
 * 核心思想：
 *
 *   1. 如果返回类型为 auto 的函数返回一个花括号初始化列表，代码将无法编译。
 *
 *   2. 在 C++14 lambda 表达式的形参类型说明中使用 auto 时，也会出现无法编译的情况。
 */

#include <vector>

auto createInitList()
{
  //return {1, 2, 3};    // error: can't deduce type
  //                     // for {1, 2, 3}
}

int main()
{
  std::vector<int> v;

  auto resetV =
    [&v](const auto& newValue) { v = newValue; };  // C++14

  //resetV( {1, 2, 3} );  // error! can't deduce type
  //                      // for { 1, 2, 3 }
}
