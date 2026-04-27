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
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

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
