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
 *
 */

/*
 * 核心思想：
 *
 *   - 当左值作为实参传给 func 时，T 会被推导为左值引用；当右值被传入时，T 会被推导为
 *     非引用类型。
 *
 *   - 引用折叠发生在四种上下文中。第一种也是最常见的一种，是模板实例化。第二种是为 auto
 *     变量生成类型。
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
