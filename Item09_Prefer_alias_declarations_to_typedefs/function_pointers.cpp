/*
 * Key Idea:
 *
 *   Using alias declarations is easier to read than function pointers.
 *
 */

/*
 * 核心思想：
 *
 *   使用别名声明比使用函数指针更易读。
 */

#include <string>

// FP is a synonym for a pointer to a function taking an int and
// a const std::string& and returning nothing
typedef void (*FP)(int, const std::string&);    // typedef

// same meaning as above
using FP = void (*)(int, const std::string&);   // alias
                                                // declaration
