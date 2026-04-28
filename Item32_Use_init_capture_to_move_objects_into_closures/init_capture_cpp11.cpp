/**
 * Key idea:
 *
 *   Example showing how you can accomplish move capture in a language lacking
 *   support for move capture.
 *
 *   A lambda expression is simply a way to cause a class to be generated and an
 *   object of that type to be created.  There is nothing you can do with a
 *   lambda that you can't do by hand.
 *
 */

/*
 * 核心思想：
 *
 *   该示例展示如何在不支持移动捕获的语言版本中实现移动捕获。
 *
 *   lambda 表达式只是一种让编译器生成一个类并创建该类型对象的方式。lambda 能做的事情，
 *   手写类也都能做到。
 */

#include <memory>

#include "Widget.h"

class IsValAndArch {                         // "is validated
public:                                      // and archived"
  using DataType = std::unique_ptr<Widget>;

  explicit IsValAndArch(DataType&& ptr)      // Item 25 explains
  : pw(std::move(ptr)) {}                    // use of std::move

  bool operator()() const
  { return pw->isValidated() && pw->isArchived(); }

private:
  DataType pw;
};

int main()
{
  // REMARK: due to the use of std::make_unique, this line is C++14 and not
  // C++11!!!
  auto func = IsValAndArch(std::make_unique<Widget>());
}
