/*
 * Key idea:
 *
 *   TODO
 *   中文解释：
 *
 *   本段说明该示例的核心思路与使用要点，帮助你更快理解代码意图。

 */

#include <string>
#include <type_traits>

std::string nameFromIdx(int idx)   // as in Item 26
{
  return std::string("Bart");
}

class Person {
public:
  template<
    typename T,
    typename = std::enable_if_t<
      !std::is_base_of<Person, std::decay_t<T>>::value
      &&
      !std::is_integral<std::remove_reference_t<T>>::value
    >
  >
  explicit Person(T&& n)      // ctor for std::strings and
  : name(std::forward<T>(n))  // args convertible to
  { /* ... */ }               // std::strings

  explicit Person(int idx)    // ctor for integral args
  : name(nameFromIdx(idx))
  { /* ... */ }

  // ...                      // copy and move ctors, etc.

private:
  std::string name;
};
