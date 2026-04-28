/*
 * Key idea:
 *
 *   * If you're a template author, the tension between parentheses and braces
 *     for object creation can be especially frustrating, because, in general,
 *     it's not possible to know which should be used.
 *
 */

/*
 * 核心思想：
 *
 *   * 如果你是模板作者，对象创建中圆括号与花括号之间的张力会尤其令人沮丧，因为通常无法
 *     预先知道应该使用哪一种。
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
