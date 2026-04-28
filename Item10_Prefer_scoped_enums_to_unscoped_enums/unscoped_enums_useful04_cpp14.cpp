/*
 * Key Idea:
 *
 *   Scoped enums require a cast to size_t type in order
 *   to reference a field in std::tuple. To create a helper
 *   function, use constexpr since std::get is a template.
 *
 */

/*
 * 核心思想：
 *
 *   为了引用 std::tuple 中的字段，限域枚举需要转换为 size_t 类型。若要创建辅助函数，
 *   应使用 constexpr，因为 std::get 是模板。
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
