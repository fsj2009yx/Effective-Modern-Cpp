/*
 * Key idea:
 *
 *   As of C++11, the special member functions club has two more inductees: the
 *   move constructor and the move assignment operator.  Their signatures are
 *   given here.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

class Widget {
public:
  // ...
  Widget(Widget&& rhs);             // move constructor
  
  Widget& operator=(Widget&& rhs);  // move assignment operator
  // ...
};
