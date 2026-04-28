/*
 * Key Idea:
 *
 *   If a new value is added to an enum that is included
 *   everywhere, the entire system will have to be recompiled.
 *
 */

/*
 * 核心思想：
 *
 *   如果向一个被到处包含的 enum 添加新值，整个系统都必须重新编译。
 */

enum Status { good = 0,
              failed = 1,
              incomplete = 100,
              corrupt = 200,
              // audited = 500,
              indeterminate = 0xFFFFFFFF
            };
