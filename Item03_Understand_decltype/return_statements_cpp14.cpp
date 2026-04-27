/*
 * Key idea:
 *
 *   In C++14, a seemingly trivial change in the way you write a return
 *   statement can affect the deduced type for a function.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

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
