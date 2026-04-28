/*
 * Key Idea:
 *
 *   Unscoped enums are useful in referencing std::tuple fields.
 *
 */

/*
 * 核心思想：
 *
 *   非限域枚举在引用 std::tuple 字段时很有用。
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
