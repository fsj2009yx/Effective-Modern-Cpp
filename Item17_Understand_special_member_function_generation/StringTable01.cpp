/*
 * Key idea:
 *
 *   Assuming that the class declares no copy operations, no move operations,
 *   and no destructor, compilers will automatically generate these functions if
 *   they are used.
 *
 */

/*
 * 核心思想：
 *
 *   假设该类没有声明拷贝操作、移动操作和析构函数，只要这些函数被使用，编译器就会自动
 *   生成它们。
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
