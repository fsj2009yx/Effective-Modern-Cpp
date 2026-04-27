/*
 * Key idea:
 *
 *   TODO
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <type_traits>

class Person {
public:
  template<
    typename T,
    typename = typename std::enable_if<
                 !std::is_base_of<Person,
                                  typename std::decay<T>::type
                                 >::value
               >::type
  >
  explicit Person(T&& n);
  // ...
};
