/*
 * Key Idea:
 *
 *   An alternative to overloading on universal references is to replace pass by
 *   reference with pass by value. This adheres to the guidance in Item 41 to
 *   consider passing objects by value when you know you'll copy them..
 *
 *   中文解释：
 *   不一定要用通用引用来处理所有构造参数。
 *   如果函数或构造函数内部本来就要复制参数，可以考虑按值传参，
 *   再在成员初始化时移动它，这样接口更简单，也能避开通用引用重载带来的问题。
 */

#include <string>
#include <utility>

std::string nameFromIdx(int idx) {
  return std::string("Bart");
}

class Person {
public:
  explicit Person(std::string n)  // replaces T&& ctor; see
  : name(std::move(n)) {}         // Item 41 for use of std::move

  explicit Person(int idx)        // as before
  : name(nameFromIdx(idx)) {}

  // ...

private:
  std::string name;
};
