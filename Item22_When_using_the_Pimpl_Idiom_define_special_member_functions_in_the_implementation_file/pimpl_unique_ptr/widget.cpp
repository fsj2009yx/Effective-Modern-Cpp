/*
 * Key Idea:
 *
 *   Implementation of the Pimpl Idiom in C++11 -
 *   replaces the raw pointer with a smart pointer.
 *
 *   Note that this compiles, but will fail for clients
 *   because the destructor is not implemented.
 *
 *   中文解释：
 *   C++11 的 Pimpl 可以用 unique_ptr 替代裸指针来管理 Impl 生命周期。
 *   但 unique_ptr 删除对象时需要知道 Impl 的完整类型；
 *   如果析构函数没有在 .cpp 中定义，客户端编译时可能因为 Impl 不完整而失败。
 */

#include "widget.h"                // in "widget.cpp"
#include "gadget.h"
#include <memory>
#include <string>
#include <vector>

struct Widget::Impl {              // as before, definition of
  std::string name;                // Widget::Impl
  std::vector<double> data;
  Gadget g1, g2, g3;
};

Widget::Widget()                   // per Item 22 create
: pImpl(std::make_unique<Impl>())  // std::unique_ptr
{}                                 // via std::make_unique

//Widget::~Widget()                // ~Widget definition
//{}

Widget::~Widget() = default;        // same effect as above 

Widget::Widget(Widget&& rhs) = default;             // defini-
Widget& Widget::operator=(Widget&& rhs) = default;  // tions

Widget::Widget(const Widget& rhs)                   // copy ctor
: pImpl(std::make_unique<Impl>(*rhs.pImpl))
{}

Widget& Widget::operator=(const Widget& rhs)        // copy operator=
{
  *pImpl = *rhs.pImpl;
  return *this;
}
