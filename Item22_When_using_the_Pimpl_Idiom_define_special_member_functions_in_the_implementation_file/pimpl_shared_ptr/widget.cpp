/*
 * Key Idea:
 *
 *   std::shared_ptr doesn't require pointed-to types to be
 *   complete, and hence no special member functions need to
 *   be defined here.
 *
 */

/*
 * 核心思想：
 *
 *   std::shared_ptr 不要求其指向的类型是完整类型，因此这里不需要定义特殊成员函数。
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
