/*
 * Key idea:
 *
 *   Universal references arise in two contexts.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

class Widget {};

Widget&& var1 = Widget();                    // rvalue reference


// Context 1: function template parameters.
template<typename T>
void f(T&& param);                           // param is a universal reference

// Context 2: auto declarations.
auto&& var2 = var1;                          // var2 is a universal reference
