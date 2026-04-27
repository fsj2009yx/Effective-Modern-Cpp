/*
 * Key idea:
 *
 *   Suppose it's decided that logging the default construction and destruction
 *   of such objects would be useful, and you add a destructor.  Then declaring
 *   a destructor has a potentially significant side effect: it prevents the
 *   move operations from being generated.  However, creation of the class's
 *   copy operations is unaffected.  This can lead to a significant performance problem!
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

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
