/*
 * Key Idea:
 *
 *   In C++11, all scoped enums have a default underlying type:
 *   int. It may also be specified explicity, can be forward
 *   declared, and the type specification can be placed in the
 *   definition.
 *
 *   中文解释：
 *   C++11 中，作用域枚举默认底层类型是 int。
 *   也可以显式指定底层类型；指定后可以前置声明，
 *   并且底层类型说明既能写在声明处，也能写在定义处。
 */

#include <cstdint>

enum class Status1;                 // underlying type is int

enum class Status2: std::uint32_t;  // underlying type for
                                    // Status is std::uint32_t
                                    // (from <cstdint>)

enum Color: std::uint8_t;          // fwd decl for unscoped enum;
                                   // underlying type is
                                   // std::uint8_t

enum class Status3: std::uint32_t { good = 0,
                                    failed = 1,
                                    incomplete = 100,
                                    corrupt = 200,
                                    audited = 500,
                                    indeterminate = 0xFFFFFFFF
                                  };
