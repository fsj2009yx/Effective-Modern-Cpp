/*
 * Key Idea:
 *
 *   In C++98, passing 0 or NULL to pointer and integral overloads never calls
 *   the pointer overload. nullptr always calls the pointer overload.
 *
 *   中文解释：
 *   在同时存在整数重载和指针重载时，0 或 NULL 会被当成整数相关实参处理，
 *   因而不会选择指针版本；nullptr 的类型专门表示空指针，所以会选择指针重载。
 */

#include <iostream>

// Three overloads of f
void f(int) { std::cout << "f(int)" << std::endl; }
void f(bool) { std::cout << "f(bool)" << std::endl; }
void f(void*) { std::cout << "f(void*)" << std::endl; }

int main()
{
  f(0);       // calls f(int) overload, not f(void*)

  //f(NULL);  // might not compile, but typically calls
              // f(int) overload.  Never calls f(void*)

  f(nullptr);  // calls f(void*) overload
}
