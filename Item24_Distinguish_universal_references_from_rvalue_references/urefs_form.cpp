/*
 * Key idea:
 *
 *   For a reference to be universal, type deduction is necessary, but it's not
 *   sufficient.  The form of the reference declaration must also be correct,
 *   and that form is quite constrained.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <utility>
#include <vector>

class Widget {};


template<typename T>
void f(std::vector<T>&& param);  // param is an rvalue reference

template<typename T>
void f(const T&& param);         // param is an rvalue reference

template<typename MyTemplateType>       // param is a
void someFunc(MyTemplateType&& param);  // universal reference

int main()
{
    std::vector<int> v;
//    f(v);                        // error! can't bind lvalue to
                                 // rvalue reference
}
