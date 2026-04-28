/*
 * Key Idea:
 *
 *   In C++11, the names of scoped enums do not belong to the scope containing
 *   the enum.
 *
 */

/*
 * 核心思想：
 *
 *   在 C++11 中，限域枚举的枚举名不属于包含该 enum 的作用域。
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
