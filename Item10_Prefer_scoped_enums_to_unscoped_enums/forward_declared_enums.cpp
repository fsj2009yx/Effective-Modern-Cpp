/*
 * Key Idea:
 *
 *   Forward declaration of enums removes the dependency
 *   on the enum definition.
 *
 */

/*
 * 核心思想：
 *
 *   enum 的前置声明可以消除对 enum 定义的依赖。
 */

enum class Status;                  // forward declaration
void continueProcessing(Status s);  // use of fwd-declared enum
