/*
 * Key Idea:
 *
 *   The C++11 version of Pimpl Idiom replaces the raw
 *   pointer with a smart pointer.
 *
 *   Note that this compiles, but will fail for clients
 *   because the destructor is not implemented.
 *
 *   中文解释：
 *   这个版本用 unique_ptr<Impl> 替代裸指针来实现 Pimpl。
 *   头文件可以只前置声明 Impl，但 unique_ptr 的析构需要完整类型，
 *   所以相关特殊成员函数应在 .cpp 中定义，否则客户端使用时可能编译失败。
 */

#include <memory>

class Widget {                  // in "widget.h"
public:
  Widget();
  ~Widget();                    // declaration only

  //Widget(Widget&& rhs) = default;             // right idea
  //Widget& operator=(Widget&& rhs) = default;  // wrong code!

  Widget(Widget&& rhs);                         // declarations
  Widget& operator=(Widget&& rhs);              // only

  Widget(const Widget& rhs);                    // declarations
  Widget& operator=(const Widget& rhs);         // only

private:
  struct Impl;
  std::unique_ptr<Impl> pImpl;  // use smart pointer
};                              // instead of raw pointer
