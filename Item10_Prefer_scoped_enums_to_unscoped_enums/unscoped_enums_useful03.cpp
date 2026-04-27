/*
 * Key Idea:
 *
 *   The scoped enum method for referencing std::tuple
 *   field with an enum - requires a cast to size_t.
 *   Unscoped enums have an advantage here with implicit
 *   conversion.
 *
 *   中文解释：
 *   如果用作用域枚举表示 tuple 字段下标，枚举值不会自动变成 size_t，
 *   因此传给 std::get 时必须显式转换。这里展示的是作用域枚举在该场景下的额外成本。
 */

#include <string>
#include <tuple>

using UserInfo =               // type alias; see Item 9
  std::tuple<std::string,      // name
             std::string,      // email
             std::size_t> ;    // reputation

int main()
{

  enum class UserInfoFields { uiName, uiEmail, uiReputation };

  UserInfo uInfo;                       // as before
  // ...
  auto val = std::get<static_cast<std::size_t>(UserInfoFields::uiEmail)>(uInfo);
}
