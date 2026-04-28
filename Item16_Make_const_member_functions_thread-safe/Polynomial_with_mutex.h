/*
 * Key idea:
 *
 *   The easiest way to address the issue of lack of thread safety is the usual
 *   one: employ a mutex.
 *
 */

/*
 * 核心思想：
 *
 *   解决线程安全缺失问题最简单的方法，就是常规做法：使用互斥量。
 */

#include <mutex>
#include <vector>

class Polynomial {
public:
  using RootsType = std::vector<double>;

  RootsType roots() const
  {
    std::lock_guard<std::mutex> g(m);  // lock mutex

    if (!rootsAreValid) {              // if cache not valid

      // ...                           // compute roots here

      rootsAreValid = true;
    }                                  // release mutex

    return rootVals;
  }

private:
  mutable std::mutex m;
  mutable bool rootsAreValid { false };
  mutable RootsType rootVals {};
};
