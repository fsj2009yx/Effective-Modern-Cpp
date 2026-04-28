/*
 * Key idea:
 *
 *   In C++14 we can omit the trailing return type, leaving just the leading
 *   auto.  With that form of declaration, auto does mean that type deduction
 *   will take place.  In particular, it means that compilers will deduce the
 *   function's return type from the function's implementation.
 *
 */

/*
 * 核心思想：
 *
 *   在 C++14 中，可以省略尾置返回类型，只保留前置的 auto。采用这种声明形式时，auto
 *   的确表示会进行类型推导；具体来说，编译器会根据函数实现推导函数返回类型。
 */

template<typename Container, typename Index>  // C++14 only, and
auto authAndAccess(Container& c, Index i)     // not quite
                                              // correct
{
  authenticateUser();
  return c[i];              // return type deduced from c[i]
}
