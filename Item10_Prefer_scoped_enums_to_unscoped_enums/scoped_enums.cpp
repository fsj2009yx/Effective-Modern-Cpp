/*
 * Key Idea:
 *
 *   In C++11, the names of scoped enums do not belong to the scope containing
 *   the enum.
 *
 *   中文解释：
 *   C++11 的作用域枚举会把枚举值限制在枚举类型自己的作用域内。
 *   因此 black、white、red 需要通过 Color::white 这种形式访问，
 *   不会污染外层作用域。
 */

enum class Color { black, white, red };  // black, white, red
                                         // are scoped to Color

auto white = false;              // fine, no other
                                 // "white" in scope

//Color c1 = white;                 // error! no enumerator named
                                 // "white" is in this scope

Color c2 = Color::white;          // fine

auto c3 = Color::white;           // also fine (and in accord
                                 // with Item4's advice)
