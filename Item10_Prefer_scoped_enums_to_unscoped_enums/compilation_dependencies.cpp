/*
 * Key Idea:
 *
 *   If a new value is added to an enum that is included
 *   everywhere, the entire system will have to be recompiled.
 *
 *   中文解释：
 *   如果枚举定义放在被大量文件包含的头文件里，枚举值一变，
 *   所有依赖该定义的代码都可能需要重新编译，增加编译依赖和构建成本。
 */

enum Status { good = 0,
              failed = 1,
              incomplete = 100,
              corrupt = 200,
              // audited = 500,
              indeterminate = 0xFFFFFFFF
            };
