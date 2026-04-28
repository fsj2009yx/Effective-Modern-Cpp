/*
 * Key idea:
 *
 *   In C++14, a seemingly trivial change in the way you write a return
 *   statement can affect the deduced type for a function.
 *
 */

/*
 * 核心思想：
 *
 *   在 C++14 中，return 语句写法上看似微小的变化，也可能影响函数的推导返回类型。
 */

decltype(auto) f1()
{
  int x = 0;
  // ...
  return x;  // decltype(x) is int, so f1 returns int
}

decltype(auto) f2()
{
  int x = 0;
  // ...
  return (x);  // decltype((x)) is int&, so f2 returns int&
}
