/*
 * Key Idea:
 *
 *   std::shared_ptr doesn't require pointed-to types to be
 *   complete, and hence no special member functions need to
 *   be defined here.
 *
 *   中文解释：
 *   shared_ptr 对不完整类型的要求比 unique_ptr 宽松。
 *   因此使用 shared_ptr 保存 Impl 时，通常不需要像 unique_ptr 那样
 *   专门在 .cpp 中定义析构函数等特殊成员函数。
 */

#include <memory>
#include <string>                  // in "widget.cpp"
#include <vector>
#include "gadget.h"
#include "widget.h"

struct Widget::Impl {              // as before
  std::string name;
  std::vector<double> data;
  Gadget g1, g2, g3;
};

Widget::Widget()                   // per Item 22 create
: pImpl(std::make_shared<Impl>())  // std::unique_ptr
{}                                 // via std::make_unique
