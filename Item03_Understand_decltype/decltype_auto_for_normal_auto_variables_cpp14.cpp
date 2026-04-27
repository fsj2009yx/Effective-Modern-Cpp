/*
 * Key idea:
 *
 *   The use of decltype(auto) is not limited to function return types.  It can
 *   also be convenient for declaring variables when you want to apply the
 *   decltype type deduction rules to the initializing expression.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

class Widget {};

Widget w;

const Widget& cw = w;

auto myWidget1 = cw;            // auto type deduction:
                                // myWidget1's type is Widget

decltype(auto) myWidget2 = cw;  // decltype type deduction:
                                // myWidget2's type is
                                //   const Widget&
