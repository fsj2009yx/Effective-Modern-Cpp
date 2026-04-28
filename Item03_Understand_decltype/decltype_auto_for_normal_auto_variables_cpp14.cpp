/*
 * Key idea:
 *
 *   The use of decltype(auto) is not limited to function return types.  It can
 *   also be convenient for declaring variables when you want to apply the
 *   decltype type deduction rules to the initializing expression.
 *
 */

/*
 * 核心思想：
 *
 *   decltype(auto) 并不限于函数返回类型。当你希望对初始化表达式应用 decltype 的类型
 *   推导规则时，它也可以方便地用于变量声明。
 */

class Widget {};

Widget w;

const Widget& cw = w;

auto myWidget1 = cw;            // auto type deduction:
                                // myWidget1's type is Widget

decltype(auto) myWidget2 = cw;  // decltype type deduction:
                                // myWidget2's type is
                                //   const Widget&
