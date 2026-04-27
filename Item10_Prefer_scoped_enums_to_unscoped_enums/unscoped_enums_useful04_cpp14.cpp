/*
 * Key Idea:
 *
 *   Scoped enums require a cast to size_t type in order
 *   to reference a field in std::tuple. To create a helper
 *   function, use constexpr since std::get is a template.
 *
 *   中文解释：
 *   作用域枚举用作 tuple 字段下标时需要转换成底层整数类型。
 *   因为 std::get 的下标必须是编译期常量，辅助转换函数要用 constexpr。
 *   C++14 可以用 std::underlying_type_t 或 auto 返回类型把写法变得更简洁。
 */

#include <string>
#include <tuple>
#include <type_traits>

using UserInfo =               // type alias; see Item 9
  std::tuple<std::string,      // name
             std::string,      // email
             std::size_t> ;    // reputation

// Method 1
template<typename E>                                // C++14
constexpr std::underlying_type_t<E>
  toUType(E enumerator) noexcept
{
  return static_cast<std::underlying_type_t<E>>(enumerator);
}

// Method 2: using auto return type
//template<typename E>                                // C++14
//constexpr auto
//  toUType(E enumerator) noexcept
//{
//  return static_cast<std::underlying_type_t<E>>(enumerator);
//}

int main()
{

  enum class UserInfoFields { uiName, uiEmail, uiReputation };

  UserInfo uInfo;                       // as before
  // ...
  auto val = std::get<toUType(UserInfoFields::uiEmail)>(uInfo);
}
