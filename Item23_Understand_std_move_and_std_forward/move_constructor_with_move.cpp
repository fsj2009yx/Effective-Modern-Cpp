/*
 * Key idea:
 *
 *   - std::move's attractions are convenience, reduced likelihood of error, and
 *     greater clarity.
 *
 *   - std::move requires only a functino argument (rhs.s)
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

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
