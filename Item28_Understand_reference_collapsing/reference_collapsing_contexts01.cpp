/*
 * Key ideas:
 *
 *   - When an lvalue is passed as an argument to func, T is deduced to be an
 *     lvalue reference.  When an rvalue is passed, T is deduced to be a
 *     non-reference.
 *
 *   - Reference collapsing occurs in four contexts.  The first and most common
 *     is template instantiation.  The second is type generation for auto
 *     variables.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include "reference_collapsing_contexts01.h"

int main()
{
    Widget w;                // a variable (an lvalue)

    func(w);                 // call func with lvalue; T deduced
                             // to be Widget&

    func(widgetFactory());   // call func with rvalue; T deduced
                             // to be Widget

    auto&& w1 = w;

    auto&& w2 = widgetFactory();
}
