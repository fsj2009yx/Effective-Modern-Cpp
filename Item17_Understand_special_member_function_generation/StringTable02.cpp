/*
 * Key idea:
 *
 *   Suppose it's decided that logging the default construction and destruction
 *   of such objects would be useful, and you add a destructor.  Then declaring
 *   a destructor has a potentially significant side effect: it prevents the
 *   move operations from being generated.  However, creation of the class's
 *   copy operations is unaffected.  This can lead to a significant performance problem!
 *
 */

/*
 * 核心思想：
 *
 *   假设你认为记录这类对象的默认构造和析构是有用的，于是添加了析构函数。此时声明析构
 *   函数会带来一个潜在的重要副作用：它会阻止移动操作生成。不过，类的拷贝操作生成不受
 *   影响。这可能导致显著的性能问题。
 */

#include <map>
#include <string>

void makeLogEntry(std::string s) {}

class StringTable {
public:
  StringTable()
  { makeLogEntry("Creating StringTable object"); }    // added

  ~StringTable()                                      // also
  { makeLogEntry("Destroying StringTable object"); }  // added

  // ...                                // other funcs as before

private:
  std::map<int, std::string> values;  // as before
};
