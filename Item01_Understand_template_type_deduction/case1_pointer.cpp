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
 *   * If expr's type is a reference, ignore the reference part.
 *   * Pattern-match expr's type against ParamType to determine T.
 *
 *   If param were a pointer (or a pointer to const) instead of a reference,
 *   things would work essentially the same way:
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
 *   * 如果 expr 的类型是引用，忽略引用部分。
 *   * 将 expr 的类型与 ParamType 做模式匹配，以确定 T。
 *
 *   如果 param 不是引用而是指针（或指向 const 的指针），基本机制也是一样的。
 */

template<typename T>
void f(T* param) {}      // param is now a pointer

int main()
{
  int x = 27;            // as before
  const int *px = &x;    // px is a ptr to x as a const int

  f(&x);                 // T is int, param's type is int*

  f(px);                 // T is const int,
                         // param's type is const int*
}
