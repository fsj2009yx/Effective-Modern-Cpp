/*
 * Key idea:
 *
 *   An effective way to get a compiler to show a type it has deduced is to use
 *   that type in a way that leads to compilation problems.  The error message
 *   reporting the problem is virtually sure to mention the type that's causing
 *   it.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

template<typename T>  // declaration only for TD;
class TD;             // TD = "Type Displayer"

const int theAnswer = 42;

auto x = theAnswer;
auto y = &theAnswer;

//TD<decltype(x)> xType;  // elicit errors containing
//TD<decltype(y)> yType;  // x's and y's types
