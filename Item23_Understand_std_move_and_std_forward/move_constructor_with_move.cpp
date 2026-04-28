/*
 * Key idea:
 *
 *   - std::move's attractions are convenience, reduced likelihood of error, and
 *     greater clarity.
 *
 *   - std::move requires only a functino argument (rhs.s)
 *
 */

/*
 * 核心思想：
 *
 *   - std::move 的吸引力在于方便、降低出错可能性，并且语义更清晰。
 *
 *   - std::move 只需要一个函数实参（rhs.s）。
 */

#include <string>

class Widget {
public:
  Widget(Widget&& rhs)
  : s(std::move(rhs.s))
  { ++moveCtorCalls; }

private:
  static std::size_t moveCtorCalls;
  std::string s;
};
