/*
 * Key Idea:
 *
 *   std::shared_ptr doesn't require pointed-to types to be
 *   complete, and hence no special member functions need to
 *   be declared here.
 *
 *   中文解释：
 *   shared_ptr 可以在头文件中持有前置声明的 Impl。
 *   因为它不要求在这里看到 Impl 的完整定义，所以也不必在类中额外声明析构、
 *   移动等特殊成员函数。
 */

#include <memory>

class Widget {                  // in "widget.h"
public:
  Widget();
                                // no declarations for dtor
                                // or move operations

private:
  struct Impl;
  std::shared_ptr<Impl> pImpl;  // std::shared_ptr
};                              // instead of std::unique_ptr
