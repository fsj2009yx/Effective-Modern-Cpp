/*
 * Key ideas:
 *
 *   - integral values that are constant and known during compilation can be
 *   used in contexts where C++ requires an integral constant expression.  Such
 *   contexts include specification of array sizes, integral template arguments
 *   (including lengths of std::array objects), enumerator values, alignment
 *   specifiers, and more.  If you want to use a variable for these kind of
 *   things, you certainly want to declare it constexpr, because then compilers
 *   will ensure that it has compile-time value.
 *
 *   - const doesn't offer the same guarantee as constexpr, because const
 *   objects need not be initialized with values known during compilation.
 *
 */

/*
 * 核心思想：
 *
 *   - 在编译期已知的常量整数值，可以用于 C++ 要求整数常量表达式的上下文。这些上下文包括
 *     指定数组大小、整数模板实参（包括 std::array 对象长度）、枚举器值、对齐说明符等。
 *     如果你想把变量用于这些地方，当然应该把它声明为 constexpr，因为这样编译器会确保它
 *     具有编译期值。
 *
 *   - const 不提供与 constexpr 相同的保证，因为 const 对象不一定用编译期已知的值初始化。
 */

#include <array>

int main()
{
  int sz;                             // non constexpr variable

  //constexpr auto arraysize1 = sz;   // error! sz's value not
                                      // known at compilation

  //std::array<int, sz> data1;        // error! same problem

  constexpr auto arraySize2 = 10;     // fine, 10 is a
                                      // compile-time constant

  std::array<int, arraySize2> data2;  // fine, arraySize2
                                      // is constexpr



  const auto arraySize = sz;          // fine, arraySize is
                                      // const copy of sz

  //std::array<int, arraySize> data;  // error! arraySize's value
                                      // not known at compilation
}
