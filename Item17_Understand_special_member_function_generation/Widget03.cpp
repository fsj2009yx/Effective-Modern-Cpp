/*
 * Key idea:
 *
 *   There's nothing in the rules about the existence of a member function
 *   template preventing compilers from generating the special member functions.
 *
 *   In the below case, compilers will still generate copy and move operations
 *   for Widget (assuming the usual conditions governing their generation are
 *   fulfilled), even though these templates could be instantiated to produce
 *   the signatures for the copy constructor and copy assignment operator. (That
 *   would be the case when T is Widget.)
 *
 */

/*
 * 核心思想：
 *
 *   规则中没有任何内容说明成员函数模板的存在会阻止编译器生成特殊成员函数。
 *
 *   在下面的情形中，编译器仍会为 Widget 生成拷贝和移动操作（假设满足通常的生成条件），
 *   即使这些模板可能被实例化出拷贝构造函数和拷贝赋值运算符的签名。（当 T 是 Widget 时
 *   就会这样。）
 */

class Widget {
public:
  // ...
  template<typename T>              // construct Widget
  Widget(const T& rhs);             // from anything

  template<typename T>              // assign Widget
  Widget& operator=(const T& rhs);  // from anything
  // ...
};
