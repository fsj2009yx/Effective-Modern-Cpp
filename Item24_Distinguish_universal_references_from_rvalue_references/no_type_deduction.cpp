/*
 * Key idea:
 *
 *   If you see "T&&" without type deduction, you're looking at an rvalue
 *   reference.
 *
 */

/*
 * 核心思想：
 *
 *   如果你看到没有类型推导参与的 T&&，看到的就是右值引用。
 */

class Widget {};


void f(Widget&& param);    // no type deduction;
                           // param is an rvalue reference

Widget&& var1 = Widget();  // no type deduction;
                           // var1 is an rvalue reference
