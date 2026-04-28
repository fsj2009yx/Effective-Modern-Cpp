/*
 * Key Idea:
 *
 *   Every enum has an underlying type determined
 *   by the compiler - it may choose char, int, or
 *   any integral type.
 *
 */

/*
 * 核心思想：
 *
 *   每个 enum 都有一个由编译器确定的底层类型；编译器可以选择 char、int 或任何整数类型。
 */

enum Color { black, white, red };

enum Status { good = 0,
              failed = 1,
              incomplete = 100,
              corrupt = 200,
              indeterminate = 0xFFFFFFFF
            };
