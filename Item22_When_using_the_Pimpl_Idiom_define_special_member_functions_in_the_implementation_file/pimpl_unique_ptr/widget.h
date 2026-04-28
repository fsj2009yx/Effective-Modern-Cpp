/*
 * Key Idea:
 *
 *   The C++11 version of Pimpl Idiom replaces the raw
 *   pointer with a smart pointer.
 *
 *   Note that this compiles, but will fail for clients
 *   because the destructor is not implemented.
 *
 */

/*
 * 核心思想：
 *
 *   C++11 版本的 Pimpl 惯用法用智能指针替换原始指针。
 *
 *   注意，这段代码本身可以编译，但客户端会失败，因为析构函数没有实现。
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
