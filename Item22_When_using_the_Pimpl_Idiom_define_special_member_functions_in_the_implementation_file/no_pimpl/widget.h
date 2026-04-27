/*
 * Key Idea:
 *
 *   All the headers of the data member types must
 *   be included in order for this code to compile.
 *   If an included header's content changes, clients
 *   of this code must recompile.
 *
 *   中文解释：
 *   如果类直接在头文件中包含所有数据成员类型，就必须包含这些类型的完整头文件。
 *   一旦这些被包含的头文件发生变化，使用 Widget 的客户端代码也会被迫重新编译。
 */

#include <string>
#include <vector>
#include "gadget.h"

class Widget {              // in header widget.h
public:
  Widget();
  // ...

private:
  std::string name;
  std::vector<double> data;
  Gadget g1, g2, g3;        // Gadget is some user-
};                          // defined type
