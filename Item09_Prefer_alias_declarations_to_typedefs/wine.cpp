/*
 * Key Idea:
 *
 *   MyAllocList<T>::type doesn't necessarily refer to a type. 
 *   Usage of a nested typedef renders it a dependent type, 
 *   (depending on what T is), and therefore the compiler requires
 *   preceding the template instantiation with typename.
 *
 *   中文解释：
 *   MyAllocList<T>::type 是否真的是类型，要取决于具体的 T。
 *   因为它是依赖模板参数的名字，编译器不能先验判断，所以需要用 typename
 *   明确告诉编译器：这里的 type 应该按“类型”来解析。
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
