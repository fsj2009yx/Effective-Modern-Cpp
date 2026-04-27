/*
 * Key idea:
 *
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <cstddef>
#include <iostream>
#include <vector>

void f(std::size_t val) {
  std::cout << "f(std::size_t val)" << std::endl;
}

template<typename T>
void fwd(T&& param)             // accept any argument
{
  f(std::forward<T>(param));    // forward it to f
}

class Widget {
public:
  static const std::size_t MinVals = 28;   // MinVals' declaration
  // ...
};

const std::size_t Widget::MinVals;   // in Widget's .cpp file

// ...                                     // no defn. for MinVals

int main()
{
  std::vector<int> widgetData;
  widgetData.reserve(Widget::MinVals);       // use of MinVals

  f(Widget::MinVals);     // fine, treated as "f(28)"
  //fwd(Widget::MinVals);   // error! shouldn't link
}
