/*
 * Key idea:
 *
 *   There's nothing in the rules about the existence of a member function
 *   template preventing compilers from generating the special member functions.
 *
 *   In the below case, compilers will still generate copy and move operations
 *   for Widget (assuming the usual conditions governing their generation are
 *   fulfilled), even though these templates could be instantiated to produce
 *   the signatures for the copy constructor and copy assignment operator. (That
 *   would be the case when T is Widget.)
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

class Widget {
public:
  // ...
  template<typename T>              // construct Widget
  Widget(const T& rhs);             // from anything

  template<typename T>              // assign Widget
  Widget& operator=(const T& rhs);  // from anything
  // ...
};
