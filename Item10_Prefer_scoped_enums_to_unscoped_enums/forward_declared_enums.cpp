/*
 * Key Idea:
 *
 *   Forward declaration of enums removes the dependency
 *   on the enum definition.
 *
 *   中文解释：
 *   枚举可以前置声明时，使用者只需要知道这个枚举类型存在，
 *   不必包含完整定义，从而降低头文件之间的编译依赖。
 */

enum class Status;                  // forward declaration
void continueProcessing(Status s);  // use of fwd-declared enum
