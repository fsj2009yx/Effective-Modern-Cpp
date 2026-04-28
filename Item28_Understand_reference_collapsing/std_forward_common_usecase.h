/*
 * Key idea:
 *
 *   A common use case for std::forward looks like this.
 *
 * TODO: add this to CMakeLists.txt somehow.
 *
 */

/*
 * 核心思想：
 *
 *   std::forward 的一个常见用法如下。
 *
 *   TODO：以某种方式把它加入 CMakeLists.txt。
 */

void someFunc(int x) {}

template<typename T>
void f(T&& fParam)
{
  // ...                              // do some work

  someFunc(std::forward<T>(fParam));  // forward fParam to
}                                     // someFunc
