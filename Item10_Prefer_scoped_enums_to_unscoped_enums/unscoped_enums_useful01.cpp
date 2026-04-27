/*
 * Key Idea:
 *
 *   Unscoped enums are useful in referencing std::tuple fields.
 *
 *   中文解释：
 *   非作用域枚举可以方便地给 std::tuple 的字段下标起名字，
 *   让代码比直接使用 0、1、2 这类数字下标更容易理解。
 */

#include <string>
#include <tuple>

using UserInfo =               // type alias; see Item 9
  std::tuple<std::string,      // name
             std::string,      // email
             std::size_t> ;    // reputation

int main()
{
  UserInfo uInfo;                 // object of tuple type
  // ...
  auto val = std::get<1>(uInfo);  // get value of field 1
}
