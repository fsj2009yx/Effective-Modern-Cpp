/*
 * Key idea:
 *
 *   If you're using C++11, you want to write maximally generic code, and none
 *   of the libraries you're using provides the missing templates for non-member
 *   cbegin and friends, you can throw your own implementations together with
 *   ease.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

template <class C>
auto cbegin(const C& container)->decltype(std::begin(container))
{
  return begin(container);    // see explanation below
}
