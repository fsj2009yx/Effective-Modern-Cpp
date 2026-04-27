/*
 * Key Idea:
 *
 *   In C++98 style enums, the names of these unscoped enumerators belong to the
 *   scope containing the enum, and that means nothing else in that scope may
 *   have the same name:
 *
 *   中文解释：
 *   C++98 风格的非作用域枚举会把枚举值名字放到外层作用域中。
 *   因此外层作用域里不能再声明同名变量，否则会产生命名冲突。
 */

enum Color { black, white, red };  // black, white, red are
                                   // in same scope as Color

//auto white = false;                // error! white already
                                   // declared in this scope
