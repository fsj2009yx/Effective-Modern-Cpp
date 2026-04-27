/*
 * Key Idea:
 *
 *   Scoped enums can be forward-declared.
 *
 *   中文解释：
 *   作用域枚举 enum class 可以前置声明，
 *   这让接口可以先声明枚举类型，而不必立刻暴露所有枚举值。
 */

//enum Color;         // error!
enum class Color;   // fine
