/*
 * Key idea:
 *
 *   In C++11, const_iterators are both easy to get and easy to use.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

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
