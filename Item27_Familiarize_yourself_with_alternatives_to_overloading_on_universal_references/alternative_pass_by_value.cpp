/*
 * Key Idea:
 *
 *   An alternative to overloading on universal references is to replace pass by
 *   reference with pass by value. This adheres to the guidance in Item 41 to
 *   consider passing objects by value when you know you'll copy them..
 *
 */

/*
 * 核心思想：
 *
 *   避免对万能引用进行重载的一种替代方案，是把按引用传递替换为按值传递。这符合 Item 41
 *   的建议：当你知道会拷贝对象时，考虑按值传递对象。
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
