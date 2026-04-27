/*
 * Key idea:
 *
 *   std::forward requires both a function argument (rhs.s) and a template type
 *   argument (std::string).
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <string>

class Widget {
public:
  Widget(Widget&& rhs)                     // unconventional,
  : s(std::forward<std::string>(rhs.s))    // undesirable
  { ++moveCtorCalls; }                     // implementation

private:
  static std::size_t moveCtorCalls;
  std::string s;
};
