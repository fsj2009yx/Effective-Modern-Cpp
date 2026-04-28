/*
 * Key Idea:
 *
 *   The Pimpl Idiom implemented C++98-style:
 *   all the data members are replaced with a pointer
 *   to struct defined here in the implementation file.
 *
 */

/*
 * 核心思想：
 *
 *   以 C++98 风格实现的 Pimpl 惯用法：所有数据成员都被替换为指向一个结构体的指针，而该
 *   结构体定义在这个实现文件中。
 */

#include "widget.h"           // in impl. file "widget.cpp"
#include "gadget.h"
#include <string>
#include <vector>

struct Widget::Impl {         // definition of Widget::Impl
  std::string name;           // with data members formerly
  std::vector<double> data;   // in Widget
  Gadget g1, g2, g3;
};

Widget::Widget()              // allocate data members for
: pImpl(new Impl)             // this Widget object
{}

Widget::~Widget()             // destroy data members for
{ delete pImpl; }             // this object
