/*
 * Key idea:
 *
 *   - The Point constructor can be declared constexpr, because if the arguments
 *   passed to it are known during compilation, the value of the data memberss
 *   of the constructed Point can also be known during compilation.  Points so
 *   initialized could thus be constexpr.
 *
 *   - The getters xValue and yValue can be constexpr, because if they're
 *   invoked on a Point object with a value known during compilation (e.g. a
 *   constexpr Point object), the values of the data members x and y can be
 *   known during compilation.  That makes it possible to write constexpr
 *   functions that call Point's getters and to initialize constexpr objects
 *   with the results of such functions.
 *
 */

/*
 * 核心思想：
 *
 *   - Point 构造函数可以声明为 constexpr，因为如果传给它的实参在编译期已知，构造出的
 *     Point 的数据成员值也可以在编译期已知。因此这样初始化的 Point 可以是 constexpr。
 *
 *   - getter 函数 xValue 和 yValue 可以是 constexpr，因为如果它们在一个编译期值已知的
 *     Point 对象上调用（例如 constexpr Point 对象），数据成员 x 和 y 的值也可以在编译期
 *     已知。这使得编写调用 Point getter 的 constexpr 函数，以及用这些函数的结果初始化
 *     constexpr 对象成为可能。
 */

#include "Point_cpp11.h"

constexpr Point
midpoint(const Point& p1, const Point& p2) noexcept
{
  return { (p1.xValue() + p2.xValue()) / 2,    // call constexpr
           (p1.yValue() + p2.yValue()) / 2 };  // member funcs
}

int main()
{
  constexpr Point p1(9.4, 27.7);   // fine, "runs" constexpr
                                   // ctor during compilation

  constexpr Point p2(28.8, 5.3);   // also fine

  constexpr auto mid = midpoint(p1, p2);  // init constexpr
                                          // object w/result of
                                          // constexpr function
}
