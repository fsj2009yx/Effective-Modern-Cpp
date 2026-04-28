/*
 * Key idea:
 *
 *   As of C++11, the special member functions club has two more inductees: the
 *   move constructor and the move assignment operator.  Their signatures are
 *   given here.
 *
 */

/*
 * 核心思想：
 *
 *   从 C++11 开始，特殊成员函数俱乐部又新增了两个成员：移动构造函数和移动赋值运算符。
 *   它们的签名如下。
 */

class Widget {
public:
  // ...
  Widget(Widget&& rhs);             // move constructor
  
  Widget& operator=(Widget&& rhs);  // move assignment operator
  // ...
};
