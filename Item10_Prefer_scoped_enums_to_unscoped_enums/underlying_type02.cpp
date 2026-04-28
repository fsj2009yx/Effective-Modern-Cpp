/*
 * Key Idea:
 *
 *   In C++11, all scoped enums have a default underlying type:
 *   int. It may also be specified explicity, can be forward
 *   declared, and the type specification can be placed in the
 *   definition.
 *
 */

/*
 * 核心思想：
 *
 *   在 C++11 中，所有限域枚举都有默认底层类型 int。也可以显式指定底层类型，可以前置声明，
 *   并且类型说明可以放在定义中。
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
