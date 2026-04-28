/*
 * Key idea:
 *
 *   An effective way to get a compiler to show a type it has deduced is to use
 *   that type in a way that leads to compilation problems.  The error message
 *   reporting the problem is virtually sure to mention the type that's causing
 *   it.
 *
 */

/*
 * 核心思想：
 *
 *   让编译器显示其推导出的类型，一个有效方法是以会导致编译问题的方式使用该类型。报告
 *   该问题的错误消息几乎一定会提到引发问题的类型。
 */

template<typename T>  // declaration only for TD;
class TD;             // TD = "Type Displayer"

const int theAnswer = 42;

auto x = theAnswer;
auto y = &theAnswer;

//TD<decltype(x)> xType;  // elicit errors containing
//TD<decltype(y)> yType;  // x's and y's types
