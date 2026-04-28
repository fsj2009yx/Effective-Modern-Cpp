/*
 * Key idea:
 *
 *   About the only situation in which C++11's support for const_iterators comes
 *   up a bit short is when you want to write maximally generic library code.
 *
 *   This works fine in C++14, but, sadly, not in C++11.
 *
 */

/*
 * 核心思想：
 *
 *   C++11 对 const_iterator 的支持唯一稍显不足的情况，大概是在你想编写最大程度泛化的
 *   库代码时。
 *
 *   这在 C++14 中可以正常工作，但遗憾的是，在 C++11 中不行。
 */

#include <algorithm>
#include <iterator>
#include <vector>

template<typename C, typename V>
void findAndInsert(C& container,         // in container, find
                   const V& targetVal,   // first occurrence
                   const V& insertVal)   // of targetVal, then
{                                        // insert insertVal
  using std::cbegin;                     // there
  using std::cend;

  auto it = std::find(cbegin(container),  // non-member cbegin
                      cend(container),    // non-member cend
                      targetVal);

  container.insert(it, insertVal);
}

int main()
{

  std::vector<int> values;                            // as before

  findAndInsert(values, 1983, 1998);
}
