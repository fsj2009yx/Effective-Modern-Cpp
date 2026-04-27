/*
 * Key idea:
 *
 *   - In C++14, the restrictions on constexpr functions are substantially
 *   looser.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <array>

int readFromDB(const char* s)
{
  return 1;
}

constexpr int pow(int base, int exp)          // C++14
{
  auto result = 1;
  for (int i = 0; i < exp; ++i) result *= base;

  return result;
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
