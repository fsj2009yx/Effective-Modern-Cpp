/*
 * Key idea:
 *
 *   * If you're a template author, the tension between parentheses and braces
 *     for object creation can be especially frustrating, because, in general,
 *     it's not possible to know which should be used.
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <vector>

template<typename T,      // type of object to create
         typename... Ts>  // types of arguments to use
void doSomeWork(Ts&&... params)
{
  // create local T object from params...

  // Method 1
  T localObject(std::forward<Ts>(params)...);    // using parens

  // Method 2
  //T localObject{std::forward<Ts>(params)...};  // using braces
}

int main()
{
  std::vector<int> v;

  doSomeWork<std::vector<int>>(10, 20);
}
