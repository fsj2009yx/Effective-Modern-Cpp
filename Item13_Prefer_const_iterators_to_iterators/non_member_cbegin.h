/*
 * Key idea:
 *
 *   If you're using C++11, you want to write maximally generic code, and none
 *   of the libraries you're using provides the missing templates for non-member
 *   cbegin and friends, you can throw your own implementations together with
 *   ease.
 *
 */

/*
 * 核心思想：
 *
 *   如果你使用 C++11，想编写最大程度泛化的代码，并且所用库都没有提供缺失的非成员 cbegin
 *   及其相关模板，那么可以很容易地自己实现它们。
 */

template <class C>
auto cbegin(const C& container)->decltype(std::begin(container))
{
  return begin(container);    // see explanation below
}
