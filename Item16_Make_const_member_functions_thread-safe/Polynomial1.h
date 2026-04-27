/*
 * Key idea:
 *
 *   It is natural to declare the roots() function const, because it does not
 *   modify the polynomial.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <vector>

class Polynomial {
public:
  using RootsType =        // data structure holding values
    std::vector<double>;   // where polynomial evals to zero
                           // (see Item 9 for info on "using")

  RootsType roots() const;
};
