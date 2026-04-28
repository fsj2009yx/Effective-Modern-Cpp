/*
 * Key idea:
 *
 *   It is natural to declare the roots() function const, because it does not
 *   modify the polynomial.
 *
 */

/*
 * 核心思想：
 *
 *   将 roots() 函数声明为 const 是自然的，因为它不会修改多项式。
 */

#include <vector>

class Polynomial {
public:
  using RootsType =        // data structure holding values
    std::vector<double>;   // where polynomial evals to zero
                           // (see Item 9 for info on "using")

  RootsType roots() const;
};
