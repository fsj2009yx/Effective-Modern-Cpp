/*
 * Key idea:
 *
 * For lvalue expressions more complicated than names, decltype ensures that the
 * type reported is always an lvalue reference.  That is, if an lvalue
 * expression other than a name has type T, decltype reports that type as T&.
 *
 */

/*
 * 核心思想：
 *
 *   对于比名字更复杂的左值表达式，decltype 会保证报告的类型始终是左值引用。也就是说，
 *   如果一个非名字左值表达式的类型是 T，decltype 会将该类型报告为 T&。
 */

int main()
{
  int x = 0;  // decltype(x) is int
              // decltype((x)) is int&
}
