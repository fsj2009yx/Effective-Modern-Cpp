/*
 * Key Idea:
 *
 *   Here an unscoped enum is used to reference a field in a
 *   std::tuple - an improvement to numbered fields.
 *
 *   Since std::get requires a size_t, here we can take
 *   advantage of implicit conversion which would have otherwise
 *   be more effort using scoped enums.
 *
 *   中文解释：
 *   这里用非作用域枚举表示 tuple 字段下标，比裸数字更清晰。
 *   因为 std::get 需要编译期整数下标，非作用域枚举能隐式转换成整数，
 *   所以不需要像作用域枚举那样额外写强制转换。
 */

#include <string>
#include <tuple>

using UserInfo =               // type alias; see Item 9
  std::tuple<std::string,      // name
             std::string,      // email
             std::size_t> ;    // reputation

int main()
{

  enum UserInfoFields { uiName, uiEmail, uiReputation };

  UserInfo uInfo;                       // as before
  // ...
  auto val = std::get<uiEmail>(uInfo);  // ah, get value of
                                        // email field
}
