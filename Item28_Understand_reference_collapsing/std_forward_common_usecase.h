/*
 * Key idea:
 *
 *   A common use case for std::forward looks like this.
 *
 * TODO: add this to CMakeLists.txt somehow.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

void someFunc(int x) {}

template<typename T>
void f(T&& fParam)
{
  // ...                              // do some work

  someFunc(std::forward<T>(fParam));  // forward fParam to
}                                     // someFunc
