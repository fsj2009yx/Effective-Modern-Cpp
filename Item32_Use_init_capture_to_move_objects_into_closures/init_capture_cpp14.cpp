/**
 * Key idea:
 *
 *   C++14 example showing how one can use init capture to move a
 *   std::unique_ptr into a closure.
 *
 */

/*
 * 核心思想：
 *
 *   C++14 示例，展示如何使用初始化捕获把 std::unique_ptr 移动到闭包中。
 */

#include <memory>
#include <utility>

#include "Widget.h"

int main()
{
  auto pw = std::make_unique<Widget>();  // create Widget; see
                                         // Item 21 for info on
                                         // std::make_unique

                                         // configure *pw

  {
    auto func = [pw = std::move(pw)]              // init data mbr
                { return pw->isValidated()        // in closure w/
                         && pw->isArchived(); };  // std::move(pw)
  }

  {
    auto func = [pw = std::make_unique<Widget>()]  // init data mem
                { return pw->isValidated()         // in closure w/
                         && pw->isArchived(); };   // result of call
                                                   // to make_unique
  }
}
