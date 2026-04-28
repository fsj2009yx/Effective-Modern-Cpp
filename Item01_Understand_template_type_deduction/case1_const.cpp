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
 *   then, in the simplest case when ParamType is a pointer type or a reference
 *   type, but not a universal reference, type deduction works like this:
 *
 *   1. If expr's type is a reference, ignore the reference part.
 *   2. Then pattern-match expr's type against ParamType to determine T.
 *
 *   If the type of f's parameter is changed from T& to const T&, the constness
 *   of cx and rx continues to be respected, but because we're now assuming that
 *   param is a reference-to-const, there's no longer a need for const to be
 *   deduced as part of T.
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
 *   在最简单的情形下，如果 ParamType 是指针类型或引用类型，但不是万能引用，类型推导按
 *   如下方式工作：
 *
 *   1. 如果 expr 的类型是引用，忽略引用部分。
 *   2. 然后将 expr 的类型与 ParamType 做模式匹配，以确定 T。
 *
 *   如果 f 的形参类型从 T& 改为 const T&，cx 和 rx 的 const 性仍然会被保留；但因为
 *   现在假定 param 是 const 引用，const 不再需要作为 T 的一部分被推导出来。
 */

template<typename T>
void f(const T& param) {}  // param is now a ref-to-const

int main()
{
  int x = 27;              // as before
  const int cx = x;        // as before
  const int& rx = x;       // as before

  f(x);                    // T is int, param's type is const int&

  f(cx);                   // T is int, param's type is const int&

  f(rx);                   // T is int, param's type is const int&
}
