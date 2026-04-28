/*
 * Key idea:
 *
 *   In C++11, const_iterators are both easy to get and easy to use.
 *
 */

/*
 * 核心思想：
 *
 *   在 C++11 中，const_iterator 既容易获取，也容易使用。
 */

#include <algorithm>
#include <vector>

int main()
{

  std::vector<int> values;                            // as before

  auto it =                                           // use cbegin
    std::find(values.cbegin(), values.cend(), 1983);  // and cend
  values.insert(it, 1998);

}
