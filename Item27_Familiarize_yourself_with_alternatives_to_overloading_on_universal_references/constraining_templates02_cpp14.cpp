/*
 * Key idea:
 *
 *   If we're using C++14, we can employ alias templates for std::enable_if and
 *   std::decay to get rid of the "typename" and "::type" cruft.
 *
 */

/*
 * 核心思想：
 *
 *   如果使用 C++14，可以使用 std::enable_if 和 std::decay 的别名模板，去掉 typename 和
 *   ::type 这些冗余写法。
 */

#include <type_traits>

class Person {                                  // C++14
public:
  template<
    typename T,
    typename = std::enable_if_t<               // less code here
                 !std::is_base_of<Person,
                                  std::decay_t<T>  // and here
                                 >::value
               >                                   // and here
  >
  explicit Person(T&& n);
  // ...
};
