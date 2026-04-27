/*
 * Key Idea:
 *
 *   Unscoped enums implicitly convert to integral types,
 *   allowing the below to run. Scoped enums are strongly
 *   typed.
 *
 *   中文解释：
 *   非作用域枚举会隐式转换成整数类型，因此可能和 double 比较，
 *   甚至被传给需要 size_t 的函数。作用域枚举是强类型的，可以避免这类误用。
 */

#include <cstddef>
#include <vector>

enum Color { black, white, red };  // unscoped enum

std::vector<std::size_t>           // func. returning
primeFactors(std::size_t x) {      // prime factors of x
  std::vector<std::size_t> temp;
  return temp;
}

int main()
{
  Color c = red;
  // ...
  if (c < 14.5) {         // compare Color to double (!)

    auto factors =        // compute prime factors
      primeFactors(c);    // of a color (!)
    // ...
  }
}
