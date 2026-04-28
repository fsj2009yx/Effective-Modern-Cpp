/*
 * Key Idea:
 *
 *   Unscoped enums implicitly convert to integral types,
 *   allowing the below to run. Scoped enums are strongly
 *   typed.
 *
 */

/*
 * 核心思想：
 *
 *   非限域枚举会隐式转换为整数类型，因此下面的代码可以运行。限域枚举是强类型的。
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
