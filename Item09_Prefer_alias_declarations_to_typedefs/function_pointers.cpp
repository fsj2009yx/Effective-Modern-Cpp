/*
 * Key Idea:
 *
 *   Using alias declarations is easier to read than function pointers.
 *
 *   中文解释：
 *   用 using 定义类型别名通常比 typedef 更直观，
 *   尤其是函数指针这种语法本身就比较难读的类型。
 */

#include <string>

// FP is a synonym for a pointer to a function taking an int and
// a const std::string& and returning nothing
typedef void (*FP)(int, const std::string&);    // typedef

// same meaning as above
using FP = void (*)(int, const std::string&);   // alias
                                                // declaration
