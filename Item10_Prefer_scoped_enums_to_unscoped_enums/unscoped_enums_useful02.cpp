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
 */

/*
 * 核心思想：
 *
 *   这里使用非限域枚举来引用 std::tuple 中的字段，相比直接使用编号字段更好。
 *
 *   由于 std::get 需要 size_t，这里可以利用隐式转换；如果使用限域枚举，则需要更多额外工作。
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
