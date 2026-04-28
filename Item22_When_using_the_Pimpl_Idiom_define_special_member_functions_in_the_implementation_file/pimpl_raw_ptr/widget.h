/*
 * Key Idea:
 *
 *   Applying the Pimpl Idiom in C++98 - replace
 *   all data members with a raw pointer to a struct.
 *   Clients of this code no longer need to recompile if
 *   the headers involved with the incomplete types change.
 *
 */

/*
 * 核心思想：
 *
 *   在 C++98 中应用 Pimpl 惯用法：用指向结构体的原始指针替换所有数据成员。如果与不完整
 *   类型相关的头文件发生变化，这段代码的客户端不再需要重新编译。
 */

class Widget {        // still in header "widget.h"
public:
  Widget();
  ~Widget();          // dtor is needed - see below

private:
  struct Impl;        // declare implementation struct
  Impl *pImpl;        // and pointer to it
};
