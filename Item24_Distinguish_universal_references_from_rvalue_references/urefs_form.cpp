/*
 * Key idea:
 *
 *   For a reference to be universal, type deduction is necessary, but it's not
 *   sufficient.  The form of the reference declaration must also be correct,
 *   and that form is quite constrained.
 *
 */

/*
 * 核心思想：
 *
 *   要成为万能引用，类型推导是必要条件，但还不充分。引用声明的形式也必须正确，而这种
 *   形式受到严格限制。
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
