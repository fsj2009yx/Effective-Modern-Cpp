/*
 * Key Idea:
 *
 *   For scoped enums, no implicit conversion is done. However
 *   type casting is still valid.
 *
 *   中文解释：
 *   作用域枚举不会发生隐式转换，但程序员仍然可以显式 static_cast。
 *   这样既避免了无意转换，也允许在确实需要底层数值时主动转换。
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
