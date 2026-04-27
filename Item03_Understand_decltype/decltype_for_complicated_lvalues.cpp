/*
 * Key idea:
 *
 * For lvalue expressions more complicated than names, decltype ensures that the
 * type reported is always an lvalue reference.  That is, if an lvalue
 * expression other than a name has type T, decltype reports that type as T&.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

int main()
{
  int x = 0;  // decltype(x) is int
              // decltype((x)) is int&
}
