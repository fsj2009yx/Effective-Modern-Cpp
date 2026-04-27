/*
 * Key Idea:
 *
 *   Scoped enums require a cast to size_t type in order
 *   to reference a field in std::tuple. To create a helper
 *   function, use constexpr since std::get is a template.
 *
 *   中文解释：
 *   作用域枚举用作 tuple 字段下标时需要转换成底层整数类型。
 *   由于 std::get 的下标是模板参数，转换结果必须在编译期可用，
 *   所以辅助函数需要声明为 constexpr。
 */

#include <string>
#include <tuple>

using UserInfo =               // type alias; see Item 9
  std::tuple<std::string,      // name
             std::string,      // email
             std::size_t> ;    // reputation

template<typename E>
constexpr typename std::underlying_type<E>::type
  toUType(E enumerator) noexcept
{
  return
    static_cast<typename
                std::underlying_type<E>::type>(enumerator);
}

int main()
{

  enum class UserInfoFields { uiName, uiEmail, uiReputation };

  UserInfo uInfo;                       // as before
  // ...
  auto val = std::get<toUType(UserInfoFields::uiEmail)>(uInfo);
}
