/*
 * Key Idea:
 *
 *   Applying the Pimpl Idiom in C++98 - replace
 *   all data members with a raw pointer to a struct.
 *   Clients of this code no longer need to recompile if
 *   the headers involved with the incomplete types change.
 *
 *   中文解释：
 *   C++98 中实现 Pimpl 时，头文件只声明 Impl 并保存 Impl*。
 *   客户端不需要知道 Impl 的完整定义，因此实现细节或相关头文件变化时，
 *   通常不必重新编译客户端。
 */

class Widget {        // still in header "widget.h"
public:
  Widget();
  ~Widget();          // dtor is needed - see below

private:
  struct Impl;        // declare implementation struct
  Impl *pImpl;        // and pointer to it
};
