/*
 * Key idea:
 *
 *   * Compiler's determiniation to match braced initializers with constructors
 *     taking std::initializer_lists is so strong, it prevails even if the
 *     best-match std::initializer_list constructor can't be called.
 *
 */

/*
 * 核心思想：
 *
 *   * 编译器将花括号初始化器匹配到接受 std::initializer_list 的构造函数的决心非常强，
 *     即使最佳匹配的 std::initializer_list 构造函数无法被调用，这种偏好仍会占上风。
 */

#include <iostream>

class Widget {
public:

  Widget(int i, bool b) {  // as before
    std::cout << "Widget(int, bool)" << std::endl;
  };

  Widget(int i, double d) {  // as before
    std::cout << "Widget(int double)" << std::endl;
  };

  Widget(std::initializer_list<bool> il) {  // element type is
                                            // now bool
    std::cout << "Widget(std::initializer_list<bool>)" << std::endl;
  };

  // ...                    // no implicit
                            // conversion funcs

};

int main()
{
  //Widget w{10, 5.0};   // error! requires narrowing conversions
}
