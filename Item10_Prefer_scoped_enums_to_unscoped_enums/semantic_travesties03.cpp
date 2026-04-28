/*
 * Key Idea:
 *
 *   For scoped enums, no implicit conversion is done. However
 *   type casting is still valid.
 *
 */

/*
 * 核心思想：
 *
 *   对于限域枚举，不会发生隐式转换。不过，显式类型转换仍然有效。
 */

#include <cstddef>
#include <vector>

enum class Color { black, white, red };  // enum is now scoped

std::vector<std::size_t>           // func. returning
primeFactors(std::size_t x) {      // prime factors of x
  std::vector<std::size_t> temp;
  return temp;
}

int main()
{
  Color c = Color::red;   // as before, but
  // ...                  // with scope qualifier
  if (static_cast<double>(c) < 14.5) {         // odd code, but
                                               // it's valid
    auto factors =                                  // suspect, but
      primeFactors(static_cast<std::size_t>(c));    // it compiles
    // ...
  }
}
