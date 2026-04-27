/*
 * Key idea:
 *
 *   * Empty braces mean no arguments, not an empty std::initializer_list.
 *
 *   * If you want to call a std::initializer_list constructor with an
 *     empty std::initializer_list, you do it by making the empty braces
 *     a constructor argument - by putting the empty braces inside the
 *     parentheses or braces demarcating what you're passing.
 *
 *   * For more discussion, see also blog post [1].
 *
 * References:
 *
 *   [1] http://scottmeyers.blogspot.be/2016/11/help-me-sort-out-meaning-of-as.html
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <iostream>
#include <vector>

class Widget {
public:

  Widget() {  // default ctor
    std::cout << "Widget()" << std::endl;
  };

  Widget(std::initializer_list<int> il) {  // std::init_list ctor
    std::cout << "Widget(std::initializer_list<int>)" << std::endl;
  };

  // ...                                   // no implicit
                                           // conversion funcs
};

int main()
{
  Widget w1;    // calls default ctor

  Widget w2{};  // also calls default ctor

  Widget w3();  // most vexing parse! declares a function!

  Widget w4({});  // calls std::init_list ctor
                  // with empty list

  Widget w5{{}};  // ditto
}
