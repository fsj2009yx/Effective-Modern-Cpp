/*
 * Key idea:
 *
 *   Forwarding functions are, by their nature, generic. The fwd template, for
 *   example, accepts any type of argument, and forwards whatever it gets.  A
 *   logical extension of this genericity is for forwarding functions to be not
 *   just templates, but variadic templates, thus accepting any number of
 *   arguments.
 *
 */

/*
 * 核心思想：
 *
 *   转发函数本质上是泛型的。例如，fwd 模板接受任意类型的实参，并转发它得到的任何内容。
 *   对这种泛型性的自然扩展，是让转发函数不仅是模板，而且是可变参数模板，从而接受任意数量
 *   的实参。
 */

#include <utility>

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
