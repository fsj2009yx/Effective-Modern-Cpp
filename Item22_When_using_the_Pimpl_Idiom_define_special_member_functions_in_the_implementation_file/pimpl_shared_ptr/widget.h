/*
 * Key Idea:
 *
 *   std::shared_ptr doesn't require pointed-to types to be
 *   complete, and hence no special member functions need to
 *   be declared here.
 *
 */

/*
 * 核心思想：
 *
 *   std::shared_ptr 不要求其指向的类型是完整类型，因此这里不需要声明特殊成员函数。
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
