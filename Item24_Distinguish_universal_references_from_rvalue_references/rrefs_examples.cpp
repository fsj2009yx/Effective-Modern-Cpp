/*
 * Key idea:
 *
 *   It seems reasonable to assume that if you see "T&&" in source code, you're
 *   looking at an rvalue reference.  However, it's not quite that simple.
 *
 */

/*
 * 核心思想：
 *
 *   如果在源码中看到 T&&，很容易合理地假定它是右值引用。然而，事情并没有那么简单。
 */

#include <vector>

class Widget {};


void f(Widget&& param);          // rvalue reference

Widget&& var1 = Widget();        // rvalue reference

auto&& var2 = var1;              // not rvalue reference

template<typename T>
void f(std::vector<T>&& param);  // rvalue reference

template<typename T>
void f(T&& param);               // not rvalue reference
