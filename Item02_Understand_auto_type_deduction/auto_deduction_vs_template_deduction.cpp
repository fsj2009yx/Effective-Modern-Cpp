/*
 * Key idea:
 *
 *   The treatment of braced initializers is the only way in which auto type
 *   deduction and template type deduction differ.
 *
 */

/*
 * 核心思想：
 *
 *   对花括号初始化器的处理，是 auto 类型推导与模板类型推导唯一不同的地方。
 */

#include <initializer_list>

template<typename T>  // template with parameter
void f(T param) {}    // declaration equivalent to
                      // x's declaration

template<typename T>
void f2(std::initializer_list<T> initList) {}

int main()
{
  {
    int x1 = 27;
    int x2(27);
    int x3 = {27};
    int x4{27};
  }

  {
    auto x1 = 27;    // type is int, value is 27
    auto x2(27);     // ditto
    auto x3 = {27};  // type is std::initializer_list<int>,
                     // value is {27}
    auto x4{27};     // ditto

    //auto x5 = {1, 2, 3.0};  // error! can't deduce T for
    //                        // std::initializer_list<T>
  }

  {
    auto x = { 11, 23, 9 };  // x's type is
                             // std::initializer_list<int>

    //f({ 11, 23, 9 });        // error! can't deduce type for T

    f2({ 11, 23, 9 });        // T deduced as int, and initList's
                              // type is std::initializer_list<int>
  }
}
