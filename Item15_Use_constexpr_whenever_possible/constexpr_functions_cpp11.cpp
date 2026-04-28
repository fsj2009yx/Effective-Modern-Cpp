/*
 * Key ideas:
 *
 *   - The constexpr in front of pow doesn't say that pow returns a const value,
 *   it says that if base and exp are compile-time constants, pow's result may
 *   be used as a compile-time constant.  If base and/or exp are not
 *   compile-time constants, pow's result will be computed at runtime.
 *
 *   - In C++11, constexpr functions may contain no more than a single
 *   executable statement: a return.
 *
 */

/*
 * 核心思想：
 *
 *   - pow 前面的 constexpr 并不是说 pow 返回 const 值，而是说如果 base 和 exp 是编译期
 *     常量，pow 的结果可以用作编译期常量。如果 base 或 exp 不是编译期常量，pow 的结果
 *     会在运行期计算。
 *
 *   - 在 C++11 中，constexpr 函数最多只能包含一条可执行语句：return。
 */

#include <array>

int readFromDB(const char* s)
{
  return 1;
}

constexpr                                     // pow's a constexpr func
int pow(int base, int exp) noexcept           // that never throws
{
  return (exp == 0 ? 1 : base * pow(base, exp - 1));
}

int main()
{
  // compile-time-compute the size of a std::array:
  constexpr auto numConds = 5;                // # of conditions
  std::array<int, pow(3, numConds)> results;  // results has
                                              // 3^{numConds}
                                              // elements

  // runtime context:
  auto base = readFromDB("base");             // get these values
  auto exp = readFromDB("exponent");          // at runtime

  auto baseToExp = pow(base, exp);            // call pow function
                                              // at runtime
}
