/*
 * Key Idea:
 *
 *   Every enum has an underlying type determined
 *   by the compiler - it may choose char, int, or
 *   any integral type.
 *
 *   中文解释：
 *   每个枚举底层都由某种整数类型保存。
 *   如果没有显式指定，编译器会根据枚举值范围选择合适的整数类型。
 */

enum Color { black, white, red };

enum Status { good = 0,
              failed = 1,
              incomplete = 100,
              corrupt = 200,
              indeterminate = 0xFFFFFFFF
            };
