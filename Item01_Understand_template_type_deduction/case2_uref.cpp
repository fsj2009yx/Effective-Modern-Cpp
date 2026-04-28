/*
 * Key idea:
 *
 *   Considering the general form for templates and calls to it:
 *
 *     template <typename T>
 *     void f(ParamType param);
 *
 *     f(expr);                // deduce T and ParamType from expr
 *
 *   then, in the case when ParamType is a universal reference
 *   type, type deduction works like this:
 *
 *   * If expr is an lvalue, both T and ParamType are deduced to be lvalue
 *     references
 *   * If expr is an rvalue, the usual type deduction rules apply.
 *
 */

/*
 * 核心思想：
 *
 *   考虑模板和调用的一般形式：
 *
 *     template <typename T>
 *     void f(ParamType param);
 *
 *     f(expr);                // 从 expr 推导 T 和 ParamType
 *
 *   当 ParamType 是万能引用类型时，类型推导按如下方式工作：
 *
 *   * 如果 expr 是左值，T 和 ParamType 都会被推导为左值引用。
 *   * 如果 expr 是右值，则应用通常的类型推导规则。
 */

template<typename T>
void f(T&& param) {}      // param is now a universal reference

int main()
{
  int x = 27;             // as before
  const int cx = x;       // as before
  const int& rx = x;      // as before

  f(x);                   // x is lvalue, so T is int&,
                          // param's type is also int&

  f(cx);                  // cx is lvalue, so T is const int&,
                          // param's type is also const int&

  f(rx);                  // rx is lvalue, so T is const int&,
                          // param's type is also const int&

  f(27);                  // 27 is rvalue, so T is int,
                          // param's type is therefore int&&
}
