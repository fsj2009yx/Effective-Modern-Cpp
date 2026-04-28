/*
 * Key Idea:
 *
 *   All the headers of the data member types must
 *   be included in order for this code to compile.
 *   If an included header's content changes, clients
 *   of this code must recompile.
 *
 */

/*
 * 核心思想：
 *
 *   为了让这段代码能够编译，必须包含所有数据成员类型的头文件。如果某个被包含头文件的
 *   内容发生变化，这段代码的客户端也必须重新编译。
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
