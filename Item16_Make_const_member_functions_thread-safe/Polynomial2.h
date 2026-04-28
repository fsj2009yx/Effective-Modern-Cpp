/*
 * Key idea:
 *
 *   Computing the roots of a polynomial can be expensive, so we don't want to
 *   do it if we don't have to.
 *
 */

/*
 * 核心思想：
 *
 *   计算多项式的根可能很昂贵，因此不必要时不应执行该计算。
 */

#include <vector>

class Polynomial {
public:
  using RootsType = std::vector<double>;

  RootsType roots() const
  {
    if (!rootsAreValid) {        // if cache not valid

      // ...                     // compute roots
                                 // store them in rootVals
      rootsAreValid = true;
    }

    return rootVals;
  }

private:
  mutable bool rootsAreValid{ false };  // see Item 7 for into
  mutable RootsType rootVals{};         // on initializers
};
