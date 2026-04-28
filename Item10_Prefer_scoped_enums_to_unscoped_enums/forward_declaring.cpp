/*
 * Key Idea:
 *
 *   Scoped enums can be forward-declared.
 *
 */

/*
 * 核心思想：
 *
 *   限域枚举可以被前置声明。
 */

//enum Color;         // error!
enum class Color;   // fine
