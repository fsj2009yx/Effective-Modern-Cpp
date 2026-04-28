/*
 * Key Idea:
 *
 *   In C++98 style enums, the names of these unscoped enumerators belong to the
 *   scope containing the enum, and that means nothing else in that scope may
 *   have the same name:
 *
 */

/*
 * 核心思想：
 *
 *   在 C++98 风格的枚举中，这些非限域枚举器的名字属于包含该 enum 的作用域，这意味着同一
 *   作用域中不能再有其他东西使用相同名字：
 */

enum Color { black, white, red };  // black, white, red are
                                   // in same scope as Color

//auto white = false;                // error! white already
                                   // declared in this scope
