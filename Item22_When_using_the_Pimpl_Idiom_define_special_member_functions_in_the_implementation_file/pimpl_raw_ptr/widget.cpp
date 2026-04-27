/*
 * Key Idea:
 *
 *   The Pimpl Idiom implemented C++98-style:
 *   all the data members are replaced with a pointer
 *   to struct defined here in the implementation file.
 *
 *   中文解释：
 *   这是 C++98 风格的 Pimpl：头文件只保存一个指向实现结构体的裸指针，
 *   真正的数据成员放到 .cpp 文件里的 Impl 定义中，从而隐藏实现细节。
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
