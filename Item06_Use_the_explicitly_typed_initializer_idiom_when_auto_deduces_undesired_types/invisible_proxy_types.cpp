/*
 * Key idea:
 *
 *   "Invisible" proxy types can cause auto to deduce the "wrong" type for an
 *   initializing expression.
 *
 */

/*
 * 核心思想：
 *
 *   “不可见”的代理类型会导致 auto 为初始化表达式推导出“错误”的类型。
 */

#include <iostream>
#include <vector>

class Widget {};

void processWidget(Widget& w, bool p)
{
  std::cout << "processWidget(Widget&, bool)" << std::endl;
}

std::vector<bool> features(const Widget& w)
{
  std::cout << "features(const Widget&)" << std::endl;
}

int main()
{
  Widget w;
  
  {
    bool highPriority = features(w)[5];  // is w high priority?
    
    processWidget(w, highPriority);      // process w in accord
                                         // with its priority
  }
  
  {
    auto highPriority = features(w)[5];  // is w high priority?
  
    processWidget(w, highPriority);      // undefined behavior!
                                         // highPriority contains
                                         // dangling pointer!
  }

  { // explicitly typed initializer idiom

    auto highPriority = static_cast<bool>(features(w)[5]);

    processWidget(w, highPriority);

  }
}
