/*
 * Key idea:
 *
 *   Assuming that the class declares no copy operations, no move operations,
 *   and no destructor, compilers will automatically generate these functions if
 *   they are used.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <map>
#include <string>

class StringTable {
public:
  StringTable() {}
  // ...                 // functions for insertion, erasure, lookup,
                         // etc., but no copy/move/dtor functionality

private:
  std::map<int, std::string> values;
};
