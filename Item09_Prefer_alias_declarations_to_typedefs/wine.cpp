/*
 * Key Idea:
 *
 *   MyAllocList<T>::type doesn't necessarily refer to a type.
 *   Usage of a nested typedef renders it a dependent type,
 *   (depending on what T is), and therefore the compiler requires
 *   preceding the template instantiation with typename.
 *
 */

/*
 * 核心思想：
 *
 *   MyAllocList<T>::type 不一定指代一个类型。使用嵌套 typedef 会使它成为依赖类型
 *   （取决于 T 是什么），因此编译器要求在模板实例化前加上 typename。
 */

// TODO: get this to compile!
#include "linked_list_synonym_with_alias_template01.cpp"

class Wine { };

template<>                      // MyAllocList specialization
class MyAllocList<Wine> {       // for when T is Wine
private:
  enum class WineType           // see Item 10 for info on
  { White, Red, Blush };        // "enum class"

  WineType type;                // in this class, type is
  // ...                        // a data member!
};
