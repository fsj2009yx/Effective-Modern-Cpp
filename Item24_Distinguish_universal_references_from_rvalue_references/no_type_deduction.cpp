/*
 * Key idea:
 *
 *   If you see "T&&" without type deduction, you're looking at an rvalue
 *   reference.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

class Widget {};


void f(Widget&& param);    // no type deduction;
                           // param is an rvalue reference

Widget&& var1 = Widget();  // no type deduction;
                           // var1 is an rvalue reference
