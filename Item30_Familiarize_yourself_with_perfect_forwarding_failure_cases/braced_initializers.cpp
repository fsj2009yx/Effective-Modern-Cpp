/*
 * Key idea:
 *
 *   The use of a braced initializer is a perfect forwarding failure case.
 *   However, there is a workaround by declaring a local variable using auto,
 *   and then passing the local variable to the forwarding function.
 *
 */

/*
 * 核心思想：
 *
 *   使用花括号初始化器是完美转发的失败场景。不过有一个变通方法：使用 auto 声明一个局部
 *   变量，然后把该局部变量传给转发函数。
 */

#include <iostream>
#include <utility>
#include <vector>

void f(const std::vector<int>& v) {
  std::cout << "f(const std::vector<int>&)" << std::endl;
}

template<typename T>
void fwd(T&& param)             // accept any argument
{
  f(std::forward<T>(param));    // forward it to f
}

template<typename... Ts>
void fwd(Ts&&... param)             // accept any arguments
{
  f(std::forward<Ts>(param)...);    // forward them to f
}

int main()
{
  f({1, 2, 3});  // fine, "{1, 2, 3}" implicitly
                 // converted to std::vector<int>

  //fwd({1, 2, 3});  // error! doesn't compile

  auto il = {1, 2, 3};  // il's type deduced to be
                        // std::initializer_list<int>

  fwd(il);              // fine, perfect-forwards il to f
}
